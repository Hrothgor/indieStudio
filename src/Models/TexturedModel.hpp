/*
** EPITECH PROJECT, 2021
** 1
** File description:
** TexturedModel
*/

#ifndef TEXTUREDMODEL_HPP_
#define TEXTUREDMODEL_HPP_

#include "../include.hpp"

namespace IS {
    class TexturedModel {
        public:
            TexturedModel() {};
            TexturedModel(const std::string &modelPath);
            TexturedModel(const std::string &modelPath, const std::string &texturePath);
            TexturedModel(Mesh mesh, const std::string &texturePath);
            ~TexturedModel();

            void setShader(Shader shader);
            void setColor(Color color, int materialNumber);
            bool hasShader();

            Model getModel() const;
            Texture2D getTexture() const;
            void setModel(Model model);
            void setTexture(Texture2D texture);
            void setTransform(Matrix matrix);

        protected:
        private:
            Model _model;
            Texture2D _texture = {0};
    };
}

#endif /* !TEXTUREDMODEL_HPP_ */
