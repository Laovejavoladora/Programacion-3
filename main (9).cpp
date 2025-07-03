#include <iostream>
#include <string>
using namespace std;

// ===============================
// Clase base
// ===============================
class Animal {
public:
    virtual void hablar() const {
        cout << "Soy un animal genérico." << endl;
    }

    virtual ~Animal() {} // Destructor virtual
};

// ===============================
// Clase derivada: Perro
// ===============================
class Perro : public Animal {
public:
    void hablar() const override {
        cout << "Guau guau!" << endl;
    }

    void moverCola() const {
        cout << "Estoy moviendo la cola de felicidad 🐶." << endl;
    }
};

// ===============================
// Clase derivada: Gato
// ===============================
class Gato : public Animal {
public:
    void hablar() const override {
        cout << "Miau miau!" << endl;
    }

    void afilarGarras() const {
        cout << "Estoy afilando mis garras 🐱." << endl;
    }
};

// ===============================
// Clase personalizada: MateoPerezNomey
// ===============================
class MateoPerezNomey {
public:
    void presentarse() const {
        cout << "👋 Bienvenido al programa de animales interactivos." << endl;
        cout << "Autor: Mateo Perez Nomey\n" << endl;
    }

    void despedirse() const {
        cout << "\n👨‍💻 Gracias por usar este código. ¡Hasta pronto! 🐾" << endl;
    }
};

// ===============================
// Función que recibe un puntero a Animal
// ===============================
void interactuarConAnimal(Animal* animal) {
    animal->hablar(); // Comportamiento polimórfico

    // Intentamos convertir a Perro
    if (Perro* ptrPerro = dynamic_cast<Perro*>(animal)) {
        cout << "Este animal es un PERRO. Activando comportamiento especial..." << endl;
        ptrPerro->moverCola();
    }

    // Intentamos convertir a Gato
    else if (Gato* ptrGato = dynamic_cast<Gato*>(animal)) {
        cout << "Este animal es un GATO. Activando comportamiento especial..." << endl;
        ptrGato->afilarGarras();
    }

    else {
        cout << "Este es un animal genérico. No tiene comportamiento especial." << endl;
    }
}

// ===============================
// Función principal
// ===============================
int main() {
    MateoPerezNomey autor;
    autor.presentarse();

    Animal* listaDeAnimales[3];
    listaDeAnimales[0] = new Perro();
    listaDeAnimales[1] = new Gato();
    listaDeAnimales[2] = new Animal();

    for (int i = 0; i < 3; ++i) {
        cout << "\n--- Interacción con animal #" << (i + 1) << " ---" << endl;
        interactuarConAnimal(listaDeAnimales[i]);
    }

    for (int i = 0; i < 3; ++i) {
        delete listaDeAnimales[i];
    }

    autor.despedirse();
    return 0;
}
