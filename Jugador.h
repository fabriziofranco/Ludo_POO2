#include "Ficha.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include "Recorrido.h"
#include <SFML/Graphics.hpp>
#ifndef PROYECTO_POO_II_JUGADOR_H
#define PROYECTO_POO_II_JUGADOR_H

using namespace std;
using par = std::pair<float, float >;
using pares_ordenados = std::vector<par>;
class Jugador {
private:
    int numeroJugador;
    int puntos;
    int movimimientos;
    Recorrido* recorrido_jugador;
    sf::Vector2<float>* c1;sf::Vector2<float>* c2;
    sf::Vector2<float>* c3;sf::Vector2<float>* c4;sf::Vector2<float>* salida;
    Ficha* ficha1;Ficha* ficha2;Ficha* ficha3;Ficha* ficha4;
public:
    Jugador(int numeroJugador);

    virtual ~Jugador();

    void setMovimimientos(int movimimientos);

    int getNumeroJugador() const;

    sf::Vector2<float> *getC1() const;

    sf::Vector2<float> *getC2() const;

    sf::Vector2<float> *getC3() const;

    sf::Vector2<float> *getC4() const;

    sf::Vector2<float> *getSalida() const;

    Ficha *getFicha1() const;

    Ficha *getFicha2() const;

    Ficha *getFicha3() const;

    Ficha *getFicha4() const;

    int getMovimimientos() const;

    int getPuntos() const;

    Recorrido *getRecorridoJugador() const;


};


#endif //PROYECTO_POO_II_JUGADOR_H
