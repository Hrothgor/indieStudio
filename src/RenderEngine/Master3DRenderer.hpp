/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Master3DRenderer
*/

#pragma once
#ifndef MASTER3DRENDERER_HPP_
#define MASTER3DRENDERER_HPP_

#include "../include.hpp"
#include "../Entities/Camera.hpp"
#include "EntityRenderer.hpp"
#include "ParticlesRenderer.hpp"
#include "../Entities/Skybox.hpp"

namespace IS {
    class Master3DRenderer {
        public:
            Master3DRenderer();
            ~Master3DRenderer();

            void start(IS::Camera camera);
            void stop();
            void render(int scene, IS::Camera camera, Map &map);

            void addSkybox(const Skybox &skybox);
            void addLight(const LightValue &light);
            void addEntity(int scene, Entity *entity);
            void addParticles(const Particle &particles);

        protected:
        private:
            EntityRenderer _entityRenderer;
            ParticlesRenderer _particlesRenderer;
            Skybox _skybox;
    };
}

#endif /* !MASTER3DRENDERER_HPP_ */
