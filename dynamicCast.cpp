#include <iostream>
#include <string>

// Clase base
class Animal {
public:
    virtual void hablar() const {
        std::cout << "Soy un animal genérico." << std::endl;
    }

    // Destructor virtual para permitir cast seguro
    virtual ~Animal() {}
};

// Clase derivada: Perro
class Perro : public Animal {
public:
    void hablar() const override {
        std::cout << "Guau guau!" << std::endl;
    }

    void moverCola() const {
        std::cout << "Estoy moviendo la cola de felicidad 🐶." << std::endl;
    }
};

// Clase derivada: Gato
class Gato : public Animal {
public:
    void hablar() const override {
        std::cout << "Miau miau!" << std::endl;
    }

    void afilarGarras() const {
        std::cout << "Estoy afilando mis garras 🐱." << std::endl;
    }
};

// Función que recibe un puntero a Animal y trata de identificar el tipo real
void interactuarConAnimal(Animal* animal) {
    animal->hablar(); // Comportamiento polimórfico

    // Intentamos convertir a Perro
    Perro* ptrPerro = dynamic_cast<Perro*>(animal);
    if (ptrPerro) {
        std::cout << "Este animal es un PERRO. Activando comportamiento especial..." << std::endl;
        ptrPerro->moverCola();
    }

    // Intentamos convertir a Gato
    Gato* ptrGato = dynamic_cast<Gato*>(animal);
    if (ptrGato) {
        std::cout << "Este animal es un GATO. Activando comportamiento especial..." << std::endl;
        ptrGato->afilarGarras();
    }
}

int main() {
    Animal* listaDeAnimales[3];
    listaDeAnimales[0] = new Perro();
    listaDeAnimales[1] = new Gato();
    listaDeAnimales[2] = new Animal();

    for (int i = 0; i < 3; ++i) {
        std::cout << "\n--- Interacción con animal #" << (i + 1) << " ---" << std::endl;
        interactuarConAnimal(listaDeAnimales[i]);
    }

    // Limpieza
    for (int i = 0; i < 3; ++i) {
        delete listaDeAnimales[i];
    }

    return 0;
}
