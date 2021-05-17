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

float angle = 0;

void IS::EntityRenderer::prepare(Camera camera)
{
    for (Light &light : _lights) {
        light.position.z = std::cos(angle) * 75;
        light.position.y = std::sin(angle) * 75;
        angle += 0.01;
        UpdateLightValues(_lightShader.getShader(), light);
        DrawSphere(light.position, 4, YELLOW);
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
    if (!entity.getTexturedModel().hasShader())
        entity.getTexturedModel().setShader(_lightShader.getShader());
    entity.update();
}

void IS::EntityRenderer::addLight(int scene, const LightValue &light)
{
    _lights.push_back(CreateLight(LIGHT_POINT, light.getPosition(), Vector3Zero(), light.getColor(), _lightShader.getShader()));
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