//Daniela Chavez Ibarra
//A00843645
#include <iostream>
using namespace std;

int main() {

    int x=42;
    int* p=&x;

    cout << x << endl;
    cout << &x << endl;
    cout << p << endl;
    cout << *p << endl;

    int* q = new int(5); //aqui es como si di
    cout << q << endl; //te mostrará la direccion de memoria
    cout << *q << endl;  //te mostrara el valor que le ingresaste a esa dirección de memoria 

    //NOTA: si le pones delete significa que le quitas el espacio de memoria asignado a ese valor


    Fraction* f= new Fraction(2, 3);
    f->print();
    delete f;
    //NOTA: cuando usas la flechita (->) es para acceder a los metodos de la clase, cuando usas el punto (.) es para acceder a los atributos de la clase
    // EJEMPLO: f->getDenominator() 

auto  g= make_unique<Fraction>(3, 4); //aqui es como si dijeras que g es un puntero inteligente que apunta a un objeto de la clase Fraction
    g->print();
    cout << g->getDenominator() << "/" << g->getNumerator() << endl; //aqui es como si dijeras que g es un puntero inteligente que apunta a un objeto de la clase Fraction



    //GLOSARIO DE LA CLASE DE HOY (11 DE SEP 2026)
    /*
    - Smart pointers: son punteros que se encargan de liberar la memoria automaticamente cuando ya no se necesita, evitando fugas de memoria
    - apuntador normal vs smart pointer: un apuntador normal es un puntero que apunta a una dirección de memoria, mientras que un smart pointer es un puntero que se encarga de liberar la memoria automaticamente cuando ya no se necesita
    - memoria dinamica: es la memoria que se asigna en tiempo de ejecución, es decir, cuando el programa ya esta corriendo, a diferencia de la memoria estatica que se asigna en tiempo de compilación

    */
}