//
// Created by JLeandroJM on 23/06/23.
//

#ifndef PROYECTO_PROYECTO_GRUPO_4_ITERATOR_H
#define PROYECTO_PROYECTO_GRUPO_4_ITERATOR_H


#include <iostream>
using namespace std;


template<class T>
class VectorIterator{
private:
    int current;
    T* array;
public:
    VectorIterator(){
        current = -1;
    }

    VectorIterator(int index, T *array = nullptr){
        current = index;
        this->array = array;
    }

    bool operator != (const VectorIterator &other){
        return current != other.current;
    }

    VectorIterator& operator++(){
        ++current;
        return *this;
    }

    T& operator*(){
        return array[current];
    }
};


#endif //PROYECTO_PROYECTO_GRUPO_4_ITERATOR_H
