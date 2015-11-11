//
// Created by jens on 11/5/15.
//

#include "Mesh.h"

#include "MeshPart.h"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"

#include <vector>

Mesh::Mesh(std::vector<unsigned char> const& mesh_data)
{
    Assimp::Importer importer;
    auto const scene = importer.ReadFileFromMemory(mesh_data.data(), mesh_data.size(), 0);

    for (int i = 0; i < scene->mNumMeshes; ++i)
    {
        parts.push_back(MeshPart(*scene->mMeshes[i]));
    }

}

Mesh::~Mesh()
{

}