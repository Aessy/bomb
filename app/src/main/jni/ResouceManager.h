//
// Created by jens on 11/6/15.
//

#ifndef BOMB_ASSETIMPORTER_H
#define BOMB_ASSETIMPORTER_H

#include <android/native_activity.h>

#include <string>


class ResourceManager
{
public:
    ResourceManager(ANativeActivity * activity);

    std::string readTextFile(std::string const& filename);

private:
    AAssetManager * asset_manager;
};

#endif //BOMB_ASSETIMPORTER_H
