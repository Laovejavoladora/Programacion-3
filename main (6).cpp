#include <iostream>
#include <vector>
using namespace std;

// ===============================
// Clase base abstracta: Figura
// ===============================
class Figura {
public:
    virtual void dibujar() const = 0; // Método virtual puro
    virtual ~Figura() {} // Destructor virtual
};

// ===============================
// Clases derivadas
// ===============================
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

// ===============================
// Clase personalizada: MateoPerezNomey
// ===============================
class MateoPerezNomey {
public:
    void presentarse() const {
        cout << "👨‍💻 Hola, soy Mateo Perez Nomey, autor de este programa de figuras geométricas.\n" << endl;
    }

    void despedirse() const {
        cout << "\n🖐️ Gracias por probar este código. ¡Nos vemos! ✨" << endl;
    }
};

// ===============================
// Función principal
// ===============================
int main() {
    MateoPerezNomey autor;
    autor.presentarse();

    vector<Figura*> figuras;
    figuras.push_back(new Circulo());
    figuras.push_back(new Cuadrado());
    figuras.push_back(new Triangulo());

    cout << "--- Dibujando Figuras ---" << endl;
    for (const Figura* f : figuras) {
        f->dibujar();
    }

    for (Figura* f : figuras) {
        delete f;
    }

    autor.despedirse();
    return 0;
}
