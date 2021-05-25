/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Bomb
*/

#include "Bomb.hpp"

IS::Bomb::Bomb(Entity entity, Bomberman *player, ParticleSystem smokeBomb, ParticleSystem explosionBomb)
    : Entity(entity)
{
    _player = player;
    _smokeBomb = smokeBomb;
    _explosionBomb = explosionBomb;
    for (int i = 0; i < 5; i++)
        setColor(_player->getColor(0), i);
    setColor(_player->getColor(1), 5);
    GLOBAL::_sounds["bombFuse"]->play();
}

IS::Bomb::~Bomb()
{
}

void IS::Bomb::checkKillPlayer(int x, int y, Camera *camera)
{
    for (Bomberman *player : GLOBAL::_bombermans) {
        int playerX = (player->getPosition().x + 4) / 10;
        int playerY = (player->getPosition().z + 4) / 10;
        if (playerX == x && playerY == y && player->IsAlive() == true) {
            player->setDeathAnimation(true);
            camera->startAnimation(camera->getPosition(), {player->getPosition().x, 30, player->getPosition().z + 30}, player->getPosition(), 4);
            GLOBAL::_slowfactor = 10;
        }
    }
}

void IS::Bomb::explode(Camera *camera)
{
    _alive = false;
    GLOBAL::_sounds["bombExplosion"]->play();
    int blastRadius = _player->getBlastRadius() + 1;
    int mapX = _position.x / 10;
    int mapY = _position.z / 10;
    for (float x = mapX; x < mapX + blastRadius; x++) {
        _explosionBomb.emitParticle({x * 10, _position.y + 6, _position.z});
        checkKillPlayer(x, mapY, camera);
        if (GLOBAL::_map->TryDestroy(x, mapY))
            break;
    }
    for (float x = mapX; x > mapX - blastRadius; x--) {
        _explosionBomb.emitParticle({x * 10, _position.y + 6, _position.z});
        checkKillPlayer(x, mapY, camera);
        if (GLOBAL::_map->TryDestroy(x, mapY))
            break;
    }
    for (float y = mapY; y < mapY + blastRadius; y++) {
        _explosionBomb.emitParticle({_position.x, _position.y + 6, y * 10});
        checkKillPlayer(mapX, y, camera);
        if (GLOBAL::_map->TryDestroy(mapX, y))
            break;
    }
    for (float y = mapY; y > mapY - blastRadius; y--) {
        _explosionBomb.emitParticle({_position.x, _position.y + 6, y * 10});
        checkKillPlayer(mapX, y, camera);
        if (GLOBAL::_map->TryDestroy(mapX, y))
            break;
    }
}


bool IS::Bomb::update(Camera *camera)
{
    // Vector2 bombScreenPosition = GetWorldToScreen({_position.x, _position.y + 14, _position.z}, camera);
    // int flooredLife = _life.getElapsedTime();
    // std::string lifeTime("Bomb: " + std::to_string(_lifeLenght - flooredLife));
    // float distanceToCam = std::fabs(Vector3Distance(_position, camera.position) / 20) + 1;
    // int sizeFont = 100 * (1/distanceToCam);
    // EndMode3D();
    // DrawText(lifeTime.c_str(), bombScreenPosition.x - MeasureText(lifeTime.c_str(), sizeFont)/2, bombScreenPosition.y, sizeFont, GREEN);
    // BeginMode3D(camera);

    _smokeBomb.generateParticles({_position.x, _position.y + 8, _position.z});
    if ((_lifeLenght -= GetFrameTime()) < 0) {
        GLOBAL::_map->setElement(MAP_TILES::EMPTY, _position.x / 10, _position.z / 10);
        explode(camera);
        _player->bombExplode();
        return (false);
    }
    return (true);
}