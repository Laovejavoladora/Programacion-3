#include <iostream>
#include <string>
using namespace std;

// ===============================
// Clase Base
// ===============================
class Animal {
protected:
    string nombre;
    int edad;

public:
    Animal(const string& n, int e) : nombre(n), edad(e) {
        cout << "  CONSTRUCTOR Animal: Nace un animal llamado '" << nombre 
             << "' de " << edad << " anio(s)." << endl;
    }
    ~Animal() {
        cout << "  DESTRUCTOR Animal: Muere el animal '" << nombre << "'." << endl;
    }
    void comer() const {
        cout << nombre << " esta comiendo." << endl;
    }
    void dormir() const {
        cout << nombre << " esta durmiendo." << endl;
    }
    string getNombre() const { return nombre; }
};

// ===============================
// Clase Derivada: Perro
// ===============================
class Perro : public Animal {
private:
    string raza;

public:
    Perro(const string& n, int e, const string& r) 
        : Animal(n, e), raza(r) {
        cout << "    CONSTRUCTOR Perro: Nace un perro de raza '" << raza 
             << "', que tambien es un animal llamado '" << nombre << "'." << endl;
    }

    ~Perro() {
        cout << "    DESTRUCTOR Perro: Muere el perro '" << nombre 
             << "' de raza '" << raza << "'." << endl;
    }

    void ladrar() const {
        cout << getNombre() << " (un " << raza << ") dice: ¡Guau! ¡Guau!" << endl;
    }
};

// ===============================
// Clase Personalizada: MateoPerezNomey
// ===============================
class MateoPerezNomey {
public:
    void presentarse() const {
        cout << "👨‍💻 Hola, soy Mateo Perez Nomey, autor de este programa de animales.\n" << endl;
    }

    void despedirse() const {
        cout << "\n👋 Gracias por usar el programa. ¡Hasta la próxima! 🐾" << endl;
    }
};

// ===============================
// Función Principal
// ===============================
int main() {
    MateoPerezNomey autor;
    autor.presentarse();

    cout << "--- Creando un Animal generico ---" << endl;
    Animal animalGenerico("Alex el Leon", 10);
    animalGenerico.comer();

    cout << "\n--- Creando un Perro ---" << endl;
    Perro miMascota("Buddy", 3, "Golden Retriever");

    miMascota.comer();  
    miMascota.dormir(); 
    cout << "El nombre de mi mascota es: " << miMascota.getNombre() << endl;
    miMascota.ladrar();   

    cout << "\n--- Fin de main (los objetos se destruiran) ---" << endl;

    autor.despedirse();
    return 0;
}
