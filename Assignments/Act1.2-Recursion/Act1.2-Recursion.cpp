// Daniela Chávez Ibarra
// A00843645

#include <iostream>
#include <cmath>
using namespace std;

int factorial (int n) {
    if (n <=1) {
        return 1;
    }
        return n * factorial(n-1);
    
}

// esto lo avanzamos en clase:
// suma iterativa
int sumIterative(int n) {
    int suma = 0;
    for (int i=1; i<= n; i++) {
        suma += i;
    }
    return suma;
}

// suma recursiva
// desventaja de la recursiva es que ocupa más memoria, porque cada llamada a la función se queda en la pila de llamadas hasta que se resuelve
int sumRecursive(int n) {
    //la funcion recursiva a fuerza tiene que llevar un if 
    if (n == 1) {
        return 1;
    }
    return n + sumRecursive(n-1);
}

//sumFormula
int sumFormula(int n) {
    return (n * (n+1)/2);
}

//fibonacciIterative
int fibonacciIterative(int n) {
    int a = 1;
    int b = 1;
    int c;
    //imprimir la lista
        cout << "F(1)=" << a << endl; // F(1)=1
        cout << "F(2)=" << b << endl; // F(2)=1
    for (int i = 3; i <= n; i++) 
    {
        c = a + b;
        //  c = 1 + 1
        //  c = 2
    
        cout << "F(" << i << ")=" << c << endl; // F(3)=2 ...
    
        //los valores nuevos se van a convertir en los valores anteriores
        a = b; // a = 1
        b = c; // b = 2 el resultado ahora será el numero anterior
    }
    return b; 

}

//fibonacciRecursive
int fibonacciRecursive(int n) { //n=3
    // 0+1=1
    // 1+1=2
    // 1+2=3
    if (n == 1 || n==2) {
        return 1;
    }
    else {
        return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}
}

//bacteriasIterative
int bacteriasIterative(int n) {
    double nacen = 3.78;
    double mueren = 2.34;
    int sum = 1; //esta es la cantidad de bacterias en el dia 0
    for (int i = 1; i<= n; i++) {
        int bac;
        // tienes que truncar primero las que nacen, luego las que mueren y después hacer la suma
        int bacNacen = sum*nacen;
        int bacMueren = sum*mueren;
        sum += bacNacen - bacMueren;
    }
    return sum;
}

//bacteriasRecursive
int bacteriasRecursive(int n) {
    if (n==0) {
        return 1;
    }
    int bacteria = bacteriasRecursive(n-1); // primero quiero saber cuantas bacterias tenia el dia anterior
    int born = bacteria * 3.78; // cuantas nacen
    int died = bacteria * 2.34; // cuantas mueren
    return bacteria + born - died; // regresa la cantidad de bacterias que hay en el dia n (las que estaban ayer mas las que nacieron menos las que murieron)
}

//InvestmentIterative
int InvestmentIterative(int n, double p) { //n meses
    double interes = 0.1875;
    double monto = p;
    for (int i = 1; i <= n; i++) {
        monto += monto * interes;
    }
    return monto;
}

//InvestmentRecursive
double InvestmentRecursive(int n, double p) {
    double interes = 0.1875;
    if (n == 0) {
        return p;
    }
    return InvestmentRecursive(n-1, p) + InvestmentRecursive(n-1, p) * interes;
}

//PowIterative
int PowerIterative(int n, int y) {
    // n elevadoa la y
    //ejemplo: 2^3 = 2*2*2 = 8
    int resultado = 1; //cuando y=0, resultado = 1
    for (int i = 1; i <= y; i++) {
        resultado = n * resultado;
    }
    return resultado;
}

//PowRecursive
int PowerRecursive(int n, int y) {
    if (y == 0) { //la condición base es cuando y vale 0, hará que el resultado sea 1
        return 1;
    }
    return n*PowerRecursive(n, y-1); //la recursividad es cuando y vale 1, hará que el resultado sea n
}


int main() {
    cout << "el factorial de 7 es: " << factorial(7) << endl;
    // suma Iterativa
    cout << "La suma iterativa de 5 es: " << sumIterative(5) << endl;
    // suma recursiva 
    cout << "La suma recursiva de 5 es: " << sumRecursive(5) << endl;
    // suma con formula
    cout << "La suma con formula de 5 es: " << sumFormula(5) << endl;
    // fibonacci iterativo
    cout << "El fibonacci iterativo de 6 es: " << fibonacciIterative(6) << endl;
    // fibonacci recursivo
    cout << "El fibonacci recursivo de 6 es: " << fibonacciRecursive(6) << endl;
    //bacterias Iterativo
    cout << "El numero de bacterias iterativo despues de 5 dias es: " << bacteriasIterative(5) << endl;
    //bacterias recursivo
    cout << "El numero de bacterias recursivo despues de 5 dias es: " << bacteriasRecursive(5) << endl;
    //Investment Iterativo
    cout << "El monto de la inversion iterativo despues de 5 años es: " << InvestmentIterative(5, 1000) << endl;
    //Investment Recursivo
    cout << "El monto de la inversion recursivo despues de 5 años es: " << round(InvestmentRecursive(5, 1000)) << endl;
    //PowIterative
    cout << "El resultado de 2 elevado a la 3 es: " << PowerIterative(2, 3) << endl;
    //PowRecursive
    cout << "El resultado de 2 elevado a la 3 es: " << PowerRecursive(2, 3) << endl;

    return 0;
}
