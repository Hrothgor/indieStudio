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
    SetTargetFPS(60);
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
    TexturedModel texturedModelBomberMan("ressources/bomberman.obj");
    for (int i = 0; i < 0; i++) {
        float x = Maths::randFloat() * 80 - 40;
        float y = Maths::randFloat() * 20;
        float z = Maths::randFloat() * 80 - 40;
        float rotx = Maths::randFloat() * 180;
        float roty = Maths::randFloat() * 180;
        float scale = 0.3;
        //Entity entity(texturedModelDragon, { x, y, z }, { rotx, roty, 0 }, scale);
        //_renderer.addEntity(0, entity);
    }
    _renderer.addEntity(0, Entity(texturedModelDragon, { 0, 0, 0 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { 0, 0, -50 }, { 0, 0, 0 }, 2));

    LightValue light({ 50, 10, -25 }, WHITE);
    _renderer.addLight(light);

    ParticleTexturedModel particleTexturedModelBurn(GenMeshCube(0.5, 0.5, 0.5), "ressources/burn.png", 4);
    ParticleTexturedModel particleTexturedModelSmoke(GenMeshCube(0.5, 0.5, 0.5), "ressources/smoke.png", 8);
    ParticleTexturedModel particleTexturedModelCosmic(GenMeshCube(0.5, 0.5, 0.5), "ressources/cosmic.png", 4);
    ParticleSystem particleSystem1(200, 6, 0.2, 3, 1, "ressources/particleStar.png", &_renderer);
    ParticleSystem particleSystem2(200, 10, 0, 3, 3, particleTexturedModelBurn, &_renderer, IS::PARTICLE_EMISSION::DIRECTIONAL);
    ParticleSystem particleSystem3(300, 2, 0, 8, 5, particleTexturedModelSmoke, &_renderer);
    ParticleSystem particleSystem4(200, 1, 0, 3, 1, particleTexturedModelCosmic, &_renderer, IS::PARTICLE_EMISSION::CIRCLE);

    Camera camera;
    ///////////////////

    ///// 2D INIT /////
    ///////////////////

    while (!WindowShouldClose())
    {
        //// UPDATE GAME ////
        UpdateCamera(camera.getCamera3DPointer());
        particleSystem1.generateParticles({10, 10, -10});

        particleSystem2.generateParticles({-8, 14, 0});
        particleSystem3.generateParticles({-11.7, 16.5, 0});
        particleSystem4.generateParticles({-5, 10, -25});
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