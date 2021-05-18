/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Bomberman
*/

#include "Bomberman.hpp"

IS::Bomberman::Bomberman(Entity entity, ParticleSystem &smokeFeet)
    : Entity(entity)
{
    _smokeFeet = smokeFeet;
    _velocity.z = Maths::randFloat() * 0.4;
}

IS::Bomberman::~Bomberman()
{
}

bool IS::Bomberman::update()
{
    //if (Vector3ToFloat(_velocity) != 0) {
        if (_position.z > 50) {
            _velocity.z *= -1;
            increaseRotation({0,180,0});
        }
        if (_position.z < -50) {
            _velocity.z *= -1;
            increaseRotation({0,180,0});
        }
        increasePosition({0, 0, _velocity.z});
        nextFrame();
        _smokeFeet.generateParticles({_position.x, _position.y, _position.z});
    //}
    //_velocity = { 0 };
    return (true);
}