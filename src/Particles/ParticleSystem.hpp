/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** ParticleSystem
*/

#ifndef PARTICLESYSTEM_HPP_
#define PARTICLESYSTEM_HPP_

#include "../include.hpp"
#include "Particle.hpp"
#include "../RenderEngine/MasterRenderer.hpp"

namespace IS {
    enum PARTICLE_EMISSION {
        PARABOLIC = 0,
        DIRECTIONAL,
        CIRCLE,
    };

    class ParticleSystem {
        public:
            ParticleSystem(float pps, float speed, float gravityComplient, float lifeLength, float scale, const std::string &fileTexture, MasterRenderer *renderer, PARTICLE_EMISSION emissionType = PARABOLIC);
            ParticleSystem(float pps, float speed, float gravityComplient, float lifeLength, float scale, ParticleTexturedModel &particleTexturedModel, MasterRenderer *renderer, PARTICLE_EMISSION emissionType = PARABOLIC);
            ~ParticleSystem();

            void generateParticles(Vector3 position);
            void emitParticle(Vector3 center);

        protected:
        private:
            void emitParticleParabolic(Vector3 center);
            void emitParticleDirectional(Vector3 center, Vector3 direction);
            void emitParticleCircle(Vector3 center);

        	float _pps;
            float _speed;
            float _gravityComplient;
            float _lifeLength;
            float _scale;
            float _particlesToCreate = 0;
            MasterRenderer *_renderer;
            PARTICLE_EMISSION _emissionType;
            ParticleTexturedModel _particleTexturedModel;
    };
}

#endif /* !PARTICLESYSTEM_HPP_ */
