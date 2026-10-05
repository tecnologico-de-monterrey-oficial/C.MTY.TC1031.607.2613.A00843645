#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "Node.h"

template <typename T>
class DoublyLinkedList {
    private:
        NodeD<T>* head;
        NodeD<T>* tail;
        int size = 0;
    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
        void addFirst(T data);

        void addLast(T data); 


template <typename T>
class DoublyLinkedList<T>::addFirst(T data){
//validamos si la lista esta vacia
if (head == nullptr) {
    //si esta vacia la lista
    //apunto head a un nuevo nodo con data
    head = new NodeD<T>(data);
    tail = head; //tail apunta al mismo nodo que head
   //incremento size
    size++;
}

else {
    //la lista no esta vacia
    //creamos un nuevo nodo

}
}


template <typename T>
void DoublyLinkedList<T>::addLast(T data) {
    // Caso 1: La lista está vacía
    if (head == nullptr) {
        head = new NodeD<T>(data);
        tail = head; // head y tail apuntan al mismo único nodo
    } 
    // Caso 2: La lista NO está vacía
    else {
        // 1. Crear el nuevo nodo
        NodeD<T>* newNode = new NodeD<T>(data);
        
        // 2. Conectar el último nodo actual (tail) hacia adelante con el nuevo nodo
        tail->setNext(newNode); // o tail->next = newNode;
        
        // 3. Conectar el nuevo nodo hacia atrás con el viejo tail
        newNode->setPrevious(tail); // o newNode->prev = tail;
        
        // 4. Mover tail para que apunte al nuevo nodo
        tail = newNode;
    }
    
    // Incrementar el tamaño
    size++;
}

// insert
template <typename T>
void DoublyLinkedList<T>::insert(T data) {
    //validamos que el indice sea desde 0 hasta el penultimo
    if (index >=0 && index <= size-1) {
        if (index != size-1){
            //el index es desde 0 hasta el penultimo
        } else{
            //el index es igual a size-1
        }
    } else {
        throw out_of_range("Index fuera de rango");
    }
}

}

#endif /*DoublyLinkedList_h*/