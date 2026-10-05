#ifndef queue_h
#define queue_h

#include "Node.h"


template <typename T>
class Queue{
private:
    // la lista tiene head y tiene tail (stack tiene top)
    Node<T>* head;
    Node<T>* tail;
public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}
    void push(T data);
    void push_PROFE(T data);
    void pop(T data);
    void print();
    void front(int index, T data);
};

// push_PROFE
template <typename T>
void Queue<T>:push_PROFE(T data) {
   //validamos que no este vacia 
   if (head != nullptr) {
    //actualizamos el next de tail con un nodo nuevo
    tail->next = new Node<T>(data);
    //actualizamos tail con tail->next
    tail = tail->next
   } 
}

// push (es como si fuera un add last)
template <typename T>
void Queue<T>::push(T data) {
    // nodo nuevo
    Node<T>* node = new Node<T>(data);
    // actualizo el next del nodo nuevo para que apunte a head
    node->next = head;
    // actualizr head
    head = node;
}

// pop
template <typename T>
void Queue<T>::pop(T data) {
    if (head == nullptr) { 
        cout << "lista esta vacia" << endl;
        return;
    }
    Node<T>* aux = head;
    head = head->next;
    delete aux;

    //avance del profe en clase
    if (head != nullptr) {
        if (head == tail) {
            Node
        }
    }
}

// front
template <typename T> 
void Queue<T>::front(int index, T data) {

}






#endif /*queue_h*/