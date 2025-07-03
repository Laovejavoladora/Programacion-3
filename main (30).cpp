// ========================================================
// Autor: Mateo Perez Nomey
// Descripción: Uso de herencia, clases abstractas, métodos
// virtuales y punteros inteligentes en C++ moderno.
// ========================================================

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
    cout << "--- Programa desarrollado por Mateo Perez Nomey ---" << endl;
    cout << "--- Dibujando todas las figuras ---" << endl;

    // Vector de punteros únicos a Figura
    vector<unique_ptr<Figura>> figuras;

    // Crear objetos con new manualmente (compatible con C++11)
    figuras.push_back(unique_ptr<Figura>(new Circulo()));
    figuras.push_back(unique_ptr<Figura>(new Cuadrado()));
    figuras.push_back(unique_ptr<Figura>(new Triangulo()));

    // Invocamos métodos virtuales polimórficamente
    for (const auto& figura : figuras) {
        figura->dibujar(); // Despacho dinámico
    }

    // No es necesario liberar memoria: unique_ptr lo hace automáticamente
    return 0;
}
