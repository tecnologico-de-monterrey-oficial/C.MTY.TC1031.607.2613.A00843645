#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <map>
#include <unordered_map>
#include "include/Queue.h"
#include "include/DoublyLinkedList.h"
#include "include/Stack.h"
#include "include/Log.h"

using namespace std;

bool cargarArchivoAQueue(const string &fileName, Queue<Log> &filaLogs) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error: no se pudo abrir el archivo " << fileName << "\n";
        return false;
    }

    string month, time, ip, message;
    int day, year;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        ss >> month >> day >> year >> time >> ip;
        getline(ss, message); // sirve para capturar el resto de la linea

        // instanciar el objeto Log inicial
        Log logObj(year, month, day, time, ip, message, "");

        // generar llave cronologica y se asigna el objeto con la llave (key)
        string key = logObj.createKey();
        Log logWithKey(year, month, day, time, ip, message, key);

        // se guarda en la Fila (Queue)
        filaLogs.push(logWithKey);
    }
    file.close();
    return true;
}

int main() {
    Queue<Log> filaLogs;
    DoublyLinkedList<Log> listaLogs;
    
    // Variables de control para las opciones del menu
    bool listaOrdenada = false;
    string ultimoDiaBuscado = "";
    bool busquedaRealizada = false;

    // Carga inicial automatica del archivo (puedes adaptarlo para pedir el archivo si lo prefieres)
    string archivoElegido = "log608-1.txt";
    cout << "Cargando archivo " << archivoElegido << "...\n";
    
    if (cargarArchivoAQueue(archivoElegido, filaLogs)) {
        while (!filaLogs.isEmpty()) {
            Log logActual = filaLogs.pop();
            listaLogs.addLast(logActual);
        }
        cout << "Carga y transferencia completadas con exito. Total de registros: " << listaLogs.getSize() << "\n\n";
    } else {
        return 1;
    }

    int opcion = 0;
    do {
        cout << "=== MENU PRINCIPAL ==\n";
        cout << "1. Ordenar por fecha y hora\n";
        cout << "2. Buscar logs por dia\n";
        cout << "3. Mostrar logs por dia en orden descendente\n";
        cout << "4. Estadisticas del archivo\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "\n--- OPCION 1: ORDENAR REGISTROS ---\n";
                // Validar si ya esta ordenada
                bool yaOrdenada = true;
                for (int i = 0; i < listaLogs.getSize() - 1; i++) {
                    if (listaLogs[i] > listaLogs[i + 1]) {
                        yaOrdenada = false;
                        break;
                    }
                }

                if (yaOrdenada && listaLogs.getSize() > 0) {
                    cout << "La lista ya esta ordenada. No es necesario ordenar de nuevo.\n";
                    listaOrdenada = true;
                    break;
                }

                string prediccion;
                cout << "Ingrese su prediccion de crecimiento (ej. O(n log n) o O(n^2)): ";
                cin >> ws; // limpiar buffer
                getline(cin, prediccion);

                auto inicio = chrono::high_resolution_clock::now();
                
                // Llamada a tu metodo sort de la DoublyLinkedList
                listaLogs.sort();
                
                auto fin = chrono::high_resolution_clock::now();
                chrono::duration<double, milli> duracion = fin - inicio;

                listaOrdenada = true;
                cout << "Lista ordenada exitosamente.\n";
                cout << "Algoritmo usado: Bubble Sort (o el que implementaste en Doubly)\n";
                cout << "Archivo: " << archivoElegido << "\n";
                cout << "Tamano de los datos: " << listaLogs.getSize() << "\n";
                cout << "Tiempo de ejecucion: " << duracion.count() << " ms\n";
                cout << "Prediccion del usuario: " << prediccion << "\n";

                // Generar output608.out
                ofstream outFile("output608.out");
                if (outFile.is_open()) {
                    for (int i = 0; i < listaLogs.getSize(); i++) {
                        outFile << listaLogs[i].getFormattedLog() << "\n";
                    }
                    outFile.close();
                    cout << "Archivo output608.out generado correctamente.\n";
                } else {
                    cout << "Error al crear el archivo de salida.\n";
                }
                break;
            }
            case 2: {
                cout << "\n--- OPCION 2: BUSCAR LOGS POR DIA ---\n";
                if (!listaOrdenada) {
                    cout << "Error: La lista aun no esta ordenada. Ejecute la opcion 1 primero.\n";
                    break;
                }

                cout << "Ingrese el dia a buscar (Ejemplo: Sep 14): ";
                cin >> ws;
                getline(cin, ultimoDiaBuscado);

                int encontrados = 0;
                cout << "Resultados encontrados para " << ultimoDiaBuscado << ":\n";
                
                // Recorrido eficiente deteniendose al cruzar el dia
                for (int i = 0; i < listaLogs.getSize(); i++) {
                    string logFmt = listaLogs[i].getFormattedLog();
                    // Verificamos si el inicio del log coincide con el mes y dia buscado
                    if (logFmt.rfind(ultimoDiaBuscado, 0) == 0) {
                        cout << logFmt << "\n";
                        encontrados++;
                    } else if (encontrados > 0) {
                        // Si ya habiamos encontrado y el mes/dia actual ya paso, podemos romper para optimizar
                        // (Asumiendo formato estricto o comparacion de llaves)
                        break;
                    }
                }

                if (encontrados == 0) {
                    cout << "No se encontraron registros para el dia especificado.\n";
                } else {
                    cout << "Total de registros encontrados: " << encontrados << "\n";
                    busquedaRealizada = true;
                }
                break;
            }
            case 3: {
                cout << "\n--- OPCION 3: MOSTRAR EN ORDEN DESCENDENTE (USANDO PILA) ---\n";
                if (!busquedaRealizada) {
                    cout << "Aun no se ha realizado ninguna busqueda. Ejecute la opcion 2 primero.\n";
                    break;
                }

                Stack<Log> pilaDescendente;
                // Volvemos a filtrar y meter a la Pila los elementos del dia buscado
                for (int i = 0; i < listaLogs.getSize(); i++) {
                    string logFmt = listaLogs[i].getFormattedLog();
                    if (logFmt.rfind(ultimoDiaBuscado, 0) == 0) {
                        pilaDescendente.push(listaLogs[i]);
                    }
                }

                cout << "Mostrando registros en orden descendente (inverso):\n";
                while (!pilaDescendente.isEmpty()) {
                    Log l = pilaDescendente.pop();
                    cout << l.getFormattedLog() << "\n";
                }
                break;
            }
            case 4: {
                cout << "\n--- OPCION 4: ESTADISTICAS DEL ARCHIVO ---\n";
                cout << "Total de registros: " << listaLogs.getSize() << "\n";
                // Aqui puedes integrar tus mapas de frecuencia (std::map / unordered_map)
                cout << "(Modulo de estadisticas listo para integrarse con map)\n";
                break;
            }
            case 5:
                cout << "Saliendo del programa. Hasta luego!\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
        cout << "\n";
    } while (opcion != 5);

    return 0;
}