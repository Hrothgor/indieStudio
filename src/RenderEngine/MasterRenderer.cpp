/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** MasterRenderer
*/

#include "MasterRenderer.hpp"

IS::MasterRenderer::MasterRenderer()
{
}

IS::MasterRenderer::~MasterRenderer()
{
}

void IS::MasterRenderer::start(IS::Camera camera)
{
    ClearBackground(RAYWHITE);
    BeginMode3D(camera.getCamera3D());
}

void IS::MasterRenderer::stop()
{
    DrawGrid(100, 1.0f);
    EndMode3D();
}

void IS::MasterRenderer::render(int scene, IS::Camera camera)
{
    start(camera);
    _entityRenderer.render(scene, camera);
    _particlesRenderer.render(scene, camera);
    stop();
}

void IS::MasterRenderer::addLight(const LightValue &light)
{
    _entityRenderer.addLight(0, light);
}

void IS::MasterRenderer::addEntity(int scene, const Entity &entity)
{
    _entityRenderer.addEntity(scene, entity);
}

void IS::MasterRenderer::addParticles(int scene, const Particles &particles)
{
    _particlesRenderer.addParticles(scene, particles);
}
