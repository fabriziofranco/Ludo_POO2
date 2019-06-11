#include "Juego.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
Juego::Juego(int numeroJugadores)
{   turno=1;
    this->numeroJugadores=numeroJugadores;
    music.openFromFile("sounds/back_music.ogg");
    music.setLoop(true);
    music.play();
    //music.setVolume(0); Descomentar al acabar el juego
    dado=new Dado();
    tablero=new Tablero();
    switch (numeroJugadores){
        case 2:
            jugador1=new Jugador(1);jugador2=new Jugador(2);break;
        case 3:
            jugador1=new Jugador(1);jugador2=new Jugador(2);jugador3=new Jugador(3);break;
        case 4:
            jugador1=new Jugador(1);jugador2=new Jugador(2);jugador3=new Jugador(3);jugador4=new Jugador(4);break;
    }
}

int Juego::getTurno(){
    return turno;
}

Tablero *Juego::getTablero() const {
    return tablero;
}
void Juego::AumentoTurno() {
    turno++;
    if(turno>numeroJugadores)
        turno=1;
}
void Juego::Jugar() {
    switch(turno){
        case 1:{
            jugador1->setMovimimientos(getDado()->Lanzar());
            break;
        }
        case 2:{
            jugador2->setMovimimientos(getDado()->Lanzar());
            break;
        }
        case 3:{
            jugador3->setMovimimientos(getDado()->Lanzar());
            break;
        }
        case 4:{
            jugador4->setMovimimientos(getDado()->Lanzar());
            break;
        }

    }}
Juego::~Juego()=default;

Dado *Juego::getDado() const {
    return dado;
}


int Juego::getNumeroJugadores() const {
    return numeroJugadores;
}

Jugador *Juego::getJugador1() const {
    return jugador1;
}

Jugador *Juego::getJugador2() const {
    return jugador2;
}

Jugador *Juego::getJugador3() const {
    return jugador3;
}

Jugador *Juego::getJugador4() const {
    return jugador4;
}

