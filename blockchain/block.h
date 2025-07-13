
#ifndef PROYECTO_PROYECTO_GRUPO_4_BLOCK_H
#define PROYECTO_PROYECTO_GRUPO_4_BLOCK_H


#include<utility>
#include <ctime>
#include <sstream>
#include <openssl/sha.h>
#include "retiro.h"
#include "../estructuras/vector.h"
#include "../estructuras/heap.h"
#include "../estructuras/hash.h"

#include "../estructuras/double.h"
#include "../estructuras/trie.h"
#include "usuario.h"
const int MAX = 5;
class Block{
private:
    Usuario* usuario;
    int nonce, blockNumber;
    bool valido;
    string target, hashValue;
    Vector<Retiro*> retiros;
    Hash<std::string, Retiro *> dataHash;
    TriePatricia<Retiro*> trie;// se crea arbol patricia

    Heap<Retiro*> maxdate{
            23,
            [](const Retiro *first, const Retiro *second) { return first->getFecha() < second->getFecha(); },
            [](const Retiro *first, const Retiro *second) { return second->getFecha() < first->getFecha(); },
            [](const Retiro *first, const Retiro *second) { return first->getFecha() == second->getFecha(); }

    };

    Heap<Retiro *, true> mindate{
            23,
            [](const Retiro *first, const Retiro *second) { return first->getFecha() < second->getFecha(); },
            [](const Retiro *first, const Retiro *second) { return second->getFecha() < first->getFecha(); },
            [](const Retiro *first, const Retiro *second) { return first->getFecha() == second->getFecha(); }
    };
    Heap<Retiro *> maxmonto{
            23,
            [](const Retiro *first, const Retiro *second) { return first->getMonto() < second->getMonto(); },
            [](const Retiro *first, const Retiro *second) { return second->getMonto() < first->getMonto(); },
            [](const Retiro *first, const Retiro *second) { return first->getMonto() == second->getMonto(); }

    };

    Heap<Retiro *, true> minmonto{
            23,
            [](const Retiro *first, const Retiro *second) { return first->getMonto() < second->getMonto(); },
            [](const Retiro *first, const Retiro *second) { return second->getMonto() < first->getMonto(); },
            [](const Retiro *first, const Retiro *second) { return first->getMonto() == second->getMonto(); }

    };




public:
    //max y min
    DoubleList<Retiro *> max_retiro_date();
    DoubleList<Retiro *> min_retiro_date();
    DoubleList<Retiro *> max_retiro_monto();
    DoubleList<Retiro *> min_retiro_monto();
    Vector<Retiro *> start(string prefix) const; // llamara a start_with del trie
    Vector<Retiro *> contain(string pattern)const;//lamara a contains del trie
    //search




    Block* prev;
    Block* next;
    //Constructor
    Block(int number):usuario(nullptr),blockNumber(number), nonce(0),valido(false),prev(nullptr),next(nullptr),hashValue(""),target("0000"){}
    Block(int number, Usuario* usuario):usuario(usuario),blockNumber(number), nonce(0),valido(false),prev(nullptr),next(nullptr),hashValue(""),target("0000"){}





    //Getter/Setter
    void setHashValue(string centinela){ this->hashValue = centinela;}
    void setValido(){if(this->hashValue == "0000000000000000000000000000000000000000000000000000000000000000") this->valido = true;} //solo sirve para el centinela
    string getHashValue(){return hashValue;}
    bool getValido(){return valido;}
    int getSize(){return retiros.getSize();}
    int getBlockNumber(){return blockNumber;}
    string getNombreUsuario(){
        cout<<usuario->getNombre();

    return usuario->getNombre();}
    string get_number_block(){
        return to_string(blockNumber);
    }
    string get_nonce(){
        return to_string(nonce);
    }
    Vector<Retiro*> get_retiros(){
        return retiros;
    }

