#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using par = std::pair<float, float >;
using pares_ordenados = std::vector<par>;

#ifndef PROYECTO_POO_II_RECORRIDO_H
#define PROYECTO_POO_II_RECORRIDO_H

class Recorrido {
private:
    int jugadorasignado;
    pares_ordenados recorrido;
public:
    Recorrido(int jugadorasignado);

    int getJugadorasignado() const;

    void setJugadorasignado(int jugadorasignado);

    pares_ordenados getRecorrido() const;


    void setRecorrido(pares_ordenados recorrido);
};


#endif //PROYECTO_POO_II_RECORRIDO_H
