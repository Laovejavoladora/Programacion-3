// =======================================================
// Autor: Mateo Perez Nomey
// Proyecto: Polimorfismo con Clases Derivadas en C++
// Descripción: Explora el comportamiento con y sin virtual
// =======================================================

#include <iostream>
#include <string>
#include <vector>

// QUITA O DEJA virtual PARA EXPERIMENTAR:

#define USAR_VIRTUAL_METODOS  // 💡 Comenta esta línea para EXPERIMENTO 1
#define USAR_VIRTUAL_DESTRUCTOR // 💡 Comenta esta línea para EXPERIMENTO 2

const double PI = 3.14159265358979323846;

class Figura {
protected:
    std::string nombreFigura;

public:
    Figura(std::string nf) : nombreFigura(nf) {}

#ifdef USAR_VIRTUAL_METODOS
    virtual void dibujar() const {
#else
    void dibujar() const {
#endif
        std::cout << nombreFigura << ": Dibujando figura genérica." << std::endl;
    }

    virtual double calcularArea() const {
        std::cout << nombreFigura << ": Área de figura genérica no definida." << std::endl;
        return 0.0;
    }

#ifdef USAR_VIRTUAL_DESTRUCTOR
    virtual ~Figura() {
#else
    ~Figura() {
#endif
        std::cout << "DESTRUCTOR Figura: " << nombreFigura << std::endl;
    }
};

// =======================================================
// 📐 Círculo
// =======================================================
class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(std::string nf, double r) : Figura(nf), radio(r) {}

    void dibujar() const override {
        std::cout << nombreFigura << ": Dibujando un CIRCULO de radio " << radio << "." << std::endl;
    }

    double calcularArea() const override {
        return PI * radio * radio;
    }

    ~Circulo() override {
        std::cout << "  DESTRUCTOR Circulo: " << nombreFigura << std::endl;
    }
};

// =======================================================
// 📏 Rectángulo
// =======================================================
class Rectangulo : public Figura {
private:
    double base, altura;

public:
    Rectangulo(std::string nf, double b, double h) : Figura(nf), base(b), altura(h) {}

    void dibujar() const override {
        std::cout << nombreFigura << ": Dibujando un RECTANGULO de base " << base
                  << " y altura " << altura << "." << std::endl;
    }

    double calcularArea() const override {
        return base * altura;
    }

    ~Rectangulo() override {
        std::cout << "  DESTRUCTOR Rectangulo: " << nombreFigura << std::endl;
    }
};

// =======================================================
// 🔺 Triángulo
// =======================================================
class Triangulo : public Figura {
private:
    double base, altura;

public:
    Triangulo(std::string nf, double b, double h) : Figura(nf), base(b), altura(h) {}

    void dibujar() const override {
        std::cout << nombreFigura << ": Dibujando un TRIANGULO de base " << base
                  << " y altura " << altura << "." << std::endl;
    }

    double calcularArea() const override {
        return (base * altura) / 2.0;
    }

    ~Triangulo() override {
        std::cout << "  DESTRUCTOR Triangulo: " << nombreFigura << std::endl;
    }
};

// =======================================================
// 🔁 Función genérica que procesa figuras
// =======================================================
void procesarFigura(const Figura* figPtr) {
    std::cout << "Procesando figura (vía puntero a Figura):" << std::endl;
    figPtr->dibujar();
    std::cout << "  Su área es: " << figPtr->calcularArea() << std::endl;
}

// =======================================================
// 🧪 Función principal con todos los experimentos
// =======================================================
int main() {
    std::cout << "\n🔧 Programa desarrollado por Mateo Perez Nomey\n" << std::endl;

    Figura* ptrFig1 = new Circulo("Círculo Mágico", 10.0);
    Figura* ptrFig2 = new Rectangulo("Rectángulo Dorado", 5.0, 8.0);
    Figura* ptrFig3 = new Figura("Figura Abstracta");
    Figura* ptrFig4 = new Triangulo("Triángulo Azul", 6.0, 4.0);

    std::cout << "\n=== 🔍 Llamadas directas ===" << std::endl;
    ptrFig1->dibujar();
    ptrFig2->dibujar();
    ptrFig3->dibujar();
    ptrFig4->dibujar();

    std::cout << "\n=== 🚀 Usando función procesarFigura ===" << std::endl;
    procesarFigura(ptrFig1);
    procesarFigura(ptrFig2);
    procesarFigura(ptrFig3);
    procesarFigura(ptrFig4);

    std::cout << "\n=== 📦 Usando vector polimórfico ===" << std::endl;
    std::vector<Figura*> figurasParaMostrar = { ptrFig1, ptrFig2, ptrFig3, ptrFig4 };
    for (const Figura* fig : figurasParaMostrar) {
        fig->dibujar();
    }

    std::cout << "\n=== 🧹 Liberando memoria ===" << std::endl;
    delete ptrFig1;
    delete ptrFig2;
    delete ptrFig3;
    delete ptrFig4;

    std::cout << "\n🔚 Fin del programa de Mateo Perez Nomey" << std::endl;
    return 0;
}
