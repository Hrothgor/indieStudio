/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** LightShader2Texture
*/

#ifndef LIGHTSHADERCOLOR_HPP_
#define LIGHTSHADERCOLOR_HPP_

#include "../include.hpp"

namespace IS {
    class LightShaderColor {
        public:
            LightShaderColor();
            ~LightShaderColor();

            void initShader();
            Shader getShader();

        protected:
        private:
            Shader _shader;
    };
}

#endif /* !LIGHTSHADERCOLOR_HPP_ */
