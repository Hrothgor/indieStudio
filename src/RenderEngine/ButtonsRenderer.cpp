/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-cyril.grosjean
** File description:
** ButtonsRenderer
*/

#include "ButtonsRenderer.hpp"

IS::ButtonsRenderer::ButtonsRenderer()
{
    init();
}

IS::ButtonsRenderer::~ButtonsRenderer()
{
}

void IS::ButtonsRenderer::init()
{

}

void IS::ButtonsRenderer::render(int scene)
{
    for (auto &list : _buttons) {
        if (list.first != scene)
            continue;
        for (Button *button : list.second) {
            button->update();
            //button->draw();
        }
    }
}