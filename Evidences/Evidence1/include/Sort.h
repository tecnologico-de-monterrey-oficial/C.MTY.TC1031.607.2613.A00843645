#ifndef Sort_h
#define Sort_h

#include <vector>
using namespace std;

template <typename T> 
void swap(vector<T> &list, int i, int j) {
    if (i != j) {
        T aux = list[i];
        list[i] = list[j];
        list[j] = aux;
    }
}

// >> Algoritmos de ordenamiento

// Swap Sort
template <typename T> 
void swapSort(vector<T> &list, long long &comparisons, long long &swaps) {
    comparisons = 0;
    swaps = 0;
    //iteramos todos los elementos de la lista hasta el penúltimo 
    for (size_t i = 0; i < list.size() - 1; i++){
        for (size_t j = i + 1; j < list.size(); j++) {
            //comparacion para determinar si es menor
            comparisons++;
            if (list[j] < list[i])
            {
                //si es menor
                //intercambiamos los valores
                swap(list, i, j);
                swaps++;
            }
        }
    }
}

// Bubble Sort
template <typename T> 
void bubbleSort(vector<T> &list, long long &comparisons, long long &swaps) {
    comparisons = 0;
    swaps = 0;
    //iterar desde n hasta 1
    bool change = true;
    for (int i = list.size() - 1; i > 0 && change; i--) {
        //cambio el valor de change a falso
        change = false;
        for (int j = 0; j < i; j++) {
            //la condicion
            comparisons++;
            if (list[j] > list[j+1]) { //comparamos el valor de j con el valor de j+1 para determinar si es mayor
                swap(list, j, j+1);
                swaps++;
                change = true;
            }
        }
    }
}

// Selection Sort
template <typename T>
void selectionSort(vector<T> &list, long long &comparisons, long long &swaps) {
    comparisons = 0;
    swaps = 0;
    //asume que el primero de la lista es el más pequeño y comienza a comparar 
    int n = list.size(); //conocer el tamano de la lista 
    for (int i = 0; i < n - 1; i++) { //aqui puse un (i<n-1) porque se supone que si llega al penultimo valor y hace sort -> el ultimo valor ya estaría acomodado
        //hacemos el valor de i como el mas chico
        int min = i;
        for (int j = i + 1; j < n; j++){ //aqui puse a j como i+1 porque le interesa hacer la comparación con el siguiente.
            //ahora si, si es menor al valor minimo 
            comparisons++;
            if (list[j] < list[min]) { //si es menor
                //actualizar el valor de min 
                min = j; //ahora el numero que reconoció como más pequeño se guardará en la variable minimo 
            }
        }
        //ya que lo identificas, haces swap
        if (min != i) {
            swap(list, min, i);
            swaps++;
        }
    }
}


// Insertion Sort
template <typename T>
void insertionSort(vector<T> &list, long long &comparisons, long long &swaps){
    comparisons = 0;
    swaps = 0;
    //aqui el primero se asume que ya esta ordenado entonces empieza con el segundo 
    for (size_t i = 1; i < list.size(); i++) {
        //iteramos desde i hasta 0
        //declaramos un contador para ver donde vamos
        int j = i;
        while (j > 0) {
            comparisons++;
            if (list[j] < list[j-1]) {
                //aqui ya no ocupas hacer if porque va a netrar siempre y cuando sí sea menor entonces te pasas diretco al SWAP
                //intercambiamos j con j-1
                swap(list, j, j-1);
                swaps++;
                //decrementamos 
                j--;
            } else {
                break;
            }
        }
    }
}


// Merge Sort
template <typename T> 
void merge(vector<T> &list, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<T> L(n1);
    vector<T> R(n2);

    for (int i = 0; i < n1; i++) L[i] = list[low + i];
    for (int j = 0; j < n2; j++) R[j] = list[mid + 1 + j];

    int i = 0, j = 0, k = low;

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

    while (i < n1) {
        list[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        list[k] = R[j];
        j++;
        k++;
    }
}
template <typename T>
void mergeSort(vector<T> &list, int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(list, low, mid);
    mergeSort(list, mid + 1, high);
    merge(list, low, mid, high);
}

// Quick Sort
template <typename T>
int getPivot(vector<T> &list, int left, int right){
    //crear variable aux con el valor de left-1
    int aux = left-1;
    //crear variable pivot con el valor de right
    int pivot = right;
    //iteramos desde left hasta pivot - 1 (< pivot)
    for (int i=left; i<pivot; i++){
        //comparamos si el valor de pivot > al valor de i (index)
        if (list[pivot] > list[i]) {
            //incrementamos el valor de i 
            aux++;
            // intercambiamos aux con i 
            swap(list, aux, i);
        }
    }
    // incrementamos aux
    aux++;
    // intercambiamos aux con pivot
    swap(list, aux, pivot);
    //regresamos aux
    return aux;
}

// QUICK SORT (pt. 1) (en clase) (esta despues le llama a la función que está arriba)
template <typename T>
void quickSort(vector<T> &list, int left, int right) {
    //recursividad si left<right
    if (left < right) {
        int pivot = getPivot(list, left, right);
        //ordenamos la lista de lado izq del pivote
        quickSort(list, left, pivot-1);

        quickSort(list, pivot + 1, right);
    }
}

// ALGORITMO EXTRA (Shell Sort)
template <typename T>
void shellSort(vector<T> &list) {
    int n = list.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            T temp = list[i];
            int j;
            for (j = i; j >= gap && list[j - gap] > temp; j -= gap) {
                list[j] = list[j - gap];
            }
            list[j] = temp;
        }
    }
}

#endif /* Sort_h */