#include <jni.h>

#include <android/native_activity.h>

#include "AndroidApp.h"
#include "log.h"

extern AndroidApp * createAndroidApplication(ANativeActivity * activity, void * saved_state, size_t saved_state_size);

static AndroidApp * createAndroidApp(ANativeActivity* activity,
                                     void*            saved_state,
                                     size_t           saved_state_size)
{
    AndroidApp * android_app = createAndroidApplication(activity, saved_state, saved_state_size);
    startRunLoop(android_app);

    return android_app;
}

static void onDestroy(ANativeActivity* activity)
{
    reinterpret_cast<AndroidApp*>(activity->instance)->onDestroy();
}

static void onStart(ANativeActivity* activity)
{
    reinterpret_cast<AndroidApp*>(activity->instance)->onStart();
}

static void onResume(ANativeActivity* activity)
{
    reinterpret_cast<AndroidApp*>(activity->instance)->onResume();
}

static void* onSaveInstanceState(ANativeActivity* activity, size_t* out_len)
{
    return reinterpret_cast<AndroidApp*>(activity->instance)->onSaveInstanceState(out_len);
}

static void onPause(ANativeActivity* activity)
{
    reinterpret_cast<AndroidApp*>(activity->instance)->onPause();
}

static void onStop(ANativeActivity* activity)
{
    reinterpret_cast<AndroidApp*>(activity->instance)->onStop();
}

static void onConfigurationChanged(ANativeActivity* activity)
{
    reinterpret_cast<AndroidApp*>(activity->instance)->onConfigurationChanged();
}

static void onLowMemory(ANativeActivity* activity)
{
    reinterpret_cast<AndroidApp*>(activity->instance)->onLowMemory();
}

static void onWindowFocusChanged(ANativeActivity* activity, int focused)
{
    reinterpret_cast<AndroidApp*>(activity->instance)->onWindowFocusChanged(focused);
}

static void onNativeWindowCreated(ANativeActivity* activity, ANativeWindow* window)
{
    reinterpret_cast<AndroidApp*>(activity->instance)->onNativeWindowCreated(window);
}

static void onNativeWindowDestroyed(ANativeActivity* activity, ANativeWindow* window)
{
    reinterpret_cast<AndroidApp*>(activity->instance)->onNativeWindowDestroyed(window);
}

static void onInputQueueCreated(ANativeActivity* activity, AInputQueue* queue)
{
    reinterpret_cast<AndroidApp*>(activity->instance)->onInputQueueCreated(queue);
}

static void onInputQueueDestroyed(ANativeActivity* activity, AInputQueue* queue)
{
    reinterpret_cast<AndroidApp*>(activity->instance)->onInputQueueDestroyed(queue);
}

void ANativeActivity_onCreate(ANativeActivity* activity,
                              void* savedState, size_t savedStateSize)
{
    LOGV("Creating: %p\n", activity);
    activity->callbacks->onDestroy = onDestroy;
    activity->callbacks->onStart = onStart;
    activity->callbacks->onResume = onResume;
    activity->callbacks->onSaveInstanceState = onSaveInstanceState;
    activity->callbacks->onPause = onPause;
    activity->callbacks->onStop = onStop;
    activity->callbacks->onConfigurationChanged = onConfigurationChanged;
    activity->callbacks->onLowMemory = onLowMemory;
    activity->callbacks->onWindowFocusChanged = onWindowFocusChanged;
    activity->callbacks->onNativeWindowCreated = onNativeWindowCreated;
    activity->callbacks->onNativeWindowDestroyed = onNativeWindowDestroyed;
    activity->callbacks->onInputQueueCreated = onInputQueueCreated;
    activity->callbacks->onInputQueueDestroyed = onInputQueueDestroyed;

    activity->instance = createAndroidApp(activity, savedState, savedStateSize);
}