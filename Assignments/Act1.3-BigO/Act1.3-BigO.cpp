//Daniela Chávez Ibarra
//A00843645

#include <iostream>
#include <vector>
using namespace std;

//1.FUNCION ITERATIVA
int funcionIterativa(const vector<int>& vector) {
    int suma = 0;
    for (size_t i=0; i < vector.size(); i++) {
        if (vector[i] % 2 != 0) { //si es impar
            suma += vector[i]; //se le agrega ese valor impar a la suma 
        }
    }
    return suma;
}

//2.FUNCION RECUURSIVA
int funcionRecursiva(const vector<int>& vector, size_t index=0) {
    if (index >= vector.size()) { //caso base. cuando ya se pasaron todos los elementos
        return 0;
    }
    if (vector[index] % 2 != 0) { //si es impar 
        return vector[index] + funcionRecursiva(vector, index + 1); //sagregar ese valor impar a la suma 
    }
    else {
        return funcionRecursiva(vector, index + 1); //si no es par, se llama a la función con el siguiente índice
    }
}

int main() {
    vector<int> numeros = {3, 8, 5, 12, 7, 2, 9};

    cout << "Suma Iterativa: " << funcionIterativa(numeros) << " Orden: O(n)" << endl;
    cout << "Suma Recursiva: " << funcionRecursiva(numeros) << " Orden: O(n)" << endl;
    return 0;   
}