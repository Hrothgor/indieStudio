/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** SkyboxShader
*/

#include "SkyboxShader.hpp"

IS::SkyboxShader::SkyboxShader()
{
    _shader.id = -1;
}

IS::SkyboxShader::~SkyboxShader()
{
}

void IS::SkyboxShader::initShader()
{
    _shader = LoadShader(ASSETS_PATH"ressources/Shaders/skybox.vs",
                        ASSETS_PATH"ressources/Shaders/skybox.fs");
    int value = MATERIAL_MAP_CUBEMAP;
    SetShaderValue(_shader, GetShaderLocation(_shader, "environmentMap"), &value, SHADER_UNIFORM_INT);
}

Shader IS::SkyboxShader::getShader()
{
    if (_shader.id == -1)
        initShader();
    return (_shader);
}

void IS::SkyboxShader::clean()
{
    if (_shader.id == -1)
        UnloadShader(_shader);
}