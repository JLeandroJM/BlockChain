//
// Created by JLeandroJM on 23/06/23.
//

#ifndef PROYECTO_PROYECTO_GRUPO_4_USUARIO_H
#define PROYECTO_PROYECTO_GRUPO_4_USUARIO_H

#include <iostream>
#include "../estructuras/vector.h"
using namespace std;

class Usuario{
private:
    string nombre,password;
    Vector<string> clientes; //cambiar por unordered set (hash)
    float montoTotal;
public:

    Usuario(string nombre, string password):nombre(nombre),password(password),montoTotal(0){}

    void aumentarMonto(float monto){this->montoTotal = montoTotal + monto;}
    void retirarMonto(float monto){this->montoTotal = montoTotal - monto;}

    float getMontoTotal(){return montoTotal;}
    string getNombre(){return nombre;}
    string getPassword(){return password;}
    //No setters
    ~Usuario(){nombre = "", password = "";}
};
#endif //PROYECTO_PROYECTO_GRUPO_4_USUARIO_H
