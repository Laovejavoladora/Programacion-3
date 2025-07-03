#include <iostream>
#include <string>
#include <vector> // Para std::vector
#define PI 3.14159 // Definimos PI para el cálculo del área del círculo

// Clase base abstracta que representa cualquier figura geométrica
class Figura {
protected:
    std::string nombreFigura; // Nombre identificador de la figura
public:
    // Constructor de la clase Figura, inicializa el nombre
    Figura(std::string nf) : nombreFigura(nf) {
        // std::cout << "CONSTRUCTOR Figura: " << nombreFigura << std::endl;
    }

    // MÉTODOS VIRTUALES: Permiten redefinir el comportamiento en las clases hijas
    virtual void dibujar() const { // const significa que no modifica atributos
        std::cout << nombreFigura << ": Dibujando figura genérica." << std::endl;
    }

    virtual double calcularArea() const {
        std::cout << nombreFigura << ": Área de figura genérica no definida." << std::endl;
        return 0.0;
    }

    // DESTRUCTOR VIRTUAL: Clave para liberar correctamente objetos derivados al usar punteros a la clase base
    virtual ~Figura() {
        std::cout << "Mateo Perez Nomey: DESTRUCTOR Figura: " << nombreFigura << std::endl;
    }
};

// Clase derivada Circulo, especialización de Figura
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(std::string nf, double r) : Figura(nf), radio(r) {
        // std::cout << "  CONSTRUCTOR Circulo: " << nombreFigura << std::endl;
    }

    // Sobreescribe el método dibujar de Figura
    void dibujar() const override {
        std::cout << nombreFigura << ": Dibujando un CIRCULO de radio " << radio << "." << std::endl;
    }

    // Sobreescribe el método calcularArea de Figura
    double calcularArea() const override {
        return PI * radio * radio;
    }

    ~Circulo() override {
        std::cout << "Mateo Perez Nomey: DESTRUCTOR Circulo: " << nombreFigura << std::endl;
    }
};

// Clase derivada Rectangulo, especialización de Figura
class Rectangulo : public Figura {
private:
    double base, altura;
public:
    Rectangulo(std::string nf, double b, double h) : Figura(nf), base(b), altura(h) {
        // std::cout << "  CONSTRUCTOR Rectangulo: " << nombreFigura << std::endl;
    }

    void dibujar() const override {
        std::cout << nombreFigura << ": Dibujando un RECTANGULO de base " << base
                  << " y altura " << altura << "." << std::endl;
    }

    double calcularArea() const override {
        return base * altura;
    }

    ~Rectangulo() override {
        std::cout << "Mateo Perez Nomey: DESTRUCTOR Rectangulo: " << nombreFigura << std::endl;
    }
};

// Una función que puede operar sobre cualquier figura
// Esto es posible gracias al POLIMORFISMO (usamos punteros a Figura)
void procesarFigura(const Figura* figPtr) {
    std::cout << "Mateo Perez Nomey: Procesando figura (vía puntero a Figura):" << std::endl;
    figPtr->dibujar(); // Llamada polimórfica: ejecuta la versión apropiada según el tipo real del objeto
    std::cout << "  Su área es: " << figPtr->calcularArea() << std::endl;
}

int main() {
    Figura* ptrFig1 = new Circulo("Círculo Mágico", 10.0);
    Figura* ptrFig2 = new Rectangulo("Rectángulo Dorado", 5.0, 8.0);
    Figura* ptrFig3 = new Figura("Figura Abstracta"); // Objeto de clase base (no común)

    std::cout << "--- Llamadas directas a través de punteros a Figura ---" << std::endl;
    ptrFig1->dibujar();
    ptrFig2->dibujar();
    ptrFig3->dibujar();

    std::cout << "\n--- Usando la función genérica procesarFigura ---" << std::endl;
    procesarFigura(ptrFig1);
    procesarFigura(ptrFig2);
    procesarFigura(ptrFig3);

    std::vector<Figura*> figurasParaMostrar = { ptrFig1, ptrFig2, ptrFig3 };

    std::cout << "\n--- Dibujando todas las figuras usando un vector ---" << std::endl;
    for (const Figura* fig : figurasParaMostrar) {
        fig->dibujar();
    }

    std::cout << "\n--- Liberando memoria (IMPORTANTE: Destructores Virtuales) ---" << std::endl;
    delete ptrFig1;
    ptrFig1 = nullptr;

    delete ptrFig2;
    ptrFig2 = nullptr;

    delete ptrFig3;
    ptrFig3 = nullptr;

    return 0;
}

