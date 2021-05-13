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
}

void IS::LightShader::initShader()
{
    _shader = LoadShader(TextFormat("ressources/Shaders/light.vs", GLSL_VERSION),
                        TextFormat("ressources/Shaders/light.fs", GLSL_VERSION));
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