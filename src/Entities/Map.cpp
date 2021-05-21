/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Map
*/

#include "Map.hpp"

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
            if (_collisionMap[y][x] == CRATE)
                DrawModel(crate, {x * 10, 0, y * 10}, 1, WHITE);
        }
    }
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
        _collisionMap.push_back(std::vector<MAP_TILES>(_width, BLOCK));
        for (int x = 0; x < _width; x++) {
            if (pixels[_height * y + x].r == BLACK.r &&
            pixels[_height * y + x].g == BLACK.g &&
            pixels[_height * y + x].b == BLACK.b) {
                _collisionMap[y][x] = IsCorner(x, y) ? EMPTY : CRATE;
            }
        }
    }
}

bool IS::Map::IsEmpty(int x, int y)
{
    if (y < 0 || y >= _height || x < 0 || x >= _width)
        return (false);
    if (_collisionMap[y][x] == EMPTY)
        return (true);
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

void IS::Map::setModel(Model model)
{
    _model = model;
}