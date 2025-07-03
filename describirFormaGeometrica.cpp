#include <iostream>
#include <string>
#include <vector>
#include <cmath> // Para operaciones matemáticas
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
    // FUNCIONES VIRTUALES PURAS (el contrato)
    virtual void dibujar() const = 0; 
    virtual double calcularArea() const = 0;
    // Método heredable
    std::string getColor() const { return color; }
    std::string getNombre() const { return nombreForma; }
    // Destructor virtual
    virtual ~FormaGeometrica() {
        std::cout << "DESTRUCTOR FormaGeometrica: " << nombreForma << std::endl;
    }
};
// Clase Derivada CONCRETA: Circulo
class Circulo : public FormaGeometrica {
private:
    double radio;
public:
    Circulo(std::string nf, std::string c, double r) : FormaGeometrica(nf, c), radio(r) {}

    void dibujar() const override {
        std::cout << getNombre() << " (" << getColor() << "): Dibujando CIRCULO con radio " 
                  << radio << "." << std::endl;
    }
    double calcularArea() const override {
        return M_PI * radio * radio;
    }
~Circulo() override {
        std::cout << "  DESTRUCTOR Circulo: " << getNombre() << std::endl;
    }
};
// Función para describir una forma
void describirForma(const FormaGeometrica* forma) {
    std::cout << "\n--- Descripción de Forma ---" << std::endl;
    forma->dibujar();
    std::cout << "   Área: " << forma->calcularArea() << std::endl;
    std::cout << "   Color: " << forma->getColor() << std::endl;
}
int main() {
    FormaGeometrica* miCirculo = new Circulo("Círculo Principal", "Rojo", 5.0);
    describirForma(miCirculo);
    delete miCirculo;
    return 0;
}

    




