/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-cyril.grosjean
** File description:
** Button
*/

#pragma once
#ifndef BUTTONBOMBERMAN_HPP_
#define BUTTONBOMBERMAN_HPP_

#include "Button.hpp"
#include "../Entities/Bomberman.hpp"

namespace IS {

    class ButtonBomberman : public Button {
        public:
            ButtonBomberman(std::string texture_path, Vector2 pos, void (IS::ButtonBomberman::*func)(void), int id, int nbFrame = 3, int controller = AI);
            ~ButtonBomberman();

            void callFunction();

            //// BUTTON FUNC ////
            void changeMonitorTypeButton();
            void changeColorButton1();
            void changeColorButton2();
            void changeController();
            /////////////////////
        protected:
        private:
            int _color1 = rand() % MAX_COLOR;
            int _color2 = rand() % MAX_COLOR;
            int _bombermanId;
            int _controllerIdx;
            void (IS::ButtonBomberman::*_func)(void);
    };
}

#endif /* !BUTTONBOMBERMAN_HPP_ */