#include <SFML/Graphics.hpp>
#ifndef LUDO_DADO_H
#define LUDO_DADO_H


class Dado {
private:
    sf::Texture dado_textura;
    sf::Sprite dado_sprite;
    int valor;
public:
    Dado();
    int Lanzar();

    const sf::Texture &getDadoTextura() const;

    void setDadoTextura(const sf::Texture &dadoTextura);

    const sf::Sprite &getDadoSprite() const;

    void setDadoSprite(const sf::Sprite &dadoSprite);
};

#endif //LUDO_DADO_H
