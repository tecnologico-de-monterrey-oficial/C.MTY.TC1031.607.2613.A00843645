#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h
#include <iostream>

#include "NodeD.h"

using namespace std;

template <typename T>
class DoublyLinkedList {
    private:
        NodeD<T>* head;
        NodeD<T>* tail;
        int size = 0;
    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
        DoublyLinkedList(const DoublyLinkedList<T>& other); // Constructor de copia
        ~DoublyLinkedList(); //destructor
       
        int getSize() const { return size; }
        bool isEmpty() const { return head == nullptr; }

        void addFirst(T data);
        void addLast(T data); 
        void insert(int index, T data);
        bool deleteAt(int index);
        bool deleteData(T data);
        T getData(int index) const;
        void updateData(T oldValue, T newValue);
        void updateAt(int index, T newData);
        int findData(T data) const;

        // Sobrecarga de Operadores
    T& operator[](int index);
    const T& operator[](int index) const;
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other);

    // Operaciones adicionales solicitadas
    void clear();
    void sort();              // Ordenamiento (Bubble Sort)
    void duplicate();          // Duplica cada elemento (1->2->3 => 1->1->2->2->3->3)
    void removeDuplicates();   // Remueve duplicados (primero necesita que se ordene)
    void print() const;
    void printReverse() const;   // Utilidad extra para probar el doble enlace hacia atras
};

//IMPLEMENTACION DE METODOS

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) : head(nullptr), tail(nullptr), size(0) {
    *this = other;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    NodeD<T>* current = head;
    while (current != nullptr) {
        NodeD<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//AddFirst
template <typename T>
void DoublyLinkedList<T>::addFirst(T data){
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
        // la lista no esta vacia
        // creamos un nuevo nodo cuyo next apunte al head actual y prev sea nullptr
        NodeD<T>* newNode = new NodeD<T>(data, head, nullptr);
        
        // Actualizamos el prev del head actual para que apunte al nuevo nodo
        head->prev = newNode;
        
        // Mover head para que apunte al nuevo nodo
        head = newNode;
        
        // Incrementamos el tamaño
        size++;
    }
}

//addLast
template <typename T>
void DoublyLinkedList<T>::addLast(T data) {
   NodeD<T>* newNode = new NodeD<T>(data, nullptr, tail);
    if (tail != nullptr) {
        tail->next = newNode; // Asignacion directa
    } else {
        head = newNode; 
    }
    tail = newNode;
    size++;
}

// insert
template <typename T>
void DoublyLinkedList<T>::insert(int index, T data) {
   // Validamos que el indice sea valido (desde 0 hasta size - 1)
    if (index < 0 || index >= size) {
        throw out_of_range("Index fuera de rango");
    }

    // Recorremos la lista hasta llegar al nodo en la posicion 'index'
    NodeD<T>* aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    // Si el indice corresponde al ultimo nodo (tail), insertar a la derecha es un addLast
    if (aux == tail) {
        addLast(data);
        return;
    }

    // Si esta en medio, creamos el nuevo nodo conectando 'next' y 'prev'
    NodeD<T>* newNode = new NodeD<T>(data, aux->next, aux);
    aux->next->prev = newNode;
    aux->next = newNode;
    
    // Incrementamos el tamaño de la lista
    size++;
}

// deleteAt
template <typename T>
bool DoublyLinkedList<T>::deleteAt(int index) {
   // 1. Validar que el indice sea valido y la lista no este vacia
    if (head == nullptr || index < 0 || index >= size) {
        return false;
    }

    NodeD<T>* nodeToDelete = head;
    
    // Recorrer hasta la posicion exacta del indice a borrar
    for (int i = 0; i < index; i++) {
        nodeToDelete = nodeToDelete->next;
    }

    // Caso 1: Es el unico elemento en la lista
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    }
    // Caso 2: Es el primer elemento (head)
    else if (nodeToDelete == head) {
        head = head->next;
        head->prev = nullptr;
    }
    // Caso 3: Es el ultimo elemento (tail)
    else if (nodeToDelete == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    }
    // Caso 4: Esta en medio de la lista (aqui actuan ambos apuntadores prev y next)
    else {
        nodeToDelete->prev->next = nodeToDelete->next;
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    delete nodeToDelete;
    size--;
    return true;
}

//deleteData
template <typename T>
bool DoublyLinkedList<T>::deleteData(T data) {
NodeD<T>* aux = head;
    
    // Recorremos la lista buscando el elemento
    while (aux != nullptr) {
        // Validamos si lo encontramos 
        if (aux->data == data) {
            
            // 1 - Si es el unico elemento en la lista
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            }
            // 2 - Si vamos a borrar el primer elemento (head)
            else if (aux == head) {
                head = head->next;
                head->prev = nullptr;
            }
            // 3 - Si vamos a borrar el ultimo elemento (tail)
            else if (aux == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            }
            // 4 - Si esta en medio de la lista
            else {
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
            }

            // Liberamos la memoria del nodo y actualizamos el tamaño
            delete aux;
            size--;
            return true; // Se encontro y se pudo borrar
        }
        
        aux = aux->next; // Avanzamos al siguiente nodo
    }
    
    return false; // No se encontro el elemento en la lista
}


