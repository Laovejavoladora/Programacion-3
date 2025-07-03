#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string nombre;
    int edad;

public:
    Animal(string n, int e) : nombre(n), edad(e) {
        cout << "Animal creado: " << nombre << ", edad " << edad << endl;
    }

    ~Animal() {
        cout << "Animal destruido: " << nombre << endl;
    }

    void comer() const {
        cout << nombre << " está comiendo." << endl;
    }
};

class Perro : public Animal {
private:
    string raza;

public:
    Perro(string n, int e, string r) : Animal(n, e), raza(r) {
        cout << "Perro de raza " << raza << " creado." << endl;
    }

    ~Perro() {
        cout << "Perro destruido: " << nombre << " de raza " << raza << endl;
    }

    void ladrar() const {
        cout << nombre << " dice: ¡Guau!" << endl;
    }
};

int main() {
    Perro p("Firulais", 5, "Labrador");
    p.comer();
    p.ladrar();
    return 0;
}
