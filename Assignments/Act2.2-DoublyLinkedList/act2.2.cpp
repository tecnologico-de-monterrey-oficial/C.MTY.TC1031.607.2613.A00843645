// Daniela Chávez Ibarra
// A00843645
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "DoublyLinkedList.h"
#include "NodeD.h"

using namespace std;

// Función auxiliar para limpiar el búfer de entrada
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Generador genérico de datos aleatorios para enteros
template <typename T>
T generarDatoAleatorio(int i) {
    return static_cast<T>((rand() % 100) + 1);
}

// Especialización para strings
template <>
string generarDatoAleatorio<string>(int i) {
    string palabras[] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Zeta", "Eta", "Theta"};
    return palabras[rand() % 8] + "_" + to_string(i + 1);
}

// Menú interactivo de operaciones
template <typename T>
void ejecutarMenu(DoublyLinkedList<T>& lista) {
    int opcion = -1;
    do {
        cout << "\n---------------------------\n";
        cout << "   MENU DE OPERACIONES       \n";
        cout << "\n \n";
        cout << " 1. Agregar al principio (addFirst)\n";
        cout << " 2. Agregar al final (addLast)\n";
        cout << " 3. Insertar a la derecha del indice (insert)\n";
        cout << " 4. Borrar un elemento por valor (deleteData)\n";
        cout << " 5. Borrar un elemento en una posicion (deleteAt)\n";
        cout << " 6. Obtener elemento en posicion (getData)\n";
        cout << " 7. Actualizar elemento por valor (updateData)\n";
        cout << " 8. Actualizar elemento en posicion (updateAt)\n";
        cout << " 9. Encontrar elemento (findData)\n";
        cout << "10. Leer o modificar con operador [ ]\n";
        cout << "11. Iguala/Duplicar lista con operador = (Copia)\n";
        cout << "12. Limpiar lista (clear)\n";
        cout << "13. Ordenar lista (sort)\n";
        cout << "14. Duplicar elementos (duplicate: 1->2 => 1->1->2->2)\n";
        cout << "15. Remover duplicados (removeDuplicates)\n";
        cout << "16. Mostrar lista (Adelante ->)\n";
        cout << "17. Mostrar lista inverso (Atras <-)\n";
        cout << " 0. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            limpiarBuffer();
            cout << "Entrada invalida. Intenta de nuevo.\n";
            continue;
        }

        try {
            if (opcion == 1) {
                T val;
                cout << "Ingrese el elemento a agregar al inicio: ";
                cin >> val;
                lista.addFirst(val);
                cout << "Elemento agregado con exito.\n";
            } 
            else if (opcion == 2) {
                T val;
                cout << "Ingrese el elemento a agregar al final: ";
                cin >> val;
                lista.addLast(val);
                cout << "Elemento agregado con exito.\n";
            } 
            else if (opcion == 3) {
                int idx;
                T val;
                cout << "Ingrese el indice de referencia: ";
                cin >> idx;
                cout << "Ingrese el elemento a insertar a la derecha: ";
                cin >> val;
                lista.insert(idx, val);
                cout << "Elemento insertado con exito.\n";
            } 
            else if (opcion == 4) {
                T val;
                cout << "Ingrese el valor del elemento a borrar: ";
                cin >> val;
                if (lista.deleteData(val)) {
                    cout << "Elemento borrado exitosamente.\n";
                } else {
                    cout << "El elemento no se encontro en la lista.\n";
                }
            } 
            else if (opcion == 5) {
                int idx;
                cout << "Ingrese la posicion (indice) a borrar: ";
                cin >> idx;
                if (lista.deleteAt(idx)) {
                    cout << "Elemento en posicion " << idx << " borrado exitosamente.\n";
                } else {
                    cout << "Posicion invalida o lista vacia.\n";
                }
            } 
            else if (opcion == 6) {
                int idx;
                cout << "Ingrese la posicion a consultar: ";
                cin >> idx;
                T val = lista.getData(idx);
                cout << "Dato en la posicion [" << idx << "]: " << val << endl;
            } 
            else if (opcion == 7) {
                T oldVal, newVal;
                cout << "Ingrese el valor actual que desea buscar: ";
                cin >> oldVal;
                cout << "Ingrese el nuevo valor: ";
                cin >> newVal;
                lista.updateData(oldVal, newVal);
                cout << "Elemento actualizado exitosamente.\n";
            } 
            else if (opcion == 8) {
                int idx;
                T newVal;
                cout << "Ingrese la posicion a actualizar: ";
                cin >> idx;
                cout << "Ingrese el nuevo valor: ";
                cin >> newVal;
                lista.updateAt(idx, newVal);
                cout << "Posicion " << idx << " actualizada con exito.\n";
            } 
            else if (opcion == 9) {
                T val;
                cout << "Ingrese el elemento a buscar: ";
                cin >> val;
                int pos = lista.findData(val);
                if (pos != -1) {
                    cout << "Elemento encontrado en el indice: " << pos << endl;
                } else {
                    cout << "El elemento no se encuentra en la lista (-1).\n";
                }
            } 
            else if (opcion == 10) {
                int idx;
                cout << "Ingrese el indice para el operador []: ";
                cin >> idx;
                cout << "Valor actual en [" << idx << "] = " << lista[idx] << endl;
                char mod;
                cout << "Desea modificar este valor? (s/n): ";
                cin >> mod;
                if (mod == 's' || mod == 'S') {
                    T newVal;
                    cout << "Ingrese el nuevo valor: ";
                    cin >> newVal;
                    lista[idx] = newVal;
                    cout << "Valor modificado usando el operador [].\n";
                }
            } 
            else if (opcion == 11) {
                DoublyLinkedList<T> copia;
                copia = lista; // Prueba de la sobrecarga del operador =
                cout << "Lista duplicada exitosamente usando operator=\n";
                cout << "Contenido de la lista copia:\n";
                copia.print();
            } 
            else if (opcion == 12) {
                lista.clear();
                cout << "La lista ha sido limpiada (vaciada).\n";
            } 
            else if (opcion == 13) {
                lista.sort();
                cout << "Lista ordenada exitosamente.\n";
                lista.print();
            } 
            else if (opcion == 14) {
                lista.duplicate();
                cout << "Elementos duplicados (1->1->2->2...):\n";
                lista.print();
            } 
            else if (opcion == 15) {
                lista.removeDuplicates();
                cout << "Elementos duplicados removidos (ordenada previamente):\n";
                lista.print();
            } 
            else if (opcion == 16) {
                cout << "Lista actual (hacia adelante):\n";
                lista.print();
            } 
            else if (opcion == 17) {
                cout << "Lista actual (hacia atras usando 'prev'):\n";
                lista.printReverse();
            }
        } 
        catch (const out_of_range& e) {
            cout << "\n[EXCEPCION CAPTURADA]: " << e.what() << "\n";
        }

    } while (opcion != 0);
}

