/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-cyril.grosjean
** File description:
** PowerUp
*/

#include "PowerUp.hpp"

IS::PowerUp::PowerUp(Entity entity, POWER_TYPE type, ParticleSystem shiny)
    : Entity(entity)
{
    _shiny = shiny;
    _type = type;
}

IS::PowerUp::~PowerUp()
{
}

IS::POWER_TYPE IS::PowerUp::getType() const
{
    return (_type);
}

bool IS::PowerUp::update(Camera *camera)
{
    setColor(WHITE, 0);
    _angle += 3;
    if (_angle > 360)
        _angle = 0;
    increaseRotation({0, 1, 0});
    increasePosition({0, std::cos(_angle * DEG2RAD) / 25, 0});
    _shiny.generateParticles({_position.x, _position.y + 6, _position.z});
    return (true);
}