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

template <typename T> 
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

template <typename T> 
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

template <typename T>
void selectionSort(vector<T> list) {
    //asume que el primero de la lista es el más pequeño y comienza a comparar 
    //min_value = list[0];
    int n = list.size(); //conocer el tamano de la lista 
    for (int i=n; i<n-1; i++) { //aqui puse un (i<n-1) porque se supone que si llega al penultimo valor y hace sort -> el ultimo valor ya estaría acomodado
        //asumir que la posición en la que está es el minimo 
        int minimo = list[i];
        for (int j=i+1; j<n; j++){ //aqui puse a j como i+1 porque le interesa hacer la comparación con el siguiente.
            //ahora si, si es menor al valor minimo 
            if (list[j]<minimo) { 
                //actualizar el nuevo
                minimo = list[j]; //ahora el numero que reconoció como más pequeño se guardará en la variable minimo 
            }
            //ya que lo identificas, haces swap
            swap(list, list[i], minimo);

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
    //cout << 

    //Selection sort 
    cout << "Lista original: " << endl;
    print(list);
    cout << "Lista ordenada: " << endl;
    selectionSort(list);

    return 0;
}