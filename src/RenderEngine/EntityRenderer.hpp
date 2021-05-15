/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** EntityRenderer
*/

#ifndef ENTITYRENDERER_HPP_
#define ENTITYRENDERER_HPP_

#include "../include.hpp"
#include "../Entities/Camera.hpp"
#include "../Entities/Entity.hpp"
#include "../Entities/Light.hpp"
#include "../Shaders/LightShader.hpp"
#include "../Shaders/LightShaderColor.hpp"
#include "rlights.h"

namespace IS {
    class EntityRenderer {
        public:
            EntityRenderer();
            ~EntityRenderer();

            void prepare(Camera camera);
            void render(int scene, IS::Camera camera);
            void prepareEntity(Entity &entity);

            void addLight(int scene, const LightValue &light);
            void addEntity(int scene, const Entity &entity);

        protected:
        private:
            LightShader _lightShader;
            LightShaderColor _lightShaderColor;

            std::vector<Light> _lights;
            std::map<int, std::vector<Entity>> _entities;
    };
}

#endif /* !ENTITYRENDERER_HPP_ */
