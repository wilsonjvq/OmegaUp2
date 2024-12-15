// F. Pattern Matching con KMP
// https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <vector>
#include <string>

// Función para calcular la tabla de prefijos (también llamada tabla de "pi")
void calcularTablaPrefijos(const std::string& P, std::vector<int>& pi) {
    int m = P.size();
    pi[0] = 0;
    int j = 0;

    for (int i = 1; i < m; ++i) {
        while (j > 0 && P[i] != P[j]) {
            j = pi[j - 1];
        }
        if (P[i] == P[j]) {
            j++;
        }
        pi[i] = j;
    }
}

// Función para realizar el algoritmo KMP
std::pair<int, std::vector<int>> kmp(const std::string& T, const std::string& P) {
    int n = T.size();
    int m = P.size();
    std::vector<int> pi(m);
    std::vector<int> indices;

    calcularTablaPrefijos(P, pi);

    int j = 0; // índice para P
    for (int i = 0; i < n; ++i) {
        while (j > 0 && T[i] != P[j]) {
            j = pi[j - 1];
        }
        if (T[i] == P[j]) {
            j++;
        }
        if (j == m) {
            // Encuentro del patrón, agregar índice a la lista
            indices.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }

    // Invertir manualmente el vector de índices para que queden en orden descendente
    for (int i = 0, j = indices.size() - 1; i < j; ++i, --j) {
        std::swap(indices[i], indices[j]);
    }

    return {indices.size(), indices};
}

int main() {
    std::string T, P;
    std::cin >> T >> P;

    auto result = kmp(T, P);
    int count = result.first;
    std::vector<int> indices = result.second;

    std::cout << count << std::endl;
    if (count > 0) {
        for (int i = 0; i < indices.size(); ++i) {
            std::cout << indices[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}