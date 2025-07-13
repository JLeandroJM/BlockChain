#include <iostream>
using namespace std;
//Pruebas
#include "blockchain/retiro.h"
#include "blockchain/block.h"
#include <string>
#include "blockchain/blockchain.h"
#include "./estructuras/heap.h"
#include "./estructuras/double.h"
#include "./estructuras/trie.h"
#include "./interfaz/view.h"
#include "./interfaz/viewmanager.h"
#include "./interfaz/login.h"
#include "./interfaz/funciones.h"
#include "blockchain/usuario.h"


int main() {
    //PROBANDO ALGUNAS FUNCIONALIDADES DEL BLOCKCHAIN, FALTA ACABR

//    Usuario* marcela = new Usuario("marcela","pasword1");
//    Usuario* alexandro = new Usuario("alexandro","pasword2");
//    Usuario* ibanez = new Usuario("ibanez","pasword3");
//    Usuario* leandro = new Usuario("leandro","pasword4");
//
//    BlockChain blockchain;
//    cout<<"Cantidad de bloques inicial: "<<blockchain.getCantidadBloques()<<endl;
//    blockchain.crearBloqueCSV("../csv/data-2.csv", marcela);
//    blockchain.crearBloqueCSV("../csv/data-2.csv", alexandro);
//    blockchain.crearBloqueCSV("../csv/data-2.csv", ibanez);
//    blockchain.crearBloqueCSV("../csv/data-2.csv", leandro);
//
//    cout<<"Mostrar detalles de bloques en el blockchain\n";
//    blockchain.mostrarDataBC();
//    //blockchain.addRetiro("HOLA","HOLA1","HOLA2","2.345",leandro);
//    //blockchain.addRetiro("HOLA","HOLA1","HOLA2","2.345",alexandro);
//    blockchain.editar(2,2,"Cliente","Heider");
//    cout<<"\n\n\n\nMostrar detalles de bloques en el blockchain (cascada)\n";
//    blockchain.mostrarDataBC();
//    cout<<"\n\n\n\nMostrar detalles de bloques en el blockchain (cascada)\n";
//
//    blockchain.mostrarDataBC();

//INTERFAZ

    ViewManager& viewManager = ViewManager::getInstance();


    Login login;



    viewManager.setCurrentView(&login);
    viewManager.mostar();


    viewManager.run();









    return 0;
}

