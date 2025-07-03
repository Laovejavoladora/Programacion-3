#include <iostream>
#include <vector>
using namespace std;
// Clase base abstracta
class Figura {
public:
    virtual void dibujar() const = 0; // Método virtual puro (interfaz)
    virtual ~Figura() {} // Destructor virtual para evitar fugas
};
// Clase derivada: Círculo
class Circulo : public Figura {
public:
    void dibujar() const override {
        cout << "Dibujar Círculo" << endl;
    }
};
// Clase derivada: Cuadrado
class Cuadrado : public Figura {
public:
    void dibujar() const override {
        cout << "Dibujar Cuadrado" << endl;
    }
};
// Clase derivada: Triángulo
class Triangulo : public Figura {
public:
    void dibujar() const override {
        cout << "Dibujar Triángulo" << endl;
    }
};
int main() {
    // Creamos un vector de punteros a Figura
    vector<Figura*> figuras;
    // Agregamos diferentes objetos derivados al vector
    figuras.push_back(new Circulo());
    figuras.push_back(new Cuadrado());
    figuras.push_back(new Triangulo());
    // Recorremos la colección polimórfica
    for (const Figura* f : figuras) {
        f->dibujar(); // Llamada polimórfica a través de puntero base
    }
    // Liberamos memoria (importante para evitar fugas)
    for (Figura* f : figuras) {
        delete f;  // Llama al destructor correcto gracias a que es virtual
    }
    return 0;
}
