#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Dado.h"
#include "Tablero.h"
#include "Jugador.h"

#ifndef LUDO_JUEGO_H
#define LUDO_JUEGO_H

class Juego {
private:
    int turno;
    int numeroJugadores;
    sf::Music music;
    Tablero* tablero;
    Dado* dado;
    Jugador* jugador1;
    Jugador* jugador2;
    Jugador* jugador3;
    Jugador* jugador4;
public:
    Juego(int numeroJugadores);
    void Jugar();
    virtual ~Juego();
    void AumentoTurno();
    Dado *getDado() const;
    int getNumeroJugadores() const;

    Tablero *getTablero() const;

    Jugador *getJugador1() const;

    Jugador *getJugador2() const;

    Jugador *getJugador3() const;

    Jugador *getJugador4() const;

    int getTurno();

};


#endif //LUDO_JUEGO_H
