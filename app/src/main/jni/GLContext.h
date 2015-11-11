//
// Created by jens on 11/10/15.
//

#ifndef BOMB_GLCONTEXT_H
#define BOMB_GLCONTEXT_H

#include <EGL/egl.h>
#include <GLES3/gl3.h>

#include <android/native_activity.h>

class GLContext
{
public:
    GLContext(ANativeWindow * window);

private:
    EGLDisplay display;
    EGLSurface surface;
    EGLContext context;

    EGLConfig config;

    int32_t width;
    int32_t height;

};


#endif //BOMB_GLCONTEXT_H
