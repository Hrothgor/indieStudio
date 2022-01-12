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
    _maxBomb += 1;
}

void IS::Bomberman::powerUpSpeed()
{
    _speed += 0.075;
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

void IS::Bomberman::setKey(keyPlayer_t keys, int gamePadID, bool ai)
{
    if (ai) {
        _keys = {};
        _monitorType = AI;
    } else if (gamePadID == -1) {
        _keys = keys;
        _monitorType = KEYBOARD;
    } else {
        _keys = {};
        _monitorType = CONTROLLER;
        _gamePadID = gamePadID;
    }
}

void IS::Bomberman::changeMonitorType()
{
    if (_monitorType == AI)
        _monitorType = KEYBOARD;
    else if (_monitorType == KEYBOARD)
        _monitorType = CONTROLLER;
    else if (_monitorType == CONTROLLER)
        _monitorType = AI;
}

void IS::Bomberman::checkKeyPressed()
{
    ///// check KEY /////
    if (_monitorType == KEYBOARD) {
        if (IsKeyDown(_keys.up))
            _actions.moveUp = true;
        if (IsKeyDown(_keys.down))
            _actions.moveDown = true;
        if (IsKeyDown(_keys.left))
            _actions.moveLeft = true;
        if (IsKeyDown(_keys.right))
            _actions.moveRight = true;
        if (IsKeyPressed(_keys.bomb))
            _actions.dropBomb = true;
    } else if (_monitorType == CONTROLLER) {
        if (IsGamepadAvailable(_gamePadID)) {
            if (GetGamepadAxisMovement(_gamePadID, GAMEPAD_AXIS_LEFT_Y) < 0)
                _actions.moveUp = true;
            if (GetGamepadAxisMovement(_gamePadID, GAMEPAD_AXIS_LEFT_Y) > 0)
                _actions.moveDown = true;
            if (GetGamepadAxisMovement(_gamePadID, GAMEPAD_AXIS_LEFT_X) < 0)
                _actions.moveLeft = true;
            if (GetGamepadAxisMovement(_gamePadID, GAMEPAD_AXIS_LEFT_X) > 0)
                _actions.moveRight = true;
            if (IsGamepadButtonPressed(_gamePadID, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT))
                _actions.dropBomb = true;
        }
    } else if (_monitorType == AI) {
        _actions = IS::AIPath::getAIMove(this, _maxBomb, _nbBomb);
        _velocity = { 0 };
    }
    ///// DO ACTION /////
    if (_actions.moveUp)
        _velocity.z = -_speed;
    if (_actions.moveDown)
        _velocity.z = _speed;
    if (_actions.moveLeft)
        _velocity.x = -_speed;
    if (_actions.moveRight)
        _velocity.x = _speed;
    if (_actions.dropBomb && _nbBomb > 0) {
        float x = floor((_position.x + 4) / 10) * 10;
        float y = floor((_position.z + 4) / 10) * 10;
        _nbBomb -= 1;
        GLOBAL::_entities.push_back(new Bomb(Entity(*GLOBAL::_texturedModels["bomb"], {x, 0, y}, { 0, 0, 0 }, 2), this,  *GLOBAL::_particleSystem["fireBomb"], *GLOBAL::_particleSystem["explosionBomb"]));
        GLOBAL::_map->addElement(IS::MAP_TILES::BOMB, x / 10, y / 10);
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
    } else if (IS::GLOBAL::_scene == GAME) {
        checkKeyPressed();
        changeModelRotation();
        checkCollisionMap();
        checkCollisionPowerUp();
        if (_velocity.x == 0 && _velocity.y == 0 && _velocity.z == 0)
            resetFrame();
        _velocity = { 0 };
        _actions = { false };
        return (true);
    }
    return (true);
}