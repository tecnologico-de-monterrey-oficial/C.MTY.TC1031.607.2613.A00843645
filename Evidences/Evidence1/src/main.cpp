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
#include "../include/Search.h"

using namespace std;

//Función encargada de leer el archivo .txt y guardar los datos
bool cargarArchivo(const string &fileName, vector<Log> &listaLogs) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error: no se pudo abrir el archivo " << fileName << endl;
        return false;
    }

    listaLogs.clear(); // limpia el vector en caso de reuso
    string month, time, ip, message;
    int day, year;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        // CORRECCIÓN 1: Se agrega 'year' en la extracción del stream
        ss >> month >> day >> year >> time >> ip;
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

// checkpoint 3: busqueda por rangos 
// Funcion para hacer la busqueda por rango de fecha 
void realizarBusquedaPorRango(const vector<Log> &listaLogs) {
    if (listaLogs.empty()) {
        cout << "\nError: La lista de logs esta vacia." << endl;
        return;
    }

    string monthStart, timeStart, monthEnd, timeEnd;
    int dayStart, yearStart, dayEnd, yearEnd;

    cout << "-------------------------------" << endl;
    cout << "Busqueda por rango de fecha" << endl;
    cout << "-------------------------------" << endl;


    // Leer Fecha/Hora INICIO
    cout << "--- Ingrese la Fecha INICIAL ---" << endl;
    cout << "Mes (ej. Sep): "; cin >> monthStart;
    cout << "Dia (ej. 29): "; cin >> dayStart;
    cout << "Año (ej. 2024): "; cin >> yearStart;
    cout << "Hora (HH:MM:SS, ej. 14:00:00): "; cin >> timeStart;

    // Leer Fecha/Hora FINAL
    cout << "\n--- Ingrese la Fecha FINAL ---" << endl;
    cout << "Mes (ej. Oct): "; cin >> monthEnd;
    cout << "Dia (ej. 05): "; cin >> dayEnd;
    cout << "Año (ej. 2024): "; cin >> yearEnd;
    cout << "Hora (HH:MM:SS, ej. 18:00:00): "; cin >> timeEnd;

    // Crear objetos Log para las fechas de inicio y fin
    Log dummyStart(yearStart, monthStart, dayStart, timeStart, "0.0.0.0", "", "");
    Log dummyEnd(yearEnd, monthEnd, dayEnd, timeEnd, "0.0.0.0", "", "");

    Log targetStart(yearStart, monthStart, dayStart, timeStart, "0.0.0.0", "", dummyStart.createKey());
    Log targetEnd(yearEnd, monthEnd, dayEnd, timeEnd, "0.0.0.0", "", dummyEnd.createKey());


    // Medición de tiempo de Búsqueda Binaria de Rangos
    auto inicio = chrono::high_resolution_clock::now();

    int startIdx = lowerBound(listaLogs, targetStart);
    int endIdx = upperBound(listaLogs, targetEnd);

    auto fin = chrono::high_resolution_clock::now();
    auto duracion = chrono::duration_cast<chrono::microseconds>(fin - inicio).count();

    if (startIdx <= endIdx && startIdx != -1 && endIdx != -1 && startIdx < (int)listaLogs.size()) 
    {
        int totalEncontrados = endIdx - startIdx + 1;
        cout << "\n Busqueda completada en " << duracion << " microsegundos (O(log n))" << endl;
        cout << "Registros encontrados en el rango: " << totalEncontrados << endl;
        cout << "Indice inicial: " << startIdx << " | Indice final: " << endIdx << endl;

        // Exportar resultados a un archivo independiente
        string archivoRango = "range607.txt";
        ofstream archivo(archivoRango);
        if (archivo.is_open()) {
            for (int i = startIdx; i <= endIdx; i++) {
                archivo << listaLogs[i].getFormattedLog() << "\n";
            }
            archivo.close();
            cout << "Registros del rango guardados en '" << archivoRango << "'." << endl;
        }

        // Mostrar muestra en pantalla
        char verMuestra;
        cout << "\n¿Deseas visualizar los primeros registros encontrados en consola? (s/n): ";
        cin >> verMuestra;
        if (verMuestra == 's' || verMuestra == 'S') {
            int limite = min(10, totalEncontrados);
            cout << "\n--- Mostrando primeros " << limite << " registros del rango ---" << endl;
            for (int i = startIdx; i < startIdx + limite; i++) {
                cout << listaLogs[i].getFormattedLog() << endl;
            }
        }
    } else {
        cout << "\n No se encontraron registros dentro del rango de fechas especificado." << endl;
    }
}
    

