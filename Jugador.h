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
using par = std::pair<float, float>;
using pares_ordenados = std::vector<par>;
class Jugador {
private:
    int numeroJugador;
    int puntos;
    int movimimientos;
    Recorrido* recorrido_jugador;
    sf::Vector2<float>* c[4];sf::Vector2<float>* salida;
    Ficha* ficha[4];
public:
    Jugador(int numeroJugador);

    virtual ~Jugador();

    void setMovimimientos(int movimimientos);

    int getNumeroJugador() const;

    sf::Vector2<float> *getC(int i) const;

    sf::Vector2<float> *getSalida() const;

    Ficha *getFicha(int i) const;

    Ficha *getFicha2(int i) const;

    Ficha *getFicha3(int i) const;

    Ficha *getFicha4(int i) const;

    int getMovimimientos() const;

    int getPuntos() const;

    Recorrido *getRecorridoJugador() const;


};


#endif //PROYECTO_POO_II_JUGADOR_H
