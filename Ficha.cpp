#include "Ficha.h"


Ficha::Ficha(int jugadorasignado) : jugadorasignado(jugadorasignado) {
    estado="c";
    posicion=-2;
    switch (jugadorasignado) {
        case 1:{
            texture_ficha.loadFromFile("img/ficharoja.png");
            sprite_ficha.setTexture(texture_ficha);
            break;

        }
        case 2:{
            texture_ficha.loadFromFile("img/fichaverde.png");
            sprite_ficha.setTexture(texture_ficha);
            break;
        }
        case 3:{
            texture_ficha.loadFromFile("img/fichaazul.png");
            sprite_ficha.setTexture(texture_ficha);
            break;

        }
        case 4:{
            texture_ficha.loadFromFile("img/fichaamarilla.png");
            sprite_ficha.setTexture(texture_ficha);
            break;

        }}
}

const sf::Sprite &Ficha::getSpriteFicha() const {
    return sprite_ficha;
}

Ficha::~Ficha() {

}

const std::string &Ficha::getEstado() const {
    return estado;
}

void Ficha::setEstado(const std::string &estado) {
    Ficha::estado = estado;
}

void Ficha::setPosicion(int posicion) {
    Ficha::posicion = posicion;
}

int Ficha::getPosicion() const {
    return posicion;
}
