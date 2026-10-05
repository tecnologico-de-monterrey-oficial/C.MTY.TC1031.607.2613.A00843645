// Daniela Chávez Ibarra
// A00843645
#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"
#include <iostream>
#include <stdexcept> // Necesario para lanzar excepciones (out_of_range)

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList() : head(nullptr), size(0) {}
    void addFirst(T data);
    void addLast(T data);
    void insert(int index, T data);
    bool deleteData(T data);
    bool deleteAt(int index);
    T getData(int index) const;
    void updateData(T oldValue, T newValue);
    void updateAt(int index, T newData);
    int findData(T data) const;

    //sobrecarga de operdadores
    T& operator[](int index);
    LinkedList<T>& operator=(const LinkedList<T>& other);

    void print() const;

};

template <typename T>
void LinkedList<T>::addFirst(T data) {
    // crear un nodo nuevo
    Node<T>* node = new Node<T>(data);
    // actualizo el next del nodo nuevo para que apunte a head
    node->next = head;
    // actualizo head
    head = node;
    // incremento size
    size++;
}

template <typename T>
void LinkedList<T>::addLast(T data) {
    // validamos si la lista vacía
    if (head != nullptr) {
        // la lista no esta vacía
        // creamos un apuntador auxiliar que apunte a head
        Node<T>* aux = head;
        // recorremos la lista mientras aux->next sea diferente de nullptr
        while (aux->next != nullptr) {
            // recorremos aux a aux->next
            aux = aux->next;
        }
        // agregamos el nodo nuevo después de aux
        aux->next = new Node<T>(data);
    } else {
        // la lista esta vacía
        head = new Node<T>(data);    
    }
    // incrementamos size
    size++;
}

template <typename T>
void LinkedList<T>::insert(int index, T data) {
    // validamos que la posición exista
    if (index >= 0 && index < size) {
        // creamos un índice auxiliar
        int auxIndex = 0;
        // creamos nodo auxiliar
        Node<T>* aux = head;
        // recorremos la lista hasta encontrar la posición donde vamos a hacer el insert
        while (auxIndex < index) {
            // recorremos aux
            aux = aux->next;
            // incrementamos el indice auxiliar
            auxIndex++;
        }
        // insertamos el nuevo nodo
        aux->next = new Node<T>(data, aux->next);
        // incrementamos size
        size++;
    } else {
        // error
        throw out_of_range("la posición no existe en la lista")
    }

}

template <typename T>
bool LinkedList<T>::deleteData(T data) {
    // validamos que la lista no este vacía
    if (head != nullptr) {
        // la lista no esta vacía
        // valido si el primer elemento es el que quiero borrar
        if (head->data == data) {
            // quiero borrar el primer elemento
            // creamos un elemento aux igual a head
            Node<T>* aux = head;
            // recorremos head a head->next
            head = head->next;
            // borramos el primer elemento
            delete aux;
            // decrementamos size
            size--;
        } else {
            // creamos un elemento auxPrev igual a head
            Node<T>* auxPrev = head;
            // creamos un elemento aux igual a head->next
            Node<T>* aux = head->next;
            // recorremos la lista
            while (aux != nullptr) {
                // validamos si el valor de aux es el que quiero borrar
                if (aux->data == data) {
                    // 
                    auxPrev->next = aux->next;
                    // borro aux
                    delete aux;
                    // decrmenatmos size
                    size--;
                    // return
                }
                // recorremos los apuntadores
                auxPrev = aux;
                aux = aux->next;
            }
            // no lo encontre
            throw out_of_range("no se encontró el dato a borrar")
        }
    } else {
        throw out_of_range("La lista esta vacía")
    }
}

//deleteAt
template <typename T>
bool LinkedList<T>::deleteAt(int index) {
    // primero hay que validar que  lista no esté vacia y que el index sea valido
    if (head == nullptr || index < 0 || index >= size) {
        return false; // lista vacía o index inválido, no se puede borrar
    }

    // caso especial: borrar el primer nodo
    if (index == 0) {
        Node<T>* aux = head; //para guardar el nodo actual (head porque es el primero)
        head = nead->next; //mover el head al siguiente nodo (porque head es el que queremos borrar de la lista)
        delete aux; //borrar el nodo original de la memoria (porque el aux solo era para ayudarnos a hacer ese cambio)
        size--, // como se borró un valor de una posicion, el tamaño de la lista disminuye en uno 
        return true;
    }

    // caso general -> elemento en medio o al final de la lista 
    Node<T>* prev=head;
    int currentIndex = 0;

    while (currentIndex < index -1) { //recorremos la lista hasta llegar un nodo antes de la posicion a borrar
        prev = prev->next;
        currentIndex++;
    }

    Node<T>* nodeDelete = prev->next; //encuentra el nodo que se queire eliminar y se guarda en un auxiliar
    prev->next = nodeToDelete->next; // se salta el nodo a eliminar para que se conecte el anterior directamente con el que sigue
    delete nodeToDelete; // se libera la memoria del nodo que se desconecto 
    size--; //como se quita algo, el tamano de la lista disminuye en uno

    return true; 
}

