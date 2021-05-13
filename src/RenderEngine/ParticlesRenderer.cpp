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

void IS::ParticlesRenderer::render(int scene, IS::Camera camera)
{

}

void IS::ParticlesRenderer::prepareParticles(Particles &particles)
{

}

void IS::ParticlesRenderer::addParticles(int scene, const Particles &particle)
{
    for (auto &list : _particles) {
        if (list.first == scene) {
            list.second.push_back(particle);
            return;
        }
    }
    _particles[scene] = std::vector<Particles> { particle };
}