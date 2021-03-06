/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** include
*/

#pragma once
#ifndef INCLUDE_HPP_
#define INCLUDE_HPP_

#define MENU 0
#define MENUBOMBERMAN 1
#define GAME 2

#define WIDTH 1920.0
#define HEIGHT 1080.0
#define GRAVITY -10
#define FOV 70.0
#define NEAR_PLANE 0.1
#define FAR_PLANE 1000.0

#define GLSL_VERSION 330
#define MAX_COLOR 21

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <map>
#include <regex>
#include <unordered_map>
#include <time.h>
#include <filesystem>

#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#include "Tools/Maths.hpp"
#include "Tools/GenMesh.hpp"
#include "Tools/Clock.hpp"

#include "Audio/Sounds.hpp"

#endif /* !INCLUDE_HPP_ */
