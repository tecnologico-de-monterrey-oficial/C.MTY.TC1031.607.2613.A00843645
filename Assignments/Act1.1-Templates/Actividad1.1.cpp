#include <iostream>
#include <string>
using namespace std;


#include "List.h"

int sum(int a, int b){
    return a + b;
}

string sum(string a, string b){
    return a + b;
}

double sum(double a, double b){
    return a + b;
}

int main(){
    
    cout << "----- Listas de enteros -----" << endl;
    List<int> data; //esto llama al cosntructor por default
    data.insert(5);
    data.insert(10);
    data.insert(15);

    // print y getSize
    cout << "Contenido de la lista (Size: " << data.getSize() << "):" << endl;
    data.print();

    // insertAt
    cout << "\n Insertando 20 en la posición 1" << endl;
    data.insertAt(1, 20);
    data.print();

    //getData
    cout << "\n--- Obteniendo el dato en la posición 2 (getData) ---" << endl;
    cout << "El dato en pos 2 es: " << data.getData(2) << endl;

    //getMax
    cout << "\n--- Obteniendo el mayor valor (getMax) ---" << endl;
    cout << "El valor máximo es: " << data.getMax() << endl;

    // removeAt
    cout << "\n--- Eliminando elemento en la posición 1 (removeAt) ---" << endl;
    data.removeAt(1);
    cout << "Lista después de removeAt:" << endl;
    data.print();

    //removeLast
    cout << "\n--- Eliminando el último elemento (removeLast) ---" << endl;
    data.removeLast();
    cout << "Lista final de enteros:" << endl;
    data.print();


cout << "\n----- Listas de strings -----" << endl;
    List<string> things;
    things.insert("Hola");
    things.insert("crayola");
    cout << "Contenido de la lista (size: " << things.getSize() << "):" << endl;
    things.print();

    cout << "\n Obteniendo el dato en la posición 1" << endl;
    cout << "El dato en pos 1 es: " << things.getData(1) << endl;

    cout << things.getMax() << " es el mayor valor" << endl;

    /*int a= 5;
    int b= 10;
    cout << "Sum of " << a << " and " << b << " is: " << sum(a, b) << endl;

    double c= 5.5;
    double d= 10.5;
    cout << "Sum of " << c << " and " << d << " is: " << sum(c, d) << endl;
    */
    return 0;
}