// Inicialización de la lista inicial
template <typename T>
void inicializarLista(DoublyLinkedList<T>& lista) {
    int modo, n;
    cout << "\n--- CREACION DE LISTA ---\n";
    cout << "1. Llenar con datos capturados manualmente\n";
    cout << "2. Llenar con datos aleatorios\n";
    cout << "Seleccione una opcion: ";
    cin >> modo;

    cout << "Cuantos elementos iniciales desea ingresar?: ";
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
        cout << "Se han generado " << n << " elementos aleatorios con exito.\n";
    }
}

int main() {
    srand(time(nullptr));

    int tipoDato;
    cout << "---------------------------------------------------\n";
    cout << "      ACTIVIDAD 2.2 - LISTAS DOBLEMENTE LIGADAS          \n";
    cout << "\n";
    cout << "Seleccione el tipo de dato para la estructura:\n";
    cout << "1. Enteros (int)\n";
    cout << "2. Cadenas de texto (string)\n";
    cout << "Opcion: ";
    cin >> tipoDato;

    if (tipoDato == 1) {
        DoublyLinkedList<int> listaInt;
        inicializarLista(listaInt);
        ejecutarMenu(listaInt);
    } else {
        DoublyLinkedList<string> listaStr;
        inicializarLista(listaStr);
        ejecutarMenu(listaStr);
    }

    cout << "\nPrograma finalizado correctamente.\n";
    return 0;
}