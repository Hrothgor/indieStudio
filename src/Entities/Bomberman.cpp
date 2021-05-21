/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Bomberman
*/

#include "Bomberman.hpp"

IS::Bomberman::Bomberman(Entity entity, ParticleSystem smokeFeet)
    : Entity(entity)
{
    _IsAI = true;
    _smokeFeet = smokeFeet;
    _velocity.z = 0.2;
}

IS::Bomberman::Bomberman(Entity entity, ParticleSystem smokeFeet, keyPlayer_t keys)
    : Entity(entity)
{
    _IsAI = false;
    _smokeFeet = smokeFeet;
    _keys = keys;
}

IS::Bomberman::~Bomberman()
{
}

void IS::Bomberman::checkKeyPressed()
{
    if (IsKeyDown(_keys.up))
        _velocity.z = -0.3;
    if (IsKeyDown(_keys.down))
        _velocity.z = 0.3;
    if (IsKeyDown(_keys.left))
        _velocity.x = -0.3;
    if (IsKeyDown(_keys.right))
        _velocity.x = 0.3;
    float x = floor((_position.x + 4) / 10) * 10;
    float y = floor((_position.z + 4) / 10) * 10;
    if (IsKeyPressed(_keys.bomb))
        GLOBAL::_entities.push_back(new Bomb(Entity(*GLOBAL::_texturedModels["bomb"], {x, 0, y}, { 0, 0, 0 }, 2), *GLOBAL::_particleSystem["fireBomb"], *GLOBAL::_particleSystem["explosionBomb"], getColor(0), getColor(1)));
}

void IS::Bomberman::changeModelRotation()
{
    if (_velocity.z > 0 && _velocity.x > 0) {
        setRotation({0,315,0});
        if (_animationClock.getElapsedTime() > 0.05) {
            _animationClock.reset();
            nextFrame();
        }
    } else if (_velocity.z > 0 && _velocity.x < 0) {
        setRotation({0,45,0});
        if (_animationClock.getElapsedTime() > 0.05) {
            _animationClock.reset();
            nextFrame();
        }
    } else if (_velocity.z < 0 && _velocity.x > 0) {
        setRotation({0,225,0});
        if (_animationClock.getElapsedTime() > 0.05) {
            _animationClock.reset();
            nextFrame();
        }
    } else if (_velocity.z < 0 && _velocity.x > 0) {
        setRotation({0,135,0});
        if (_animationClock.getElapsedTime() > 0.05) {
            _animationClock.reset();
            nextFrame();
        }
    } else if (_velocity.z > 0) {
        setRotation({0,0,0});
        if (_animationClock.getElapsedTime() > 0.05) {
            _animationClock.reset();
            nextFrame();
        }
    } else if (_velocity.z < 0) {
        setRotation({0,180,0});
        if (_animationClock.getElapsedTime() > 0.05) {
            _animationClock.reset();
            nextFrame();
        }
    } else if (_velocity.x > 0) {
        setRotation({0,270,0});
        if (_animationClock.getElapsedTime() > 0.05) {
            _animationClock.reset();
            nextFrame();
        }
    } else if (_velocity.x < 0) {
        setRotation({0,90,0});
        if (_animationClock.getElapsedTime() > 0.05) {
            _animationClock.reset();
            nextFrame();
        }
    }
}

void IS::Bomberman::checkCollisionMap(Map &map)
{
    bool moved = false;
    int nextx1 = (_position.x + _velocity.x) / 10;
    int nexty1 = (_position.z) / 10;
    int nextx2 = (_position.x + _velocity.x + 8) / 10;
    int nexty2 = (_position.z + 8) / 10;

    if (map.IsEmpty(nextx1, nexty1) &&
        map.IsEmpty(nextx2, nexty1) &&
        map.IsEmpty(nextx1, nexty2) &&
        map.IsEmpty(nextx2, nexty2) &&
        _velocity.x != 0) {
        increasePosition({_velocity.x, 0, 0});
        moved = true;
    }
    nextx1 = (_position.x) / 10;
    nexty1 = (_position.z + _velocity.z) / 10;
    nextx2 = (_position.x + 8) / 10;
    nexty2 = (_position.z + _velocity.z + 8) / 10;
    if (map.IsEmpty(nextx1, nexty1) &&
        map.IsEmpty(nextx2, nexty1) &&
        map.IsEmpty(nextx1, nexty2) &&
        map.IsEmpty(nextx2, nexty2) &&
        _velocity.z != 0) {
        increasePosition({0, 0, _velocity.z});
        moved = true;
    }
    if (moved && Vector3Length(_velocity) != 0)
        _smokeFeet.generateParticles({_position.x, _position.y, _position.z});
    else if (_IsAI) {
        int dir = rand() % 4;
        switch (dir)
        {
        case 0:
            setVelocity({0.2, 0, 0});
            break;
        case 1:
            setVelocity({-0.2, 0, 0});
            break;
        case 2:
            setVelocity({0, 0, 0.2});
            break;
        case 3:
            setVelocity({0, 0, -0.2});
            break;
        }
    }
}

bool IS::Bomberman::update(Camera3D camera, Map &map)
{
    IS::Entity::update(camera, map);

    if (!_IsAI)
        checkKeyPressed();
    changeModelRotation();
    checkCollisionMap(map);
    if (!_IsAI)
        _velocity = { 0 };
    return (true);
}