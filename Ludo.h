#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "config.h"
#include "Juego.h"
#ifndef LUDO_LUDO_H
#define LUDO_LUDO_H


class Ludo{
private:
    sf::RenderWindow window;
    sf::Texture texture_back;
    sf::RenderWindow *window_puntero;
    sf::Sprite background;
    Juego* juego;
    bool permiso;
    int bloqueo_3_6;
public:
    Ludo();
    void Run();
};


#endif //LUDO_LUDO_H
