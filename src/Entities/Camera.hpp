/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "../include.hpp"

namespace IS {
    class Camera {
        public:
            Camera();
            ~Camera();

            Camera3D getCamera3D() const;
            Camera3D *getCamera3DPointer();
            Vector3 getPosition() const;
            Vector3 getTarget() const;

        protected:
        private:
            Camera3D _camera;
    };
}

#endif /* !CAMERA_HPP_ */
