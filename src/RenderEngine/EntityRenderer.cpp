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

void IS::EntityRenderer::prepare(int scene, Camera camera)
{
    for (Light &light : _lights) {
        light.position.z = std::cos(angle) * 500;
        light.position.y = std::sin(angle) * 500;
        angle += 0.003;
        UpdateLightValues(_lightShader.getShader(), light);
        DrawSphere(light.position, 4, YELLOW);
    }
    for (auto &list : _entities) {
        if (list.first != scene)
            continue;
        for (auto it = list.second.begin(); it != list.second.end(); it++)
            if (!(*it)->update())
                list.second.erase(it--);
    }
}

void IS::EntityRenderer::render(int scene, IS::Camera camera)
{
    prepare(scene, camera);
    for (auto &list : _entities) {
        if (list.first != scene)
            continue;
        for (Entity *entity : list.second) {
            prepareEntity(entity);
            DrawModel(entity->getTexturedModel().getModel(), entity->getPosition(), entity->getScale(), WHITE);
        }
    }
}

void IS::EntityRenderer::prepareEntity(Entity *entity)
{
    if (!entity->getTexturedModel().hasShader())
        entity->getTexturedModel().setShader(_lightShader.getShader());
    entity->IS::Entity::update();
}

void IS::EntityRenderer::addLight(int scene, const LightValue &light)
{
    _lights.push_back(CreateLight(LIGHT_POINT, light.getPosition(), Vector3Zero(), light.getColor(), _lightShader.getShader()));
}

void IS::EntityRenderer::addEntity(int scene, Entity *entity)
{
    for (auto &list : _entities) {
        if (list.first == scene) {
            list.second.push_back(entity);
            return;
        }
    }
    _entities[scene] = std::vector<Entity *> { entity };
}