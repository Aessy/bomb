//
// Created by jens on 11/3/15.
//

#include "AndroidApp.h"

#include "log.h"

#include "GLContext.h"

#include <chrono>
#include <thread>

static void * run_loop(void * app);

void startRunLoop(AndroidApp * app)
{
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&app->thread, &attr, run_loop, reinterpret_cast<void*>(app));
}

static void * run_loop(void * app)
{
    reinterpret_cast<AndroidApp*>(app)->run();
    return nullptr;
}


AndroidApp::AndroidApp(ANativeActivity *activity, std::shared_ptr<Application> app)
    : activity { activity }
    , application { app }
    , gl_context { nullptr }
{ }

void AndroidApp::onDestroy()
{
    // App will be destroyed after this. Should probably exit the thread.
    LOGI("On destroy");
}
void AndroidApp::onStart()
{
    LOGI("On start");
}
void AndroidApp::onResume()
{
    LOGI("On resume");
}
void * AndroidApp::onSaveInstanceState(size_t * out_size)
{
    LOGI("On save instance state");

    *out_size = 0;
    return nullptr;

}
void AndroidApp::onPause()
{
    LOGI("On pause");
}
void AndroidApp::onStop()
{
    LOGI("On stop");
}
void AndroidApp::onConfigurationChanged()
{
    LOGI("On configuration changed");
}
void AndroidApp::onLowMemory()
{
    LOGI("On low memory");
}
void AndroidApp::onWindowFocusChanged(int has_focus)
{
    LOGI("On window focus changed: %i", has_focus);
}

void AndroidApp::onNativeWindowCreated(ANativeWindow * window)
{
    this->window = window;
    LOGI("On native window created");
    gl_context = std::unique_ptr<GLContext>(new GLContext(window));
}

void AndroidApp::onNativeWindowDestroyed(ANativeWindow * window)
{
    // Must stop drawing to window before returning from function
    gl_context.reset(nullptr);
    this->window = nullptr;
    LOGI("On native window destroyed");
}
void AndroidApp::onInputQueueCreated(AInputQueue * queue)
{
    // Input queue is used to poll events. Need to synchronise with run thread.
    // Hmm, should figure out a way without using semaphores I guess.
    // Probably wait with starting the run loop until we have a input queue.
    this->input_queue = queue;
    LOGI("On input queue created");

}
void AndroidApp::onInputQueueDestroyed(AInputQueue * queue)
{
    this->input_queue = nullptr;
    LOGI("On input queue destroyed.");
}

void AndroidApp::run()
{
    // 1. Wait for window to be created.
    // 2. Take lock.
    // 3. application->loadResources(rm);
    bool run_loop = true;
    while (run_loop)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        this->application->update(*gl_context);
    }
}