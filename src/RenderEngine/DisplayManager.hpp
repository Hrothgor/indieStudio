/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** DisplayManager
*/

#pragma once
#ifndef DISPLAYMANAGER_HPP_
#define DISPLAYMANAGER_HPP_

#include "../include.hpp"
#include "../Entities/Camera.hpp"
#include "../Entities/Light.hpp"
#include "../Entities/Bomb.hpp"
#include "../Entities/Bomberman.hpp"
#include "../Models/TexturedModel.hpp"
#include "../Particles/ParticleSystem.hpp"
#include "Master3DRenderer.hpp"
#include "Master2DRenderer.hpp"

namespace IS {
    class DisplayManager {
        public:
            DisplayManager();
            ~DisplayManager();

            void run();
            void load();
            void clean();

        protected:
        private:
            Master3DRenderer _3Drenderer;
            Master2DRenderer _2Drenderer;
            int _actualscene = 0;

            std::map<std::string, TexturedModel> _texturedModels;
            std::map<std::string, ParticleTexturedModel> _particleTexturedModels;
            std::map<std::string, ParticleSystem> _particleSystem;

            std::vector<Entity *> _entities;
            std::vector<LightValue> _lights;
    };
}

#endif /* !DISPLAYMANAGER_HPP_ */
