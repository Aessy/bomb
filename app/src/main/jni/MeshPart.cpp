//
// Created by jens on 11/5/15.
//

#include "MeshPart.h"

#include "assimp/mesh.h"

#include "Buffer.h"
#include <memory>

static GLuint genVao()
{
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    return vao;
}

static std::vector<GLfloat> getVertices(aiMesh const& mesh)
{
    std::vector<GLfloat> vertices;
    vertices.reserve(mesh.mNumVertices * 3);
    for (int i = 0; i < mesh.mNumVertices; ++i)
    {
        vertices.push_back(mesh.mVertices[i].x);
        vertices.push_back(mesh.mVertices[i].y);
        vertices.push_back(mesh.mVertices[i].z);
    }
}

MeshPart::MeshPart(aiMesh const& mesh)
    : vao { genVao() }
{
    vertices = std::make_shared<VertexBuffer>(getVertices(mesh), true);
}