#include "Jugador.h"

Jugador::Jugador(int numeroJugador) : numeroJugador(numeroJugador) {
    movimimientos=0;
    switch (numeroJugador){
        case 1:{
            c1= new sf::Vector2<float>(613,230);
            c2= new sf::Vector2<float>(613,305.5);
            c3= new sf::Vector2<float>(650.75,267.75);
            c4= new sf::Vector2<float>(575.25,267.75);
            salida= new sf::Vector2<float>(480,213);
            break;
        }
        case 2:{
            c1= new sf::Vector2<float>(273.25,230);
            c2= new sf::Vector2<float>(273.25,305.5);
            c3= new sf::Vector2<float>(311,267.75);
            c4= new sf::Vector2<float>(235.5,267.75);
            salida= new sf::Vector2<float>(217,399.75);
            break;
        }
        case 3:{
            c1= new sf::Vector2<float>(613,569.75);
            c2= new sf::Vector2<float>(613,645.25);
            c3= new sf::Vector2<float>(650.75,607.5);
            c4= new sf::Vector2<float>(575.25,607.5);
            salida= new sf::Vector2<float>(670.25,475.25);
            break;
        }
        case 4:{
            c1= new sf::Vector2<float>(273.25,569.75);
            c2= new sf::Vector2<float>(273.25,645.25);
            c3= new sf::Vector2<float>(311,607.5);
            c4= new sf::Vector2<float>(235.5,607.5);
            salida= new sf::Vector2<float>(406,664);
            break;
        }
        default:
            break;
    }
    recorrido_jugador=new Recorrido(numeroJugador);
    puntos=0;
    ficha1=new Ficha(numeroJugador);ficha2=new Ficha(numeroJugador);ficha3=new Ficha(numeroJugador);ficha4=new Ficha(numeroJugador);
}

int Jugador::getNumeroJugador() const {
    return numeroJugador;
}


Ficha* Jugador::getFicha1() const {
    return ficha1;
}

Ficha* Jugador::getFicha2() const {
    return ficha2;
}

Ficha* Jugador::getFicha3() const {
    return ficha3;
}

Ficha* Jugador::getFicha4() const {
    return ficha4;
}

sf::Vector2<float> *Jugador::getC1() const {
    return c1;
}

sf::Vector2<float> *Jugador::getC2() const {
    return c2;
}

sf::Vector2<float>* Jugador::getC3() const {
    return c3;
}

sf::Vector2<float>* Jugador::getC4() const {
    return c4;
}

int Jugador::getPuntos() const {
    return puntos;
}

Recorrido *Jugador::getRecorridoJugador() const {
    return recorrido_jugador;
}

Jugador::~Jugador() {
    delete c1;delete c2;delete c3;delete c4;
    delete ficha1; delete ficha2; delete ficha3; delete ficha4;
}

void Jugador::setMovimimientos(int movimimientos) {
    Jugador::movimimientos = movimimientos;
}

int Jugador::getMovimimientos() const {
    return movimimientos;
}

sf::Vector2<float> *Jugador::getSalida() const {
    return salida;
}
