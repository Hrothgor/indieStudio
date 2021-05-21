/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** DisplayManager
*/

#include "DisplayManager.hpp"

IS::DisplayManager::DisplayManager()
{
    //SetTraceLogLevel(TraceLogLevel::LOG_WARNING);
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
    _map = Map("ressources/cubicmap.png", "ressources/cubicmap_atlas.png");

    GLOBAL::_texturedModels["dragon"] = new TexturedModel("dragon");
    GLOBAL::_texturedModels["bomberman"] = new TexturedModel("bomberman");
    GLOBAL::_texturedModels["bomb"] = new TexturedModel("bomb");
    GLOBAL::_texturedModels["crate"] = new TexturedModel("crate");

    GLOBAL::_particleTexturedModels["burn"] = new ParticleTexturedModel(GenMesh::GenMeshSquare(0.5), "ressources/burn.png", 4);
    GLOBAL::_particleTexturedModels["smoke"] = new ParticleTexturedModel(GenMesh::GenMeshSquare(0.5), "ressources/smoke.png", 8);
    GLOBAL::_particleTexturedModels["cosmic"] = new ParticleTexturedModel(GenMesh::GenMeshSquare(0.5), "ressources/cosmic.png", 4);
    GLOBAL::_particleTexturedModels["fire"] = new ParticleTexturedModel(GenMesh::GenMeshSquare(0.5), "ressources/fire.png", 8);

    GLOBAL::_particleSystem["star"] = new ParticleSystem(100, 6, 1, 3, 1, "ressources/particleStar.png", &_3Drenderer);
    GLOBAL::_particleSystem["burn"] = new ParticleSystem(100, 10, 0, 3, 3, *GLOBAL::_particleTexturedModels["burn"], &_3Drenderer, IS::PARTICLE_EMISSION::DIRECTIONAL);
    GLOBAL::_particleSystem["smoke"] = new ParticleSystem(50, 2, 0, 6, 5, *GLOBAL::_particleTexturedModels["smoke"], &_3Drenderer);
    GLOBAL::_particleSystem["cosmic"] = new ParticleSystem(100, 1, 0, 3, 1, *GLOBAL::_particleTexturedModels["cosmic"], &_3Drenderer, IS::PARTICLE_EMISSION::CIRCLE);

    GLOBAL::_particleSystem["smokeFeet"] = new ParticleSystem(15, 2, 0, 3, 15, *GLOBAL::_particleTexturedModels["smoke"], &_3Drenderer, IS::PARTICLE_EMISSION::FLYING);
    GLOBAL::_particleSystem["fireBomb"] = new ParticleSystem(20, 2, 0, 2, 5, *GLOBAL::_particleTexturedModels["fire"], &_3Drenderer);
    GLOBAL::_particleSystem["explosionBomb"] = new ParticleSystem(1, 0, 0, 0.8, 12, *GLOBAL::_particleTexturedModels["cosmic"], &_3Drenderer, IS::PARTICLE_EMISSION::STATIC);

    GLOBAL::_entities.push_back(new Entity(*GLOBAL::_texturedModels["dragon"], { 120, 10, 60 }, { 0, 90, 0 }, 2));
    GLOBAL::_entities.push_back(new Bomberman(Entity(*GLOBAL::_texturedModels["bomberman"], { 10, 0, 10 }, { 0, 0, 0 }, 2), *GLOBAL::_particleSystem["smokeFeet"], {KEY_W, KEY_S, KEY_A, KEY_D, KEY_E}));
    GLOBAL::_entities.push_back(new Bomberman(Entity(*GLOBAL::_texturedModels["bomberman"], { 110, 0, 10 }, { 0, 0, 0 }, 2), *GLOBAL::_particleSystem["smokeFeet"], {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_RIGHT_CONTROL}));
    GLOBAL::_entities.push_back(new Bomberman(Entity(*GLOBAL::_texturedModels["bomberman"], { 10, 0, 110 }, { 0, 0, 0 }, 2), *GLOBAL::_particleSystem["smokeFeet"]));
    GLOBAL::_entities.push_back(new Bomberman(Entity(*GLOBAL::_texturedModels["bomberman"], { 110, 0, 110 }, { 0, 0, 0 }, 2), *GLOBAL::_particleSystem["smokeFeet"]));

    GLOBAL::_lights.push_back(new LightValue({ 2000, 3000, 2000 }, WHITE));
}

void IS::DisplayManager::run()
{
    ///// 3D INIT /////
    load();
    _3Drenderer.addSkybox(Skybox("ressources/skybox.png"));
    _3Drenderer.addLight(*GLOBAL::_lights[0]);

    Camera camera;
    camera.startAnimation({-200, 500, 100}, {60, 100, 150}, {60, 0, 50}, 5);
    ///////////////////

    ///// 2D INIT /////
    ///////////////////

    while (!WindowShouldClose())
    {
        //// UPDATE GAME ////
        camera.update();
        GLOBAL::_particleSystem["burn"]->generateParticles({120, 24, 48});
        ////////////

        for (int i = 0; i < GLOBAL::_entities.size(); i++)
            if (GLOBAL::_entities[i]->IsAlive())
                _3Drenderer.addEntity(0, GLOBAL::_entities[i]);
        BeginDrawing();
        {
            //// 3D ////
            _3Drenderer.render(_actualscene, camera, _map);
            ////////////
            //// 2D ////
            _2Drenderer.render(_actualscene);
            /////////////
        }
        EndDrawing();
    }
    clean();
    CloseWindow();
}

void IS::DisplayManager::clean()
{
    for (auto &texturedModel : GLOBAL::_texturedModels)
        texturedModel.second->clean();
    for (auto &particleTexturedModel : GLOBAL::_particleTexturedModels)
        particleTexturedModel.second->clean();
    GLOBAL::_particleSystem.clear();
    GLOBAL::_entities.clear();
    GLOBAL::_lights.clear();
}