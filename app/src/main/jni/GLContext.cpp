//
// Created by jens on 11/10/15.
//

#include "GLContext.h"

#include "log.h"

#include "GLES3/gl3.h"
#include <EGL/egl.h>

GLContext::GLContext(ANativeWindow * window)
{
    display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    eglInitialize(display, 0, 0);

    static const EGLint attribs[] = { EGL_RENDERABLE_TYPE,
        EGL_OPENGL_ES2_BIT, EGL_SURFACE_TYPE, EGL_WINDOW_BIT, EGL_BLUE_SIZE, 8, EGL_GREEN_SIZE, 8,
        EGL_RED_SIZE, 8, EGL_DEPTH_SIZE, 24, EGL_NONE };

    int32_t color_size = 8;
    int32_t depth_size = 24;

    EGLint num_configs;
    eglChooseConfig(display, attribs, &config, 1, &num_configs);

    if (!num_configs)
    {
        LOGV("Failed to retrieve EGL config");
        return;
    }

    surface = eglCreateWindowSurface(display, config, window, nullptr);
    eglQuerySurface(display, surface, EGL_WIDTH, &width);
    eglQuerySurface(display, surface, EGL_HEIGHT, &height);

    EGLint format;
    eglGetConfigAttrib(display, config, EGL_NATIVE_VISUAL_ID, &format);
    ANativeWindow_setBuffersGeometry(window, 0, 0, format);



    // Init EGL

    static const EGLint context_attribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE };
    context = eglCreateContext(display, config, nullptr, context_attribs);

    if (eglMakeCurrent(display, surface, surface, context) == EGL_FALSE)
    {
        LOGV("Failed to make egl current");
        return;
    }

    const char * version = reinterpret_cast<char const*>(glGetString(GL_VERSION));

    LOGV("GL version: %s", version);

}
