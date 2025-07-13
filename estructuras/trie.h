//
// Created by JLeandroJM on 11/06/23.
//

#ifndef PROYECTO_PROYECTO_GRUPO_4_TRIE_H
#define PROYECTO_PROYECTO_GRUPO_4_TRIE_H

#include <iostream>

using namespace std;

const unsigned ALPHA_SIZE = 256;

template <typename TV>
class TriePatricia {
private:
    struct TrieNode {
        TrieNode **children;
        string prefix;
        bool endWord;
        TV value;
        TrieNode() : children(new TrieNode *[ALPHA_SIZE]), endWord(false) {
            for (int i = 0; i < ALPHA_SIZE; i++) {
                children[i] = nullptr;
            }
        }
        ~TrieNode() {
            for (int i = 0; i < ALPHA_SIZE; i++) {
                if (children[i] != nullptr)
                    delete children[i];
            }
        }
    };
    TrieNode *root;

public:
    TriePatricia() : root(nullptr) {}

    void insert(string key, TV value) {
        if (root == nullptr)
            root = new TrieNode();
        TrieNode *currentNode = root;
        string prefix = "";

        for (char c : key) {
            if (currentNode->children == nullptr)
                currentNode->children = new TrieNode *[ALPHA_SIZE]();
            int index = c - '0';
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode();
                currentNode->children[index]->prefix = prefix + c;
            }
            currentNode = currentNode->children[index];
            prefix += c;
        }
        currentNode->endWord = true;
        currentNode->value = value;
    }

    bool search(string key) {
        TrieNode *currentNode = root;
        for (char c : key) {
            if (currentNode == nullptr || currentNode->children == nullptr)
                return false;
            int index = c - '0';
            if (currentNode->children[index] == nullptr)
                return false;
            currentNode = currentNode->children[index];
        }
        return (currentNode != nullptr && currentNode->endWord);
    }

    void remove(string key) { root = removeIntern(root, key, 0); }

    TrieNode *removeIntern(TrieNode *node, const string &key, int depth) {
        if (node == nullptr)
            return nullptr;
        if (depth == key.length()) {
            if (!node->endWord)
                return node;
            node->endWord = false;
            if (isEmptyNode(node)) {
                delete node;
                return nullptr;
            }
            return node;
        }

        int index = key[depth] - '0';
        node->children[index] = removeIntern(node->children[index], key, depth + 1);
        if (isEmptyNode(node) && !node->endWord) {
            delete node;
            return nullptr;
        }

        return node;
    }

    string toString(string sep) {
        string result = "";
        TrieNode *current = root;
        toStringIntern(current, result, sep);
        return result;
    }
    Vector<TV> contains(string pattern) const{
        Vector<TV> result;
        TrieNode *currentNode = root;
        wordFind(currentNode, result, pattern);
        return result;
    }

    Vector<TV> start_with(string prefix) const{
        Vector<TV> results;
        TrieNode* currentNode = root;
        string currentPrefix = ""; // Variable para almacenar el prefijo acumulado

        for (char c : prefix) {
            if (currentNode == nullptr || currentNode->children == nullptr) return results;

            int index = c - '0';
            if (currentNode->children[index] == nullptr) return results;
            currentNode = currentNode->children[index]; // avanzar
            currentPrefix += c;
        }

        getWords(currentNode, results, currentPrefix);

        return results;
    }

    ~TriePatricia() {
        if (root != nullptr)
            delete root;
    }

private:
    void toStringIntern(TrieNode *node, string &result, const string &sep) {
        if (node == nullptr)
            return;
        if (node->endWord)
            result += node->prefix + sep;
        for (int i = 0; i < ALPHA_SIZE; i++) {
            if (node->children[i] != nullptr)
                toStringIntern(node->children[i], result, sep);
        }
    }

    void getWords(TrieNode* node, Vector<TV>& results, const string& currentPrefix) const{
        if (node == nullptr) return;
        if (node->endWord) {
            results.push_back(node->value); // se agrega si es palabra
        }
        for (int i = 0; i < ALPHA_SIZE; i++) {
            if (node->children[i] != nullptr) {
                string childPrefix = currentPrefix + node->children[i]->prefix;
                getWords(node->children[i], results, childPrefix); // nuevo prefijo
            }
        }
    }

    bool isEmptyNode(TrieNode *node) const{
        for (int i = 0; i < ALPHA_SIZE; i++) {
            if (node->children[i] != nullptr)
                return false;
        }
        return true;
    }

    void wordFind(TrieNode *node, Vector<TV> &result, string pattern) const{
        if (node == nullptr) {
            return;
        }
        if (node->endWord && node->prefix.find(pattern) != string::npos) {
            result.push_back(node->value);
        }
        for (int i = 0; i < ALPHA_SIZE; i++) {
            if (node->children[i] != nullptr) {
                wordFind(node->children[i], result, pattern);
            }
        }
    }
};

#endif //PROYECTO_PROYECTO_GRUPO_4_TRIE_H
