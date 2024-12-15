// J - Ordenamiento Inverso
// https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    // Leer los números
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Ordenar el arreglo de mayor a menor
    std::sort(arr.begin(), arr.end(), std::greater<int>());

    // Imprimir el arreglo ordenado
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}