#include "Dado.h"
#include<stdlib.h>
#include<ctime>


int Dado::Lanzar(){
    srand(time(nullptr));
    int x = 1 + rand()%6;
    switch (x) {
        case 1:{
            dado_textura.loadFromFile("img/1.png");
            dado_sprite.setTexture(dado_textura);
            break;

        }
        case 2:{
            dado_textura.loadFromFile("img/2.png");
            dado_sprite.setTexture(dado_textura);
            break;

        }
        case 3:{
            dado_textura.loadFromFile("img/3.png");
            dado_sprite.setTexture(dado_textura);
            break;

        }
        case 4:{
            dado_textura.loadFromFile("img/4.png");
            dado_sprite.setTexture(dado_textura);
            break;

        }
        case 5:{
            dado_textura.loadFromFile("img/5.png");
            dado_sprite.setTexture(dado_textura);
            break;

        }
        case 6:{
            dado_textura.loadFromFile("img/6.png");
            dado_sprite.setTexture(dado_textura);
            break;

        }
    }
    return x;
}


Dado::Dado() {

    dado_textura.loadFromFile("img/1.png");

    // Asignamos la textura al sprite
    dado_sprite.setTexture(dado_textura);
    // Movemos el sprite
}

const sf::Texture &Dado::getDadoTextura() const {
    return dado_textura;
}

void Dado::setDadoTextura(const sf::Texture &dadoTextura) {
    dado_textura = dadoTextura;
}

const sf::Sprite &Dado::getDadoSprite() const {
    return dado_sprite;
}

void Dado::setDadoSprite(const sf::Sprite &dadoSprite) {
    dado_sprite = dadoSprite;
}
