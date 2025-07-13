//
// Created by JLeandroJM on 23/06/23.
//

#ifndef PROYECTO_PROYECTO_GRUPO_4_SISTEMA_H
#define PROYECTO_PROYECTO_GRUPO_4_SISTEMA_H

#include "blockchain.h"

class Sistema{
private:
    bool login;
    Usuario* userTemp;
    Vector<Usuario*> usuarios;
    BlockChain* blockchain;
public:

    Sistema():login(false){
        blockchain = new BlockChain();
    }

    int cantUsers(){return usuarios.getSize();}
    bool registrarUsuario(string nombre, string password){//se puede mejorar
        for(auto usuario:usuarios){
            if(usuario->getNombre() == nombre) return false; //mostrar validaciones basicas
        }
        usuarios.push_back(new Usuario(nombre, password));
        return true;
    }

    void setLogin(string nombre, string password){
        for(auto usuario:usuarios){
            if(usuario->getNombre() == nombre && usuario->getPassword() == password){
                this->login = true;
                userTemp = usuario;
            }
        }
    }

    ~Sistema(){
        for(auto usuario:usuarios) delete usuario;
        delete blockchain;
    }

};



#endif //PROYECTO_PROYECTO_GRUPO_4_SISTEMA_H
