/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Master2DRenderer
*/

#pragma once
#ifndef MASTER2DRENDERER_HPP_
#define MASTER2DRENDERER_HPP_

#include "../include.hpp"

namespace IS {
    class Master2DRenderer {
        public:
            Master2DRenderer();
            ~Master2DRenderer();

            void start();
            void stop();
            void render(int scene);

        protected:
        private:
    };
}

#endif /* !MASTER2DRENDERER_HPP_ */
