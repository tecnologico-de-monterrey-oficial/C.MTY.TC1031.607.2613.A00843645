//Daniela Chavez Ibarra
#include <iostream>
using namespace std;

#include "Node.h"

int main() {
    auto node1 = std::make_unique<Node<int>>(20);
    cout << "node1 data: " << node1->data << endl;


    auto node2 = std::make_unique<Node<int>>(10, std::move(node1));
    cout << "node2 data: " << node2->data << endl;
    cout << "node2 next data: " << node2->next->data << endl;
    //listas ligadas
    /*
    listas doblemente igadas
    abrol binario de busqueda 
    */
}