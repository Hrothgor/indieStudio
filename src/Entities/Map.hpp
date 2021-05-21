/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "../global.hpp"
#include "../Models/TexturedModel.hpp"

namespace IS {
    enum MAP_TILES {
        EMPTY = 0,
        BLOCK,
        CRATE,
    };

    class Map {
        public:
            Map() {};
            Map(const std::string &cubicMapPath, const std::string &texturePath);
            ~Map();

            void render();

            bool IsCorner(int x, int y);
            void createCollisionFromImage(Image image);
            bool IsEmpty(int x, int y);
            bool TryDestroy(int x, int y);

            Model getModel() const;
            int getHeight() const;
            int getWidth() const;

            void setModel(Model model);

        protected:
        private:
            Model _model;
            int _height;
            int _width;
            std::vector<std::vector<MAP_TILES>> _2DMap;
    };
}

#endif /* !MAP_HPP_ */
