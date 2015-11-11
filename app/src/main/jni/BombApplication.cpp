//
// Created by jens on 11/3/15.
//

#include "BombApplication.h"

#include "AndroidApp.h"

#include "log.h"

#include "ResouceManager.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "GLContext.h"

#include <chrono>
#include <thread>


BombApplication::BombApplication()
    : Application {}
{ }

void BombApplication::loadResources(ResourceManager const &resource_manager)
{
    LOGV("Loading bomb application");
}

void BombApplication::update(GLContext const& context)
{
    LOGV("tick");
}