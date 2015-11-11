//
// Created by jens on 11/6/15.
//

#ifndef BOMB_ASSETIMPORTER_H
#define BOMB_ASSETIMPORTER_H

#include <android/native_activity.h>

#include <string>
#include <vector>

struct Resource
{
    void const * data_ptr;
    size_t length;
};

class ResourceManager
{
public:
    ResourceManager(ANativeActivity * activity);

    Resource readTextFile(std::string const& filename);

    std::vector<unsigned char> readFile(std::string const& filename) const;

private:
    AAssetManager * asset_manager;
};

#endif //BOMB_ASSETIMPORTER_H
