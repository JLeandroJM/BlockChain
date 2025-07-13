//
// Created by JLeandroJM on 11/06/23.
//

#ifndef PROYECTO_PROYECTO_GRUPO_4_CIRCULAR_ARRAY_H
#define PROYECTO_PROYECTO_GRUPO_4_CIRCULAR_ARRAY_H


#include <iostream>
using namespace std;

//HeapSort
template<typename Temp>
void heapify(Temp arr[], int N, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}


template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray(int _capacity = 10);
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int index);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    //created
    void get_front_back();

    virtual //
    int size();
    void clear();
    T& operator[](int);
    void sort();
    //void swap(T& a , T& b);
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");
    void resize();

private:
    int next(int);
    int prev(int);
};

template<class T>
int CircularArray<T>::next(int i) {
    return (i + 1) % capacity;
}

template<class T>
int CircularArray<T>::prev(int i) {
    return (i - 1 + capacity) % capacity;
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->capacity = _capacity;
    this->array = new T[_capacity];
    this->front = this->back = -1;//empty
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] this->array;
}

template <class T>
void CircularArray<T>::push_front(T data)
{
    if(is_full()){
        resize();
    }
    if (this->front == -1 and this->back == -1){
        this->front = 0;
        this->back =0;
    } else if (this->front == 0){
        this->front = this->capacity-1;
    } else {
        front = front - 1;
    };
    this->array[front] = data;
//    cout << "front " << front << endl;
}

template <class T>
void CircularArray<T>::push_back(T data)
{
    if(is_full()){
        resize();
    }
    if (this->front == -1 and this->back == -1){
        this->front = 0;
        this->back =0;
    } else if(this->back == capacity-1){
        this->back = 0;
    }
    else{
        this->back += 1;
    }
    this->array[back] = data;
}


template <class T>
void CircularArray<T>::resize(){
    capacity = capacity *2;
    T *nuevo = new T[capacity];
    for(int i = 0; i < capacity/2 ; i++){
        nuevo[i] = array[i];
    }
    delete[] array;
    array = nuevo;
}


template <class T>
void CircularArray<T>::insert(T data, int index) {
    if (index < size()) {
        if(is_full()){
            resize();
        }
        int temp = (front + index) % capacity;
        for(int i=size()-1; i>temp;i--){
            array[i+1] = array[i];
        }
        array[temp] = data;
        back +=1;
    } else {
        cout << "Index out of range" << endl;
    }
}

template <class T>
T CircularArray<T>::pop_front(){
    int old_front = front;

    if (this->back == this->front){
        this->back = -1;
        this->front = -1;
        throw std::out_of_range("Is empty");
    }else {
        if (this->front == capacity - 1) {
            this->front = 0;
        } else {
            this->front += 1;
        }
    }
    return array[old_front];
}

template <class T>
T CircularArray<T>::pop_back(){
    int old_back = back;
    if(this->back == this->front == -1){
        throw std::out_of_range("CircularArray is empty");
    }

    if (this->back == this->front){
        this->back = -1;
        this->front = -1;
    }else {

        if (this->back == 0) {
            this->back = this->capacity - 1;
        } else {
            back = back - 1;
        };
    }
    return array[old_back];
}


template <class T>
bool CircularArray<T>::is_full()
{
    return (this->back + 1)%(this->capacity)== this->front;
}

template <class T>
bool CircularArray<T>::is_empty()
{
    if(this->front==-1 and this->back==-1)
        return true;
    else
        return false;
}

template <class T>
void CircularArray<T>::get_front_back(){
    cout << front << " " << back << endl;
};


template <class T>
int CircularArray<T>::size()
{
    if (back >= front)
        return (back - front + 1);
    else
        return (capacity - front + back + 1);
}


template <class T>
void CircularArray<T>::clear() {
    front = -1;
    back = -1;
}

template <class T>
T& CircularArray<T>::operator[](int index) {
    if (index < 0 || index >= capacity) {
        cout << "Index out of bounds" << endl;
    }
    int i = (front + index) % capacity;
    return array[i];

}

//HEAPSORT
template <class T>
void CircularArray<T>::sort() {
    front = 0;
    back = capacity-1;

    for (int i = capacity / 2 - 1; i >= 0; i--)
        heapify(array, capacity, i);

    for (int i = capacity - 1; i > 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}


template <class T>
bool CircularArray<T>::is_sorted() {
    int index = front;
    for (int i = 0; i < size()-1; i++)
    {
        if (array[index]>array[index+1]){
            return false;
        }
        if(index == capacity-1){
            index = 0;
        } else{
            index++;
        }

    }
    return true;
}

template<class T>
void CircularArray<T>::reverse() {
    int index_front = front;
    int index_back = back;
    for (int i = 0; i < size()/2; i++)
    {
        swap(array[index_front],array[index_back]);
        index_front = next(index_front);
        index_back = prev(index_back);
    }
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string str = "CircularArray is empty";
    if(!is_empty()) {
        str = "";
        int index = front;

        for (int i = 0; i < size(); i++) {
            if (index == capacity - 1) { //if index is located in the back
                str += std::to_string(array[index]) + sep;
                index = 0;  // return index to the front
            } else {
                str += std::to_string(array[index]) + sep;
                index++;
            }
        }
    }
    return str;
}

#endif //PROYECTO_PROYECTO_GRUPO_4_CIRCULAR_ARRAY_H
