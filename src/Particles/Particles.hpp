/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Particles
*/

#ifndef PARTICLES_HPP_
#define PARTICLES_HPP_

#include "../include.hpp"

namespace IS {
    class Particles {
        public:
            Particles(Vector3 position, Vector3 velocity, float gravityEffect, float lifeLenght, float rotation, float scale);
            ~Particles();

            bool update();

            Vector3 getPosition() const;
            Vector3 getVelocity() const;
            float getGravityEffect() const;
            float getLifeLenght() const;
            float getRotation() const;
            float getScale() const;

        protected:
        private:
            Vector3 _position;
            Vector3 _velocity;
            float _gravityEffect;
            float _lifeLenght;
            float _rotation;
            float _scale;
            float _elapsedTime = 0;
    };
}

#endif /* !PARTICLES_HPP_ */