//getData
template <typename T>
T DoublyLinkedList<T>::getData(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Out_Of_Range: Posicion invalida en la lista");
    }
    
    NodeD<T>* aux = head;
    // Optimizacion opcional de recorrido bidireccional
    if (index <= size / 2) {
        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }
    } else {
        aux = tail;
        for (int i = size - 1; i > index; i--) {
            aux = aux->prev;
        }
    }
    return aux->data;
}

//updateData
template <typename T>
void DoublyLinkedList<T>::updateData(T oldValue, T newValue) {
    NodeD<T>* aux = head;
    while (aux != nullptr) {
        if (aux->data == oldValue) {
            aux->data = newValue;
            return;
        }
        aux = aux->next;
    }
    throw out_of_range("Out_Of_Range: Elemento no encontrado para actualizar");
}

//updateAt
template <typename T>
void DoublyLinkedList<T>::updateAt(int index, T newData) {
    if (index < 0 || index >= size) {
        throw out_of_range("Out_Of_Range: Indice fuera de rango");
    }
    NodeD<T>* aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    aux->data = newData;
}

// findData
template <typename T>
int DoublyLinkedList<T>::findData(T data) const {
    NodeD<T>* aux = head;
    int index = 0;
    while (aux != nullptr) {
        if (aux->data == data) {
            return index;
        }
        aux = aux->next;
        index++;
    }
    return -1;
}

//Sobrecarga operador []
template <typename T>
T& DoublyLinkedList<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Out_Of_Range: Indice fuera de rango en operador []");
    }
    NodeD<T>* aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->data;
}

template <typename T>
const T& DoublyLinkedList<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Out_Of_Range: Indice fuera de rango en operador []");
    }
    NodeD<T>* aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->data;
}

// Sobrecarga operador =
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other) {
    if (this != &other) {
        clear();
        NodeD<T>* aux = other.head;
        while (aux != nullptr) {
            addLast(aux->data);
            aux = aux->next;
        }
    }
    return *this;
}

// sort (Ordenamiento por Bubble Sort)
template <typename T>
void DoublyLinkedList<T>::sort() {
    if (size <= 1) return;
    bool swapped;
    NodeD<T>* ptr1;
    NodeD<T>* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                T temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// duplicate (1->2->3 => 1->1->2->2->3->3)
template <typename T>
void DoublyLinkedList<T>::duplicate() {
    NodeD<T>* aux = head;
    int originalSize = size;
    for (int i = 0; i < originalSize; i++) {
        NodeD<T>* duplicateNode = new NodeD<T>(aux->data, aux->next, aux);
        if (aux->next != nullptr) {
            aux->next->prev = duplicateNode;
        } else {
            tail = duplicateNode;
        }
        aux->next = duplicateNode;
        aux = duplicateNode->next; // Avanzar al siguiente nodo original
        size++;
    }
}

// removeDuplicates (Requiere previa ordenacion)
template <typename T>
void DoublyLinkedList<T>::removeDuplicates() {
    if (size <= 1) return;
    sort(); // Ordenar primero como pide la instruccion

    NodeD<T>* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            NodeD<T>* duplicateNode = current->next;
            current->next = duplicateNode->next;
            if (duplicateNode->next != nullptr) {
                duplicateNode->next->prev = current;
            } else {
                tail = current;
            }
            delete duplicateNode;
            size--;
        } else {
            current = current->next;
        }
    }
}

template <typename T>
void DoublyLinkedList<T>::print() const {
    if (head == nullptr) {
        cout << "La lista esta vacia.\n";
        return;
    }
    NodeD<T>* aux = head;
    int i = 0;
    while (aux != nullptr) {
        cout << "[" << i << "](" << aux->data << ")";
        aux = aux->next;
        if (aux != nullptr) {
            cout << " <-> ";
        }
        i++;
    }
    cout << " <-> NULL\n";
}

template <typename T>
void DoublyLinkedList<T>::printReverse() const {
    if (tail == nullptr) {
        cout << "La lista esta vacia.\n";
        return;
    }
    NodeD<T>* aux = tail;
    int i = size - 1;
    while (aux != nullptr) {
        cout << "[" << i << "](" << aux->data << ")";
        aux = aux->prev;
        if (aux != nullptr) {
            cout << " <-> ";
        }
        i--;
    }
    cout << " <-> NULL\n";
}

#endif /* DoublyLinkedList_h */