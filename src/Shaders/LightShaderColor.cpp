/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** LightShaderColor
*/

#include "LightShaderColor.hpp"

IS::LightShaderColor::LightShaderColor()
{
    _shader.id = -1;
}

IS::LightShaderColor::~LightShaderColor()
{
    if (_shader.id != -1)
        UnloadShader(_shader);
}

void IS::LightShaderColor::initShader()
{
    _shader = LoadShader("ressources/Shaders/lightColor.vs",
                        "ressources/Shaders/lightColor.fs");
    _shader.locs[SHADER_LOC_MATRIX_MODEL] = GetShaderLocation(_shader, "matModel");
    _shader.locs[SHADER_LOC_MATRIX_VIEW] = GetShaderLocation(_shader, "matView");
    _shader.locs[SHADER_LOC_MATRIX_PROJECTION] = GetShaderLocation(_shader, "matProjection");
}

Shader IS::LightShaderColor::getShader()
{
    if (_shader.id == -1)
        initShader();
    return (_shader);
}