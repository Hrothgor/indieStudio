/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Camera
*/

#include "Camera.hpp"

IS::Camera::Camera()
{
    _camera = { 0 };
    _camera.position = { 0, 30.0, -70.0 }; // _camera position
    _camera.target = { 0.0, 0.0, 0.0 };     // _camera looking at point
    _camera.up = { 0.0, 1.0, 0.0 };          // _camera up vector (rotation towards target)
    _camera.fovy = 70;
    _camera.projection = CAMERA_PERSPECTIVE;
    SetCameraMode(_camera, CAMERA_FIRST_PERSON);
}

IS::Camera::~Camera()
{
}

Camera3D IS::Camera::getCamera3D() const
{
    return (_camera);
}

Camera3D *IS::Camera::getCamera3DPointer()
{
    return (&_camera);
}

Vector3 IS::Camera::getPosition() const
{
    return (_camera.position);
}

Vector3 IS::Camera::getTarget() const
{
    return (_camera.target);
}