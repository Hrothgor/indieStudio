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
    _camera.position = { 0, 10.0, -40.0 }; // _camera position
    _camera.target = { 0.0, 0.0, 0.0 };     // _camera looking at point
    _camera.up = { 0.0, 1.0, 0.0 };          // _camera up vector (rotation towards target)
    _camera.fovy = 70;
    _camera.projection = CAMERA_PERSPECTIVE;
    //SetCameraMode(_camera, CAMERA_FIRST_PERSON);
}

IS::Camera::~Camera()
{
}

void IS::Camera::update()
{
    if (IsKeyPressed(KEY_ONE))
        startAnimation(_camera.position, {0,50,50}, {0,0,0}, 5);
    if (_currentAnimation.isRunning) {
        Vector3 direction = Vector3Subtract(_currentAnimation.end, _currentAnimation.begin);
        direction = Vector3Normalize(direction);
        float distance = Vector3Distance(_currentAnimation.begin, _currentAnimation.end);
        float speed = distance * (GetFrameTime() / _currentAnimation.length);
        direction = Vector3Multiply(direction, {speed, speed, speed});
        _camera.position = Vector3Add(_camera.position, direction);
        if (Vector3Distance(_camera.position, _currentAnimation.end) <= speed) {
            //SetCameraMode(_camera, CAMERA_FIRST_PERSON);
            _currentAnimation = { 0 };
        }
    }
    UpdateCamera(&_camera);
}

void IS::Camera::startAnimation(Vector3 begin, Vector3 end, Vector3 target, float length)
{
    _currentAnimation.begin = begin;
    _currentAnimation.end = end;
    _camera.position = begin;
    _camera.target = target;
    _currentAnimation.length = length;
    _currentAnimation.isRunning = true;
    SetCameraMode(_camera, CameraMode::CAMERA_CUSTOM);
}

Camera3D IS::Camera::getCamera3D() const
{
    return (_camera);
}

Vector3 IS::Camera::getPosition() const
{
    return (_camera.position);
}

Vector3 IS::Camera::getTarget() const
{
    return (_camera.target);
}