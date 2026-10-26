//Daniela Chávez Ibarra

#include <iostream>
#include <string>
#include "Stack.h"
#include "PaginaWeb.h"

using namespace std;

void mostrarMenu() {
    cout << "\n-----\n";
    cout << "     SIMULADOR DE HISTORIAL WEB (LIFO)  \n";
    cout << "----\n";
    cout << "1. Visitar una nueva pagina\n";
    cout << "2. Retroceder a la pagina anterior (pop)\n";
    cout << "3. Ver la pagina actual (top)\n";
    cout << "4. Mostrar cuantas paginas hay en el historial\n";
    cout << "5. Salir\n";
    cout << "Selecciona una opcion: ";
}

int main() {
    Stack<PaginaWeb> historial;
    int opcion;

    do {
        mostrarMenu();
        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Por favor ingresa un numero.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1: {
                PaginaWeb nueva;
                cout << "Ingresa el titulo de la pagina: ";
                getline(cin, nueva.titulo);
                cout << "Ingresa la URL de la pagina: ";
                getline(cin, nueva.url);

                historial.push(nueva);
                cout << "-> Pagina visitada con exito y agregada al historial!\n";
                break;
            }
            case 2: {
                try {
                    PaginaWeb cerrada = historial.pop();
                    cout << "-> Boton Atras presionado. Se cerro la pagina:\n";
                    cout << "   [Titulo]: " << cerrada.titulo << "\n";
                    cout << "   [URL]:    " << cerrada.url << "\n";
                } catch (const exception& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: {
                try {
                    PaginaWeb actual = historial.top();
                    cout << "-> Pagina actual en pantalla:\n";
                    cout << "   [Titulo]: " << actual.titulo << "\n";
                    cout << "   [URL]:    " << actual.url << "\n";
                } catch (const exception& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4: {
                cout << "-> Hay " << historial.getSize() << " pagina(s) en el historial de navegacion.\n";
                break;
            }
            case 5:
                cout << "Saliendo del navegador. Hasta luego!\n";
                break;
            default:
                cout << "Opcion no valida. Intenta de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}