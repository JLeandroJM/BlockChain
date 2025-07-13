//
// Created by JLeandroJM on 9/07/23.
//

#ifndef PROYECTO_PROYECTO_GRUPO_4_DOUBLE_H
#define PROYECTO_PROYECTO_GRUPO_4_DOUBLE_H
#include <type_traits>


template<typename T>
struct node_d {
    T data;
    node_d<T> *next;
    node_d<T> *prev;
    node_d() = default;
    ~node_d() = default;

    explicit node_d(T data, node_d<T> *next = nullptr, node_d<T> *prev = nullptr);
};

template<typename T>
node_d<T>::node_d(T data, node_d<T> *next, node_d<T> *prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}



template<typename T>
class DoubleList {
private:
    node_d<T> *front;
    node_d<T> *back;
    size_t size;

public:

    DoubleList();

    DoubleList(const DoubleList<T> &other) : size(0) {
        for (int i = 0; i < other.size; ++i) {
            push_back(other[i]);
        }
    }
    ~DoubleList();
    T FRONT();
    T BACK();

    void push_front(T data);
    void push_back(T data);
    void pop_front();
    void pop_back();
    [[nodiscard]] bool is_empty() const;
    void clear();
    node_d<T> *begin() const;
    node_d<T> *end() const;
    void insert(T data, int pos);
    T &operator[](int pos) const;
    DoubleList<T>& operator=(const DoubleList<T>& other);
    [[nodiscard]] size_t SIZE() const;
    void print() const;


};

template<typename T>
DoubleList<T>::DoubleList() {
    this->front = nullptr;
    this->back = nullptr;
    this->size = 0;
}

template<typename T>
DoubleList<T>::~DoubleList() { clear(); }

template<typename T>
T DoubleList<T>::FRONT() {
    if (!is_empty()) { return front->data; }
    else { throw std::runtime_error("empty"); }
}

template<typename T>
T DoubleList<T>::BACK() {
    if (!is_empty()) { return back->data; }
    else { throw std::runtime_error("empty"); }
}

template<typename T>
void DoubleList<T>::push_front(T data) {
    if (is_empty()) {
        front = new node_d<T>(data);
        back = front;
    } else {
        auto *newN = new node_d<T>(data, front);
        front->prev = newN;
        front = newN;
    }
    size++;
}

template<typename T>
void DoubleList<T>::push_back(T data) {
    if (is_empty()) { push_front(data); }
    else {
        back->next = new node_d<T>(data, nullptr, back);
        back = back->next;
        size++;
    }
}

template<typename T>
void DoubleList<T>::pop_front() {
    if (!is_empty()) {
        if (size == 1) {
            delete front;
            front = nullptr;
            back = nullptr;
        } else {
            node_d<T> *temp = front->next;
            delete front;
            front = temp;
            front->prev = nullptr;
        }
        size--;
    } else { throw std::runtime_error("empty"); }
}

template<typename T>
void DoubleList<T>::pop_back() {
    if (!is_empty()) {
        if (size == 1) { pop_front(); }
        else {
            node_d<T> *temp = back->prev;
            delete back;
            back = temp;
            back->next = nullptr;
            size--;
        }
    } else { throw std::runtime_error("empty"); }
}

template<typename T>
bool DoubleList<T>::is_empty() const { return size == 0; }

template<typename T>
void DoubleList<T>::clear() {
    node_d<T> *iterator = front;
    while (iterator != nullptr) {
        node_d<T> *next = iterator->next;
        delete iterator;
        iterator = next;
    }
    front = nullptr;
    back = nullptr;
    size = 0;
}

template<typename T>
node_d<T> *DoubleList<T>::begin() const { return front; }

template<typename T>
node_d<T> *DoubleList<T>::end() const { return back; }

template<typename T>
void DoubleList<T>::insert(T data, int pos) {
    if (!is_empty() && pos < size) {
        node_d<T> *iterator = front;
        for (int i = 0; i <= pos - 1; i++) { iterator = iterator->next; }
        auto *newN = new node_d<T>(data, iterator->next, iterator);
        iterator->next = newN;
        newN->next->prev = newN;
        size++;
    } else { throw std::runtime_error("error"); }
}

/*remove section*/

template<typename T>
T &DoubleList<T>::operator[](int pos) const {
    if (!is_empty() && pos < size) {
        node_d<T> *iterator = front;
        for (int i = 0; i <= pos - 1; i++) { iterator = iterator->next; }
        return iterator->data;
    } else { throw std::runtime_error("error"); }
}

template<typename T>
size_t DoubleList<T>::SIZE() const { return size; }

template<typename T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList<T>& other) {
    if (this != &other) {
        // Limpiar la lista actual
        clear();

        // Copiar los elementos de la lista 'other'
        node_d<T>* iterator = other.front;
        while (iterator != nullptr) {
            push_back(iterator->data);
            iterator = iterator->next;
        }
    }
    return *this;
}

template<typename T>
void DoubleList<T>::print() const {
    node_d<T>* iterator = front;
    while (iterator != nullptr) {
        std::cout << iterator->data << " ";
        iterator = iterator->next;
    }
    std::cout << std::endl;
}

#endif //PROYECTO_PROYECTO_GRUPO_4_DOUBLE_H
