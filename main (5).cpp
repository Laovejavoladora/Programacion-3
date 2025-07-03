#include <iostream>
#include <string>
using namespace std;

// ==============================
//   CLASE 'Perro'
// ==============================
class Perro {
public:
    string nombre;
    string raza;
    int edad;

    void ladrar() {
        cout << nombre << " dice: ¡Guau! ¡Guau!" << endl;
    }

    void presentar() {
        cout << "Hola, soy " << nombre << ", un " << raza 
             << " de " << edad << " años." << endl;
    }
};

// ==============================
//   CLASE PERSONALIZADA: MateoPerezNomey
// ==============================
class MateoPerezNomey {
public:
    void presentarse() const {
        cout << "\n👋 ¡Hola! Soy Mateo Perez Nomey, creador de este mini programa de perros." << endl;
    }

    void despedirse() const {
        cout << "\n🙌 ¡Gracias por usar este código! Espero que te haya gustado. 🐶" << endl;
    }
};

// ==============================
//   FUNCIÓN PRINCIPAL
// ==============================
int main() {
    MateoPerezNomey autor;
    autor.presentarse();

    Perro perro1;
    Perro perro2;

    perro1.nombre = "Firulais";
    perro1.raza = "Mestizo Juguetón";
    perro1.edad = 3;

    perro2.nombre = "Rex";
    perro2.raza = "Pastor Alemán";
    perro2.edad = 5;

    cout << "\n--- Conozcamos a nuestras mascotas ---" << endl;
    perro1.presentar();
    perro1.ladrar();

    cout << endl;
    perro2.presentar();
    perro2.ladrar();

    autor.despedirse();

    return 0;
}
