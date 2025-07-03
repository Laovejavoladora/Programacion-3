#include <iostream>
#include <string>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
// Clase Base ABSTRACTA
class FormaGeometrica {
protected:
    std::string nombreForma;
    std::string color;
public:
    FormaGeometrica(std::string nf, std::string c) : nombreForma(nf), color(c) {}
    virtual void dibujar() const = 0;
    virtual double calcularArea() const = 0;
    std::string getColor() const { return color; }
    std::string getNombre() const { return nombreForma; }
    virtual ~FormaGeometrica() {
        std::cout << "DESTRUCTOR FormaGeometrica: " << nombreForma << std::endl;
    }
};
// Clase derivada completa: Circulo
class Circulo : public FormaGeometrica {
private:
    double radio;
public:
    Circulo(std::string nf, std::string c, double r) : FormaGeometrica(nf, c), radio(r) {}

    void dibujar() const override {
        std::cout << getNombre() << " (" << getColor() << "): Dibujando CIRCULO de radio " << radio << std::endl;
    }

    double calcularArea() const override {
        return M_PI * radio * radio;
    }

    ~Circulo() override {
        std::cout << "  DESTRUCTOR Circulo: " << getNombre() << std::endl;
    }
};
// ❌ Ejemplo 1: Intentar instanciar directamente una clase abstracta
void probarInstanciaAbstracta() {
    // FormaGeometrica f("Generica", "Transparente"); 
    // ❌ ERROR: cannot declare variable ‘f’ to be of abstract type ‘FormaGeometrica’
    // Explicación: FormaGeometrica tiene métodos virtuales puros => no se puede instanciar directamente.
}
// ❌ Ejemplo 2: Clase derivada INCOMPLETA (olvida implementar calcularArea)
class TrianguloError : public FormaGeometrica {
private:
    double base, altura;
public:
    TrianguloError(std::string nf, std::string c, double b, double h)
        : FormaGeometrica(nf, c), base(b), altura(h) {}

    void dibujar() const override {
        std::cout << getNombre() << " (" << getColor() << "): Dibujando TRIANGULO de base " << base
                  << " y altura " << altura << std::endl;
    }
    // ❌ FALTA calcularArea()
    // Por tanto, esta clase sigue siendo abstracta.
};
// ✅ Versión CORREGIDA de Triangulo
class Triangulo : public FormaGeometrica {
private:
    double base, altura;
public:
    Triangulo(std::string nf, std::string c, double b, double h)
        : FormaGeometrica(nf, c), base(b), altura(h) {}
    void dibujar() const override {
        std::cout << getNombre() << " (" << getColor() << "): Dibujando TRIANGULO de base " << base
                  << " y altura " << altura << std::endl;
    }
    double calcularArea() const override {
        return 0.5 * base * altura;
    }
    ~Triangulo() override {
        std::cout << "  DESTRUCTOR Triangulo: " << getNombre() << std::endl;
    }
};
// Función auxiliar para describir cualquier forma
void describirForma(const FormaGeometrica* forma) {
    std::cout << "\n--- Descripción de Forma ---" << std::endl;
    forma->dibujar();
    std::cout << "   Área: " << forma->calcularArea() << std::endl;
    std::cout << "   Color: " << forma->getColor() << std::endl;
}
int main() {
    std::cout << "🚫 1. Intentando instanciar FormaGeometrica directamente (comenta esta línea si pruebas):" << std::endl;
    // probarInstanciaAbstracta(); // ❌ ERROR si se descomenta
    std::cout << "\n🚫 2. Intentando crear objeto de TrianguloError sin implementar calcularArea:" << std::endl;
    // TrianguloError t("Triángulo Defectuoso", "Gris", 4.0, 3.0); // ❌ ERROR si se descomenta
    std::cout << "\n✅ 3. Instanciando un Circulo y un Triangulo válidos:" << std::endl;
    FormaGeometrica* forma1 = new Circulo("Círculo Perfecto", "Azul", 5.0);
    FormaGeometrica* forma2 = new Triangulo("Triángulo Correcto", "Verde", 4.0, 3.0);
    describirForma(forma1);
    describirForma(forma2);
    delete forma1;
    delete forma2;
    return 0;
}

