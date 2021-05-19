/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Skybox
*/

#ifndef SKYBOX_HPP_
#define SKYBOX_HPP_

#include "../include.hpp"
#include "../Models/TexturedModel.hpp"
#include "../Shaders/SkyboxShader.hpp"

namespace IS {
    class Skybox {
        public:
            Skybox() {};
            Skybox(const std::string &texturePath);
            ~Skybox();

            Model getModel() const;

            void setModel(Model model);

        protected:
        private:
            Model _model = {0};
            SkyboxShader _skyboxShader;
    };
}

#endif /* !SKYBOX_HPP_ */
