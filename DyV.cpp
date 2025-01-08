#include <iostream>
#include <vector>
#include <algorithm>
#include "DyV.h"

// Implementación de la función de búsqueda binaria
int BusquedaBinaria(int X, const std::vector<int>& V, int ini, int fin) {
    if (ini > fin) {
        std::cout << "No se encuentra en el array" << std::endl;
        return -1;
    }

    int medio = (ini + fin) / 2;

    if (V[medio] == X) {
        return medio;
    } else if (V[medio] > X) {
        return BusquedaBinaria(X, V, ini, medio - 1);
    } else {
        return BusquedaBinaria(X, V, medio + 1, fin);
    }
}

void function1(std::vector<int> a) {
    int target = 15;
    std::sort(a.begin(), a.end());

    int result = BusquedaBinaria(target, a, 0, a.size() - 1);
    if (result != -1) {
        std::cout << "Elemento encontrado en la posición: " << result << std::endl;
    }
}

void function2(std::vector<int>& a) {
    // Aquí se podría modificar el vector si fuera necesario
}

int main() {
    std::vector<int> a; // Crea un vector vacío
    a.push_back(20);
    a.push_back(5);
    a.push_back(15);
    a.push_back(10);
    a.push_back(30);
    a.push_back(25);

    function1(a);
    function2(a);

    return 0;
}

