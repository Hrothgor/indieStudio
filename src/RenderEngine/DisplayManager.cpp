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
    Image image = LoadImage("ressources/cubicmap.png");
    Texture2D cubicmap = LoadTextureFromImage(image);

    Mesh mesh = GenMeshCubicmap(image, {1.0, 1.0, 1.0});
    Model model = LoadModelFromMesh(mesh);

    Texture2D texture = LoadTexture("ressources/cubicmap_atlas.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    UnloadImage(image);
    _entities.push_back(new Entity(TexturedModel(mesh, "ressources/cubicmap_atlas.png"), {-60, 0, -60}, {0,0,0}, 10));

    _texturedModels["dragon"] = TexturedModel("dragon");
    _texturedModels["bomberman"] = TexturedModel("bomberman");
    _texturedModels["bomb"] = TexturedModel("bomb");

    _particleTexturedModels["burn"] = ParticleTexturedModel(GenMesh::GenMeshSquare(0.5), "ressources/burn.png", 4);
    _particleTexturedModels["smoke"] = ParticleTexturedModel(GenMesh::GenMeshSquare(0.5), "ressources/smoke.png", 8);
    _particleTexturedModels["cosmic"] = ParticleTexturedModel(GenMesh::GenMeshSquare(0.5), "ressources/cosmic.png", 4);
    _particleTexturedModels["fire"] = ParticleTexturedModel(GenMesh::GenMeshSquare(0.5), "ressources/fire.png", 8);

    _particleSystem["star"] = ParticleSystem(100, 6, 1, 3, 1, "ressources/particleStar.png", &_3Drenderer);
    _particleSystem["burn"] = ParticleSystem(100, 10, 0, 3, 3, _particleTexturedModels["burn"], &_3Drenderer, IS::PARTICLE_EMISSION::DIRECTIONAL);
    _particleSystem["smoke"] = ParticleSystem(50, 2, 0, 6, 5, _particleTexturedModels["smoke"], &_3Drenderer);
    _particleSystem["cosmic"] = ParticleSystem(100, 1, 0, 3, 1, _particleTexturedModels["cosmic"], &_3Drenderer, IS::PARTICLE_EMISSION::CIRCLE);

    _particleSystem["smokeFeet"] = ParticleSystem(15, 2, 0, 3, 15, _particleTexturedModels["smoke"], &_3Drenderer, IS::PARTICLE_EMISSION::FLYING);
    _particleSystem["fireBomb"] = ParticleSystem(20, 2, 0, 2, 5, _particleTexturedModels["fire"], &_3Drenderer);
    _particleSystem["explosionBomb"] = ParticleSystem(5000, 4, 0, 2, 3, _particleTexturedModels["cosmic"], &_3Drenderer, IS::PARTICLE_EMISSION::CIRCLE);

    _entities.push_back(new Entity(_texturedModels["dragon"], { 60, 10, 0 }, { 0, 90, 0 }, 2));
    _entities.push_back(new Bomberman(Entity(_texturedModels["bomberman"], { -50, 0, -50 }, { 0, 0, 0 }, 2), _particleSystem["smokeFeet"]));
    _entities.push_back(new Bomberman(Entity(_texturedModels["bomberman"], { -30, 0, -50 }, { 0, 0, 0 }, 2), _particleSystem["smokeFeet"]));
    _entities.push_back(new Bomberman(Entity(_texturedModels["bomberman"], { -10, 0, -50 }, { 0, 0, 0 }, 2), _particleSystem["smokeFeet"]));
    _entities.push_back(new Bomb(Entity(_texturedModels["bomb"], { 10, 10, -50 }, { 0, 0, 0 }, 2), _particleSystem["fireBomb"], _particleSystem["explosionBomb"]));
    _entities.push_back(new Bomb(Entity(_texturedModels["bomb"], { 20, 10, -50 }, { 0, 0, 0 }, 2), _particleSystem["fireBomb"], _particleSystem["explosionBomb"]));
    _entities.push_back(new Bomb(Entity(_texturedModels["bomb"], { 30, 10, -50 }, { 0, 0, 0 }, 2), _particleSystem["fireBomb"], _particleSystem["explosionBomb"]));
    _entities.push_back(new Bomb(Entity(_texturedModels["bomb"], { 40, 10, -50 }, { 0, 0, 0 }, 2), _particleSystem["fireBomb"], _particleSystem["explosionBomb"]));
    _entities.push_back(new Bomb(Entity(_texturedModels["bomb"], { 50, 10, -50 }, { 0, 0, 0 }, 2), _particleSystem["fireBomb"], _particleSystem["explosionBomb"]));

    _lights.push_back(LightValue({ 2000, 3000, 2000 }, WHITE));
}

void IS::DisplayManager::clean()
{
    for (auto &texturedModel : _texturedModels)
        texturedModel.second.clean();
    for (auto &particleTexturedModel : _particleTexturedModels)
        particleTexturedModel.second.clean();
    _particleSystem.clear();
    _entities.clear();
    _lights.clear();
}

void IS::DisplayManager::run()
{
    load();
    ///// 3D INIT /////
    _3Drenderer.addSkybox(Skybox("ressources/skybox.png"));
    _3Drenderer.addLight(_lights[0]);

    Camera camera;
    camera.startAnimation({-200, 500, 100}, {0,30, 50}, {12,14,0}, 5);
    ///////////////////

    ///// 2D INIT /////
    ///////////////////

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_SPACE))
            _entities.push_back(new Bomb(Entity(_texturedModels["bomb"], { Maths::randFloat() * 100 - 50, 10, Maths::randFloat() * 100 - 50 }, { 0, 0, 0 }, 2), _particleSystem["fireBomb"], _particleSystem["explosionBomb"]));
        //// UPDATE GAME ////
        camera.update();
        _particleSystem["star"].generateParticles({0, 40, -20});
        _particleSystem["burn"].generateParticles({60, 24, -12});
        // _particleSystem["smoke"].generateParticles({-11.7, 16.5, 0});
        // _particleSystem["cosmic"].generateParticles({-5, 10, -25});
        ////////////
        for (int i = 0; i < _entities.size(); i++)
            if (_entities[i]->IsAlive())
                _3Drenderer.addEntity(0, _entities[i]);

        BeginDrawing();
        {
            //// 3D ////
            _3Drenderer.render(_actualscene, camera);
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