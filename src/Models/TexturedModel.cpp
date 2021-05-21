/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** TexturedModel
*/

#include "TexturedModel.hpp"

std::string IntPlusPadding(int i, int paddingLength)
{
    std::ostringstream ss;
    ss << std::setw(paddingLength) << std::setfill('0') << i;
    return ss.str();
}

IS::TexturedModel::TexturedModel(const std::string &modelPath)
{
    std::string path = "ressources/" + modelPath + ".obj";
    std::string pathTexture = "ressources/" + modelPath + ".png";

    if (std::filesystem::exists(path)) {
        _models.push_back(LoadModel(path.c_str()));
        if (std::filesystem::exists(pathTexture)) {
            _texture = LoadTexture(pathTexture.c_str());
            _models[0].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
        }
    } else {
        int i = 0;
        while (std::filesystem::exists((path = std::string("ressources/" + modelPath + "/" + modelPath + "_" + IntPlusPadding(i, 6) + ".obj")))) {
            _models.push_back(LoadModel(path.c_str()));
            i += 1;
        }
    }
}

IS::TexturedModel::TexturedModel(Mesh mesh, const std::string &texturePath)
{
    _models.push_back(LoadModelFromMesh(mesh));
    _texture = LoadTexture(texturePath.c_str());
    _models[0].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
}

IS::TexturedModel::TexturedModel(Model model)
{
    _models.push_back(model);
}

IS::TexturedModel::~TexturedModel()
{
}

void IS::TexturedModel::nextFrame()
{
    std::rotate(_models.begin(), _models.begin() + 1, _models.end());
}

void IS::TexturedModel::prevFrame()
{
    std::rotate(_models.rbegin(), _models.rbegin() + 1, _models.rend());
}

void IS::TexturedModel::clean()
{
    for (auto &model : _models)
        UnloadModel(model);
    UnloadTexture(_texture);
}

Model IS::TexturedModel::getModel() const
{
    return (_models[0]);
}

Texture2D IS::TexturedModel::getTexture() const
{
    return (_texture);
}

void IS::TexturedModel::setModel(Model model)
{
    _models[0] = model;
}

void IS::TexturedModel::setTransform(Matrix matrix)
{
    for (Model &_model : _models) {
        _model.transform = matrix;
    }
}

bool IS::TexturedModel::hasShader()
{
    if (_models[0].materials[0].shader.id == 3)
        return (false);
    return (true);
}

void IS::TexturedModel::setShader(Shader shader)
{
    for (Model &_model : _models) {
        for (int i = 0; i < _model.materialCount; i++)
            _model.materials[i].shader = shader;
    }
}

void IS::TexturedModel::setColor(Color color, int materialNumber)
{
    for (Model &_model : _models) {
        for (int i = 0; i < _model.materialCount; i++)
            if (i == materialNumber)
                _model.materials[i].maps[MATERIAL_MAP_ALBEDO].color = color;
    }
}
