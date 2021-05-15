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
    ClearBackground(DARKBLUE);
    BeginMode3D(camera.getCamera3D());
}

void IS::MasterRenderer::stop()
{
    EndMode3D();
}

void IS::MasterRenderer::render(int scene, IS::Camera camera)
{
    start(camera);
    _entityRenderer.render(scene, camera);
    DrawGrid(100, 1.0f);
    rlDisableDepthMask();
    //BeginBlendMode(BLEND_ADDITIVE);
    _particlesRenderer.render(scene, camera);
    //EndBlendMode();
    rlEnableDepthMask();
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

void IS::MasterRenderer::addParticles(const Particle &particles)
{
    _particlesRenderer.addParticles(particles);
}
