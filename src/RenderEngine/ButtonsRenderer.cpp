/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-cyril.grosjean
** File description:
** ButtonsRenderer
*/

#include "ButtonsRenderer.hpp"

IS::ButtonsRenderer::ButtonsRenderer()
{
}

IS::ButtonsRenderer::~ButtonsRenderer()
{
}

void IS::ButtonsRenderer::addButton(int scene, Button *button)
{
    for (auto &list : _buttons) {
        if (list.first == scene) {
            list.second.push_back(button);
            return;
        }
    }
    _buttons[scene] = std::vector<Button *> { button };
}

void IS::ButtonsRenderer::init()
{
    addButton(MENU, new Button(ASSETS_PATH"ressources/startButton.png", {835, 452}, &IS::Button::scene1Button));
    addButton(MENU, new Button(ASSETS_PATH"ressources/quitButton.png", {835, 600}, &IS::Button::quitButton));
    addButton(MENUBOMBERMAN, new Button(ASSETS_PATH"ressources/backButton.png", {70, 952}, &IS::Button::scene0Button));
    addButton(MENUBOMBERMAN, new Button(ASSETS_PATH"ressources/startButton.png", {1600, 952}, &IS::Button::scene2Button));
    addButton(MENUBOMBERMAN, new ButtonBomberman(ASSETS_PATH"ressources/changeColor1Button.png", {184, 502}, &IS::ButtonBomberman::changeColorButton1, 0));
    addButton(MENUBOMBERMAN, new ButtonBomberman(ASSETS_PATH"ressources/changeColor1Button.png", {618, 502}, &IS::ButtonBomberman::changeColorButton1, 1));
    addButton(MENUBOMBERMAN, new ButtonBomberman(ASSETS_PATH"ressources/changeColor1Button.png", {1052, 502}, &IS::ButtonBomberman::changeColorButton1, 2));
    addButton(MENUBOMBERMAN, new ButtonBomberman(ASSETS_PATH"ressources/changeColor1Button.png", {1486, 502}, &IS::ButtonBomberman::changeColorButton1, 3));

    addButton(MENUBOMBERMAN, new ButtonBomberman(ASSETS_PATH"ressources/changeColor2Button.png", {184, 630}, &IS::ButtonBomberman::changeColorButton2, 0));
    addButton(MENUBOMBERMAN, new ButtonBomberman(ASSETS_PATH"ressources/changeColor2Button.png", {618, 630}, &IS::ButtonBomberman::changeColorButton2, 1));
    addButton(MENUBOMBERMAN, new ButtonBomberman(ASSETS_PATH"ressources/changeColor2Button.png", {1052, 630}, &IS::ButtonBomberman::changeColorButton2, 2));
    addButton(MENUBOMBERMAN, new ButtonBomberman(ASSETS_PATH"ressources/changeColor2Button.png", {1486, 630}, &IS::ButtonBomberman::changeColorButton2, 3));

    addButton(MENUBOMBERMAN, new ButtonBomberman(ASSETS_PATH"ressources/changeKeyboardButton.png", {184, 758}, &IS::ButtonBomberman::changeController, 0, 3, KEYBOARD));
    addButton(MENUBOMBERMAN, new ButtonBomberman(ASSETS_PATH"ressources/changeAIButton.png", {618, 758}, &IS::ButtonBomberman::changeController, 1, 3, AI));
    addButton(MENUBOMBERMAN, new ButtonBomberman(ASSETS_PATH"ressources/changeAIButton.png", {1052, 758}, &IS::ButtonBomberman::changeController, 2, 3, AI));
    addButton(MENUBOMBERMAN, new ButtonBomberman(ASSETS_PATH"ressources/changeAIButton.png", {1486, 758}, &IS::ButtonBomberman::changeController, 3, 3, AI));
}

void IS::ButtonsRenderer::render(int scene)
{
    if (_buttons.empty())
        init();
    for (auto &list : _buttons) {
        if (list.first != scene)
            continue;
        for (Button *button : list.second) {
            button->update();
            Rectangle source = button->getRect();
            Rectangle dest = { button->getPosition().x, button->getPosition().y, source.width*button->getScale(), source.height*button->getScale() };
            Vector2 origin = { 0.0, 0.0 };
            DrawTexturePro(button->getTexture(), source, dest, origin, button->getRotation(), WHITE);
        }
    }
}