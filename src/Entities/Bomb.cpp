/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Bomb
*/

#include "Bomb.hpp"

IS::Bomb::Bomb(Entity entity, ParticleSystem smokeBomb, ParticleSystem explosionBomb, Color color1, Color color2)
    : Entity(entity)
{
    _smokeBomb = smokeBomb;
    _explosionBomb = explosionBomb;
    for (int i = 0; i < 5; i++)
        setColor(color1, i);
    setColor(color2, 5);
}

IS::Bomb::~Bomb()
{
}

void IS::Bomb::explode(Map &map)
{
    _alive = false;
    int mapX = _position.x / 10;
    int mapY = _position.z / 10;
    for (float x = mapX + 1; x < mapX + 4; x++) {
        _explosionBomb.emitParticle({x * 10, _position.y + 6, _position.z});
        if (map.TryDestroy(x, mapY))
            break;
    }
    for (float x = mapX - 1; x > mapX - 4; x--) {
        _explosionBomb.emitParticle({x * 10, _position.y + 6, _position.z});
        if (map.TryDestroy(x, mapY))
            break;
    }
    for (float y = mapY + 1; y < mapY + 4; y++) {
        _explosionBomb.emitParticle({_position.x, _position.y + 6, y * 10});
        if (map.TryDestroy(mapX, y))
            break;
    }
    for (float y = mapY - 1; y > mapY - 4; y--) {
        _explosionBomb.emitParticle({_position.x, _position.y + 6, y * 10});
        if (map.TryDestroy(mapX, y))
            break;
    }
}


bool IS::Bomb::update(Camera3D camera, Map &map)
{
    IS::Entity::update(camera, map);
    // Vector2 bombScreenPosition = GetWorldToScreen({_position.x, _position.y + 14, _position.z}, camera);
    // int flooredLife = _life.getElapsedTime();
    // std::string lifeTime("Bomb: " + std::to_string(_lifeLenght - flooredLife));
    // float distanceToCam = std::fabs(Vector3Distance(_position, camera.position) / 20) + 1;
    // int sizeFont = 100 * (1/distanceToCam);
    // EndMode3D();
    // DrawText(lifeTime.c_str(), bombScreenPosition.x - MeasureText(lifeTime.c_str(), sizeFont)/2, bombScreenPosition.y, sizeFont, GREEN);
    // BeginMode3D(camera);

    _smokeBomb.generateParticles({_position.x, _position.y + 8, _position.z});
    if (_life.getElapsedTime() > _lifeLenght) {
        explode(map);
        return (false);
    }
    return (true);
}