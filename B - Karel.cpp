// B. Karel
// https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Funcion principal
int main() {
    // Declaracion de variables
    int ancho, alto, pasos_horizontales, pasos_verticales, num_beepers;

    // Leer dimensiones del cuarto, pasos y numero de beepers
    cout << "Introduce H W Sx Sy K (ancho, alto, pasos horizontales, pasos verticales, numero de beepers): ";
    cin >> ancho >> alto >> pasos_horizontales >> pasos_verticales >> num_beepers;

    // Leer posiciones de los beepers
    set<pair<int, int>> posiciones_beepers; // Usar un conjunto para almacenar posiciones de los beepers
    cout << "Introduce las posiciones de los " << num_beepers << " beepers en formato x y:" << endl;
    for (int i = 0; i < num_beepers; i++) {
        int x, y;
        cin >> x >> y;
        posiciones_beepers.insert({x, y});
    }

    // Posicion inicial y orientacion de Karel
    int x = 0, y = 0;
    string orientacion_horizontal = "este", orientacion_vertical = "norte";

    // Contador de beepers recogidos
    int beepers_recogidos = 0;

    // Simular el movimiento de Karel
    int iteraciones = 0; // Limitar iteraciones para evitar posibles bucles infinitos
    const int LIMITE_ITERACIONES = 1000000;

    while (!posiciones_beepers.empty() && iteraciones < LIMITE_ITERACIONES) {
        iteraciones++;

        // Movimiento horizontal
        for (int i = 0; i < pasos_horizontales; i++) {
            if (orientacion_horizontal == "este") {
                if (x + 1 < ancho) {
                    x++; // Avanza hacia el este
                } else {
                    orientacion_horizontal = "oeste"; // Cambia de direccion
                }
            } else {
                if (x - 1 >= 0) {
                    x--; // Avanza hacia el oeste
                } else {
                    orientacion_horizontal = "este"; // Cambia de direccion
                }
            }
        }

        // Movimiento vertical
        for (int i = 0; i < pasos_verticales; i++) {
            if (orientacion_vertical == "norte") {
                if (y + 1 < alto) {
                    y++; // Avanza hacia el norte
                } else {
                    orientacion_vertical = "sur"; // Cambia de direccion
                }
            } else {
                if (y - 1 >= 0) {
                    y--; // Avanza hacia el sur
                } else {
                    orientacion_vertical = "norte"; // Cambia de direccion
                }
            }
        }

        // Verificar si hay un beeper en la posicion actual
        if (posiciones_beepers.count({x, y})) {
            beepers_recogidos++;
            posiciones_beepers.erase({x, y}); // Recoger el beeper
            cout << "Beeper recogido en: (" << x << ", " << y << ")" << endl;
        }

        // Salida de depuracion opcional (comentar para evitar sobrecarga)
        // cout << "Posicion actual: (" << x << ", " << y << ")" << endl;
    }

    // Verificar si se alcanzo el limite de iteraciones
    if (iteraciones >= LIMITE_ITERACIONES) {
        cout << "LIMITE DE ITERACIONES ALCANZADO. Verifica los datos de entrada." << endl;
    }

    // Mostrar el numero de beepers recogidos
    cout << "Numero de beepers recogidos: " << beepers_recogidos << endl;

    return 0;
}