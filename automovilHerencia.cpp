#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
protected:
    string marca;
    int año;

public:
    Vehiculo(string m, int a) : marca(m), año(a) {
        cout << "Vehículo creado: " << marca << " (" << año << ")" << endl;
    }

    ~Vehiculo() {
        cout << "Vehículo destruido: " << marca << endl;
    }

    void arrancar() const {
        cout << marca << " está arrancando..." << endl;
    }
};

class Automovil : public Vehiculo {
private:
    string tipoCombustible;

public:
    Automovil(string m, int a, string tc) : Vehiculo(m, a), tipoCombustible(tc) {
        cout << "Automóvil con combustible " << tipoCombustible << " creado." << endl;
    }

    ~Automovil() {
        cout << "Automóvil destruido: " << marca << endl;
    }

    void tocarBocina() const {
        cout << marca << ": ¡Piiii!" << endl;
    }
};

int main() {
    Automovil a("Toyota", 2022, "Gasolina");
    a.arrancar();
    a.tocarBocina();
    return 0;
}
