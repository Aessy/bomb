//
// Created by jens on 11/3/15.
//

#include <android/native_activity.h>

#include "Application.h"
#include "GLContext.h"
#include "ResouceManager.h"

#include <memory>

#ifndef BOMB_BOMBAPPLICATION_H
#define BOMB_BOMBAPPLICATION_H


class BombApplication : public Application
{
public:
    BombApplication();

    void loadResources(ResourceManager const& resource_manager) override;
    void update(GLContext const& gl_context) override;
};


#endif //BOMB_BOMBAPPLICATION_H
