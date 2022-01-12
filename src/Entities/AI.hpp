/*
** EPITECH PROJECT, 2021
** YEP
** File description:
** AI
*/

#pragma once
#ifndef AI_HPP_
#define AI_HPP_

#include "../global.hpp"
#include "Bomberman.hpp"

namespace IS {
    class AIPath {
        public:
            AIPath();
            ~AIPath();

            IS::Bomberman *getNearestBomberman(Vector3 aiPositions);
            Vector3 move(Vector3 ai, Vector3 oldVelocity);
            Vector3 moveToAnotherPlace(Vector3 ai, Vector3 oldVelocity);
            bool placeBomb(Vector3 ai);

            Vector3 checkNearestPlace(Vector3 ai);

            Vector3 moveBombLeft(Vector3 ai, Vector3 oldVelocity);
            Vector3 moveBombRight(Vector3 ai, Vector3 oldVelocity);
            Vector3 moveBombUp(Vector3 ai, Vector3 oldVelocity);
            Vector3 moveBombDown(Vector3 ai, Vector3 oldVelocity);

            Vector3 moveLeft(Vector3 ai);
            Vector3 moveRight(Vector3 ai);
            Vector3 moveUp(Vector3 ai);
            Vector3 moveDown(Vector3 ai);

            int bombInRange(Vector3 ai);
            bool hasCrate(int x, int y);
            bool canPlaceBomb(Vector3 ai);

            static IS::actionPlayer_t getAIMove(IS::Bomberman *ai, int maxBomb, int nbBomb);

        protected:
        private:
    };
};

#endif /* !AI_HPP_ */
