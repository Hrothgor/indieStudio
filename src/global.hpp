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
    class Sounds;
    class Entity;
    class Bomberman;
    class PowerUp;
    class Map;
    class Camera;

    namespace GLOBAL {
        inline std::map<std::string, TexturedModel *> _texturedModels;
        inline std::map<std::string, ParticleTexturedModel *> _particleTexturedModels;
        inline std::map<std::string, ParticleSystem *> _particleSystem;
        inline std::map<std::string, Sounds *> _sounds;

        inline std::vector<Entity *> _entities;
        inline std::vector<Bomberman *> _bombermans;
        inline std::vector<PowerUp *> _powerups;
        inline Map *_map;

        inline Color listColor[MAX_COLOR] = {
        DARKGRAY, MAROON, ORANGE, DARKGREEN, DARKBLUE, DARKPURPLE, DARKBROWN,
        GRAY, RED, GOLD, LIME, BLUE, VIOLET, BROWN, LIGHTGRAY, PINK, YELLOW,
        GREEN, SKYBLUE, PURPLE, BEIGE };
        inline IS::Camera *camera;

        inline int _scene = 0;

        inline int _slowfactor = 1;
        inline int _nbFrame = 0;
    }
}

#endif /* !GLOBAL_HPP_ */
