/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** FrameRate
*/

#include "FrameRate.hpp"

IS::FrameRate::FrameRate()
{
}

IS::FrameRate::~FrameRate()
{
}

void IS::FrameRate::update()
{
    nbFrame++;
    if (_clock.getElapsedTime() > 1) {
        framerate = (1 * nbFrame);
        nbFrame = 0;
        _clock.reset();
    }
}

void IS::FrameRate::show()
{
    DrawText(std::to_string(framerate).c_str(), 0, 0, 50, RED);
}