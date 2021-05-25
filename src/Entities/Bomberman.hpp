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

    typedef struct keyPlayer_s {
        KeyboardKey up;
        KeyboardKey down;
        KeyboardKey left;
        KeyboardKey right;
        KeyboardKey bomb;
    } keyPlayer_t;

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

            void checkKeyPressed();
            void changeModelRotation();
            void checkCollisionMap();
            void checkCollisionPowerUp();
            bool update(Camera *camera);

        protected:
        private:
            ParticleSystem _smokeFeet;
            float _animationLenght = 0.05;
            MONITOR_TYPE _monitorType;
            keyPlayer_t _keys;
            int _gamePadID = -1;
            int _nbBomb = 1;
            float _speed = 0.2;
            int _blastRadius = 1;
            bool _dying = false;
            float _deathAnimation = 1;
    };
}

#endif /* !BOMBERMAN_HPP_ */
