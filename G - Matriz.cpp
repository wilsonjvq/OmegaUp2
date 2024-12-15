// G. Matriz
// https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));

    // Leer la matriz
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Imprimir la matriz desde la última fila hasta la primera
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j];
            if (j < m - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}