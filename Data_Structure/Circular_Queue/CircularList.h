ifndef CLIST_H
#define CLIST_H
#include <iostream>
#include <string>
#include "Node.h"

class CircularList {
private:
    Node *m_head {nullptr};  // ponteiro para o primeiro elemento
    int m_size {0};          // numero de elementos na lista

public:
    // Construtor default: ja esta implementado
    CircularList() = default; 

    // retorna se a lista esta vazia
    bool empty() const { return m_head == nullptr; } 

    // retorna o numero de elementos na lista
    int size() const { return m_size; }

    // adiciona um elemento ao final da lista
    void push_back(const int& val); 

    // remove um elemento do final da lista, se ele existir
    // caso contrario, nao faz nada
    void pop_back();

    // sobrecarga do operador[] 
    // possibilita acessar diretamente o elemento no indice 'index'
    int& operator[](int index);

    // versao const da sobrecarga do operador[] 
    // possibilita acessar diretamente o elemento no indice 'index' 
    const int& operator[](int index) const;

    // deixa a lista vazia, liberando todos os nos
    void clear();

    // destrutor
    ~CircularList();

    // retorna os elementos no formato de string
    std::string toString() const;

    // sobrecarga do operador<<
    friend std::ostream operator<<(std::ostream& out, CircularList& lst);

    // adiciona um elemento no inicio da lista
    void push_front(const int& val); 

    // remove um elemento do inicio da lista, se ele existir
    // caso contrario, nao faz nada
    void pop_front();
};

#endif