//Daniela Chávez Ibarra 
//A00843645

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include <limits>

#include "../include/Log.h"
#include "../include/Sort.h"

using namespace std;

//Función encargada de leer el archivo .txt y guardar los datos
bool cargarArchivo(const string &fileName, vector<Log> &listaLogs) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error: no se pudo abrir el archivo" << fileName << endl;
        return false;
    }

    listaLogs.clear(); // limpia el vector en caso de reuso
    string month, time, ip, message;
    int day, year;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        ss >> month >> day >> time >> ip;
        getline(ss, message); //sirve para capturar el resto de la linea

        //instanciar el objeto Log inicial
        Log logObj(year, month, day, time, ip, message, "");

        //generar llave cronologica y se asigna el objeto con la llave (key)
        string key = logObj.createKey();
        Log logWithKey(year, month, day, time, ip, message, key);

        //se guarda en listaLogs
        listaLogs.push_back(logWithKey);
    }
    file.close();
    return true;
}

/*
// Función auxiliar para obtener datos de complejidad teórica
void obtenerComplejidad(int opcion, string &mejorCaso, string &peorCaso, string &nombreAlgo) {
    switch (opcion) {
        case 1: nombreAlgo = "Swap Sort";      mejorCaso = "O(n^2)";     peorCaso = "O(n^2)";     break;
        case 2: nombreAlgo = "Bubble Sort";    mejorCaso = "O(n)";       peorCaso = "O(n^2)";     break;
        case 3: nombreAlgo = "Selection Sort"; mejorCaso = "O(n^2)";     peorCaso = "O(n^2)";     break;
        case 4: nombreAlgo = "Insertion Sort"; mejorCaso = "O(n)";       peorCaso = "O(n^2)";     break;
        case 5: nombreAlgo = "Merge Sort";     mejorCaso = "O(n log n)"; peorCaso = "O(n log n)"; break;
        case 6: nombreAlgo = "Quick Sort";     mejorCaso = "O(n log n)"; peorCaso = "O(n^2)";     break;
        case 7: nombreAlgo = "Shell Sort";     mejorCaso = "O(n log n)"; peorCaso = "O(n^2)";     break;
    }
}
*/

int main() {
    vector<Log> listaLogs; //declaré listaLogs porque es la variable donde almacenaré los objetos de Log del archivo .txt seleccionado por el usuario
    char continuar = 's';

    do{
        int opcionArchivo = 0;
        int opcionAlgoritmo = 0; 
        string rutaArchivo = "";
        string nombreArchivo = "";

        cout << "EVIDENCIA 1" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Cargar log607-1.txt " << endl;
        cout << "2. Cargar log607-2.txt " << endl;
        cout << "Seleccione el archivo a procesar: ";
        cin >> opcionArchivo;

        if (opcionArchivo == 1) {
            rutaArchivo = "../data/log607-1.txt";
        }
        else if (opcionArchivo == 2) {
            rutaArchivo = "../data/log607-2.txt";
        }
        else {
            cout << "Opción no valida. Saliendo del programa" << endl;
            return 1;
        }

        cout << "\nCargando datos desde: " << rutaArchivo << "..." << endl;
        if (!cargarArchivo(rutaArchivo, listaLogs)) {
            return 1;
        }
        cout << "Registros cargados en listaLogs: " << listaLogs.size() << endl;

        // ORDENAR LOS DATOS

        
    } while (continuar == 's' || continuar == 'S');

    cout << "\nGracias por utilizar el sistema de ordenamiento de logs. ¡Programa finalizado!" << endl;
    return 0;
}