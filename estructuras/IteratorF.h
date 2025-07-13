
#ifndef PROYECTO_PROYECTO_GRUPO_4_ITERATORF_H
#define PROYECTO_PROYECTO_GRUPO_4_ITERATORF_H
#include <iostream>
using namespace std;

template<typename T>
struct Nodeforward {
    T data;
    Nodeforward* next;
    Nodeforward() = default;



    Nodeforward(T value){
        this->data = value;
    }

    ~Nodeforward(){
        this->killSelf();
    }

    void killSelf(){
        next = nullptr;

    }

};

template <typename T>
class ForwardListIterator {
private:
    Nodeforward<T>* current;
public:
    ForwardListIterator() : current(nullptr) {}

    explicit ForwardListIterator(Nodeforward<T>* node) : current(node) {}

    bool operator!=(const ForwardListIterator& other) const {
        return current != other.current;
    }
    bool operator==(const ForwardListIterator& other) const {
        return current == other.current;
    }

    ForwardListIterator& operator++() {
        if (current) {
            current = current->next;
        }
        return *this;
    }

    T& operator*() const {
        if (current) {
            return current->data;
        }
        throw std::runtime_error("Invalid iterator");
    }

};
#endif //PROYECTO_PROYECTO_GRUPO_4_ITERATORF_H
