//
// Created by jens on 11/5/15.
//

#ifndef BOMB_MESHPART_H
#define BOMB_MESHPART_H

#include <GLES3/gl3.h>

#include <memory>

#include "Buffer.h"

#include "assimp/mesh.h"

class MeshPart
{
public:
    MeshPart(aiMesh const& mesh);

private:
    GLuint vao;

    std::shared_ptr<VertexBuffer> vertices;
    std::shared_ptr<NormalsBuffer> normals;
    std::shared_ptr<Indices> indices;
};


#endif //BOMB_MESHPART_H
