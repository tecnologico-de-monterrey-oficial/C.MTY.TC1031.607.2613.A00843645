// Daniela Chávez Ibarra
// A00843645

#include <iostream>
#include <vector>
using namespace std;

template <typename T> 

void swap(vector<T> &list, int i, int j)
{
    //creamos variable temporal
    T aux = list[i];
    //cambiamos i por j
    list[i]=list[j];
    //cambiamos j por aux
    list[j] = aux;

}

void swapSort(vector<T> list) {
    //iteramos todos los elementos de la lista hasta el penúltimo 
    for (int i=0; i < list.size()-1; i++){
        for (int j=i+1; j<list.size(); j++) {
        //comparacion para determinar si es menor
        if (list[j]<list[i])
        {
            //si es menor
            //intercambiamos los valores
            swap(list, i, j);
        }
    }

}
}

// en que falle: si comprendo la parte de la condicion, no comprendo como separar los dos for anidados 
void bubbleSort(vector<T> list) {
    //iterar desde n hasta 1
    bool change = true;
    for (int i=list.size()-1; i>0 && change; i--) {
        //cambio el valor de change a falso
        change = false;
        for (int i=0; j<i; j++) {//se supone que me falta algo en esa condición porque no recorre hasta el ultimo dato cuando va acomodando porque se supone que se asume que los últimos valores ya se van acomodando
             //la condicion
            if (list[j] > list[j+1]) { //comparamos el valor de j con el valor de j+1 para determinar si es mayor
                swap(list, i, i+1);
    }
    }
}
}



int main() {
    vector<T> list = {15, 7, 3, 9, 12, 5, 2};

    print(list);
    swapSort(list);
    cout << "lista ordenada: " << endl;
    print(list);

    cout << "BUBBLE SORT" << endl; 
    cout << 



    return 0;
}