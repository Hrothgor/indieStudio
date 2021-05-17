/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** DisplayManager
*/

#include "DisplayManager.hpp"

IS::DisplayManager::DisplayManager()
//    : _thread(&IS::DisplayManager::LoadData, this)
{
    InitWindow(WIDTH, HEIGHT, "Indie Studio Window");
    SetTargetFPS(120);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
	ToggleFullscreen();
}

IS::DisplayManager::~DisplayManager()
{
}

void IS::DisplayManager::LoadData()
{
    TexturedModel texturedModelDragon("ressources/dragon.obj", "ressources/dragon.png");
    TexturedModel texturedModelBomberMan("ressources/bomberman.obj");

    _progress = 10;
    sleep(1);

    Entity bombermanTest(texturedModelBomberMan, { -50, 0, -50 }, { 0, 0, 0 }, 2);
    _renderer.addEntity(0, Entity(texturedModelDragon, { 0, 0, 0 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, bombermanTest);
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { -40, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { -30, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { -20, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { -10, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { 0, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { 10, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { 20, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { 30, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { 40, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { 50, 0, -50 }, { 0, 0, 0 }, 2));

    _progress = 40;
    sleep(1);

    int animsCount = 0;
    ModelAnimation *anims = LoadModelAnimations("ressources/bomberman.obj", &animsCount);
    int animFrameCounter = 0;

    LightValue light({ 0, 75, 0 }, WHITE);
    _renderer.addLight(light);

    _progress = 70;
    sleep(1);

    ParticleTexturedModel particleTexturedModelBurn(GenMeshCube(0.5, 0.5, 0.5), "ressources/burn.png", 4);
    ParticleTexturedModel particleTexturedModelSmoke(GenMeshCube(0.5, 0.5, 0.5), "ressources/smoke.png", 8);
    ParticleTexturedModel particleTexturedModelCosmic(GenMeshCube(0.5, 0.5, 0.5), "ressources/cosmic.png", 4);
    ParticleSystem particleSystem1(100, 6, 0.2, 3, 1, "ressources/particleStar.png", &_renderer);
    ParticleSystem particleSystem2(100, 10, 0, 3, 3, particleTexturedModelBurn, &_renderer, IS::PARTICLE_EMISSION::DIRECTIONAL);
    ParticleSystem particleSystem3(150, 2, 0, 8, 5, particleTexturedModelSmoke, &_renderer);
    ParticleSystem particleSystem4(100, 1, 0, 3, 1, particleTexturedModelCosmic, &_renderer, IS::PARTICLE_EMISSION::CIRCLE);

    _progress = 100;
    sleep(1);
    _thread.detach();
}

void IS::DisplayManager::run()
{
    ///// 3D INIT /////
    TexturedModel texturedModelDragon("ressources/dragon.obj", "ressources/dragon.png");
    TexturedModel texturedModelBomberMan("ressources/bomberman.obj");

    Entity bombermanTest(texturedModelBomberMan, { -50, 0, -50 }, { 0, 0, 0 }, 2);
    _renderer.addEntity(0, Entity(texturedModelDragon, { 0, 0, 0 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, bombermanTest);
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { -40, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { -30, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { -20, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { -10, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { 0, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { 10, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { 20, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { 30, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { 40, 0, -50 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, Entity(texturedModelBomberMan, { 50, 0, -50 }, { 0, 0, 0 }, 2));

    int animsCount = 0;
    ModelAnimation *anims = LoadModelAnimations("ressources/bomberman.obj", &animsCount);
    int animFrameCounter = 0;

    LightValue light({ 0, 75, 0 }, WHITE);
    _renderer.addLight(light);

    ParticleTexturedModel particleTexturedModelBurn(GenMeshCube(0.5, 0.5, 0.5), "ressources/burn.png", 4);
    ParticleTexturedModel particleTexturedModelSmoke(GenMeshCube(0.5, 0.5, 0.5), "ressources/smoke.png", 8);
    ParticleTexturedModel particleTexturedModelCosmic(GenMeshCube(0.5, 0.5, 0.5), "ressources/cosmic.png", 4);
    ParticleSystem particleSystem1(100, 6, 0.2, 3, 1, "ressources/particleStar.png", &_renderer);
    ParticleSystem particleSystem2(100, 10, 0, 3, 3, particleTexturedModelBurn, &_renderer, IS::PARTICLE_EMISSION::DIRECTIONAL);
    ParticleSystem particleSystem3(150, 2, 0, 8, 5, particleTexturedModelSmoke, &_renderer);
    ParticleSystem particleSystem4(100, 1, 0, 3, 1, particleTexturedModelCosmic, &_renderer, IS::PARTICLE_EMISSION::CIRCLE);

    Camera camera;
    ///////////////////

    ///// 2D INIT /////
    ///////////////////

    _progress = 0;
    int framesCounter = 0;
    while (!WindowShouldClose())
    {
        //// UPDATE GAME ////
        UpdateCamera(camera.getCamera3DPointer());
        particleSystem1.generateParticles({10, 10, -10});

        particleSystem2.generateParticles({-8, 14, 0});
        particleSystem3.generateParticles({-11.7, 16.5, 0});
        particleSystem4.generateParticles({-5, 10, -25});

        if (IsKeyDown(KEY_SPACE))
        {
            // animFrameCounter++;
            // UpdateModelAnimation(bombermanTest.getTexturedModel().getModel(), anims[4], animFrameCounter);
            // if (animFrameCounter >= anims[0].frameCount) animFrameCounter = 0;
        }
        ////////////
        BeginDrawing();
            // if (_progress != 100) {
            //     framesCounter++;
            //     ClearBackground(RAYWHITE);
            //     DrawRectangle(WIDTH / 2 - 250, HEIGHT / 2 - 30, _progress * 5, 60, SKYBLUE);
            //     if ((framesCounter/15)%2) DrawText("LOADING DATA...", WIDTH / 2 - 250 + 90, HEIGHT / 2 - 30 + 10, 40, DARKBLUE);
            //     DrawRectangleLines(WIDTH / 2 - 250, HEIGHT / 2 - 30, 500, 60, DARKGRAY);
            // } else {
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