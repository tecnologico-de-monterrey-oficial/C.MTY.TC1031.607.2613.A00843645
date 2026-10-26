#if !defined(Queue_h)
#define Queue_h

#include "Node.h"
#include <stdexcept>
using namespace std;

template <typename T>

class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    int sizeCount; // Contador para saber cuántos elementos hay
public:
    Queue() : head(nullptr), tail(nullptr), sizeCount(0) {}
    // Destructor para liberar memoria
    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int getSize() const {
        return sizeCount;
    }

    void push(T data);
    T pop();
    T front() const;

};
    

template <typename T>
T Queue<T>::pop() {
   if (isEmpty()) {
        throw out_of_range("Excepción: La fila está vacía, no se pudo borrar.");
    }
    
    Node<T>* aux = head;
    T data = aux->data; // guarda el valor para retornarlo
    
    head = head->next;
    if (head == nullptr) {
        tail = nullptr; // Si era el único elemento, la cola queda vacía
    }
    
    delete aux;
    sizeCount--;
    return data; // return
}

template <typename T>
void Queue<T>::push(T data) {
    // validamos que no este vacía
    Node<T>* newNode = new Node<T>(data);
    if (head != nullptr) {
        tail->next = newNode;
        tail = newNode;
    } else {
        head = newNode;
        tail = newNode;
    }
    sizeCount++;
}

template <typename T>
T Queue<T>::front() const {
    if (isEmpty()) {
        throw out_of_range("La fila esta vacia, no hay datos en el Queue.");
    }
    return head->data;
}

#endif // Queue_h