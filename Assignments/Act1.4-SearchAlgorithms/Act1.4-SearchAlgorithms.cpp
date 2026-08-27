// Daniela Chavez Ibarra
// A00843645

#include <iostream>
#include <cmath>
using namespace std;

int busquedaSecuencial(vector<int> &list, int data) { //pedir la lista y pedir el tamano de la lista
   
   for (int i = 0; i < list.size(); i++) {
        if (list[i] == data) {
            return i;
        }
    }
    return -1; //retornar -1 si no se encuentra el elemento
}

//Busqueda binaria (apoyo del profe)
template <typename T>
int binarySearch(vector<T> &list, T data){
    //obtenemos left
    int left = 0;
    //obtenemos right
    int right = list.size()-1;
    //buscamos el elemento mientras left <= right
    while (left <= right) {
        //obtenemos la mitad
        int mid = (left+right)/2;
        //comparamos el valor buscado con el valor de la mitad
        if (data == list[mid]) {
            //regresamos el valor de mid que es el indice del valor encontrado
            return mid;
        }
        else {
            //pregunta si el valor buscado es menor que el valor de mid 
            if (data < list[mid]){
                //si es menor 
                right = mid-1;
            }
            else {
                // si es mayor
                left = mid+1;
            }
            // TAREA: buscar cómo hacer esta línea de abajo una recursiva 
            // data < list[mid] ? right = mid-1 : left = mid+1;
        }
    } 
    // no lo encontramos
    throw out_of_range("El valor no se encuentra en la lista");
}


int main() {
 
    vector<int> list = {3, 5, 6, 8, 11, 12, 13, 16, 27, 35};

    try {
        int index = binarySearch(list, 11);
        cout << "El valor se encuentra en: " << index <<endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}