template <typename T>
T LinkedList<T>::getData(int index) const {
    //asegurarse que el index si sea valido
    if (index < 0 || index >= size ) {
        throw out_of_range("la posicion es invalida o la lista esta vacia");
    }

    // después cree un apuntador auxiliar para empezar el recorrido desde el inicio 
    Node<T>* aux = head;
    int currentIndex = 0;

    // while para recorrer nodo por nodo hasta llegar a la posicion que se pidio
    while (currentIndex < index) {
        aux = aux->next;
        currentIndex++; //el apuntador auxiliar avanza 
    }

    //regresa el dato que se encuentra en el nodo solicitado
    return aux->data;
}


template <typename T>
void LinkedList<T>::updateData(T oldValue, T newValue) {
    //crear el apuntador para iniciar el recorrido
    Node<T>* aux = head;

    //se recorre la lista para encontrar la 1era coincidencia con oldValue
    while (aux != nullptr) {
        if (aux->data == oldValue) { //si ya encontro la coincidencia:
            aux->data = newValue; //actualiza el dato con el nuevo valor 
            return;
        }
        aux = aux->next; //se avanza al siguiente nodo 
    }

    //si se llega al final y no se encontro el dato
    throw out_of_range("el elemento a actualizar no se encuentra en la lista");
}

template <typename T>
void LinkedList<T>::updateAt(int index, T newData) {
    //verificar que el index sea valido 
    if (index < 0 || index >= size) {
        throw out_of_range("posicion no valida");
    }

    // apuntador auxiliar para recorrer la lista 
    Node<T>* aux = head;
    int currentIndex = 0;

    //recorrer la lista hasta llegar al nodo en la posición de index
    while (currentIndex < index) {
        aux = aux->next
        currentIndex++;
    }

    //cuando ya lo encuentre: actualiza el dato 
    aux->data = newData;
}

template <typename T>
int LinkedList<T>::findData(T data) const {
    //apuntador aux 
    Node<T>* aux = head;
    int index = 0; //este contador va a servir para rastrear la posicion actual

    //while para recorrer la lista nodo por nodo
    while (aux != nullptr) {
        if (aux->data == data) { //si encuentra el dato
            return index; //regresa la posicion donde se encontro
        }
        aux = aux->next; //avanza al siguiente nodo 
        index++; //incrementa el contador de la posicion
    }
    // si se recorrio toda la lista y no se encontro:
    return -1;
}

template <typename T>
void LinkedList<T>::print() const{
    // creamos un apuntador auxiliar que apunte a head
    Node<T>* aux = head;
    // recorremos la lista mientras aux sea diferente de nullptr
    while (aux != nullptr) {
        cout << aux->data;
        aux = aux->next;
        if (aux != nullptr) {
            cout << "-";
        }
    }
    cout << endl;
}

template <typename T>
T& LinkedList<T>::operator[](int index) {
    // validar posicion
    if (index < 0 || index >= size) {
        throw std::out_of_range("indice fuera de rango en el operador []");
    }

    // auxiliar y recorrer la lista hasta el índice indicado
    Node<T>* aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    // regresar por referencia para lectura y modificación
    return aux->data;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    // verificar si es la misma lista (auto-asignación: lista1 = lista1)
    if (this == &other) {
        return *this;
    }

    // aqui se libera la memoria de los nodos que ya tenía esta lista
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;

    // se copian todos los elementos de la otra lista
    Node<T>* aux = other.head;
    while (aux != nullptr) {
        addLast(aux->data); // Copia cada valor manteniendo el orden
        aux = aux->next;
    }

    // regresa la referencia a esta lista (*this)
    return *this;
}









#endif /* LinkedList_h */