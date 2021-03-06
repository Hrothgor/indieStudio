/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Map
*/

#include "Map.hpp"
#include "PowerUp.hpp"

IS::Map::Map(const std::string &cubicMapPath, const std::string &texturePath)
{
    Image image = LoadImage(cubicMapPath.c_str());
    Texture2D cubicmap = LoadTextureFromImage(image);

    Mesh mesh = GenMeshCubicmap(image, {1.0, 1.0, 1.0});
    _model = LoadModelFromMesh(mesh);
    _width = image.width;
    _height = image.height;
    createCollisionFromImage(image);

    Texture2D texture = LoadTexture(texturePath.c_str());
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    UnloadImage(image);
}

IS::Map::~Map()
{
}

void IS::Map::render()
{
    Model crate = GLOBAL::_texturedModels["crate"]->getModel();
    DrawModel(_model, {0, 0, 0}, 10, WHITE);
    for (float y = 0; y < _height; y++) {
        for (float x = 0; x < _width; x++) {
            if (_2DMap[y][x] == CRATE)
                DrawModel(crate, {x * 10, 0, y * 10}, 1, WHITE);
        }
    }
}

void IS::Map::addElement(MAP_TILES elem, int x, int y)
{
    if (y < 0 || y >= _height || x < 0 || x >= _width)
        return;
    _2DMap[y][x] = elem;
}

bool IS::Map::IsCorner(int x, int y)
{
    if (y == 1 && x == 1 ||
        y == 2 && x == 1 ||
        y == 1 && x == 2)
        return (true);
    if (y == _height - 1 - 1 && x == 1 ||
        y == _height - 2 - 1 && x == 1 ||
        y == _height - 1 - 1 && x == 2)
        return (true);
    if (y == 1 && x == _width - 1 - 1 ||
        y == 2 && x == _width - 1 - 1 ||
        y == 1 && x == _width - 2 - 1)
        return (true);
    if (y == _height - 1 - 1 && x == _width - 1 - 1 ||
        y == _height - 2 - 1 && x == _width - 1 - 1 ||
        y == _height - 1 - 1 && x == _width - 2 - 1)
        return (true);
    return (false);
}

void IS::Map::createCollisionFromImage(Image image)
{
    Color *pixels = LoadImageColors(image);

    for (int y = 0; y < _height; y++) {
        _2DMap.push_back(std::vector<MAP_TILES>(_width, BLOCK));
        for (int x = 0; x < _width; x++) {
            if (pixels[_height * y + x].r == BLACK.r &&
            pixels[_height * y + x].g == BLACK.g &&
            pixels[_height * y + x].b == BLACK.b) {
                _2DMap[y][x] = IsCorner(x, y) ? EMPTY : CRATE;
            }
        }
    }
}

bool IS::Map::IsEmpty(int x, int y)
{
    if (y < 0 || y >= _height || x < 0 || x >= _width)
        return (false);
    if (_2DMap[y][x] == EMPTY)
        return (true);
    return (false);
}

void IS::Map::spawnPowerUp(int x, int y)
{
    if (rand() % 3 == 0) {
        int powerUp = rand() % 3;
        float posX = x * 10;
        float posY = y * 10;
        switch (powerUp)
        {
        case 0:
            GLOBAL::_powerups.push_back(new PowerUp(Entity(*GLOBAL::_texturedModels["powerUpBlastRadius"], { posX, 4, posY }, { 0, 0, 0 }, 1), POWER_TYPE::FIRE, *GLOBAL::_particleSystem["shinyPowerUp"]));
            break;
        case 1:
            GLOBAL::_powerups.push_back(new PowerUp(Entity(*GLOBAL::_texturedModels["powerUpIncreaseBomb"], { posX, 4, posY }, { 0, 0, 0 }, 1), POWER_TYPE::MOREBOMB, *GLOBAL::_particleSystem["shinyPowerUp"]));
            break;
        case 2:
            GLOBAL::_powerups.push_back(new PowerUp(Entity(*GLOBAL::_texturedModels["powerUpSpeedUp"], { posX, 4, posY }, { 0, 0, 0 }, 1), POWER_TYPE::SPEED, *GLOBAL::_particleSystem["shinyPowerUp"]));
            break;
        case 3:
            GLOBAL::_powerups.push_back(new PowerUp(Entity(*GLOBAL::_texturedModels["powerUpSoftPass"], { posX, 4, posY }, { 0, 0, 0 }, 1), POWER_TYPE::SOFTPASS, *GLOBAL::_particleSystem["shinyPowerUp"]));
            break;
        default:
            break;
        }
    }
}

bool IS::Map::TryDestroy(int x, int y)
{
    if (!IsEmpty(x, y)) {
        if (_2DMap[y][x] == CRATE) {
            spawnPowerUp(x, y);
            _2DMap[y][x] = EMPTY;
        }
        return (true);
    }
    return (false);
}

Model IS::Map::getModel() const
{
    return (_model);
}

int IS::Map::getHeight() const
{
    return (_height);
}

int IS::Map::getWidth() const
{
    return (_width);
}

IS::MAP_TILES IS::Map::getElement(int x, int y) const
{
    if (y < 0 || y >= _height || x < 0 || x >= _width)
        return (MAP_TILES::EMPTY);
    return (_2DMap[y][x]);
}

void IS::Map::setModel(Model model)
{
    _model = model;
}

void IS::Map::setElement(MAP_TILES elem, int x, int y)
{
    if (y < 0 || y >= _height || x < 0 || x >= _width)
        return;
    _2DMap[y][x] = elem;
}
