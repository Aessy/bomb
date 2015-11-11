//
// Created by jens on 11/3/15.
//

#ifndef BOMB_ANDROIDAPP_H
#define BOMB_ANDROIDAPP_H

#include <android/native_activity.h>
#include <pthread.h>
#include "GLContext.h"

#include "Application.h"

#include <memory>

class AndroidApp
{
public:
    AndroidApp(ANativeActivity * activity, std::shared_ptr<Application> app);

    void run();

    void onDestroy();
    void onStart();
    void onResume();
    void * onSaveInstanceState(size_t * out_size);
    void onPause();
    void onStop();
    void onConfigurationChanged();
    void onLowMemory();
    void onWindowFocusChanged(int has_focus);
    void onNativeWindowCreated(ANativeWindow * window);
    void onNativeWindowDestroyed(ANativeWindow * window);
    void onInputQueueCreated(AInputQueue * queue);
    void onInputQueueDestroyed(AInputQueue * queue);

public:
    friend void startRunLoop(AndroidApp*);
    ANativeActivity * activity;
    std::shared_ptr<Application> application;

    ANativeWindow * window;

    std::unique_ptr<GLContext> gl_context;

private:
    AInputQueue * input_queue;
    pthread_t thread;
};

void startRunLoop(AndroidApp * app);


#endif //BOMB_ANDROIDAPP_H
