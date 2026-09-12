// Daniela Chávez Ibarra
// A00843645

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <fstream>

using namespace std;

// 

template <typename T> 
void swap(vector<T> &list, int i, int j)
{
    if (i != j){
        //creamos variable temporal
        T aux = list[i];
        //cambiamos i por j
        list[i] = list[j];
        //cambiamos j por aux
        list[j] = aux;
    }
}

template <typename T> 
void swapSort(vector<T> &list, long long &comparisons, long long &swaps) {
    comparisons = 0;
    swaps = 0;
    //iteramos todos los elementos de la lista hasta el penúltimo 
    for (int i = 0; i < list.size() - 1; i++){
        for (int j = i + 1; j < list.size(); j++) {
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

template <typename T>
void insertionSort(vector<T> &list, long long &comparisons, long long &swaps){
    comparisons = 0;
    swaps = 0;
    //aqui el primero se asume que ya esta ordenado entonces empieza con el segundo 
    for (int i = 1; i < list.size(); i++) {
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

// QUICK SORT (pt. 2)
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

template <typename T>
void print(vector<T> &list) {
    for (int i=0; i<list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

//  FUNCIONES PARA CREAR LISTAS CON DATOS ALEATORIOS 

vector<int> generateRandomInts(int size) {
    vector<int> vec(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 100000);
    for (int i = 0; i < size; i++) vec[i] = dis(gen);
    return vec;
}

vector<double> generateRandomDoubles(int size) {
    vector<double> vec(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(1.0, 100000.0);
    for (int i = 0; i < size; i++) vec[i] = dis(gen);
    return vec;
}

vector<string> generateRandomStrings(int size) {
    vector<string> vec(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> charDis('a', 'z');
    for (int i = 0; i < size; i++) {
        string s = "";
        for (int j = 0; j < 5; j++) s += (char)charDis(gen);
        vec[i] = s;
    }
    return vec;
}

// -> MEDICIÓN DE TIEMPOS Y EXPORTACIÓN A CSV 

template <typename T>
long long measureTime(vector<T> list, int algoType) {
    long long comp = 0, swp = 0;
    auto start = chrono::high_resolution_clock::now();
    
    switch(algoType) {
        case 1: swapSort(list, comp, swp); break;
        case 2: bubbleSort(list, comp, swp); break;
        case 3: selectionSort(list, comp, swp); break;
        case 4: insertionSort(list, comp, swp); break;
        case 5: mergeSort(list, 0, list.size() - 1); break;
        case 6: quickSort(list, 0, list.size() - 1); break;
        case 7: shellSort(list); break;
    }

    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

void runBenchmarkAndSaveCSV() {
    cout << "\nProcesando pruebas y generando el archivo 'tiempos.csv'..." << endl;
    ofstream file("tiempos.csv");

    vector<string> algoNames = {"swapSort", "bubbleSort", "selectionSort", "insertionSort", "mergeSort", "quickSort", "shellSort"};
    
    for (int i = 1; i <= 7; i++) {
        // Generar para Tipo 1: int
        long long t1000_int = measureTime(generateRandomInts(1000), i);
        long long t10000_int = measureTime(generateRandomInts(10000), i);
        // Evitar tiempos excesivos en O(n^2) para 100,000 elementos
        long long t100000_int = (i >= 5) ? measureTime(generateRandomInts(100000), i) : -1;

        file << algoNames[i-1] << ",int," << t1000_int << "," << t10000_int << "," << t100000_int << "\n";
        cout << algoNames[i-1] << ", int, " << t1000_int << ", " << t10000_int << ", " << t100000_int << endl;

        // Generar para Tipo 2: double
        long long t1000_dbl = measureTime(generateRandomDoubles(1000), i);
        long long t10000_dbl = measureTime(generateRandomDoubles(10000), i);
        long long t100000_dbl = (i >= 5) ? measureTime(generateRandomDoubles(100000), i) : -1;

        file << algoNames[i-1] << ",double," << t1000_dbl << "," << t10000_dbl << "," << t100000_dbl << "\n";

        // Generar para Tipo 3: string
        long long t1000_str = measureTime(generateRandomStrings(1000), i);
        long long t10000_str = measureTime(generateRandomStrings(10000), i);
        long long t100000_str = (i >= 5) ? measureTime(generateRandomStrings(100000), i) : -1;

        file << algoNames[i-1] << ",string," << t1000_str << "," << t10000_str << "," << t100000_str << "\n";
    }

    file.close();
    cout << "\n Archivo 'tiempos.csv' generado exitosamente." << endl;
}

// --- MENÚ PRINCIPAL ---

int main() {
    int option;
    do {
        cout << "    ACTIVIDAD 1.5 - ALGORITMOS DE SORT" << endl;
        cout << "1. Probar un algoritmo con lista de prueba corta" << endl;
        cout << "2. Generar análisis comparativo (Archivo CSV)" << endl;
        cout << "0. Salir" << endl;
        cout << "Selecciona una opción: ";
        cin >> option;

        if (option == 1) {
            vector<int> list = {15, 7, 3, 9, 12, 5, 2};
            long long comp = 0, swp = 0;
            int algoOpt;

            cout << "\nVector inicial: ";
            print(list);

            cout << "\n1. Swap Sort\n2. Bubble Sort\n3. Selection Sort\n4. Insertion Sort\n5. Merge Sort\n6. Quick Sort\n7. Shell Sort\nElige un algoritmo: ";
            cin >> algoOpt;

            auto start = chrono::high_resolution_clock::now();
            switch (algoOpt) {
                case 1: swapSort(list, comp, swp); cout << "Comparaciones: " << comp << " | Swaps: " << swp << endl; break;
                case 2: bubbleSort(list, comp, swp); cout << "Comparaciones: " << comp << " | Swaps: " << swp << endl; break;
                case 3: selectionSort(list, comp, swp); cout << "Comparaciones: " << comp << " | Swaps: " << swp << endl; break;
                case 4: insertionSort(list, comp, swp); cout << "Comparaciones: " << comp << " | Swaps: " << swp << endl; break;
                case 5: mergeSort(list, 0, list.size() - 1); break;
                case 6: quickSort(list, 0, list.size() - 1); break;
                case 7: shellSort(list); break;
            }
            auto end = chrono::high_resolution_clock::now();

            cout << "Lista ordenada: ";
            print(list);
            cout << "Tiempo: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

        } else if (option == 2) {
            runBenchmarkAndSaveCSV();
        }

    } while (option != 0);

    return 0;
}