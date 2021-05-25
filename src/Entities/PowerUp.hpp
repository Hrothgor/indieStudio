/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-cyril.grosjean
** File description:
** PowerUp
*/

#pragma once
#ifndef POWERUP_HPP_
#define POWERUP_HPP_

#include "../include.hpp"
#include "Entity.hpp"
#include "../Particles/ParticleSystem.hpp"

namespace IS {
    enum POWER_TYPE {
        FIRE = 0,
        MOREBOMB,
        SPEED,
        SOFTPASS,
    };

    class PowerUp : public Entity {
        public:
            PowerUp(Entity entity, POWER_TYPE type, ParticleSystem shiny);
            ~PowerUp();

            POWER_TYPE getType() const;

            bool update(Camera *camera);

        protected:
        private:
            ParticleSystem _shiny;
            float _angle = 0;
            POWER_TYPE _type;
    };
}

#endif /* !POWERUP_HPP_ */
