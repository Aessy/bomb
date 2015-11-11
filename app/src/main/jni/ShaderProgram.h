//
// Created by jens on 11/4/15.
//

#ifndef BOMB_SHADERPROGRAM_H
#define BOMB_SHADERPROGRAM_H

#include <string>
#include <vector>

#include "GLES3/gl3.h"

class ShaderProgram
{
public:
    ShaderProgram(std::vector<unsigned char> const& vertex, std::vector<unsigned char> const& fragment);

    void use();

private:
    GLuint shader_program;

};


#endif //BOMB_SHADERPROGRAM_H
