#include <SFML/Graphics.hpp>
#ifndef PROYECTO_POO_II_TABLERO_H
#define PROYECTO_POO_II_TABLERO_H


class Tablero {
private:
    sf::Texture tablero_textura;
    sf::Sprite tablero_sprite;
public:
    Tablero();

    const sf::Sprite &getTableroSprite() const;
};


#endif //PROYECTO_POO_II_TABLERO_H
