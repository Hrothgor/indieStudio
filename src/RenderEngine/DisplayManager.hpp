/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** DisplayManager
*/

#ifndef DISPLAYMANAGER_HPP_
#define DISPLAYMANAGER_HPP_

#include "../include.hpp"
#include "../Entities/Camera.hpp"
#include "../Entities/Light.hpp"
#include "../Entities/Entity.hpp"
#include "../Models/TexturedModel.hpp"
#include "../Particles/ParticleSystem.hpp"
#include "MasterRenderer.hpp"

namespace IS {
    class DisplayManager {
        public:
            DisplayManager();
            ~DisplayManager();

            void run();
            void LoadData();

        protected:
        private:
            MasterRenderer _renderer;
            std::thread _thread;
            int _progress = -1;

            std::vector<TexturedModel> _texturedModels;
            std::vector<ParticleTexturedModel> _particleTexturedModels;
            std::vector<ParticleSystem> _particleSystem;
            std::vector<Entity> _entities;
            std::vector<LightValue> _lights;
    };
}

#endif /* !DISPLAYMANAGER_HPP_ */
