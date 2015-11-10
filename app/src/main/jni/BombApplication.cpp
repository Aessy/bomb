//
// Created by jens on 11/3/15.
//

#include "BombApplication.h"

#include "AndroidApp.h"

#include "log.h"

#include "ResouceManager.h"

#include <chrono>
#include <thread>

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

    ResourceManager resource_manager(activity);
    std::string barrel_data = resource_manager.readTextFile("barrel.obj");
    bool run = true;
    while (run)
    {
        LOGV("tick");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // 1. Poll events.
        // 2. Update logic.
        // 3. Render scene
    }
}