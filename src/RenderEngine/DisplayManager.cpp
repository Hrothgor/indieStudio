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

void IS::DisplayManager::load()
{
    _texturedModels["dragon"] = TexturedModel("dragon");
    _texturedModels["bomberman"] = TexturedModel("bomberman");
    _texturedModels["bomb"] = TexturedModel("bomb");

    _particleTexturedModels["burn"] = ParticleTexturedModel(GenMeshCube(0.5, 0.5, 0.5), "ressources/burn.png", 4);
    _particleTexturedModels["smoke"] = ParticleTexturedModel(GenMeshCube(0.5, 0.5, 0.5), "ressources/smoke.png", 8);
    _particleTexturedModels["cosmic"] = ParticleTexturedModel(GenMeshCube(0.5, 0.5, 0.5), "ressources/cosmic.png", 4);
    _particleTexturedModels["fire"] = ParticleTexturedModel(GenMeshCube(0.5, 0.5, 0.5), "ressources/fire.png", 8);
}

void IS::DisplayManager::run()
{
    load();
    ///// 3D INIT /////
    LightValue light({ 0, 75, 0 }, WHITE);
    _renderer.addLight(light);

    ParticleSystem particleSystem1(100, 6, 1, 3, 1, "ressources/particleStar.png", &_renderer);
    ParticleSystem particleSystem2(100, 10, 0, 3, 3, _particleTexturedModels["burn"], &_renderer, IS::PARTICLE_EMISSION::DIRECTIONAL);
    ParticleSystem particleSystem3(50, 2, 0, 6, 5, _particleTexturedModels["smoke"], &_renderer);
    ParticleSystem particleSystem4(100, 1, 0, 3, 1, _particleTexturedModels["cosmic"], &_renderer, IS::PARTICLE_EMISSION::CIRCLE);

    ParticleSystem particleSystemSmoke(15, 2, 0, 3, 15, _particleTexturedModels["smoke"], &_renderer, IS::PARTICLE_EMISSION::FLYING);
    ParticleSystem particleSystemFire(20, 2, 0, 2, 5, _particleTexturedModels["fire"], &_renderer);
    ParticleSystem particleSystemExplosion(5000, 4, 0, 2, 3, _particleTexturedModels["cosmic"], &_renderer, IS::PARTICLE_EMISSION::CIRCLE);

    _renderer.addEntity(0, new Entity(_texturedModels["dragon"], { 20, 0, 0 }, { 0, 0, 0 }, 2));
    _renderer.addEntity(0, new Bomberman(Entity(_texturedModels["bomberman"], { -50, 0, -50 }, { 0, 0, 0 }, 2), particleSystemSmoke));
    _renderer.addEntity(0, new Bomberman(Entity(_texturedModels["bomberman"], { -40, 0, -50 }, { 0, 0, 0 }, 2), particleSystemSmoke));
    _renderer.addEntity(0, new Bomberman(Entity(_texturedModels["bomberman"], { -30, 0, -50 }, { 0, 0, 0 }, 2), particleSystemSmoke));
    _renderer.addEntity(0, new Bomb(Entity(_texturedModels["bomb"], { 10, 0, -50 }, { 0, 0, 0 }, 2), particleSystemFire, particleSystemExplosion));
    _renderer.addEntity(0, new Bomb(Entity(_texturedModels["bomb"], { 20, 0, -50 }, { 0, 0, 0 }, 2), particleSystemFire, particleSystemExplosion));
    _renderer.addEntity(0, new Bomb(Entity(_texturedModels["bomb"], { 30, 0, -50 }, { 0, 0, 0 }, 2), particleSystemFire, particleSystemExplosion));
    _renderer.addEntity(0, new Bomb(Entity(_texturedModels["bomb"], { 40, 0, -50 }, { 0, 0, 0 }, 2), particleSystemFire, particleSystemExplosion));
    _renderer.addEntity(0, new Bomb(Entity(_texturedModels["bomb"], { 50, 0, -50 }, { 0, 0, 0 }, 2), particleSystemFire, particleSystemExplosion));

    Camera camera;
    camera.startAnimation({0, 100, 0}, {0,10,-40}, {12,14,0}, 4);

    ///////////////////

    ///// 2D INIT /////
    ///////////////////

    float _playerPosZ = -50;
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ONE))
            camera.startAnimation(camera.getPosition(), {-20,10,50}, {12,14,0}, 5);
        //// UPDATE GAME ////
        camera.update();
        // particleSystem1.generateParticles({10, 10, -10});
        particleSystem2.generateParticles({12, 14, 0});
        // particleSystem3.generateParticles({-11.7, 16.5, 0});
        // particleSystem4.generateParticles({-5, 10, -25});
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