/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Particles
*/

#ifndef PARTICLES_HPP_
#define PARTICLES_HPP_

#include "../include.hpp"
#include "../Models/ParticleTexturedModel.hpp"

namespace IS {
    class Particle {
        public:
            Particle(Vector3 position, Vector3 velocity, float gravityEffect, float lifeLenght, float rotation, float scale, ParticleTexturedModel &particleTexturedModel);
            ~Particle();

            bool update();
            void updateTextureCoordInfo();
            float distanceToCamera(Camera3D camera);

            Vector3 getPosition() const;
            Vector3 getVelocity() const;
            float getGravityEffect() const;
            float getLifeLenght() const;
            float getRotation() const;
            float getScale() const;
            ParticleTexturedModel getTexturedModel() const;
            Vector2 getTexOffset1() const;
            Vector2 getTexOffset2() const;
            float getBlendFactor() const;

            void setModelTransform(Matrix &matrix);

        protected:
        private:
            Vector3 _position;
            Vector3 _velocity;
            float _gravityEffect;
            float _lifeLenght;
            float _scale;
            float _rotation;
            float _elapsedTime = 0;
            ParticleTexturedModel _particleTexturedModel;
            Vector2 _texOffset1 = {0};
            Vector2 _texOffset2 = {0};
            float _blendFactor = 0;
    };
}

#endif /* !PARTICLES_HPP_ */
