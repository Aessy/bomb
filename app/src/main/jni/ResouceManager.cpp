//
// Created by jens on 11/6/15.
//

#include "ResouceManager.h"
#include <android/native_activity.h>

#include "log.h"

#include <string>
#include <fstream>

static std::string getAssetsPath(ANativeActivity * activity)
{
    JNIEnv * env;

    activity->vm->AttachCurrentThread(&env, nullptr);

    jclass cls_env = env->FindClass("android/app/NativeActivity");
    jmethodID mid = env->GetMethodID(cls_env, "getExternalFilesDir",
                                     "(Ljava/lang/String;)Ljava/io/File;");
    jobject obj_file = env->CallObjectMethod(activity->clazz, mid, nullptr);
    jclass cls_file = env->FindClass("java/io/File");
    jmethodID mid_get_path = env->GetMethodID(cls_file, "getPath", "()Ljava/lang/String;");
    jstring obj_path = (jstring) env->CallObjectMethod(obj_file, mid_get_path);

    const char * path = env->GetStringUTFChars(obj_path, nullptr);

    return path;
}

ResourceManager::ResourceManager(ANativeActivity * activity)
    : asset_manager { activity->assetManager }
{
}

std::string ResourceManager::readTextFile(std::string const &filename)
{
    AAsset * asset_file = AAssetManager_open(asset_manager, filename.c_str(), AASSET_MODE_BUFFER);
    if (!asset_file)
        return "";

    char const * data = reinterpret_cast<char const*>(AAsset_getBuffer(asset_file));
    auto const size = AAsset_getLength(asset_file);

    std::string text_file(data, data+size);

    return text_file;
}
