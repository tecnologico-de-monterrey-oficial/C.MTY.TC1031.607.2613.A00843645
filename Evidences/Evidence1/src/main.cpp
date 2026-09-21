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


// Función para obtener datos de complejidad teórica
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
        cout << "1. Cargar log607-1.txt (desordenado)" << endl;
        cout << "2. Cargar log607-2.txt (casi ordenado) " << endl;
        cout << "Seleccione el archivo a procesar: ";
        cin >> opcionArchivo;

        if (opcionArchivo == 1) {
            rutaArchivo = "../data/log607-1.txt";
            nombreArchivo = "log607-1.txt (desordenado)";
        }
        else if (opcionArchivo == 2) {
            rutaArchivo = "../data/log607-2.txt";
            nombreArchivo = "log607-2.txt (casi ordenado)";
        }
        else {
            cout << "Opción no valida. Saliendo del programa" << endl;
            continue;
        }

        cout << "\nCargando datos desde " << nombreArchivo << "..." << endl;
        if (!cargarArchivo(rutaArchivo, listaLogs)) {
            continue;
        }
        cout << "Registros cargados exitosamente: " << listaLogs.size() << endl;
        // ORDENAR LOS DATOS

        //seleccion de algoritmo
        cout << "\nSeleccione el algoritmo de ordenamiento:" << endl;
        cout << "1. Swap Sort" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Insertion Sort" << endl;
        cout << "5. Merge Sort" << endl;
        cout << "6. Quick Sort" << endl;
        cout << "7. Shell Sort" << endl;
        cout << "Ingrese el número del algoritmo: ";
        cin >> opcionAlgoritmo;

        if (opcionAlgoritmo < 1 || opcionAlgoritmo > 7) {
            cout << "Opción de algoritmo inválida." << endl;
            continue;
        }

        // Pedir prediccion al usuario previo a ordenar3
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
        string prediccionRapidez, justificacionPrediccion;
        
        cout << "\n--- PREDICCIÓN ANTES DE LA EJECUCIÓN ---" << endl;
        cout << "¿Qué tan rápido o lento esperas que sea esta corrida? (Ej: Muy rápido, Moderado, Muy lento): ";
        getline(cin, prediccionRapidez);
        cout << "¿Por qué esperas ese comportamiento? (Justificación basada en ordenamiento/algoritmo): ";
        getline(cin, justificacionPrediccion); 

        // ahora ya pasa a la ejecucion y a la medicion del tiempo
        long long comparisons = 0;
        long long swaps = 0;
        string nombreAlgo, mejorCaso, peorCaso;
        obtenerComplejidad(opcionAlgoritmo, mejorCaso, peorCaso, nombreAlgo);

        cout << "\nEjecutando " << nombreAlgo << "..." << endl;
        auto inicio = chrono::high_resolution_clock::now();
        
        switch (opcionAlgoritmo) {
            case 1: swapSort(listaLogs, comparisons, swaps); break;
            case 2: bubbleSort(listaLogs, comparisons, swaps); break;
            case 3: selectionSort(listaLogs, comparisons, swaps); break;
            case 4: insertionSort(listaLogs, comparisons, swaps); break;
            case 5: if (!listaLogs.empty()) mergeSort(listaLogs, 0, listaLogs.size() - 1); break;
            case 6: if (!listaLogs.empty()) quickSort(listaLogs, 0, listaLogs.size() - 1); break;
            case 7: shellSort(listaLogs); break;
        }

        auto fin = chrono::high_resolution_clock::now();
        auto duracion = chrono::duration_cast<chrono::milliseconds>(fin - inicio).count();

        // MOSTRARE LOS RESULTADOS
        cout << "\n               RESUMEN              " << endl;
        cout << "...................................." << endl;
        cout << "Algoritmo elegido:     " << nombreAlgo << endl;
        cout << "Archivo utilizado:     " << nombreArchivo << endl;
        cout << "Tamaño de datos:       " << listaLogs.size() << " registros" << endl;
        cout << "Tiempo de ejecución:   " << duracion << " ms" << endl;
        cout << "Complejidad Teórica:   Mejor caso: " << mejorCaso << " | Peor caso: " << peorCaso << endl;
        
        if (opcionAlgoritmo >= 1 && opcionAlgoritmo <= 4) {
            cout << "Comparaciones:         " << comparisons << " | Swaps: " << swaps << endl;
        }

        cout << "\n--- EVALUACIÓN DE PREDICCION ---" << endl;
        cout << "Predicción inicial:    " << prediccionRapidez << " (" << justificacionPrediccion << ")" << endl;
        
        string coincidio;
        cout << "¿El tiempo medido (" << duracion << " ms) coincidió con tu predicción inicial? (Sí/No y por qué): ";
        getline(cin, coincidio);


        // Ahora guarda estos resultados en OUTPUT608.TXT 
        string archivoSalida = "output608.txt";
        ofstream archivo(archivoSalida);
        if (archivo.is_open()) {
            for (const auto &registro : listaLogs) {
                archivo << registro.getFormattedLog() << "\n";
            }
            archivo.close();
            cout << "\n Datos ordenados exportados exitosamente a '" << archivoSalida << "'." << endl;
        } else {
            cerr << "\n Error al crear el archivo 'output608.txt'." << endl;
        }

        //Preguntar si quiere repetir el proceso
        cout << "\n¿Desea realizar otra corrida para comparar? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "\nGracias por utilizar el sistema de ordenamiento de logs. ¡Programa finalizado!" << endl;
    return 0;
}