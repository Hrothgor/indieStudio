/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "../include.hpp"
#include "../Models/TexturedModel.hpp"

namespace IS {
    class Entity {
        public:
            Entity(const TexturedModel &texturedModel, Vector3 position, Vector3 rotation, float scale);
            ~Entity();

            void increasePosition(Vector3 vec);
            void increaseRotation(Vector3 vec);

            TexturedModel getTexturedModel() const;
            Vector3 getPosition() const;
            Vector3 getRotation() const;
            float getScale() const;

            void setTexturedModel(TexturedModel texturedModel);
            void setPosition(Vector3 position);
            void setRotation(Vector3 rotation);
            void setScale(float scale);

        protected:
        private:
            TexturedModel _texturedModel;
            Vector3 _position;
            Vector3 _rotation;
            float _scale;
    };
}

#endif /* !ENTITY_HPP_ */