    //CrearHashValue
    void calculateHashValue(){
        valido = false;
        //calculate hash value
        char tmp[SHA256_DIGEST_LENGTH * 2 + 1];
        unsigned char digest[SHA256_DIGEST_LENGTH];

        stringstream ss;
        for(auto retiro: retiros) ss<<retiro->getData(); //implementar
        ss <<this->prev->getHashValue()<<nonce; //valores de importancia
        string data = ss.str();

        SHA256_CTX ctx;
        SHA256_Init(&ctx);
        SHA256_Update(&ctx, data.c_str(), data.length());
        SHA256_Final(digest, &ctx);

        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            sprintf(&tmp[i * 2], "%02x", digest[i]);
        }
        tmp[SHA256_DIGEST_LENGTH * 2] = '\0';
        hashValue = string(tmp);
    }

    void insertRetiro(string cliente, string lugar, string fecha, float monto){ //verificación en sistema
        if(retiros.getSize() + 1 <= MAX) {
           // this->usuario->aumentarMonto(monto);
            retiros.push_back(new Retiro(cliente, lugar, fecha, monto));
            maxdate.push(retiros[retiros.getSize()-1]);
            mindate.push(retiros[retiros.getSize()-1]);
            maxmonto.push(retiros[retiros.getSize()-1]);
            minmonto.push(retiros[retiros.getSize()-1]);
            trie.insert(cliente,retiros[retiros.getSize()-1]);// se inserta retiro en el arbol (cliente)

            calculateHashValue();
        }

    }
    void insertRetiro2(string cliente, string lugar, string fecha, float monto){ //verificación en sistema
        if(retiros.getSize() + 1 <= MAX) {
             //this->usuario->aumentarMonto(monto);
            retiros.push_back(new Retiro(cliente, lugar, fecha, monto));
            maxdate.push(retiros[retiros.getSize()-1]);
            mindate.push(retiros[retiros.getSize()-1]);
            maxmonto.push(retiros[retiros.getSize()-1]);
            minmonto.push(retiros[retiros.getSize()-1]);
            trie.insert(cliente,retiros[retiros.getSize()-1]);// se inserta retiro en el arbol (cliente)

            calculateHashValue();
        }

    }
    void miningBlock(){ //target = "0000"
        do{
            nonce ++;
            calculateHashValue();
            valido = (hashValue.substr(0, target.length()) == target);
        }while(!valido);
    }
    //evaluar para modificar de otra forma
    void modificarRegistro(int index, string parametro, string nexValue){
        Retiro* modificar = retiros[index];
        if(parametro == "Cliente"){
            modificar->setCliente(nexValue);
        }else if(parametro == "Lugar"){
            modificar->setLugar(nexValue);
        }else if(parametro == "Fecha"){
            modificar->setFecha(nexValue);
        }else if(parametro == "Monto"){
            this->usuario->retirarMonto(modificar->getMonto());
            this->usuario->aumentarMonto(stof(nexValue));
            modificar->setMonto(stof(nexValue));
        }
        calculateHashValue();
    }

    void eliminarRegistro(int index){
        if (index < retiros.getSize()) {
            if (index != retiros.getSize() - 1) {
                retiros[index] = retiros[getSize()-1];  // Mover el último elemento a la posición 'index'
            }
            this->usuario->retirarMonto(retiros[index]->getMonto());
            retiros.pop_back();  // Reducir el tamaño del vector en 1
        }
        calculateHashValue();
    }

    string getBlockData(){
        stringstream ss;
        ss <<"---------------------"<<endl;
        ss << "Block Number: " << blockNumber << endl;
        ss << "Nonce: " << nonce << endl;
        ss << "Prev hash: " << this->prev->getHashValue()<< endl;
        ss << "Curr hash: " << hashValue << endl;
        ss << "Cantidad de retiros: " << retiros.getSize() << endl;
        ss << "Bloque valido: " << valido << endl;
        return ss.str();
    }

    //Destructor
    ~Block(){
        prev = nullptr;
        next = nullptr;
        hashValue = "";
        nonce = 0;
        valido = 0;
        blockNumber = -1;
        for(auto retiro:retiros) delete retiro;
    }
};



DoubleList<Retiro *> Block::max_retiro_date() {return maxdate.topRange();
}
DoubleList<Retiro *> Block::min_retiro_date() {return mindate.topRange();}

DoubleList<Retiro *> Block::max_retiro_monto()  { return maxmonto.topRange(); }

DoubleList<Retiro *> Block::min_retiro_monto()  { return minmonto.topRange(); }

Vector<Retiro *> Block::start(string prefix)  const{ return trie.start_with(prefix); }
Vector<Retiro *> Block::contain(string pattern)const {
    return trie.contains(pattern);
}
#endif //PROYECTO_PROYECTO_GRUPO_4_BLOCK_H
