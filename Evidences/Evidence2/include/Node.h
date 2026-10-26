#ifndef Node_h
#define Node_h

template <typename T>
struct Node {
    T data;
    //aqui solo tenemos un apuntador que apunta hacia adelante con next
    Node<T>* next;

    // Constructor 1: Solo con el valor (el apuntador next inicia por defecto en nullptr)
    Node(const T& value) : data(value), next(nullptr) {}

    // Constructor 2: Con valor y un apuntador al nodo siguiente (ideal para inserciones rápidas)
    Node(const T& value, Node<T>* nextNode) : data(value), next(nextNode) {} 
};

#endif // Node_h