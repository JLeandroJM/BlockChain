//
// Created by JLeandroJM on 11/06/23.
//

#ifndef PROYECTO_PROYECTO_GRUPO_4_BLOCKCHAIN_H
#define PROYECTO_PROYECTO_GRUPO_4_BLOCKCHAIN_H

//#include "../estructuras/forward_list.h"
#include "../estructuras/heap.h"
#include "../estructuras/trie.h"
#include "../estructuras/vector.h"
//#include "../estructuras/bplustree.h"
#include <fstream>
#include "block.h"

//BlockChain circular
class BlockChain{
private:
    Block* head;
    int bloques;
    bool buscable;
    //TriePatricia<Retiro*> trie; //probando
    Hash<string, Block *> usersHash {};
    Heap<Retiro *> max_monto{
            23,
            [](const Retiro *first, const Retiro *second) { return (first->getMonto() < second->getMonto()); },
            [](const Retiro *first, const Retiro *second) { return second->getMonto() < first->getMonto(); },
            [](const Retiro *first, const Retiro *second) { return first->getMonto() == second->getMonto(); }

    };
    Heap<Retiro *, true> min_monto{
            23,
            [](const Retiro *first, const Retiro *second) { return first->getMonto() < second->getMonto(); },
            [](const Retiro *first, const Retiro *second) { return second->getMonto() < first->getMonto(); },
            [](const Retiro *first, const Retiro *second) { return first->getMonto() == second->getMonto(); }

    };
    Heap<Retiro *> max_date{
            23,
            [](const Retiro *first, const Retiro *second) { return (first->getFecha() < second->getFecha()); },
            [](const Retiro *first, const Retiro *second) { return second->getFecha() < first->getFecha(); },
            [](const Retiro *first, const Retiro *second) { return first->getFecha() == second->getFecha(); }

    };
    Heap<Retiro *, true> min_date{
            23,
            [](const Retiro *first, const Retiro *second) { return first->getFecha() < second->getFecha(); },
            [](const Retiro *first, const Retiro *second) { return second->getFecha() < first->getFecha(); },
            [](const Retiro *first, const Retiro *second) { return first->getFecha() == second->getFecha(); }

    };






public:
    Block* get_head()const;

    DoubleList<Retiro *> max_block_monto()const{return max_monto.topRange();};

    DoubleList<Retiro *> min_block_monto()const{return min_monto.topRange();};
    DoubleList<Retiro *> max_block_date()const{return max_date.topRange();};
    DoubleList<Retiro *> min_block_date()const{return min_date.topRange();};






    BlockChain():bloques(0){
        head = new Block(0);
        head->setHashValue("0000000000000000000000000000000000000000000000000000000000000000");
        head->setValido();
        head->next = head;
        head->prev = head;
    }
    int getCantidadBloques(){return this->bloques;}
    //Mostrar data BlockChain

    void mostrarDataBC(){
        Block *temp = head;
        while (temp->next != head) {
            cout<<temp->getBlockData();
            temp = temp->next;
        }
        cout<<temp->getBlockData();
    }
    //agregar bloque
    void pushBack(int numero){
        Block* newBloque = new Block(numero);
        newBloque->next = this->head;
        newBloque->prev = this->head->prev;
        this->head->prev->next = newBloque;
        this->head->prev = newBloque;
        this->bloques++;
    }
    //eliminar ultimo bloque
    void pop_back(){
        if (bloques == 0) throw ("No hay elementos en la lista");
        Block* temp = this->head->prev;
        this->head->prev = this->head->prev->prev;
        this->head->prev->next = this->head;
        delete temp;
        this->bloques--;
    }
    //Crear cadena de bloques desde csv
    void crearBloqueCSV(string archivoPath,Usuario* user){//recibe como parametro un csv
        //agregar a la cadena
        this->pushBack(bloques+1);
        ifstream archivo(archivoPath);
        string linea;
        if (!archivo.is_open()) {
            cout << "Error al abrir el archivo" << endl;
        }
        while (getline(archivo, linea)){
            stringstream ss(linea);
            string cliente, lugar, fecha, monto;
            getline(ss, cliente, ',');
            getline(ss, lugar, ',');
            getline(ss, fecha, ',');
            getline(ss, monto, ',');
            if(head->prev->getSize() < MAX && head->prev->getNombreUsuario() == user->getNombre()) {
                head->prev->insertRetiro2(cliente,lugar,fecha,stof(monto));
                min_monto.push(head->prev->min_retiro_monto()[0]);
                max_monto.push(head->prev->max_retiro_monto()[0]);
                min_date.push(head->prev->min_retiro_date()[0]);
                max_date.push(head->prev->max_retiro_date()[0]);
            }else{
                head->prev->miningBlock();
                this->pushBack(bloques+1);
                head->prev->insertRetiro2(cliente,lugar,fecha,stof(monto));
                min_monto.push(head->prev->min_retiro_monto()[0]);
                max_monto.push(head->prev->max_retiro_monto()[0]);
                min_date.push(head->prev->min_retiro_date()[0]);
                max_date.push(head->prev->max_retiro_date()[0]);
            }
        }
        head->prev->miningBlock(); //En caso el ultimo bloque añadido no esté full
        archivo.close();
    }

