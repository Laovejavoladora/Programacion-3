#include <iostream>
#include <string>

// Clase Base
class Animal {
protected: // Hacemos nombre protected para que Perro pueda accederlo si quisiera
    std::string nombre;
    int edad; // Podría ser private si solo se accede vía getters/setters públicos de Animal

public:
    Animal(const std::string& n, int e) : nombre(n), edad(e) {
        std::cout << "  CONSTRUCTOR Animal: Nace un animal llamado '" << nombre 
                  << "' de " << edad << " anio(s)." << std::endl;
    }
    ~Animal() {
        std::cout << "  DESTRUCTOR Animal: Muere el animal '" << nombre << "'." << std::endl;
    }
    void comer() const { // const porque no modifica el estado del Animal
        std::cout << nombre << " esta comiendo." << std::endl;
    }
    void dormir() const {
        std::cout << nombre << " esta durmiendo." << std::endl;
    }
    std::string getNombre() const { return nombre; }
};

// Clase Derivada
class Perro : public Animal { // Perro "es un tipo de" Animal
private:
    std::string raza; // Atributo específico de Perro

public:
// Constructor de Perro llama explícitamente al constructor de Animal
    Perro(const std::string& n, int e, const std::string& r) 
        : Animal(n, e), raza(r) { // Pasa 'n' y 'e' al constructor de Animal
        std::cout << "    CONSTRUCTOR Perro: Nace un perro de raza '" << raza 
                  << "', que tambien es un animal llamado '" << nombre << "'." << std::endl; 
                  // 'nombre' es accesible aquí porque es 'protected' en Animal
    }
    ~Perro() {
        // 'nombre' es accesible aquí
        std::cout << "    DESTRUCTOR Perro: Muere el perro '" << nombre << "' de raza '" << raza << "'." << std::endl;
    }
    // Método específico de Perro
    void ladrar() const {
        std::cout << getNombre() << " (un " << raza << ") dice: ¡Guau! ¡Guau!" << std::endl;
        // Usamos getNombre() para acceder al nombre, buena práctica aunque sea protected
    }
};

int main() {
    std::cout << "--- Creando un Animal generico ---" << std::endl;
    Animal animalGenerico("Alex el Leon", 10);
    animalGenerico.comer();

    std::cout << "\n--- Creando un Perro ---" << std::endl;
    Perro miMascota("Buddy", 3, "Golden Retriever");

    // Métodos heredados de Animal
    miMascota.comer();  
    miMascota.dormir(); 
    std::cout << "El nombre de mi mascota es: " << miMascota.getNombre() << std::endl;

    // Método propio de Perro
    miMascota.ladrar();   

    std::cout << "\n--- Fin de main (los objetos se destruiran) ---" << std::endl;
    return 0;
}
