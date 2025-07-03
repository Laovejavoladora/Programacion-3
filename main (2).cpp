#include <iostream>
#include <string>
using namespace std;

// =============================================
//   PROYECTO VEHÍCULO - by Mateo Perez Nomey 🚗
// =============================================

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

// Función interactiva para mostrar el autor
void mostrarAutor() {
    cout << "\n👨‍💻 Autor del proyecto: Mateo Perez Nomey\n";
    cout << "Gracias por revisar este código 🚘✨\n";
}

int main() {
    cout << "=== PROYECTO VEHÍCULO - Código creado por Mateo Perez Nomey ===\n" << endl;

    Automovil a("Toyota", 2022, "Gasolina");
    a.arrancar();
    a.tocarBocina();

    // Interacción final
    char respuesta;
    cout << "\n¿Deseas conocer al autor del proyecto? (s/n): ";
    cin >> respuesta;

    if (respuesta == 's' || respuesta == 'S') {
        mostrarAutor();
    } else {
        cout << "Autor oculto. ¡Hasta la próxima! 👋\n";
    }

    return 0;
}

