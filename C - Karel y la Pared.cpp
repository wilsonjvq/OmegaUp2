// C. Karel y la Pared
// https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
using namespace std;

// Declaramos funciones para simular movimientos de Karel
void girarIzquierda();
void girarDerecha();
void avanzar();
bool frenteLibre();
bool izquierdaBloqueada();
bool derechaBloqueada();

// Variables globales para simular el entorno de Karel
int posicionX = 0, posicionY = 0; // Posicion actual de Karel
int direccion = 0; // 0: norte, 1: este, 2: sur, 3: oeste

// Implementacion de funciones de movimiento
void girarIzquierda() {
    direccion = (direccion + 3) % 4;
}

void girarDerecha() {
    direccion = (direccion + 1) % 4;
}

void avanzar() {
    if (direccion == 0) posicionY++;
    else if (direccion == 1) posicionX++;
    else if (direccion == 2) posicionY--;
    else if (direccion == 3) posicionX--;
}

bool frenteLibre() {
    // Simulacion: siempre libre excepto al estar frente a la pared
    return !(direccion == 0 && posicionY == 1 && posicionX == 0) &&
           !(direccion == 1 && posicionX == 1 && posicionY == 0);
}

bool izquierdaBloqueada() {
    return direccion == 3 && posicionX == 0 && posicionY == 0;
}

bool derechaBloqueada() {
    return direccion == 1 && posicionX == 0 && posicionY == 0;
}

// Funcion principal
int main() {
    cout << "Inicio de simulacion: Karel y la pared" << endl;

    // Karel debe rodear la pared que esta a su izquierda o derecha
    if (izquierdaBloqueada()) {
        // Rodear por la derecha
        girarDerecha();
        avanzar();
        girarIzquierda();
        avanzar();
        girarIzquierda();
        avanzar();
        girarDerecha();
    } else if (derechaBloqueada()) {
        // Rodear por la izquierda
        girarIzquierda();
        avanzar();
        girarDerecha();
        avanzar();
        girarDerecha();
        avanzar();
        girarIzquierda();
    }

    // Posicion final
    cout << "Karel ha rodeado la pared." << endl;
    cout << "Posicion final: (" << posicionX << ", " << posicionY << ")" << endl;

    return 0;
}