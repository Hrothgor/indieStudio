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
#include "MasterRenderer.hpp"

namespace IS {
    class DisplayManager {
        public:
            DisplayManager();
            ~DisplayManager();

            void run();

        protected:
        private:
            MasterRenderer _renderer;
    };
}

#endif /* !DISPLAYMANAGER_HPP_ */
