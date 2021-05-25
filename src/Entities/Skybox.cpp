/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Skybox
*/

#include "Skybox.hpp"

IS::Skybox::Skybox(const std::string &texturePath)
{
    Mesh cube = GenMeshCube(1.0f, 1.0f, 1.0f);
    _model = LoadModelFromMesh(cube);
    _model.materials[0].shader = _skyboxShader.getShader();
    Image img = LoadImage(texturePath.c_str());
    _model.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = LoadTextureCubemap(img, CUBEMAP_LAYOUT_AUTO_DETECT);
    UnloadImage(img);
}

IS::Skybox::~Skybox()
{
}

Model IS::Skybox::getModel() const
{
    return (_model);
}

void IS::Skybox::setModel(Model model)
{
    _model = model;
}
