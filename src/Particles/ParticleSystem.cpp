/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** ParticleSystem
*/

#include "ParticleSystem.hpp"

IS::ParticleSystem::ParticleSystem(float pps, float speed, float gravityComplient, float lifeLength, float scale, const std::string &texturePath, MasterRenderer *renderer, PARTICLE_EMISSION emissionType)
    : _particleTexturedModel(GenMeshCube(0.5, 0.5, 0.5), texturePath, 1)
{
    _pps = pps;
    _speed = speed;
    _gravityComplient = gravityComplient;
    _lifeLength = lifeLength;
    _scale = scale;
    _renderer = renderer;
    _emissionType = emissionType;
}

IS::ParticleSystem::ParticleSystem(float pps, float speed, float gravityComplient, float lifeLength, float scale, ParticleTexturedModel &particleTexturedModel, MasterRenderer *renderer, PARTICLE_EMISSION emissionType)
{
    _pps = pps;
    _speed = speed;
    _gravityComplient = gravityComplient;
    _lifeLength = lifeLength;
    _scale = scale;
    _renderer = renderer;
    _emissionType = emissionType;
    _particleTexturedModel = particleTexturedModel;
}

IS::ParticleSystem::~ParticleSystem()
{
}

void IS::ParticleSystem::generateParticles(Vector3 position)
{
    float delta = GetFrameTime();
    _particlesToCreate += _pps * delta;
    if (_particlesToCreate < 1)
        return;
    int count = floor(_particlesToCreate);
    _particlesToCreate -= count;
    for (int i = 0; i < count ; i++)
        emitParticle(position);
}

void IS::ParticleSystem::emitParticle(Vector3 center)
{
    switch (_emissionType) {
        case PARABOLIC:
            emitParticleParabolic(center);
            break;
        case DIRECTIONAL:
            emitParticleDirectional(center, {-1, 0, 0});
            break;
        case CIRCLE:
            emitParticleCircle(center);
            break;
        default:
            break;
    }
}

void IS::ParticleSystem::emitParticleParabolic(Vector3 center)
{
    float dirX = Maths::randFloat() * 1 - 0.5;
    float dirZ = Maths::randFloat() * 1 - 0.5;
    Vector3 velocity = { dirX, 1, dirZ };
    velocity = Vector3Normalize(velocity);
    velocity = Vector3Scale(velocity, _speed);
    _renderer->addParticles(Particle(center, velocity, _gravityComplient, _lifeLength, 0, _scale, _particleTexturedModel));
}

void IS::ParticleSystem::emitParticleDirectional(Vector3 center, Vector3 direction)
{
    float dirX = Maths::randFloat() * 0.2 + 0.1;
    float dirY = Maths::randFloat() * 0.2 + 0.1;
    float dirZ = Maths::randFloat() * 0.2 + 0.1;
    Vector3 velocity = { direction.x + dirX, direction.y + dirY, direction.z + dirZ };
    velocity = Vector3Normalize(velocity);
    velocity = Vector3Scale(velocity, _speed);
    _renderer->addParticles(Particle(center, velocity, _gravityComplient, _lifeLength, 0, _scale, _particleTexturedModel));
}

void IS::ParticleSystem::emitParticleCircle(Vector3 center)
{
    float dirX = Maths::randFloat() * 1 - 0.5;
    float dirY = Maths::randFloat() * 1 - 0.5;
    float dirZ = Maths::randFloat() * 1 - 0.5;
    Vector3 velocity = { dirX, dirY, dirZ };
    velocity = Vector3Normalize(velocity);
    velocity = Vector3Scale(velocity, _speed);
    _renderer->addParticles(Particle(center, velocity, _gravityComplient, _lifeLength, 0, _scale, _particleTexturedModel));
}
