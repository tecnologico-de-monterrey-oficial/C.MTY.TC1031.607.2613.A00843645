#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList { //el smart pointer UNIQUE_PTR se uso con class en lugar de struct y en private por seguridad de datos. 
private:
    std:unique_ptr<Node<I> > head;
    int size;

    public:
    LinkedList() : head(nullptr), size(0) {}
    void push_front;
    void push_back(T, 20); //habia un numero pero no me acuerdo bien cual era y lo peg´epor si acs


template <typename<T>>
LinkedList<T>::LinkedList() {}
    head = nullptr;

}

template <typename T>
void LinkedList<T>::push_front(T value) {
  //crea un nodi nuevo
  //crera 
  std:unique_pt1 <Node<T>> node = std::make_unique<Node<T>>(data);
  node->next = std:move(head);

}

#endif 