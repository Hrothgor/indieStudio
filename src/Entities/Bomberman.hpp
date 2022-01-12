/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Bomberman
*/

#pragma once
#ifndef BOMBERMAN_HPP_
#define BOMBERMAN_HPP_

#include "../global.hpp"
#include "PowerUp.hpp"
#include "Bomb.hpp"
#include "../Particles/ParticleSystem.hpp"

namespace IS {
    enum MONITOR_TYPE {
        AI = 0,
        KEYBOARD,
        CONTROLLER,
    };

    enum CONTROLLER_NUMBER {
        CONTROLLER1 = 0,
        CONTROLLER2 = 1,
        CONTROLLER3 = 2,
        CONTROLLER4 = 3,
    };

    typedef struct keyPlayer_s {
        KeyboardKey up;
        KeyboardKey down;
        KeyboardKey left;
        KeyboardKey right;
        KeyboardKey bomb;
    } keyPlayer_t;

    typedef struct actionPlayer_s {
        bool moveUp;
        bool moveDown;
        bool moveLeft;
        bool moveRight;
        bool dropBomb;
    } actionPlayer_t;

    class Bomberman : public Entity {
        public:
            Bomberman(Entity entity, ParticleSystem smokeFeet);
            Bomberman(Entity entity, ParticleSystem smokeFeet, keyPlayer_t keys);
            Bomberman(Entity entity, ParticleSystem smokeFeet, int gamePadID);
            ~Bomberman();

            void powerUpFire();
            void powerUpBomb();
            void powerUpSpeed();

            void bombExplode();
            int getBlastRadius() const;

            void setDeathAnimation(bool state);
            void changeMonitorType();

            void checkKeyPressed();
            void changeModelRotation();
            void checkCollisionMap();
            void checkCollisionPowerUp();
            bool update(Camera *camera);
            void setKey(keyPlayer_t keys, int gamePadID, bool ai);

        protected:
        private:
            ParticleSystem _smokeFeet;
            float _animationLenght = 0.05;
            MONITOR_TYPE _monitorType;
            keyPlayer_t _keys;
            int _gamePadID;
            actionPlayer_t _actions = { false };
            int _nbBomb = 1;
            float _speed = 0.2;
            int _blastRadius = 1;
            bool _dying = false;
            float _deathAnimation = 1;
            int _maxBomb = 1;
    };
};

#include "AI.hpp"

#endif /* !BOMBERMAN_HPP_ */
