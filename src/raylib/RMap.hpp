/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** RMap
*/

#ifndef RMAP_HPP_
    #define RMAP_HPP_

    #include <raylib.h>
    #include <vector>
    #include <random>

    namespace indie {
        class RMap {
            public:
                RMap();
                ~RMap();

                void draw(Camera3D camera);
                Vector3 calcul(int number, Vector3 mapPosition2);
                int RMap::verif(std::vector <int> tab, int temp);
                std::vector <int> aleatoire();
            protected:
            private:
                Color *_mapPixels;
                Texture2D _cubicmap;
                Texture2D _texture;
                Model _model;
                Texture2D _cubicmap_wood;
                Texture2D _texture_wood;
                Model _model_wood;
                Vector3 _mapPos;
                Vector3 _mapPos2;
                Vector3 _mapPos3;
                std::vector<int> tab = this->aleatoire();
        };
    }

#endif /* !RMAP_HPP_ */
