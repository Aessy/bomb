//
// Created by jens on 11/4/15.
//

#include "ShaderProgram.h"
#include "log.h"

// TODO: Platform dependant header.
#include "GLES3/gl3.h"

GLuint loadShader(std::string const& shader_data, GLenum shader_type)
{
    GLuint shader_obj = glCreateShader(shader_type);

    GLchar const * shader_source = shader_data.c_str();
    GLint const length = shader_data.length();

    glShaderSource(shader_obj,1,&shader_source,&length);
    glCompileShader(shader_obj);
    GLint success;
    glGetShaderiv(shader_obj, GL_COMPILE_STATUS,&success);
    if (!success)
    {
        LOGV("Failed compiling shader");
        return 0;
    }

    return shader_obj;
}

ShaderProgram::ShaderProgram(std::string const& vertex, std::string const& fragment)
    : shader_program { glCreateProgram() }
{
    auto vertex_shader = loadShader(vertex, GL_VERTEX_SHADER);
    auto fragment_shader = loadShader(fragment, GL_FRAGMENT_SHADER);
    if (vertex_shader == 0 || fragment_shader == 0)
    {
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);
        glDeleteProgram(shader_program);
        return;
    }

    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    glValidateProgram(shader_program);
    glUseProgram(shader_program);
}

void ShaderProgram::use()
{
    if (shader_program != 0)
        glUseProgram(shader_program);
}