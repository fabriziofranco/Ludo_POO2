#include "Jugador.h"

Jugador::Jugador(int numeroJugador) : numeroJugador(numeroJugador) {
    movimimientos=0;
    switch (numeroJugador){
        case 1:{
            c[0]= new sf::Vector2<float>(613,230);
            c[1]= new sf::Vector2<float>(613,305.5);
            c[2]= new sf::Vector2<float>(650.75,267.75);
            c[3]= new sf::Vector2<float>(575.25,267.75);
            salida= new sf::Vector2<float>(480,213);
            break;
        }
        case 2:{
            c[0]= new sf::Vector2<float>(273.25,230);
            c[1]= new sf::Vector2<float>(273.25,305.5);
            c[2]= new sf::Vector2<float>(311,267.75);
            c[3]= new sf::Vector2<float>(235.5,267.75);
            salida= new sf::Vector2<float>(215.75,401.75);
            break;
        }
        case 3:{
            c[0]= new sf::Vector2<float>(613,569.75);
            c[1]= new sf::Vector2<float>(613,645.25);
            c[2]= new sf::Vector2<float>(650.75,607.5);
            c[3]= new sf::Vector2<float>(575.25,607.5);
            salida= new sf::Vector2<float>(668.75,477.25);
            break;
        }
        case 4:{
            c[0]= new sf::Vector2<float>(273.25,569.75);
            c[1]= new sf::Vector2<float>(273.25,645.25);
            c[2]= new sf::Vector2<float>(311,607.5);
            c[3]= new sf::Vector2<float>(235.5,607.5);
            salida= new sf::Vector2<float>(404.5,666);
            break;
        }
        default:
            break;
    }
    recorrido_jugador=new Recorrido(numeroJugador);
    puntos=0;
    for(int i = 0; i < 4; i++){ficha[i]=new Ficha(numeroJugador);}
}


int Jugador::getNumeroJugador() const {
    return numeroJugador;
}


Ficha* Jugador::getFicha(int i) const {
    return ficha[i];
}

Ficha* Jugador::getFicha2(int i) const {
    if(i==0){
        return ficha[1];
    }
    return ficha[0];
}

Ficha* Jugador::getFicha3(int i) const {
    if(i <= 1){return ficha[2];}
    return ficha[1];
}

Ficha* Jugador::getFicha4(int i) const {
    if(i <= 2){return ficha[3];}
    return ficha[2];
}

sf::Vector2<float> *Jugador::getC(int i) const {
    return c[i];
}

int Jugador::getPuntos() const {
    return puntos;
}

Recorrido *Jugador::getRecorridoJugador() const {
    return recorrido_jugador;
}

Jugador::~Jugador() {
    for(int i = 0; i < 4; i++){
        delete c[i];
        delete ficha[i];}
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
