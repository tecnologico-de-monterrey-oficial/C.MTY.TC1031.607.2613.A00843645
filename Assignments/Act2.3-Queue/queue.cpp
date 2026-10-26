// Daniela Chávez Ibarra
// A00843645

#include <iostream>
#include "queue.h"
#include "Node.h"
#include "cliente.h"

using namespace std;

int main() {
    Queue<Cliente> filaTaquilla;
    int opcion;

    do {
        cout << "\n -----------------------------------\n" ;
        cout << "Sistema de atencion - Taquilla de boletos \n";
        cout << "\n \n";
        cout << "1. Llegada de un nuevo cliente\n";
        cout << "2. Atender al siguiente cliente\n";
        cout << "3. Ver al siguiente cliente sin atenderlo aun\n";
        cout << "4. Mostrar cuantas personas hay en la fila\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Cliente nuevoCliente;
                cout << "Ingrese el nombre del cliente: ";
                cin >> nuevoCliente.nombre;
                cout << "Ingrese la cantidad de boletos: ";
                cin >> nuevoCliente.boletos;
                
                filaTaquilla.push(nuevoCliente);
                cout << "¡Cliente agregado a la fila exitosamente!\n";
                break;
            }
            case 2: {
                try {
                    Cliente atendido = filaTaquilla.pop();
                    cout << "\n-> Atendiendo a: " << atendido.nombre 
                         << " | Boletos comprados: " << atendido.boletos << "\n";
                } catch (const exception& e) {
                    cout << e.what() << "\n";
                }
                break;
            }
            case 3: {
                try {
                    Cliente siguiente = filaTaquilla.front();
                    cout << "\n-> Siguiente en la fila -> Nombre: " << siguiente.nombre 
                         << " | Boletos solicitados: " << siguiente.boletos << "\n";
                } catch (const exception& e) {
                    cout << e.what() << "\n";
                }
                break;
            }
            case 4: {
                cout << "\n-> Personas actualmente en la fila: " << filaTaquilla.getSize() << "\n";
                break;
            }
            case 5:
                cout << "Saliendo del sistema de taquilla...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
    }