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

bool IS::Bomb::update(Camera3D camera, Map map)
{
    IS::Entity::update(camera, map);
    Vector2 bombScreenPosition = GetWorldToScreen({_position.x, _position.y + 14, _position.z}, camera);
    int flooredLife = _life.getElapsedTime();
    std::string lifeTime("Bomb: " + std::to_string(_lifeLenght - flooredLife));
    float distanceToCam = std::fabs(Vector3Distance(_position, camera.position) / 20) + 1;
    int sizeFont = 100 * (1/distanceToCam);
    EndMode3D();
    DrawText(lifeTime.c_str(), bombScreenPosition.x - MeasureText(lifeTime.c_str(), sizeFont)/2, bombScreenPosition.y, sizeFont, GREEN);
    BeginMode3D(camera);

    _smokeBomb.generateParticles({_position.x, _position.y + 8, _position.z});
    if (_life.getElapsedTime() > _lifeLenght) {
        _explosionBomb.generateParticles({_position.x, _position.y + 4, _position.z});
        _alive = false;
        return (false);
    }
    return (true);
}