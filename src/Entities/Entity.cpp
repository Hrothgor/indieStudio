/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Entity
*/

#include "Entity.hpp"

Color listColor[10] = { GREEN, YELLOW, RED, BLACK, WHITE, ORANGE, BEIGE, MAROON, LIME, PINK };

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
        color = listColor[rand() % 10];
}

IS::Entity::~Entity()
{
}

void IS::Entity::update()
{
    int i = 0;

    for (Color color : _colors)
        _texturedModel.setColor(color, i++);
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

void IS::Entity::setTexturedModel(TexturedModel texturedModel)
{
    _texturedModel = texturedModel;
}

void IS::Entity::setPosition(Vector3 position)
{
    _position = position;
}

void IS::Entity::setRotation(Vector3 rotation)
{
    _rotation = rotation;
}

void IS::Entity::setScale(float scale)
{
    _scale = scale;
}

void IS::Entity::setColor(Color color, int materialNumber)
{
    _colors[materialNumber] = color;
}
