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
    _monitorType = AI;
    _smokeFeet = smokeFeet;
    _velocity.z = 0.2;
}

IS::Bomberman::Bomberman(Entity entity, ParticleSystem smokeFeet, keyPlayer_t keys)
    : Entity(entity)
{
    _monitorType = KEYBOARD;
    _smokeFeet = smokeFeet;
    _keys = keys;
}

IS::Bomberman::Bomberman(Entity entity, ParticleSystem smokeFeet, int gamePadID)
    : Entity(entity)
{
    _monitorType = CONTROLLER;
    _smokeFeet = smokeFeet;
    _gamePadID = gamePadID;
}

IS::Bomberman::~Bomberman()
{
}

void IS::Bomberman::powerUpFire()
{
    _blastRadius += 1;
}

void IS::Bomberman::powerUpBomb()
{
    _nbBomb += 1;
}

void IS::Bomberman::powerUpSpeed()
{
    _speed += 0.1;
}

void IS::Bomberman::bombExplode()
{
    _nbBomb += 1;
}

int IS::Bomberman::getBlastRadius() const
{
    return (_blastRadius);
}

void IS::Bomberman::setDeathAnimation(bool state)
{
    _dying = state;
}

void IS::Bomberman::checkKeyPressed()
{
    if (_monitorType == KEYBOARD) {
        if (IsKeyDown(_keys.up))
            _velocity.z = -_speed;
        if (IsKeyDown(_keys.down))
            _velocity.z = _speed;
        if (IsKeyDown(_keys.left))
            _velocity.x = -_speed;
        if (IsKeyDown(_keys.right))
            _velocity.x = _speed;
        if (IsKeyPressed(_keys.bomb) && _nbBomb > 0) {
            float x = floor((_position.x + 4) / 10) * 10;
            float y = floor((_position.z + 4) / 10) * 10;
            _nbBomb -= 1;
            GLOBAL::_entities.push_back(new Bomb(Entity(*GLOBAL::_texturedModels["bomb"], {x, 0, y}, { 0, 0, 0 }, 2), this,  *GLOBAL::_particleSystem["fireBomb"], *GLOBAL::_particleSystem["explosionBomb"]));
            GLOBAL::_map->addElement(IS::MAP_TILES::BOMB, x / 10, y / 10);
        }
    } else if (_monitorType == CONTROLLER) {
        if (IsGamepadAvailable(_gamePadID)) {
            if (GetGamepadAxisMovement(_gamePadID, GAMEPAD_AXIS_LEFT_Y) > 0)
                _velocity.z = -_speed;
            if (GetGamepadAxisMovement(_gamePadID, GAMEPAD_AXIS_LEFT_Y) < 0)
                _velocity.z = _speed;
            if (GetGamepadAxisMovement(_gamePadID, GAMEPAD_AXIS_LEFT_X) < 0)
                _velocity.x = -_speed;
            if (GetGamepadAxisMovement(_gamePadID, GAMEPAD_AXIS_LEFT_X) > 0)
                _velocity.x = _speed;
            if (IsGamepadButtonDown(_gamePadID, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) {
                float x = floor((_position.x + 4) / 10) * 10;
                float y = floor((_position.z + 4) / 10) * 10;
                _nbBomb -= 1;
                GLOBAL::_entities.push_back(new Bomb(Entity(*GLOBAL::_texturedModels["bomb"], {x, 0, y}, { 0, 0, 0 }, 2), this,  *GLOBAL::_particleSystem["fireBomb"], *GLOBAL::_particleSystem["explosionBomb"]));
                GLOBAL::_map->addElement(IS::MAP_TILES::BOMB, x / 10, y / 10);
            }
        }
    } else if (_monitorType == AI) {

    }
}

void IS::Bomberman::changeModelRotation()
{
    if (_velocity.z > 0 && _velocity.x > 0) {
        setRotation({0,315,0});
        if ((_animationLenght -= GetFrameTime()) < 0) {
            _animationLenght = 0.05;
            nextFrame();
        }
    } else if (_velocity.z > 0 && _velocity.x < 0) {
        setRotation({0,45,0});
        if ((_animationLenght -= GetFrameTime()) < 0) {
            _animationLenght = 0.05;
            nextFrame();
        }
    } else if (_velocity.z < 0 && _velocity.x > 0) {
        setRotation({0,225,0});
        if ((_animationLenght -= GetFrameTime()) < 0) {
            _animationLenght = 0.05;
            nextFrame();
        }
    } else if (_velocity.z < 0 && _velocity.x < 0) {
        setRotation({0,135,0});
        if ((_animationLenght -= GetFrameTime()) < 0) {
            _animationLenght = 0.05;
            nextFrame();
        }
    } else if (_velocity.z > 0) {
        setRotation({0,0,0});
        if ((_animationLenght -= GetFrameTime()) < 0) {
            _animationLenght = 0.05;
            nextFrame();
        }
    } else if (_velocity.z < 0) {
        setRotation({0,180,0});
        if ((_animationLenght -= GetFrameTime()) < 0) {
            _animationLenght = 0.05;
            nextFrame();
        }
    } else if (_velocity.x > 0) {
        setRotation({0,270,0});
        if ((_animationLenght -= GetFrameTime()) < 0) {
            _animationLenght = 0.05;
            nextFrame();
        }
    } else if (_velocity.x < 0) {
        setRotation({0,90,0});
        if ((_animationLenght -= GetFrameTime()) < 0) {
            _animationLenght = 0.05;
            nextFrame();
        }
    }
}

void IS::Bomberman::checkCollisionMap()
{
    bool moved = false;
    int x = _position.x / 10;
    int y = _position.z / 10;
    int xsize = (_position.x + 8) / 10;
    int ysize = (_position.z + 8) / 10;
    int nextx1 = (_position.x + _velocity.x) / 10;
    int nexty1 = (_position.z + _velocity.z) / 10;
    int nextx2 = (_position.x + _velocity.x + 8) / 10;
    int nexty2 = (_position.z + _velocity.z + 8) / 10;

    ///// MOVE ON X
    if (_velocity.x < 0) {
        if (nextx1 != x) {
            if (GLOBAL::_map->IsEmpty(nextx1, y) &&
                GLOBAL::_map->IsEmpty(nextx1, ysize)) {
                increasePosition({_velocity.x, 0, 0});
                moved = true;
            }
        } else {
            increasePosition({_velocity.x, 0, 0});
            moved = true;
        }
    } else if (_velocity.x > 0) {
        if (nextx2 != xsize) {
            if (GLOBAL::_map->IsEmpty(nextx2, y) &&
                GLOBAL::_map->IsEmpty(nextx2, ysize)) {
                increasePosition({_velocity.x, 0, 0});
                moved = true;
            }
        } else {
            increasePosition({_velocity.x, 0, 0});
            moved = true;
        }
    }
    ///// MOVE ON Y
    if (_velocity.z < 0) {
        if (nexty1 != y) {
            if (GLOBAL::_map->IsEmpty(x, nexty1) &&
                GLOBAL::_map->IsEmpty(xsize, nexty1)) {
                increasePosition({0, 0, _velocity.z});
                moved = true;
            }
        } else {
            increasePosition({0, 0, _velocity.z});
            moved = true;
        }
    } else if (_velocity.z > 0) {
        if (nexty2 != ysize) {
            if (GLOBAL::_map->IsEmpty(x, nexty2) &&
                GLOBAL::_map->IsEmpty(xsize, nexty2)) {
                increasePosition({0, 0, _velocity.z});
                moved = true;
            }
        } else {
            increasePosition({0, 0, _velocity.z});
            moved = true;
        }
    }
    /////
    if (moved && Vector3Length(_velocity) != 0)
        _smokeFeet.generateParticles({_position.x, _position.y, _position.z});
    else if (_monitorType == AI) {
        int dir = rand() % 4;
        switch (dir)
        {
        case 0:
            setVelocity({_speed, 0, 0});
            break;
        case 1:
            setVelocity({-_speed, 0, 0});
            break;
        case 2:
            setVelocity({0, 0, _speed});
            break;
        case 3:
            setVelocity({0, 0, -_speed});
            break;
        }
    }
}

void IS::Bomberman::checkCollisionPowerUp()
{
    Rectangle rectPlayer = {_position.x, _position.z, 8, 8};

    for (PowerUp *powerUp : GLOBAL::_powerups) {
        if (powerUp->IsAlive() == false)
            continue;
        Rectangle rectPowerUp = {powerUp->getPosition().x + 2, powerUp->getPosition().z + 2, 6, 6};
        if (CheckCollisionRecs(rectPlayer, rectPowerUp)) {
            POWER_TYPE type = powerUp->getType();
            switch (type)
            {
            case POWER_TYPE::FIRE:
                powerUpFire();
                break;
            case POWER_TYPE::MOREBOMB:
                powerUpBomb();
                break;
            case POWER_TYPE::SPEED:
                powerUpSpeed();
                break;
            default:
                break;
            }
            powerUp->setAlive(false);
        }
    }
}

bool IS::Bomberman::update(Camera *camera)
{
    if (_dying == true) {
        setColor(RED, 0);
        setColor(RED, 1);
        if ((_deathAnimation -= GetFrameTime()) < 0) {
            _alive = false;
            return (false);
        }
        increaseRotation({0, 0, 1});
    } else {
        if (_monitorType != AI)
            checkKeyPressed();
        changeModelRotation();
        checkCollisionMap();
        checkCollisionPowerUp();
        if (_velocity.x == 0 && _velocity.y == 0 && _velocity.z == 0)
            resetFrame();
        if (_monitorType != AI)
            _velocity = { 0 };
        return (true);
    }
    return (true);
}