#include <iostream>
using namespace std;

// Clase base
class Figura {
public:
    // Método virtual para habilitar el despacho dinámico
    virtual void dibujar() const {
        cout << "Dibujar Figura genérica" << endl;
    }

    // Es buena práctica tener un destructor virtual
    virtual ~Figura() {}
};

// Clase derivada
class Circulo : public Figura {
public:
    // Redefinición del método virtual
    void dibujar() const override {
        cout << "Dibujar Círculo" << endl;
    }
};

// Clase derivada adicional para contraste
class Cuadrado : public Figura {
public:
    void dibujar() const override {
        cout << "Dibujar Cuadrado" << endl;
    }
};

int main() {
    // Puntero de tipo base apuntando a objeto derivado
    Figura* figura1 = new Circulo();
    Figura* figura2 = new Cuadrado();

    // Invocación del método virtual: se ejecuta dinámicamente
    figura1->dibujar();  // Salida: "Dibujar Círculo"
    figura2->dibujar();  // Salida: "Dibujar Cuadrado"

    // Liberar memoria
    delete figura1;
    delete figura2;

    return 0;
}
