/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** DisplayManager
*/

#include "DisplayManager.hpp"

IS::DisplayManager::DisplayManager()
{
    InitWindow(WIDTH, HEIGHT, "Indie Studio Window");
    SetTargetFPS(120);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
	ToggleFullscreen();
}

IS::DisplayManager::~DisplayManager()
{
}

void IS::DisplayManager::run()
{
    ///// 3D INIT /////
    TexturedModel texturedModelDragon("ressources/dragon.obj", "ressources/dragon.png");
    for (int i = 0; i < 20; i++) {
        float x = Maths::randFloat() * 80 - 40;
        float y = Maths::randFloat() * 20;
        float z = Maths::randFloat() * 80 - 40;
        float rotx = Maths::randFloat() * 180;
        float roty = Maths::randFloat() * 180;
        float scale = 0.3;
        Entity entity(texturedModelDragon, { x, y, z }, { rotx, roty, 0 }, scale);
        _renderer.addEntity(0, entity);
    }
    _renderer.addEntity(0, Entity(texturedModelDragon, { 0, 0, 0 }, { 0, 0, 0 }, 2));

    LightValue light({ 2000, 3000, -2000 }, WHITE);
    _renderer.addLight(light);

    Camera camera;
    ///////////////////

    ///// 2D INIT /////
    ///////////////////

    while (!WindowShouldClose())
    {
        //// UPDATE ////
        UpdateCamera(camera.getCamera3DPointer());
        ////////////
        BeginDrawing();
            //// 3D ////
            _renderer.render(0, camera);
            ////////////
            //// 2D ////
            DrawText(std::to_string(GetFPS()).c_str(), 0, 0, 50, RED);
            /////////////
        EndDrawing();
    }
    CloseWindow();
}