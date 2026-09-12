#pragma once
//investigar qué hace pragma once

template <typename T>
struct Node {
    //Danny, recuerda que la estructura todo es publico por default
    T data; 
    std::unique_ptr<Node<T>> next;
    Node(const T& value) : data(value), next(nullptr) {} //constructor donde nada mas recibo el valor 
    Node(const T& value, std::unique_ptr<Node<T>> nextNode) : data(value), next(std::move(nextNode)) {} //constructor donde recibo el valor y el siguiente nodo

}; 