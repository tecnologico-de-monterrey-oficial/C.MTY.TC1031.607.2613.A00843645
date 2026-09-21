#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
using namespace std;

// Búsqueda Secuencial (O(n)) para comparar tiempos contra Búsqueda Binaria
template <typename T>
int sequentialSearch(const vector<T> &list, const T &target) {
    for (size_t i = 0; i < list.size(); i++) {
        if (list[i] == target) {
            return i;
        }
    }
    return -1;
}

// Búsqueda Binaria Estándar (O(log n)) - Busca un elemento exacto
template <typename T>
int binarySearch(const vector<T> &list, const T &target) {
    int low = 0;
    int high = list.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (list[mid] == target) {
            return mid;
        } else if (list[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // No encontrado
}

// Búsqueda Binaria para Límite Inferior (Lower Bound)
// Encuentra el primer elemento que es >= target
template <typename T>
int lowerBound(const vector<T> &list, const T &target) {
    int low = 0;
    int high = list.size() - 1;
    int result = list.size(); // Valor por defecto si no hay ninguno >= target

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (list[mid] >= target) {
            result = mid;
            high = mid - 1; // Seguir buscando a la izquierda para encontrar el primero
        } else {
            low = mid + 1;
        }
    }
    return result;
}

// Búsqueda Binaria para Límite Superior (Upper Bound)
// Encuentra el último elemento que es <= target
template <typename T>
int upperBound(const vector<T> &list, const T &target) {
    int low = 0;
    int high = list.size() - 1;
    int result = -1; // Valor por defecto si no hay ninguno <= target

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (list[mid] <= target) {
            result = mid;
            low = mid + 1; // Seguir buscando a la derecha para encontrar el último
        } else {
            high = mid - 1;
        }
    }
    return result;
}

#endif /* Search_h */