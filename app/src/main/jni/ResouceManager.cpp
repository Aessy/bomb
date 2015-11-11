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

Resource ResourceManager::readTextFile(std::string const &filename)
{
    AAsset * asset_file = AAssetManager_open(asset_manager, filename.c_str(), AASSET_MODE_BUFFER);
    if (!asset_file)
        return {};

    void const * data = AAsset_getBuffer(asset_file);
    auto const size = AAsset_getLength(asset_file);

    return { data, static_cast<size_t>(size)};
}
std::vector<unsigned char> ResourceManager::readFile(std::string const& filename) const
{
    AAsset * asset_file = AAssetManager_open(asset_manager, filename.c_str(), AASSET_MODE_BUFFER);
    if (!asset_file)
        return {};

    unsigned char const * data = reinterpret_cast<const unsigned char*>(AAsset_getBuffer(asset_file));
    auto const size = AAsset_getLength(asset_file);

    std::vector<unsigned char> file(data, data+size);
    LOGV("File size: %u", file.size());

    AAsset_close(asset_file);

    return file;

}
