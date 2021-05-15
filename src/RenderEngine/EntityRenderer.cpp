/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** EntityRenderer
*/

#include "EntityRenderer.hpp"

#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"

IS::EntityRenderer::EntityRenderer()
{
}

IS::EntityRenderer::~EntityRenderer()
{
}

void IS::EntityRenderer::prepare(Camera camera)
{
    for (auto &light : _lights) {
        UpdateLightValues(_lightShader.getShader(), light);
        UpdateLightValues(_lightShaderColor.getShader(), light);
        DrawSphere(light.position, 2, light.color);
    }
}

void IS::EntityRenderer::render(int scene, IS::Camera camera)
{
    prepare(camera);
    for (auto &list : _entities) {
        if (list.first != scene)
            continue;
        for (Entity &entity : list.second) {
            prepareEntity(entity);
            DrawModel(entity.getTexturedModel().getModel(), entity.getPosition(), entity.getScale(), WHITE);
        }
    }
}

void IS::EntityRenderer::prepareEntity(Entity &entity)
{
    if (!entity.getTexturedModel().hasShader()) {
        if (entity.getTexturedModel().getTexture().id == 0) {
            entity.getTexturedModel().getModel().materials[0].shader = _lightShaderColor.getShader();
            entity.getTexturedModel().getModel().materials[1].shader = _lightShaderColor.getShader();
        }
        else {
            entity.getTexturedModel().setShader(_lightShader.getShader());
        }
    }
}

void IS::EntityRenderer::addLight(int scene, const LightValue &light)
{
    _lights.push_back(CreateLight(LIGHT_POINT, light.getPosition(), Vector3Zero(), light.getColor(), _lightShader.getShader()));
    CreateLight(LIGHT_POINT, light.getPosition(), Vector3Zero(), light.getColor(), _lightShaderColor.getShader());
}

void IS::EntityRenderer::addEntity(int scene, const Entity &entity)
{
    for (auto &list : _entities) {
        if (list.first == scene) {
            list.second.push_back(entity);
            return;
        }
    }
    _entities[scene] = std::vector<Entity> { entity };
}