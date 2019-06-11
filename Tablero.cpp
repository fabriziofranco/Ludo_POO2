#include "Tablero.h"

Tablero::Tablero() {
    tablero_textura.loadFromFile("img/tablero.png");
    tablero_sprite.setTexture(tablero_textura);
}

const sf::Sprite &Tablero::getTableroSprite() const {
    return tablero_sprite;
}
