// Daniela Chavez Ibarra
// A00843645

#include <iostream>
#include <stdexcept>
#include <vector> 
#include <cstdlib> // rand() y srand()
#include <ctime>   // time()
#include <algorithm> //esta es para ordenar el vector de numeros (con sort())
#include <random>
#include <chrono> //  medir el tiempo de ejecucion
using namespace std;

// Búsqueda secuencial
int seqSearch(vector<int> &list, int data) {
    for (int i=0; i<list.size(); i++) {
        if (list[i] == data) {
            return i;
        }
    }
    throw out_of_range("no se encontro el valor");
}

// Búsueda binaria (La lista ya esta ordenada)
template <typename T>
int binarySearch(vector<T> &list, T data) {
    // obtenemos left
    int left = 0;
    // obtenemos right
    int right = list.size() - 1;
    // buscamos el elemento mientras left <= right
    while (left <= right) {
        // obtenemos la mitad
        int mid = (left + right) / 2;
        // comparamos el valor buscado con el valor de la mitad
        if (data == list[mid]) {
            // regresamoe el valor de mid que es el índice del valor encontrado
            return mid;
        } else {
            // preguntamos si el valor buscado es menor que el valor de mid
            if (data < list[mid]) {
                // si es menor
                right = mid - 1;
            } else {
                // es mayor
                left = mid + 1;
            }
            // data < list[mid] ? right = mid - 1 : left = mid + 1;
        }
    }
    // no lo encontramos
    throw out_of_range("No se econtro el valor");
}

int main() {

    //vector<int> list = {3, 5, 6, 8, 11, 12, 13, 16, 27, 35};
    // 1->Nuevo vector de 10,000 numeros:
    int n = 10000;
    vector<int> list(n); //squi se crea el vector con espacio para los 10,000 numeritos
   
   //2->aquí lleno el vector con numeros aleatorios
   srand(time(0)); 
   for (int i=0; i<n; i++) {
        list[i] = rand() % 1000000 + 1; //esta linea es para que gener un num entre 1 y 1,000,000
   }
   // 3->Después de llenarlo , lo ordeno
   sort(list.begin(), list.end());

   //4-> int query y ciclo do-while
   int query;
   do {
        cout << "Ingresa un numero a buscar (1 - 1,000,000) o 0 para salir: ";
        cin >> query;

        if (query==0){
            //si ya quiere terminar
            break; //romper el ciclo
        }
        //aquí pruebas
// Medición de la búsqueda secuencial
        auto startSeq = chrono::high_resolution_clock::now();
        try {
            int index = seqSearch(list, query);
            auto endSeq = chrono::high_resolution_clock::now();
            auto durationSeq = chrono::duration_cast<chrono::microseconds>(endSeq - startSeq).count();
            cout << "[Secuencial] Encontrado en indice " << index << " | Tiempo: " << durationSeq << " us\n";
        } catch (const out_of_range &e) {
            auto endSeq = chrono::high_resolution_clock::now();
            auto durationSeq = chrono::duration_cast<chrono::microseconds>(endSeq - startSeq).count();
            cout << "[Secuencial] " << e.what() << " | Tiempo: " << durationSeq << " us\n";
        }

        // Medición de la búsqueda binaria
        auto startBin = chrono::high_resolution_clock::now();
        try {
            int index = binarySearch(list, query);
            auto endBin = chrono::high_resolution_clock::now();
            auto durationBin = chrono::duration_cast<chrono::microseconds>(endBin - startBin).count();
            cout << "[Binaria]    Encontrado en indice " << index << " | Tiempo: " << durationBin << " us\n";
        } catch (const out_of_range &e) {
            auto endBin = chrono::high_resolution_clock::now();
            auto durationBin = chrono::duration_cast<chrono::microseconds>(endBin - startBin).count();
            cout << "[Binaria]    " << e.what() << " | Tiempo: " << durationBin << " us\n";
        }

       } while (query!=0);
       return 0;

}

