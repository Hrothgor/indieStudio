/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Bomb
*/

#include "Bomb.hpp"

IS::Bomb::Bomb(Entity entity, ParticleSystem &smokeBomb, ParticleSystem &explosionBomb)
    : Entity(entity)
{
    _smokeBomb = smokeBomb;
    _explosionBomb = explosionBomb;
}

IS::Bomb::~Bomb()
{
}

bool IS::Bomb::update()
{
    _smokeBomb.generateParticles({_position.x, _position.y + 8, _position.z});
    if (IsKeyPressed(KEY_SPACE)) {
        _explosionBomb.generateParticles({_position.x, _position.y + 4, _position.z});
        return (false);
    }
    return (true);
}