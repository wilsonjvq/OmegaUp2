// D. Ubicando a Karel
// https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <string>
using namespace std;

// Estructura para representar la posicion y orientacion de Karel
struct Karel {
    int x; // Coordenada horizontal
    int y; // Coordenada vertical
    string orientacion; // Orientacion de Karel: "Norte", "Sur", "Este", "Oeste"
};

// Funcion para posicionar y orientar a Karel
void posicionarKarel(Karel& karel, int x, int y, string orientacion) {
    karel.x = x;
    karel.y = y;
    karel.orientacion = orientacion;
}

// Funcion para mostrar la posicion y orientacion de Karel
void mostrarEstadoKarel(const Karel& karel) {
    cout << "Karel se encuentra en la posicion (" << karel.x << ", " << karel.y << ") viendo al " << karel.orientacion << "." << endl;
}

int main() {
    // Declaracion de la instancia de Karel
    Karel karel;

    // Caso 1: Posicion inicial (1, 3) viendo al norte
    posicionarKarel(karel, 1, 3, "Norte");
    mostrarEstadoKarel(karel);

    // Caso 2: Posicion inicial (2, 4) viendo al sur
    posicionarKarel(karel, 2, 4, "Sur");
    mostrarEstadoKarel(karel);

    // Caso 3: Posicion inicial (9, 3) viendo al este
    posicionarKarel(karel, 9, 3, "Este");
    mostrarEstadoKarel(karel);

    // Caso 4: Posicion inicial (10, 10) viendo al oeste
    posicionarKarel(karel, 10, 10, "Oeste");
    mostrarEstadoKarel(karel);

    return 0;
}