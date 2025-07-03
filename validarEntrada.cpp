#include <iostream>
#include <string>
#include <cctype> // para isalpha
using namespace std;

// Validación para int
bool validarEntrada(int valor) {
    return valor >= 1 && valor <= 100;
}

// Validación para double
bool validarEntrada(double valor) {
    return valor >= 0.0 && valor <= 10.0;
}

// Validación para string (solo letras y al menos 3 caracteres)
bool validarEntrada(const string& texto) {
    if (texto.length() < 3) return false;
    for (char c : texto) {
        if (!isalpha(c)) return false;
    }
    return true;
}

int main() {
    // Probar con int
    int num = 50;
    cout << "¿El int " << num << " es válido? " << (validarEntrada(num) ? "Sí" : "No") << endl;

    // Probar con double
    double dec = 5.5;
    cout << "¿El double " << dec << " es válido? " << (validarEntrada(dec) ? "Sí" : "No") << endl;

    // Probar con string
    string texto = "Hola";
    cout << "¿El string \"" << texto << "\" es válido? " << (validarEntrada(texto) ? "Sí" : "No") << endl;

    // Probar con valores inválidos
    cout << "\n-- Pruebas con datos inválidos --\n";
    cout << "¿El int -5 es válido? " << (validarEntrada(-5) ? "Sí" : "No") << endl;
    cout << "¿El double 12.3 es válido? " << (validarEntrada(12.3) ? "Sí" : "No") << endl;
    cout << "¿El string \"H0l@\" es válido? " << (validarEntrada("H0l@") ? "Sí" : "No") << endl;

    return 0;
}