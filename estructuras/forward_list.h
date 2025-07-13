//
// Created by JLeandroJM on 11/06/23.
//

#ifndef PROYECTO_PROYECTO_GRUPO_4_FORWARD_LIST_H
#define PROYECTO_PROYECTO_GRUPO_4_FORWARD_LIST_H


#include <iostream>

#include "../estructuras/IteratorF.h"

using namespace std;






template <typename T>
class ForwardList {
private:
    Nodeforward<T>* head = nullptr;
    int nodes;


public:
    typedef ForwardListIterator<T> iterator;
    ForwardList() : head(nullptr), nodes(0){}

    ~ForwardList(){
        clear();
    }

    T front(){
        if (head != nullptr){
            return head->data;
        }else{
            throw("No hay elementos en la lista");
        }
    }

    T back(){
        if (head != nullptr){
            auto temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            return temp->data;
        }else{
            throw("No hay elementos en la lista");

        }
    }

    void push_front(T data){
        Nodeforward<T>* nodo = new Nodeforward<T>;
        nodo->data = data;
        nodo->next = head;
        if(is_empty()){
            head = nodo;
        }else{
            head = nodo;
        }
        nodes++;
    }

    void push_back(T data){
        Nodeforward<T>* nodo = new Nodeforward<T>;
        nodo->data = data;
        if (is_empty()){
            head = nodo;
        }else{
            Nodeforward<T>* temp = head;
            while (temp->next !=nullptr){
                temp = temp->next;
            }
            temp->next = nodo;
            nodo->next = nullptr;
        }
        nodes++;
    }

    T pop_front(){
        if (is_empty()){
            throw("No hay elementos en la lista");
        }
        T value = front();
        if (nodes == 1){
            delete head;
            head = nullptr;
        }else{
            Nodeforward<T>* temp = head;
            head = head->next;
            delete temp;
        }
        nodes--;
        return value;
    }

    T pop_back(){
        T value = back();
        if(nodes == 0){
            return 0;
        }
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            nodes--;
            return value;
        }else{
            Nodeforward<T>* temp = head;
            while((temp->next)->next != nullptr){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            return value;
        }
    }

    void insert(T data, int pos){
        if (pos < 0 or pos > nodes) throw ("Posicion fuera de rango");
        if (pos == 0) {
            push_front(data);
            return data;
        }
        else if (pos == nodes){
            push_back(data);
            return data;
        }
        Nodeforward<T>* nodo = new Nodeforward<T>;
        nodo->data = data;
        Nodeforward<T>* temp = head;
        int i = 0;
        while(i++ < pos - 1) temp = temp->next;
        nodo->next = temp->next;
        temp->next = nodo;
        nodes++;

    }

    void remove(int pos){
        if (pos < 0 || pos >= nodes) throw ("Posicion fuera de rango");
        if (pos == 0) {
            pop_front();

        }
        else if (pos == nodes-1) {
            pop_back();

        }
        Nodeforward<T>* temp = head;
        for (int i=0; i<pos-1; i++) temp = temp->next;
        temp->next = (temp->next)->next;
        delete temp;
        nodes--;

    }



    bool is_empty(){
        return nodes == 0;
    }

    int size(){
        return nodes;
    }

    void clear(){
        while(head != nullptr){
            Nodeforward<T>* temp = head;
            head = head->next;
            delete temp;
        }
        nodes = 0;
    }

    iterator begin(){
        return iterator(this->head);
    }

    iterator end(){
        return iterator(nullptr);
    }

};

#endif //PROYECTO_PROYECTO_GRUPO_4_FORWARD_LIST_H
