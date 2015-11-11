//
// Created by jens on 11/5/15.
//

#ifndef BOMB_MESH_H
#define BOMB_MESH_H

#include <GLES3/gl3.h>

#include <string>

#include "MeshPart.h"

class Mesh
{
public:
    Mesh(std::vector<unsigned char> const& mesh_data);
    ~Mesh();

private:
    std::vector<MeshPart> parts;
};


#endif //BOMB_MESH_H
