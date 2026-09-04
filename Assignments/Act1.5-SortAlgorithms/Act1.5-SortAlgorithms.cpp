// Daniela Chávez Ibarra
// A00843645

#include <iostream>
#include <vector>
using namespace std;

template <typename T> 

void swap(vector<T> &list, int i, int j)
{
    if (i!=j){
    //creamos variable temporal
    T aux = list[i];
    //cambiamos i por j
    list[i]=list[j];
    //cambiamos j por aux
    list[j] = aux;
    }
}

template <typename T> 
void swapSort(vector<T> &list) {
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
void bubbleSort(vector<T> &list) {
    //iterar desde n hasta 1
    bool change = true;
    for (int i=list.size()-1; i>0 && change; i--) {
        //cambio el valor de change a falso
        change = false;
        for (int j=0; j<i; j++) {//se supone que me falta algo en esa condición porque no recorre hasta el ultimo dato cuando va acomodando porque se supone que se asume que los últimos valores ya se van acomodando
             //la condicion
            if (list[j] > list[j+1]) { //comparamos el valor de j con el valor de j+1 para determinar si es mayor
                swap(list, j, j+1);
            }
        }
    }
}


template <typename T>
void selectionSort(vector<T> &list) {
    //asume que el primero de la lista es el más pequeño y comienza a comparar 
    //min_value = list[0];
    int n = list.size(); //conocer el tamano de la lista 
    for (int i=n; i<n-1; i++) { //aqui puse un (i<n-1) porque se supone que si llega al penultimo valor y hace sort -> el ultimo valor ya estaría acomodado
        //hacemos el valor de i como el mas chico
        T min = i;
        for (int j=i+1; j<n; j++){ //aqui puse a j como i+1 porque le interesa hacer la comparación con el siguiente.
            //ahora si, si es menor al valor minimo 
            if (list[j]<list[min]) { //si es menor
                //actualizar el valor de min 
                min = j; //ahora el numero que reconoció como más pequeño se guardará en la variable minimo 
            }
            //ya que lo identificas, haces swap
            swap(list, min, i);

        }
    }
}

template <typename T>
void insertionSort(vector<T> &list){
    //aqui el primero se asume que ya esta ordenado entonces empieza con el segundo 
    for (int i=1; i<list.size(); i++) {
        //iteramos desde i hasta 0
        //declaramos un contador para ver donde vamos
        int j=i;
        while (j>0 && list[j]<list[j-1]){
            //aqui ya no ocupas hacer if porque va a netrar siempre y cuando sí sea menor entonces te pasas diretco al SWAP
            //intercambiamos j con j-1
            swap(list, j,j-1);
            //decrementamos 
            j--;
        }
    }
}

// MERGE SORT (tarea)
template <typename T> 
//el merge que llamará al final mergeSort después de la recursividad
void merge(vector<T> &list, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // aquí delcaré unos vectores auxiliares que ayudarán a almacenar las dos mitades
    vector<T> L(n1);
    vector<T> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = list[low + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = list[mid + 1 + j];
    }

    int i = 0;   // index para L
    int j = 0;   // index para R
    int k = low; // es el index para el vector original

    // aquí se van intercalando los elementos y se selecciona siempre el menor
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            list[k] = L[i];
            i++;
        } else {
            list[k] = R[j];
            j++;
        }
        k++;
    }

    // copiar elementos sobrantes si una mitad terminó antes
    while (i < n1) { // si la mitad derecha (R) se acabó primero
        list[k] = L[i]; // aquí coloca el elemento sobrante de L en la posición actual de la lista original 
        i++; // avanza al siguiente elemnto de la mitad izquierda
        k++; //aqui avanza a la siguiente casilla libre en la lista original
    }

    while (j < n2) { // si la mitad izquierda (L) se acabó primero
        list[k] = R[j]; //elemento sobrante de R en la posición actual de la lista orginal
        j++; // avanza al siguiente elemnto de la mitad derecha (o sea R)
        k++; //esta es la siguiente casilla libre en la lista original
    }
}

template <typename T>
void mergeSort(vector<T> &list, int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = low + (high - low) / 2;

    mergeSort(list, low, mid);
    mergeSort(list, mid + 1, high);
    merge(list, low, mid, high);
}

template <typename T>
void print(vector<T> &list) {
    for (int i=0; i<list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> list = {15, 7, 3, 9, 12, 5, 2};
    vector<int> listOriginal = list;

    print(list);
    swapSort(list);
    cout << "Lista ordenada: con Swap Sort" << endl;
    print(list);
    list = listOriginal;
    print(list);
    bubbleSort(list);
    cout << "Lista ordenada: con Bubble Sort" << endl;
    print(list);
    list = listOriginal;
    print(list);
    selectionSort(list);
    cout << "Lista ordenada: con Selection Sort" << endl;
    print(list);

    //MERGE SORT
    print(listOriginal);
    cout << "tarea para clase:" << endl;
    cout << "Lista ordenada con Merge Sort" << endl;
    mergeSort(list, 0, list.size() - 1);
    print(list);

    return 0;
}