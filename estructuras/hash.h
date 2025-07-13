//
// Created by JLeandroJM on 11/06/23.
//

#ifndef PROYECTO_PROYECTO_GRUPO_4_HASH_H
#define PROYECTO_PROYECTO_GRUPO_4_HASH_H

#include <vector>
#include <list>
#include <functional>
//INTENTAMOS IMPLEMENTAR HASH

const double maxColision = 3;
const double maxFillFactor = 0.7;

template<typename TK, typename TV>
struct node_h {
    std::list<TV> values;
    TK key;
    node_h() = default;
    ~node_h() = default;
    node_h(TK key, TV value);
};

template<typename TK, typename TV>
node_h<TK, TV>::node_h(TK key, TV value) {
    this->key = key;
    this->values.push_back(value);
}

template<typename TK, typename TV>
class Hash {
private:
    struct ListNode {
        node_h<TK, TV> data;
        ListNode* next;
        explicit ListNode(const node_h<TK, TV>& entry) : data(entry), next(nullptr) {}
    };

    std::vector<ListNode*> array;
    size_t capacity;
    size_t size;

public:
    Hash();
    ~Hash();
    explicit Hash(size_t capacity);
    void set(TK key, TV value);
    std::list<TV> get(TK key);
    bool search(TK key);
    size_t countElements();
private:
    int hashFunction(TK key);
    double fillFactor();
    void rehashing();
};

template<typename TK, typename TV>
Hash<TK, TV>::Hash() {
    this->capacity = 23;
    this->size = 0;
    this->array = std::vector<ListNode*>(23, nullptr);
}

template<typename TK, typename TV>
Hash<TK, TV>::~Hash() {
    for (auto* node : array) {
        while (node != nullptr) {
            auto* next = node->next;
            delete node;
            node = next;
        }
    }
}

template<typename TK, typename TV>
Hash<TK, TV>::Hash(size_t capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->array = std::vector<ListNode*>(capacity, nullptr);
}

template<typename TK, typename TV>
void Hash<TK, TV>::set(TK key, TV value) {
    if (fillFactor() >= maxFillFactor) {
        rehashing();
    }
    node_h<TK, TV> entry(key, value);
    int index = hashFunction(key);

    ListNode* node = array[index];
    while (node != nullptr) {
        if (node->data.key == key) {
            if (std::find(node->data.values.begin(), node->data.values.end(), value) == node->data.values.end()) {
                node->data.values.push_back(value);
            }
            return;
        }
        node = node->next;
    }

    node = new ListNode(entry);
    node->next = array[index];
    array[index] = node;
    size++;
}

template<typename TK, typename TV>
std::list<TV> Hash<TK, TV>::get(TK key) {
    int index = hashFunction(key);
    ListNode* node = array[index];
    while (node != nullptr) {
        if (node->data.key == key) {
            return node->data.values;
        }
        node = node->next;
    }
    throw std::runtime_error("There is no value with the given key.");
}

template<typename TK, typename TV>
bool Hash<TK, TV>::search(TK key) {
    try {
        get(key);
        return true;
    } catch (const std::runtime_error& e) {
        return false;
    }
}

template<typename TK, typename TV>
size_t Hash<TK, TV>::countElements() {
    return size;
}

template<typename TK, typename TV>
int Hash<TK, TV>::hashFunction(TK key) {
    std::hash<TK> hasher;
    return hasher(key) % capacity;
}

template<typename TK, typename TV>
double Hash<TK, TV>::fillFactor() {
    return static_cast<double>(size) / (capacity * maxColision);
}

template<typename TK, typename TV>
void Hash<TK, TV>::rehashing() {
    size_t prevCapacity = capacity;
    capacity *= 2;
    std::vector<ListNode*> prevArray = array;
    array = std::vector<ListNode*>(capacity, nullptr);

    for (size_t i = 0; i < prevCapacity; i++) {
        ListNode* node = prevArray[i];
        while (node != nullptr) {
            for (const auto& value : node->data.values) {
                set(node->data.key, value);
            }
            ListNode* next = node->next;
            delete node;
            node = next;
        }
    }}
#endif //PROYECTO_PROYECTO_GRUPO_4_HASH_H
