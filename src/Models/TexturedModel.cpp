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

Model IS::TexturedModel::getModel() const
{
    return (_model);
}

Texture2D IS::TexturedModel::getTexture() const
{
    return (_texture);
}

void IS::TexturedModel::setModel(Model model)
{
    _model = model;
}

void IS::TexturedModel::setTexture(Texture2D texture)
{
    _texture = texture;
}

void IS::TexturedModel::setTransform(Matrix matrix)
{
    _model.transform = matrix;
}

bool IS::TexturedModel::hasShader()
{
    if (_model.materials[0].shader.id == 3)
        return (false);
    return (true);
}

void IS::TexturedModel::setShader(Shader shader)
{
    for (int i = 0; i < _model.materialCount; i++)
        _model.materials[i].shader = shader;
}

void IS::TexturedModel::setColor(Color color, int materialNumber)
{
    for (int i = 0; i < _model.materialCount; i++)
        if (i == materialNumber)
            _model.materials[i].maps[MATERIAL_MAP_ALBEDO].color = color;
}