    void crearBloqueCSV2(string archivoPath){//recibe como parametro un csv
        //agregar a la cadena
        this->pushBack(bloques+1);
        ifstream archivo(archivoPath);
        string linea;
        if (!archivo.is_open()) {
            cout << "Error al abrir el archivo" << endl;
        }
        while (getline(archivo, linea)){
            stringstream ss(linea);
            string cliente, lugar, fecha, monto;
            getline(ss, cliente, ',');
            getline(ss, lugar, ',');
            getline(ss, fecha, ',');
            getline(ss, monto, ',');
            if(head->prev->getSize() < MAX) {
                head->prev->insertRetiro(cliente,lugar,fecha,stof(monto));
                min_monto.push(head->prev->min_retiro_monto()[0]);
                max_monto.push(head->prev->max_retiro_monto()[0]);
                min_date.push(head->prev->min_retiro_date()[0]);
                max_date.push(head->prev->max_retiro_date()[0]);
            }else{
                head->prev->miningBlock();
                this->pushBack(bloques+1);
                head->prev->insertRetiro(cliente,lugar,fecha,stof(monto));
                min_monto.push(head->prev->min_retiro_monto()[0]);
                max_monto.push(head->prev->max_retiro_monto()[0]);
                min_date.push(head->prev->min_retiro_date()[0]);
                max_date.push(head->prev->max_retiro_date()[0]);
            }
        }
        head->prev->miningBlock(); //En caso el ultimo bloque añadido no esté full
        archivo.close();
    }

    void cascada(Block* bloque){

        Block *temp = bloque;
        while (temp->next != head) {
            if(!temp->prev->getValido())temp->calculateHashValue();
            temp = temp->next;
        }
        temp->calculateHashValue();
        this->buscable = false;
    }
    //Hacer una funcion editar para garegar a un bloque n si está incompleto
    void editar(int posicionR, int posicionB, string parametro, string nuevoValor){
        auto temp = head;
        while (temp->getBlockNumber() != posicionB) temp = temp->next;
        temp->modificarRegistro(posicionR,parametro,nuevoValor); //Se debe modificar para acceder dede antes
        cascada(temp);
    }

    void addRetiro(string cliente, string lugar, string fecha, string monto){
        if(head->prev->getSize() < MAX){
            head->prev->insertRetiro(cliente, lugar, fecha, stof(monto));
            min_monto.push(head->prev->min_retiro_monto()[0]);
            max_monto.push(head->prev->max_retiro_monto()[0]);
            min_date.push(head->prev->min_retiro_date()[0]);
            max_date.push(head->prev->max_retiro_date()[0]);
        }
        else{
            this->pushBack(bloques+1);
            head->prev->insertRetiro(cliente, lugar, fecha, stof(monto));
            min_monto.push(head->prev->min_retiro_monto()[0]);
            max_monto.push(head->prev->max_retiro_monto()[0]);
            min_date.push(head->prev->min_retiro_date()[0]);
            max_date.push(head->prev->max_retiro_date()[0]);
        }
    }
    //eliminar registro
    void eliminarRetiro(int posicionR, int posicionB){//no importa la posicion del retiro se arregla en consola
        auto temp = head;
        while (temp->getBlockNumber() != posicionB) temp = temp->next;
        temp->eliminarRegistro(posicionR);
        cascada(temp);
    }


    //Destructor
    ~BlockChain(){
        //Falta implementar
        Block* currentBlock = head->next;
        while (currentBlock != head) {
            Block* temp = currentBlock;
            currentBlock = currentBlock->next;
            delete temp;
        }
        delete head;
    }
    Vector<Retiro *> block_start(string prefix) const{
        Vector<Retiro *> results;
        Block *currentBlock = head;
        while (currentBlock->next != head) {
            Vector<Retiro *> blockResults = currentBlock->start(prefix);
           // results.insert(results.end(), blockResults.begin(), blockResults.end());
            for(int i=0;i<blockResults.getSize();i++){
                results.push_back(blockResults[i]);
            }
            currentBlock = currentBlock->next;
        }
        Vector<Retiro *> blockResults = currentBlock->start(prefix);
       // results.insert(results.end(), blockResults.begin(), blockResults.end());
        for(int i=0;i<blockResults.getSize();i++){
            results.push_back(blockResults[i]);
        }
        return results;
    }

    Vector<Retiro *> block_contains(string pattern)const {
        Vector<Retiro *> results;
        Block *currentBlock = head;
        while (currentBlock->next != head) {
            Vector<Retiro *> blockResults = currentBlock->contain(pattern);
            for(int i=0;i<blockResults.getSize();i++){
                results.push_back(blockResults[i]);
            }
           // results.push_back(results.end(), blockResults.begin(), blockResults.end());
            currentBlock = currentBlock->next;
        }
        Vector<Retiro *> blockResults = currentBlock->contain(pattern);
        //results.insert(results.end(), blockResults.begin(), blockResults.end());
        for(int i=0;i<blockResults.getSize();i++){
            results.push_back(blockResults[i]);
        }
        return results;
    }


};

Block *BlockChain::get_head()const {
    return head;
}

#endif //PROYECTO_PROYECTO_GRUPO_4_BLOCKCHAIN_H