int main() {
    vector<Log> listaLogs;
    char continuar = 's';
    // CORRECCIÓN 2: Renombrado a datosOrdenados para coincidir con la validación de abajo
    bool datosOrdenados = false; 

    do {
        int opcionArchivo = 0;
        int opcionAlgoritmo = 0; 
        string rutaArchivo = "";
        string nombreArchivo = "";

        cout << "EVIDENCIA 1" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Cargar log607-1.txt (desordenado)" << endl;
        cout << "2. Cargar log607-2.txt (casi ordenado) " << endl;
        cout << "Seleccione el archivo a procesar: ";
    // Validar que la entrada sea un entero válido
        if (!(cin >> opcionArchivo)) {
            cout << "\n[!] Entrada inválida. Debe ingresar un número (1 o 2)." << endl;
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
            continue;
        }

        // Asignar rutas ajustadas a la estructura estándar del proyecto
        if (opcionArchivo == 1) {
            // Nota: Si ejecutas desde la raíz del proyecto, usa "data/log607-1.txt". 
            // Si ejecutas desde dentro de /src, usa "../data/log607-1.txt".
            rutaArchivo = "data/log607-1.txt"; 
            nombreArchivo = "log607-1.txt (desordenado)";
        }
        else if (opcionArchivo == 2) {
            rutaArchivo = "data/log607-2.txt";
            nombreArchivo = "log607-2.txt (casi ordenado)";
        }
        else {
            cout << "\n[!] Opción no válida. Ingrese únicamente 1 o 2." << endl;
            continue;
        }

        cout << "\nCargando datos desde " << nombreArchivo << "..." << endl;
        
        // Intenta abrir con ruta estándar; si falla, intenta con ruta previa por si se ejecuta desde /src
        if (!cargarArchivo(rutaArchivo, listaLogs)) {
            string rutaAlternativa = "../" + rutaArchivo;
            cout << "Intentando ruta alternativa: " << rutaAlternativa << "..." << endl;
            
            if (!cargarArchivo(rutaAlternativa, listaLogs)) {
                cout << " No se pudo encontrar el archivo en ninguna ruta." << endl;
                cout << "Verifica que ejecutes el ejecutable desde la raíz del proyecto o desde la carpeta src." << endl;
                continue;
            }
        }
        cout << "Registros cargados exitosamente: " << listaLogs.size() << endl;
        datosOrdenados = false; // Al cargar archivo nuevo, aún no está ordenado

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
            cout << "Opcion de algoritmo invalida." << endl;
            continue;
        }

        // Pedir prediccion al usuario previo a ordenar
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
        string prediccionRapidez, justificacionPrediccion;
        
        cout << "\n--- PREDICCION ANTES DE LA EJECUCION ---" << endl;
        cout << "¿Que tan rapido o lento esperas que sea esta corrida? (Ej: Muy rapido, Moderado, Muy lento): ";
        getline(cin, prediccionRapidez);
        cout << "¿Por que esperas ese comportamiento? (Justificacion basada en ordenamiento/algoritmo): ";
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
        datosOrdenados = true; // CORRECCIÓN 3: Marcamos que ya fueron ordenados exitosamente

        // MOSTRARE LOS RESULTADOS
        cout << "\n               RESUMEN              " << endl;
        cout << "...................................." << endl;
        cout << "Algoritmo elegido:     " << nombreAlgo << endl;
        cout << "Archivo utilizado:     " << nombreArchivo << endl;
        cout << "Tamano de datos:       " << listaLogs.size() << " registros" << endl;
        cout << "Tiempo de ejecucion:   " << duracion << " ms" << endl;
        cout << "Complejidad Teorica:   Mejor caso: " << mejorCaso << " | Peor caso: " << peorCaso << endl;
        
        if (opcionAlgoritmo >= 1 && opcionAlgoritmo <= 4) {
            cout << "Comparaciones:         " << comparisons << " | Swaps: " << swaps << endl;
        }

        cout << "\n--- EVALUACIÓN DE PREDICCION ---" << endl;
        cout << "Prediccion inicial:    " << prediccionRapidez << " (" << justificacionPrediccion << ")" << endl;
        
        string coincidio;
        cout << "¿El tiempo medido (" << duracion << " ms) coincidio con tu prediccion inicial? (Si/No y por que): ";
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

        // checkpoint 3: busqueda por rangos
        char realizarBusqueda;
        cout << "\n¿Deseas realizar una busqueda por rango de fechas en estos datos ordenados? (s/n): ";
        cin >> realizarBusqueda;

        if ((realizarBusqueda == 's' || realizarBusqueda == 'S') && datosOrdenados) {
            realizarBusquedaPorRango(listaLogs);
        }

        //Preguntar si quiere repetir el proceso
        cout << "\n¿Desea realizar otra corrida para comparar? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "\nGracias por utilizar el sistema de ordenamiento de logs. ¡Programa finalizado!" << endl;
    return 0;
}