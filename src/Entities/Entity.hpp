/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#pragma once
#include "../include.hpp"
#include "../Models/TexturedModel.hpp"

namespace IS {
    class Entity {
        public:
            Entity(const TexturedModel &texturedModel, Vector3 position, Vector3 rotation, float scale);
            ~Entity();

            virtual bool update(Camera3D camera);
            void increasePosition(Vector3 vec);
            void increaseRotation(Vector3 vec);

            void nextFrame();
            void prevFrame();

            TexturedModel getTexturedModel() const;
            Vector3 getPosition() const;
            Vector3 getRotation() const;
            float getScale() const;

            void setTexturedModel(TexturedModel texturedModel);
            void setPosition(Vector3 position);
            void setRotation(Vector3 rotation);
            void setScale(float scale);
            void setColor(Color color, int materialNumber);

            int test = 0;
        protected:
            TexturedModel _texturedModel;
            Vector3 _position;
            Vector3 _rotation;
            float _scale;
            std::vector<Color> _colors;
        private:
    };
}

#endif /* !ENTITY_HPP_ */
