#ifndef List_h
#define List_h

#include <iostream>
#include <vector>

template <typename T>
class List {
private:
    std::vector<T> data;
    int size;
public:
    List();
    void insert(T data);
    void removeLast();
    T getData(int pos) const; //recibe la posición que tiene que buscar y de la cual tiene que desplegar el valor
    int getSize() const; //regresa valor del atributo size
    T getMax() const;
    void print() const;
    void insertAt(int pos, T data);
    void removeAt(int pos);
};

//aquí se define el constructor
template <typename T>
List<T>::List() {
    size = 0;
}

//insert
template <typename T>
void List<T>::insert(T val) {
    data.push_back(val);
    size++;
}; 

//removeLast
template <typename T>
void List<T>::removeLast(){
    if (size > 0) {
        std::cout << "El último elemento a eliminar es:" << data.back() << std::endl;
        data.pop_back();
        size--;
    }
    else {
        std::cout << "NO HAY ELEMENTOS" << std::endl;
    }
}

//getData
template <typename T>
T List<T>::getData(int pos) const {
if (pos >= 0 && pos < size) {
    return data[pos];
}  
else {
    std::cout << "posición no válida" << std::endl;
    return T(); 
}
}

//getSize
template <typename T>
int List<T>::getSize() const {
    return size;
}

//getMax
template <typename T>
T List<T>::getMax() const {
    if (size == 0) {
        std::cout << "La lista está vacía" << std::endl;
        return T();
    }
    T maxVal = data[0];
    for (int i=1; i<size; i++) {
        if (data[i] > maxVal) {
            maxVal = data[i];
        }
    }  
    return maxVal;
}

//print
template <typename T>
void List<T>::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << "[" << i << "] – " << data[i] << "\n";
}
}


//insertAt
template <typename T>
void List<T>::insertAt(int pos, T val) {
    if (pos < 0 || pos > size){
        std::cout << "Posición no válida" << std::endl;
        return;
    }
    data.insert(data.begin() + pos, val);
    size++;
}

//removeAt
template <typename T>
void List<T>::removeAt(int pos) {
    if (pos < 0 || pos >= size) {
        std::cout << "Posición no válida" << std::endl;
        return;
    }
    T eliminado = data[pos];
    data.erase(data.begin() + pos);
    size--;
    std::cout << "Elemento eliminado: " << eliminado << std::endl;
}

#endif