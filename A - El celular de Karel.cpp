// A. El celular de Karel
// https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
using namespace std;

// Funcion principal
int main() {
    // Declaracion de variables
    bool celular_en_cama = false; // Indica si el celular esta en la cama de Karel

    // Entrada: leer si hay un zumbador en la posicion actual
    cout << "Introduce 1 si hay zumbador (celular) en la cama, o 0 si no lo hay: ";
    cin >> celular_en_cama;

    // Evaluar la condicion del celular
    if (celular_en_cama) {
        // Caso: Karel encuentra el celular en su cama
        cout << "Celular encontrado en la cama. Guardando en la mochila..." << endl;
        cout << "Celular guardado en la mochila. Buenas noches, Karel!" << endl;
    } else {
        // Caso: Karel no encuentra el celular
        cout << "No hay celular en la cama. Buenas noches, Karel!" << endl;
    }

    // Fin del programa
    return 0;
}

