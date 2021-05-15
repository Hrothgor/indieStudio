/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** LightShader
*/

#include "LightShader.hpp"

IS::LightShader::LightShader()
{
    _shader.id = -1;
}

IS::LightShader::~LightShader()
{
    if (_shader.id != -1)
        UnloadShader(_shader);
}

void IS::LightShader::initShader()
{
    _shader = LoadShader("ressources/Shaders/light.vs",
                        "ressources/Shaders/light.fs");
    _shader.locs[SHADER_LOC_MATRIX_MODEL] = GetShaderLocation(_shader, "matModel");
    _shader.locs[SHADER_LOC_MATRIX_VIEW] = GetShaderLocation(_shader, "matView");
    _shader.locs[SHADER_LOC_MATRIX_PROJECTION] = GetShaderLocation(_shader, "matProjection");
}

Shader IS::LightShader::getShader()
{
    if (_shader.id == -1)
        initShader();
    return (_shader);
}