//
// Created by JLeandroJM on 23/06/23.
//

#ifndef PROYECTO_PROYECTO_GRUPO_4_VECTOR_H
#define PROYECTO_PROYECTO_GRUPO_4_VECTOR_H
#include "../estructuras/Iterator.h"


using namespace std;
template<typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;
public:
    typedef VectorIterator<T> iterator;
    Vector() : size(0), capacity(10) {data = new T[capacity];}

    ~Vector() {
        delete[] data;
    }

    size_t getSize() const {
        return size;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            capacity *= 2;
            T* newData = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        this->data[size++] = value;
    }
    iterator begin(){
        return iterator(0, this->data);
    }

    iterator end(){
        return iterator(size);
    }

//    void push_front(const T& value) {
//        if (size == capacity) {
//
//            capacity *= 2;
//            T* newData = new T[capacity];
//            for (size_t i = 0; i < size; ++i) {
//                newData[i + 1] = data[i];
//            }
//            delete[] data;
//            data = newData;
//        } else {
//            for (size_t i = size; i > 0; --i) {
//                data[i] = data[i - 1];
//            }
//        }
//        data[0] = value;
//        ++size;
//    }

    void pop_back() {
        if (size > 0) {
            --size;
        }
    }

    void clear() {size = 0;}

    T& operator[](size_t index) {
        return data[index];
    }
};

#endif //PROYECTO_PROYECTO_GRUPO_4_VECTOR_H
