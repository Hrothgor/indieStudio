/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Entity
*/

#include "Entity.hpp"

Color listColor[21] = {
        DARKGRAY, MAROON, ORANGE, DARKGREEN, DARKBLUE, DARKPURPLE, DARKBROWN,
        GRAY, RED, GOLD, LIME, BLUE, VIOLET, BROWN, LIGHTGRAY, PINK, YELLOW,
        GREEN, SKYBLUE, PURPLE, BEIGE };

IS::Entity::Entity(const TexturedModel &texturedModel, Vector3 position, Vector3 rotation, float scale)
    : _texturedModel(texturedModel)
    , _colors(_texturedModel.getModel().materialCount)
{
    _position = position;
    _rotation = rotation;
    _scale = scale;
    _texturedModel.setTransform(MatrixRotateXYZ({
        DEG2RAD*_rotation.x, DEG2RAD*_rotation.y, DEG2RAD*_rotation.z }));
    for (Color &color : _colors)
        color = listColor[rand() % 21];
}

IS::Entity::~Entity()
{
}

bool IS::Entity::update(Camera3D camera, Map &map)
{
    int i = 0;

    for (Color color : _colors)
        _texturedModel.setColor(color, i++);
    return (true);
}

void IS::Entity::increasePosition(Vector3 vec)
{
    _position.x += vec.x;
    _position.y += vec.y;
    _position.z += vec.z;
}

void IS::Entity::increaseRotation(Vector3 vec)
{
    _rotation.x += vec.x;
    _rotation.y += vec.y;
    _rotation.z += vec.z;
    _texturedModel.setTransform(MatrixRotateXYZ({
        DEG2RAD*_rotation.x, DEG2RAD*_rotation.y, DEG2RAD*_rotation.z }));
}

void IS::Entity::nextFrame()
{
    _texturedModel.nextFrame();
}

void IS::Entity::prevFrame()
{
    _texturedModel.prevFrame();
}

IS::TexturedModel IS::Entity::getTexturedModel() const
{
    return (_texturedModel);
}

Vector3 IS::Entity::getPosition() const
{
    return (_position);
}

Vector3 IS::Entity::getRotation() const
{
    return (_rotation);
}

float IS::Entity::getScale() const
{
    return (_scale);
}

Color IS::Entity::getColor(int materialNumber) const
{
    if (materialNumber >= _colors.size() || materialNumber < 0)
        return (WHITE);
    return (_colors[materialNumber]);
}

bool IS::Entity::IsAlive() const
{
    return (_alive);
}

void IS::Entity::setTexturedModel(TexturedModel texturedModel)
{
    _texturedModel = texturedModel;
}

void IS::Entity::setPosition(Vector3 position)
{
    _position = position;
}

void IS::Entity::setVelocity(Vector3 velocity)
{
    _velocity = velocity;
}

void IS::Entity::setRotation(Vector3 rotation)
{
    _rotation = rotation;
    _texturedModel.setTransform(MatrixRotateXYZ({
        DEG2RAD*_rotation.x, DEG2RAD*_rotation.y, DEG2RAD*_rotation.z }));
}

void IS::Entity::setScale(float scale)
{
    _scale = scale;
}

void IS::Entity::setColor(Color color, int materialNumber)
{
    if (materialNumber >= _colors.size() || materialNumber < 0)
        return;
    _colors[materialNumber] = color;
}
