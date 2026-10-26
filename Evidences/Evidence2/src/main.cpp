#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "include/Queue.h"
#include "include/DoublyLinkedList.h"
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

        // se guarda en la Fila (Queue) en lugar del vector
        filaLogs.push(logWithKey);
    }
    file.close();
    return true;
}

int main() {
    Queue<Log> filaLogs;
    DoublyLinkedList<Log> listaLogs;

    if (cargarArchivoAQueue("log608-1.txt", filaLogs)) {
        // Transferir de la Fila a la Lista Doblemente Ligada
        while (!filaLogs.isEmpty()) {
            Log logActual = filaLogs.pop();
            listaLogs.addLast(logActual);
        }
        cout << "Carga y transferencia completadas con exito.\n";
    }

    return 0;
}