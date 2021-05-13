/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Particles
*/

#include "Particles.hpp"

IS::Particles::Particles(Vector3 position, Vector3 velocity, float gravityEffect, float lifeLenght, float rotation, float scale)
{
    _position = position;
    _velocity = velocity;
    _gravityEffect = gravityEffect;
    _lifeLenght = lifeLenght;
    _rotation = rotation;
    _scale = scale;
}

IS::Particles::~Particles()
{
}

Vector3 IS::Particles::getPosition() const
{
    return (_position);
}

Vector3 IS::Particles::getVelocity() const
{
    return (_velocity);
}

float IS::Particles::getGravityEffect() const
{
    return (_gravityEffect);
}

float IS::Particles::getLifeLenght() const
{
    return (_lifeLenght);
}

float IS::Particles::getRotation() const
{
    return (_rotation);
}

float IS::Particles::getScale() const
{
    return (_scale);
}

bool IS::Particles::update()
{
    _velocity.y += GRAVITY * _gravityEffect * GetFrameTime();
    _position.x += _velocity.x * GetFrameTime();
    _position.x += _velocity.y * GetFrameTime();
    _position.x += _velocity.z * GetFrameTime();
    _elapsedTime += GetFrameTime();
    return _elapsedTime < _lifeLenght;
}