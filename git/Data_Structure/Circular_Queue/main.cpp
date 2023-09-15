#include <iostream>
#include "CircularList.h"
using namespace std;

void print(const CircularList& lst) {
    for(int i = 0; i < lst.size(); ++i)
        cout << lst[i] << " ";
    cout << endl;
}

// retorna se a lista esta vazia
bool circularList::empty const {
    if(m_head->next == m_head) {
        return;
    } else {
        return false;
    }

    // return m_head->next = m_head;
}


// adicionar um elemento ao final da lista
void CircularList::push_back(const int& val) {
    while (aux->next != m_head)
    {
        aux = aux->next;
    }
    Node node* = new Node(val, m_head);
    aux->next = node;

    // better
    aux->next = new Node(val, m_head);
    m_size++;
}

int main() {
    CircularList lst;

    for(int i = 1; i <= 9; ++i) 
        lst.push_back(i * 0.5);
    
    cout << lst.toString() << endl;

    m_head = new Node(-1, nullptr);
    m_head->next = m_head;
}