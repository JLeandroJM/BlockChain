
#ifndef PROYECTO_PROYECTO_GRUPO_4_RETIRO_H
#define PROYECTO_PROYECTO_GRUPO_4_RETIRO_H
#include <iostream>
#include <string>
using namespace std;

class Retiro{
private:
    string cliente, lugar, fecha;
    float monto;
    //int pos;//evaluar
public:

    string get_datos(){
        return cliente+"  "+ lugar+"  "+fecha+"  " +to_string(monto);
    }
    //Constructors
    Retiro(string cliente, string lugar, string fecha,float monto): cliente(cliente), lugar(lugar), fecha(fecha), monto(monto){}
    Retiro(const Retiro &other){
        this->cliente = other.cliente;
        this->lugar = other.lugar;
        this->fecha = other.fecha;
        this->monto = other.monto;
    }
    //Getters
    string getCliente(){return cliente;}
    string getLugar(){return lugar;}
    string getFecha() const {return fecha;}
    float getMonto()const{return monto;}
    //int getPosicion(){return pos;} EVALUAR

    string getData(){
        return ("Cliente: " + cliente + " - Lugar: " + lugar + " - Fecha: "+ fecha + " - Monto: "+ to_string(monto));
    } //obtener toda la informacion del retiro, para mostrar en consola


    //Setters
    void setCliente(string _cliente){this->cliente = _cliente;}
    void setLugar(string _lugar){this->lugar = _lugar;}
    void setFecha(string _fecha){this->fecha = _fecha;}
    void setMonto(float _monto){this->monto = _monto;}
    //void setPoscion(int _posicion){this->pos = _posicion;} EVALUAR

    Retiro &operator=(const Retiro &retiro);
    bool operator==(Retiro const &other) const;
    bool operator!=(Retiro const &other) const;
    bool operator>(const Retiro& retiro) const;
    bool operator<(const Retiro& retiro) const;

    friend std::ostream &operator<<(std::ostream &os, const Retiro &tx);
    ~Retiro(){}
};
Retiro &Retiro::operator=(const Retiro &retiro){
    cout << "Contructor retiro para retiro" << endl;
    this->cliente = retiro.cliente;
    this->lugar = retiro.lugar;
    this->monto = retiro.monto;
    this->fecha = retiro.fecha;
    return *this;
}

bool Retiro::operator==(const Retiro &retiro) const {
    return cliente==retiro.cliente and lugar==retiro.lugar and fecha==retiro.fecha and monto==retiro.monto;

}

bool Retiro::operator!=(const Retiro &retiro)const{
    auto resultado=!(*this==retiro);
    return resultado;
}

bool Retiro::operator>(const Retiro& retiro) const {
    return monto > retiro.monto;
}

bool Retiro::operator<(const Retiro& retiro) const {
    return monto < retiro.monto;
}


#endif //PROYECTO_PROYECTO_GRUPO_4_RETIRO_H
