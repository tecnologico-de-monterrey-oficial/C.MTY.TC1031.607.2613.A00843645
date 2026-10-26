#ifndef Stack_h
#define Stack_h

#include "Node.h"
#include <stdexcept>
using namespace std;

template <typename T>
class Stack {
private:
    Node<T>* topNode; // Apuntador a la cima de la pila
    int sizeCount;    // Contador de elementos

public:
    // Constructor
    Stack() : topNode(nullptr), sizeCount(0) {}

    // Destructor para liberar memoria
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Verificar si está vacía
    bool isEmpty() const {
        return topNode == nullptr;
    }

    // Obtener cuántos elementos hay
    int getSize() const {
        return sizeCount;
    }

    // push: Agrega un elemento a la cima del Stack
    void push(T data) {
        Node<T>* newNode = new Node<T>(data, topNode);
        topNode = newNode;
        sizeCount++;
    }

    // pop: Borra el último elemento agregado (cima) y regresa su valor
    T pop() {
        if (isEmpty()) {
            throw out_of_range("El Stack esta vacio, no se pudo hacer pop.");
        }
        
        Node<T>* aux = topNode;
        T data = aux->data; // Guardamos el valor para retornarlo
        
        topNode = topNode->next;
        delete aux;
        sizeCount--;
        
        return data;
    }

    // top: Obtiene el valor del último elemento agregado sin sacarlo
    T top() const {
        if (isEmpty()) {
            throw out_of_range("El Stack esta vacio, no hay datos en el Stack.");
        }
        return topNode->data;
    }
};

#endif // Stack_h