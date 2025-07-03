#include <iostream>
#include <string>

// Clase Base
class Animal {
protected:
    std::string nombre;
    int edad;

public:
    Animal(const std::string& n, int e) : nombre(n), edad(e) {
        std::cout << "CONSTRUCTOR Animal: Nace un animal llamado '" << nombre 
                  << "' de " << edad << " anio(s)." << std::endl;
    }
    ~Animal() {
        std::cout << "DESTRUCTOR Animal: Muere el animal '" << nombre << "'." << std::endl;
    }
    void comer() const {
        std::cout << nombre << " está comiendo." << std::endl;
    }
    void dormir() const {
        std::cout << nombre << " está durmiendo." << std::endl;
    }
    std::string getNombre() const { return nombre; }
};

// Clase Derivada
class Perro : public Animal {
private:
    std::string raza;

public:
    Perro(const std::string& n, int e, const std::string& r) 
        : Animal(n, e), raza(r) {
        std::cout << "CONSTRUCTOR Perro: Nace un perro de raza '" << raza 
                  << "', que también es un animal llamado '" << nombre << "'." << std::endl;
    }
    ~Perro() {
        std::cout << "DESTRUCTOR Perro: Muere el perro '" << nombre << "' de raza '" << raza << "'." << std::endl;
    }
    void ladrar() const {
        std::cout << getNombre() << " (un " << raza << ") dice: ¡Guau! ¡Guau!" << std::endl;
    }
};

int main() {
    std::cout << "--- Creando un Animal genérico ---" << std::endl;
    Animal animalGenerico("Alex el León", 10);
    animalGenerico.comer();

    std::cout << "\n--- Creando un Perro llamado Mateo Pérez Nomey ---" << std::endl;
    Perro miMascota("Mateo Pérez Nomey", 3, "Golden Retriever");

    miMascota.comer();  
    miMascota.dormir(); 
    std::cout << "El nombre de mi mascota es: " << miMascota.getNombre() << std::endl;

    miMascota.ladrar();   

    std::cout << "\n--- Fin de main (los objetos se destruirán) ---" << std::endl;
    return 0;
}
