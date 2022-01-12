/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-cyril.grosjean
** File description:
** Button
*/

#include "ButtonBomberman.hpp"

IS::ButtonBomberman::ButtonBomberman(std::string texture_path, Vector2 pos, void (IS::ButtonBomberman::*func)(void), int id, int nbFrame, int controller)
    : Button(texture_path, pos, nullptr, nbFrame)
{
    _func = func;
    _bombermanId = id;
    _controllerIdx = controller;
    GLOBAL::_bombermans[_bombermanId]->setColor(GLOBAL::listColor[_color1], 0);
    GLOBAL::_bombermans[_bombermanId]->setColor(GLOBAL::listColor[_color2], 1);
}

IS::ButtonBomberman::~ButtonBomberman()
{
}

void IS::ButtonBomberman::callFunction()
{
    if (_func != nullptr)
        (this->*_func)();
}

void IS::ButtonBomberman::changeMonitorTypeButton()
{
    GLOBAL::_bombermans[_bombermanId]->changeMonitorType();
}

void IS::ButtonBomberman::changeColorButton1()
{
    // GLOBAL::listColor
    _color1 += 1;
    if (_color1 >= MAX_COLOR) {
        _color1 = 0;
    }
    GLOBAL::_bombermans[_bombermanId]->setColor(GLOBAL::listColor[_color1], 0);
}

void IS::ButtonBomberman::changeColorButton2()
{
    _color2 += 1;
    if (_color2 >= MAX_COLOR) {
        _color2 = 0;
    }
    GLOBAL::_bombermans[_bombermanId]->setColor(GLOBAL::listColor[_color2], 1);
}

void IS::ButtonBomberman::changeController()
{
    _controllerIdx++;
    if (_controllerIdx >= 3) {
        _controllerIdx = 0;
    }

    if (_controllerIdx == CONTROLLER) { // CONTROLLER
        GLOBAL::_bombermans[_bombermanId]->setKey({}, CONTROLLER2, false);
        _texture = LoadTexture(ASSETS_PATH"ressources/changeControllerButton.png");
    } else if (_controllerIdx == KEYBOARD) { // Keyboard
        _texture = LoadTexture(ASSETS_PATH"ressources/changeKeyboardButton.png");
        keyPlayer_t keys;
        switch (_bombermanId) {
            case 0:
                keys = {KEY_W, KEY_S, KEY_A, KEY_D, KEY_E};
                break;
            case 1:
                keys = {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_RIGHT_CONTROL};
                break;
            case 2:
                keys = {KEY_T, KEY_G, KEY_F, KEY_H, KEY_Y};
                break;
            default:
                keys = {KEY_I, KEY_K, KEY_J, KEY_L, KEY_O};
                break;
        }
        GLOBAL::_bombermans[_bombermanId]->setKey(keys, -1, false);
    } else {// AI
        GLOBAL::_bombermans[_bombermanId]->setKey({}, -1, true);
        _texture = LoadTexture(ASSETS_PATH"ressources/changeAIButton.png");
    }
}