/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Bomberman
*/

#pragma once
#ifndef BOMBERMAN_HPP_
#define BOMBERMAN_HPP_

#include "../include.hpp"
#include "Entity.hpp"
#include "../Particles/ParticleSystem.hpp"

namespace IS {
    class Bomberman : public Entity {
        public:
            Bomberman(Entity entity, ParticleSystem &smokeFeet);
            ~Bomberman();

            bool update();

        protected:
        private:
            Vector3 _velocity = { 0 };
            ParticleSystem _smokeFeet;
    };
}

#endif /* !BOMBERMAN_HPP_ */
