/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** ParticlesRenderer
*/

#ifndef PARTICLESRENDERER_HPP_
#define PARTICLESRENDERER_HPP_

#include "../include.hpp"
#include "../Entities/Camera.hpp"
#include "../Particles/Particles.hpp"

namespace IS {
    class ParticlesRenderer {
        public:
            ParticlesRenderer();
            ~ParticlesRenderer();

            void render(int scene, IS::Camera camera);
            void prepareParticles(Particles &particles);
            void addParticles(int scene, const Particles &entity);

        protected:
        private:
            std::map<int, std::vector<Particles>> _particles;
    };
}

#endif /* !PARTICLESRENDERER_HPP_ */
