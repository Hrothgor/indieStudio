/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** ParticlesRenderer
*/

#include "ParticlesRenderer.hpp"

IS::ParticlesRenderer::ParticlesRenderer()
{
}

IS::ParticlesRenderer::~ParticlesRenderer()
{
}

void IS::ParticlesRenderer::update(int scene, Camera3D camera)
{
    std::map<int, Particle>::iterator iter;
    for (iter = _particles.begin(); iter != _particles.end(); ) {
        if (!iter->second.update())
            iter = _particles.erase(iter);
        else
            ++iter;
    }
    for (iter = _particles.begin(); iter != _particles.end(); iter++) {
        auto nodeHandler = _particles.extract(iter->first);
        nodeHandler.key() = iter->second.distanceToCamera(camera);
        _particles.insert(std::move(nodeHandler));
    }
}

void IS::ParticlesRenderer::render(int scene, IS::Camera camera)
{
    Matrix viewMatrix = GetCameraMatrix(camera.getCamera3D());

    update(scene, camera.getCamera3D());
    for (auto &particle : _particles) {
        updateModelViewMatrix(particle.second, viewMatrix);
        _particlesShader.loadData(
            particle.second.getTexOffset1(),
            particle.second.getTexOffset2(),
            particle.second.getTexturedModel().getNumberOfRows(),
            particle.second.getBlendFactor()
        );
        DrawModel(particle.second.getTexturedModel().getModel(), particle.second.getPosition(), particle.second.getScale(), WHITE);
    }
}

void IS::ParticlesRenderer::updateModelViewMatrix(Particle &particle, Matrix viewMatrix)
{
    if (!particle.getTexturedModel().hasShader())
        particle.getTexturedModel().setShader(_particlesShader.getShader());
    Matrix matrix = particle.getTexturedModel().getModel().transform;

    matrix.m0 = viewMatrix.m0;
    matrix.m1 = viewMatrix.m4;
    matrix.m2 = viewMatrix.m8;
    matrix.m4 = viewMatrix.m1;
    matrix.m5 = viewMatrix.m5;
    matrix.m6 = viewMatrix.m9;
    matrix.m8 = viewMatrix.m2;
    matrix.m9 = viewMatrix.m6;
    matrix.m10 = viewMatrix.m10;
    particle.setModelTransform(matrix);
}

void IS::ParticlesRenderer::addParticles(const Particle &particle)
{
    _particles.insert(std::make_pair(0, particle));
}