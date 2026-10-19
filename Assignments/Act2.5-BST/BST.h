#if !defined(BST_H)
#define BST_H
#include <iostream>
#include <string>
#include "NodeT.h"

using namespace std;

template <typename T>
class BST {
private:
    NodeT<T>* root;
    void printTree(NodeT<T>* node, string prefix, bool isRight, bool isRoot);
public:
    BST() {}
    void insert(T data);
    void print();
};

template <typename T>
void BST<T>::insert(T data) {
    //validamos si el arbol esta vacio 
    if (root == nullptr) {
        //el arbol esta vacio
        //apuntamos root al nuevo nodo
        root = new NodeT<T>(data);
    } else {
        //el arbol no está vacio
        //creamos apuntador auxiliar igual a root 
        NodeT<T>* aux = root;
        //creamos un apuntador father igual a root
        NodeT<T>* father = root;
        //itero en el arbol hasta encontrar done voy a insertar el nodo 
        while (aux != nullptr) {
            //valido si aux->data es igual a data
            if (aux->data == data) {
                return;
            } else {
                //hacemos father igual a aux
                father = aux;
                //recorremos aux
                if (data < aux->data) {
                    aux = aux->left;
                }  else {
                    aux = aux->right;
                }

            }

        } //cuando te sales del ciclo:
        //inserto el nodo en el lado correspondiente
        if (data < father->data ) {
            //el nodo va al lado izquierdo del father
            father->left = new 
        }
    }
}

template <typename T>
void BST<T>::printTree(NodeT<T>* node, string prefix, bool isRight, bool isRoot) {
    if (node == nullptr) return;
    printTree(node->right, prefix + (isRoot ? "" : (isRight ? "      " : "|     ")), true, false);
    cout << prefix << (isRoot ? "" : (isRight ? ".---- " : "`---- ")) << node->data << endl;
    printTree(node->left,  prefix + (isRoot ? "" : (isRight ? "|     " : "      ")), false, false);
}

template <typename T>
void BST<T>::print() {
    if (root == nullptr) { cout << "(arbol vacio)" << endl; return; }
    printTree(root, "", false, true);
}


#endif // BST_H