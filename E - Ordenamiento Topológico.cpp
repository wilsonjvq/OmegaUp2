// E. Ordenamiento Topologico
// https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Función para realizar un DFS y obtener el orden topológico
void dfs(int v, const vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& topoStack) {
    visited[v] = true;
    for (int neighbor : adjList[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited, topoStack);
        }
    }
    topoStack.push(v); // Push the vertex to the stack when finishing its DFS
}

int main() {
    int n, m;
    cin >> n >> m; // Leer número de vértices y arcos

    vector<vector<int>> adjList(n); // Crear lista de adyacencia
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v; // Leer arco u -> v
        adjList[u].push_back(v); // Añadir arco a la lista de adyacencia
    }

    vector<bool> visited(n, false);
    stack<int> topoStack;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adjList, visited, topoStack);
        }
    }

    // Construir el orden topológico en orden lexicográfico menor
    vector<int> result;
    while (!topoStack.empty()) {
        result.push_back(topoStack.top());
        topoStack.pop();
    }
    
    // Ordenar lexicográficamente el resultado
    sort(result.begin(), result.end());

    // Imprimir el orden topológico
    if (result.size() != n) {
        cout << "-1" << endl; // No hay un orden topológico posible
    } else {
        for (int v : result) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
