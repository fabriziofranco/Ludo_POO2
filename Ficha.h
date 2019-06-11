#include <string>
#include <SFML/Graphics.hpp>
#ifndef prueba_FICHA_H
#define prueba_FICHA_H


class Ficha {
private:
    int jugadorasignado;
    std::string estado; //C de casa, N de normal, S de seguro y F es casilla final
    int posicion;
    sf::Sprite sprite_ficha;
    sf::Texture texture_ficha;
public:
    Ficha(int jugadorasignado);
    const sf::Sprite &getSpriteFicha() const;
    const std::string &getEstado() const;
    virtual ~Ficha();

    int getPosicion() const;

    void setEstado(const std::string &estado);

    void aumento_de_posicion(int aumento);
    void setPosicion(int posicion);
};


#endif //prueba_FICHA_H


