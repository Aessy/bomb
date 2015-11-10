//
// Created by jens on 11/3/15.
//

#include "BombApplication.h"

#include "AndroidApp.h"

#include "log.h"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/mesh.h"

#include <string>
#include <future>

AndroidApp * createAndroidApplication(ANativeActivity * activity, void * saved_state, size_t saved_state_size)
{
    return new BombApplication(activity);
}

BombApplication::BombApplication(ANativeActivity *activity)
    : AndroidApp { activity }
{ }

void BombApplication::run()
{
    LOGV("Running bomb application");
    while (1)
    {
        // 1. Poll events.
        // 2. Update logic.
        // 3. Render scene
    }
}