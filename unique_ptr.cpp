#include <iostream>
#include <vector>
#include <memory>  // Necesario para smart pointers
using namespace std;

// Clase base abstracta
class Figura {
public:
    virtual void dibujar() const = 0; // Método virtual puro
    virtual ~Figura() {}              // Destructor virtual
};

// Clases derivadas
class Circulo : public Figura {
public:
    void dibujar() const override {
        cout << "Dibujar Círculo" << endl;
    }
};

class Cuadrado : public Figura {
public:
    void dibujar() const override {
        cout << "Dibujar Cuadrado" << endl;
    }
};

class Triangulo : public Figura {
public:
    void dibujar() const override {
        cout << "Dibujar Triángulo" << endl;
    }
};

int main() {
    // Vector de punteros únicos a Figura
    vector<unique_ptr<Figura>> figuras;

    // Agregamos elementos usando std::make_unique (C++14 en adelante)
    figuras.push_back(make_unique<Circulo>());
    figuras.push_back(make_unique<Cuadrado>());
    figuras.push_back(make_unique<Triangulo>());

    // Invocamos métodos virtuales polimórficamente
    for (const auto& figura : figuras) {
        figura->dibujar(); // Despacho dinámico
    }

    // No es necesario liberar memoria: unique_ptr lo hace automáticamente
    return 0;
}
