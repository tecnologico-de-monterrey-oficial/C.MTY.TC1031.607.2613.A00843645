#ifndef NODED_H
#define NODED_H

template <typename T>
struct NodeD {
    T data;
    NodeD<T>* next;
    NodeD<T>* prev;
//Constructor solo con el valor
    NodeD(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    //constructor2 -> nodo siguiente, nodo anteior
    NodeD(const T& value, NodeD<T>* nextNode, NodeD<T>* prevNode) : data(value), next(nextNode), prev(prevNode) {}
};

#endif // NODED_H

