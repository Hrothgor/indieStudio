/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Bomb
*/

#include "Bomb.hpp"

IS::Bomb::Bomb(Entity entity, ParticleSystem smokeBomb, ParticleSystem explosionBomb)
    : Entity(entity)
{
    _smokeBomb = smokeBomb;
    _explosionBomb = explosionBomb;
}

IS::Bomb::~Bomb()
{
}

bool IS::Bomb::update(Camera3D camera)
{
    Vector2 bombScreenPosition = GetWorldToScreen((Vector3){_position.x, _position.y + 14, _position.z}, camera);
    int flooredLife = _life.getElapsedTime();
    std::string lifeTime("Bomb: " + std::to_string(10 - flooredLife));
    float distanceToCam = std::fabs(Vector3Distance(_position, camera.position) / 20) + 1;
    int sizeFont = 100 * (1/distanceToCam);
    DrawText(lifeTime.c_str(), bombScreenPosition.x - MeasureText(lifeTime.c_str(), sizeFont)/2, bombScreenPosition.y, sizeFont, GREEN);

    _smokeBomb.generateParticles({_position.x, _position.y + 8, _position.z});
    if (_life.getElapsedTime() > 10) {
        _explosionBomb.generateParticles({_position.x, _position.y + 4, _position.z});
        return (false);
    }
    return (true);
}