/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** global
*/

#ifndef GLOBAL_HPP_
#define GLOBAL_HPP_

#include "include.hpp"

namespace IS {
    class TexturedModel;
    class ParticleTexturedModel;
    class ParticleSystem;
    class Entity;
    class LightValue;

    namespace GLOBAL {
        inline std::map<std::string, TexturedModel *> _texturedModels;
        inline std::map<std::string, ParticleTexturedModel *> _particleTexturedModels;
        inline std::map<std::string, ParticleSystem *> _particleSystem;

        inline std::vector<Entity *> _entities;
        inline std::vector<LightValue *> _lights;
    }
}

#endif /* !GLOBAL_HPP_ */
