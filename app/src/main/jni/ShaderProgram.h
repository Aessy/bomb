//
// Created by jens on 11/4/15.
//

#ifndef BOMB_SHADERPROGRAM_H
#define BOMB_SHADERPROGRAM_H

#include <string>

#include "GLES3/gl3.h"

class ShaderProgram
{
public:
    ShaderProgram(std::string const& vertex, std::string const& fragment);

    void use();

private:
    GLuint shader_program;

};


#endif //BOMB_SHADERPROGRAM_H
