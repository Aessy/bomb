//
// Created by jens on 11/5/15.
//


#ifndef BOMB_BUFFER_H
#define BOMB_BUFFER_H

#include "log.h"

#include <GLES3/gl3.h>
#include <vector>

template<typename BufferType, GLuint buffer_type, GLuint size, GLuint position>
struct Buffer
{
    Buffer(std::vector<BufferType> const& buffer_data, bool enable_attrib_ptr)
    {
        if (buffer_data.size() % 3 != 0)
        {
            LOGV("Cannot create VBO because size of buffer data does not match the buffer type.");
            return;
        }
        if (buffer_data.empty())
        {
            LOGV("Cannot create VBO, missing buffer data.");
            return;
        }

        glGenBuffers(1, &vbo);
        glBindBuffer(buffer_type, vbo);
        glBufferData(buffer_type, buffer_data.size() * sizeof(BufferType), buffer_data.data(), GL_STATIC_DRAW);

        if (enable_attrib_ptr)
        {
            glEnableVertexAttribArray(position);
            glVertexAttribPointer(position, size, GL_FLOAT, GL_FALSE, 0, nullptr);
        }
    }

    Buffer()
    { }

    ~Buffer()
    {
        glDeleteBuffers(1, &vbo);
    }

    void bind()
    {
        glBindBuffer(buffer_type, vbo);
    }

private:
    GLuint vbo = 0;
};

using VertexBuffer  = Buffer<GLfloat, GL_ARRAY_BUFFER,         3, 0>;
using NormalsBuffer = Buffer<GLfloat, GL_ARRAY_BUFFER,         3, 1>;
using UVBuffer      = Buffer<GLfloat, GL_ARRAY_BUFFER,         2, 2>;
using Indices       = Buffer<GLuint,  GL_ELEMENT_ARRAY_BUFFER, 3, 0>;


#endif //BOMB_BUFFER_H
