/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** FrameRate
*/

#ifndef FRAMERATE_HPP_
#define FRAMERATE_HPP_

#include "../include.hpp"

namespace IS {
    class FrameRate {
        public:
            FrameRate();
            ~FrameRate();

            void update();
            void show();

        protected:
        private:
            Clock _clock;
            int nbFrame = 0;
            int framerate = 0;
    };
}

#endif /* !FRAMERATE_HPP_ */
