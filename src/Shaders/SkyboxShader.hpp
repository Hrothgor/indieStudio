/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** SkyboxShader
*/

#pragma once
#ifndef SKYBOXSHADER_HPP_
#define SKYBOXSHADER_HPP_

#include "../include.hpp"

namespace IS {
    class SkyboxShader {
        public:
            SkyboxShader();
            ~SkyboxShader();

            void initShader();
            Shader getShader();
            void clean();

        protected:
        private:
            Shader _shader;
    };
}

#endif /* !SKYBOXSHADER_HPP_ */
