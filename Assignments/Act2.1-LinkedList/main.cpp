//Daniela Chávez Ibarra
//A00843645
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "LinkedList.h"

using namespace std;

// Funcion auxiliar para limpiar el buffer de cin
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Generador de datos aleatorios generico
template <typename T>
T generarDatoAleatorio(int i) {
    return static_cast<T>((rand() % 100) + 1);
}

// Especializacion para string
template <>
string generarDatoAleatorio<string>(int i) {
    string palabras[] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Zeta", "Eta", "Theta"};
    return palabras[rand() % 8] + "_" + to_string(i + 1);
}

// Menu generico reutilizable
template <typename T>
void ejecutarMenu(LinkedList<T>& lista) {
    int opcion = -1;
    do {
        cout << "\n********\n";
        cout << "         MENU DE OPERACIONES            \n";
        cout << "----------------------------------------\n";
        cout << "1. Agregar al principio (addFirst)\n";
        cout << "2. Agregar al final (addLast)\n";
        cout << "3. Insertar despues de una posicion (insert)\n";
        cout << "4. Borrar un elemento por valor (deleteData)\n";
        cout << "5. Borrar un elemento por posicion (deleteAt)\n";
        cout << "6. Obtener elemento por posicion (getData)\n";
        cout << "7. Actualizar elemento por valor (updateData)\n";
        cout << "8. Actualizar elemento por posicion (updateAt)\n";
        cout << "9. Encontrar posicion de un elemento (findData)\n";
        cout << "10. Leer con operador []\n";
        cout << "11. Actualizar con operador []\n";
        cout << "12. Duplicar lista con operador =\n";
        cout << "13. Mostrar contenido de la lista\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            limpiarBuffer();
            cout << "Opcion invalida.\n";
            continue;
        }

        try {
            if (opcion == 1) {
                T dato;
                cout << "Ingresa el valor: ";
                cin >> dato;
                lista.addFirst(dato);
                cout << "Elemento agregado con exito.\n";
            } 
            else if (opcion == 2) {
                T dato;
                cout << "Ingresa el valor: ";
                cin >> dato;
                lista.addLast(dato);
                cout << "Elemento agregado al final.\n";
            } 
            else if (opcion == 3) {
                int index;
                T dato;
                cout << "Ingresa el indice despues del cual insertar: ";
                cin >> index;
                cout << "Ingresa el valor: ";
                cin >> dato;
                lista.insert(index, dato);
                cout << "Elemento insertado exitosamente.\n";
            } 
            else if (opcion == 4) {
                T dato;
                cout << "Ingresa el valor a borrar: ";
                cin >> dato;
                if (lista.deleteData(dato)) {
                    cout << "Elemento eliminado exitosamente.\n";
                } else {
                    cout << "El elemento no se encontro en la lista.\n";
                }
            } 
            else if (opcion == 5) {
                int index;
                cout << "Ingresa la posicion a borrar: ";
                cin >> index;
                if (lista.deleteAt(index)) {
                    cout << "Elemento eliminado exitosamente.\n";
                } else {
                    cout << "No se pudo borrar (posicion fuera de rango).\n";
                }
            } 
            else if (opcion == 6) {
                int index;
                cout << "Ingresa la posicion: ";
                cin >> index;
                T valor = lista.getData(index);
                cout << "El valor en la posicion " << index << " es: " << valor << "\n";
            } 
            else if (opcion == 7) {
                T oldVal, newVal;
                cout << "Ingresa el valor a buscar: ";
                cin >> oldVal;
                cout << "Ingresa el nuevo valor: ";
                cin >> newVal;
                lista.updateData(oldVal, newVal);
                cout << "Dato actualizado correctamente.\n";
            } 
            else if (opcion == 8) {
                int index;
                T newVal;
                cout << "Ingresa la posicion a actualizar: ";
                cin >> index;
                cout << "Ingresa el nuevo valor: ";
                cin >> newVal;
                lista.updateAt(index, newVal);
                cout << "Dato actualizado en la posicion " << index << ".\n";
            } 
            else if (opcion == 9) {
                T dato;
                cout << "Ingresa el valor a buscar: ";
                cin >> dato;
                int pos = lista.findData(dato);
                if (pos != -1) {
                    cout << "El elemento se encuentra en el indice: " << pos << "\n";
                } else {
                    cout << "El elemento no existe en la lista (-1).\n";
                }
            } 
            else if (opcion == 10) {
                int index;
                cout << "Ingresa la posicion a consultar con []: ";
                cin >> index;
                cout << "lista[" << index << "] = " << lista[index] << "\n";
            } 
            else if (opcion == 11) {
                int index;
                T newVal;
                cout << "Ingresa la posicion a modificar con []: ";
                cin >> index;
                cout << "Ingresa el nuevo valor: ";
                cin >> newVal;
                lista[index] = newVal;
                cout << "Posicion " << index << " actualizada con el operador [].\n";
            } 
            else if (opcion == 12) {
                LinkedList<T> copia;
                copia = lista; // Invoca sobrecarga de operator=
                cout << "Lista duplicada exitosamente en 'copia'.\n";
                cout << "Contenido de la lista copia:\n";
                copia.print();
            } 
            else if (opcion == 13) {
                cout << "Contenido actual de la lista:\n";
                lista.print();
            }
        } 
        catch (const out_of_range& e) {
            cout << "\n[EXCEPCION CAPTURADA]: " << e.what() << "\n";
        }

    } while (opcion != 0);
}

// Inicializacion de la lista (Capturada o Aleatoria)
template <typename T>
void inicializarLista(LinkedList<T>& lista) {
    int modo = 0;
    cout << "\nComo deseas llenar la lista inicial?\n";
    cout << "1. Datos capturados por el usuario\n";
    cout << "2. Datos aleatorios\n";
    cout << "Selecciona una opcion: ";
    cin >> modo;

    int n = 0;
    cout << "Cuantos elementos iniciales deseas agregar?: ";
    cin >> n;

    if (modo == 1) {
        for (int i = 0; i < n; i++) {
            T val;
            cout << "Elemento [" << i << "]: ";
            cin >> val;
            lista.addLast(val);
        }
    } else {
        for (int i = 0; i < n; i++) {
            lista.addLast(generarDatoAleatorio<T>(i));
        }
        cout << "Se han generado " << n << " elementos aleatorios.\n";
    }
}

int main() {
    srand(time(nullptr)); // Semilla para numeros aleatorios

    int tipoDato = 0;
    cout << "*****************\n";
    cout << "     CREACION DE LINKED LIST (ADT)      \n";
    cout << "\n";
    cout << "Selecciona el tipo de dato para la lista:\n";
    cout << "1. Enteros (int)\n";
    cout << "2. Cadenas de texto (string)\n";
    cout << "Seleccion: ";
    cin >> tipoDato;

    if (tipoDato == 1) {
        LinkedList<int> listaInt;
        inicializarLista(listaInt);
        ejecutarMenu(listaInt);
    } else {
        LinkedList<string> listaStr;
        inicializarLista(listaStr);
        ejecutarMenu(listaStr);
    }

    cout << "\nPrograma finalizado correctamente.\n";
    return 0;
}