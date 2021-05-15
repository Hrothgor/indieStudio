/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** MasterRenderer
*/

#ifndef MASTERRENDERER_HPP_
#define MASTERRENDERER_HPP_

#include "../include.hpp"
#include "../Entities/Camera.hpp"
#include "EntityRenderer.hpp"
#include "ParticlesRenderer.hpp"

namespace IS {
    class MasterRenderer {
        public:
            MasterRenderer();
            ~MasterRenderer();

            void start(IS::Camera camera);
            void stop();
            void render(int scene, IS::Camera camera);

            void addLight(const LightValue &light);
            void addEntity(int scene, const Entity &entity);
            void addParticles(const Particle &particles);

        protected:
        private:
            EntityRenderer _entityRenderer;
            ParticlesRenderer _particlesRenderer;
    };
}

#endif /* !MASTERRENDERER_HPP_ */
