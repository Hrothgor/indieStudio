/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** TexturedModel
*/

#include "TexturedModel.hpp"

IS::TexturedModel::TexturedModel(const std::string &modelPath)
{
    _model = LoadModel(modelPath.c_str());
    _model.materials[0].maps[MATERIAL_MAP_ALBEDO].color = RED;
    _model.materials[1].maps[MATERIAL_MAP_ALBEDO].color = GREEN;
}

IS::TexturedModel::TexturedModel(const std::string &modelPath, const std::string &texturePath)
{
    _model = LoadModel(modelPath.c_str());
    _texture = LoadTexture(texturePath.c_str());
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
}

IS::TexturedModel::TexturedModel(Mesh mesh, const std::string &texturePath)
{
    _model = LoadModelFromMesh(mesh);
    _texture = LoadTexture(texturePath.c_str());
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
}

IS::TexturedModel::~TexturedModel()
{
}

Model &IS::TexturedModel::getModel()
{
    return (_model);
}

Texture2D IS::TexturedModel::getTexture() const
{
    return (_texture);
}

bool IS::TexturedModel::hasShader()
{
    if (_model.materials[0].shader.id == 3)
        return (false);
    return (true);
}

void IS::TexturedModel::setShader(Shader shader)
{
    _model.materials[0].shader = shader;
}
