#include <iostream>
#include <string>
#include <vector>
#include <cmath>
// Clase base abstracta
class FormaGeometrica {
protected:
    std::string nombreFigura;
    std::string color;
public:
    FormaGeometrica(std::string nf, std::string c) : nombreFigura(nf), color(c) {
        std::cout << "CONSTRUCTOR FormaGeometrica: " << nombreFigura << " (" << color << ")" << std::endl;
    }
    virtual void dibujar() const = 0; // Método puro
    virtual double calcularArea() const = 0; // Método puro
    std::string getColor() const { return color; }
    std::string getNombre() const { return nombreFigura; }
    virtual ~FormaGeometrica() {
        std::cout << "DESTRUCTOR FormaGeometrica: " << nombreFigura << std::endl;
    }
};
// Clase derivada: Circulo
class Circulo : public FormaGeometrica {
private:
    double radio;
public:
    Circulo(std::string nf, std::string c, double r) : FormaGeometrica(nf, c), radio(r) {}

    void dibujar() const override {
        std::cout << getNombre() << " (" << getColor() << "): Dibujando CIRCULO de radio " 
                  << radio << "." << std::endl;
    }
    double calcularArea() const override {
        return 3.14159 * radio * radio;
    }

    ~Circulo() override {
        std::cout << "  DESTRUCTOR Circulo: " << getNombre() << std::endl;
    }
};
// Clase derivada: Rectangulo
class Rectangulo : public FormaGeometrica {
private:
    double base, altura;
public:
    Rectangulo(std::string nf, std::string c, double b, double h) : FormaGeometrica(nf, c), base(b), altura(h) {}

    void dibujar() const override {
        std::cout << getNombre() << " (" << getColor() << "): Dibujando RECTANGULO base " 
                  << base << ", altura " << altura << "." << std::endl;
    }
    double calcularArea() const override {
        return base * altura;
    }
    ~Rectangulo() override {
        std::cout << "  DESTRUCTOR Rectangulo: " << getNombre() << std::endl;
    }
};
// Función para describir cualquier forma
void describirForma(const FormaGeometrica* forma) {
    std::cout << "\n--- Descripcion de Forma ---" << std::endl;
    forma->dibujar();
    std::cout << "   Area: " << forma->calcularArea() << std::endl;
    std::cout << "   Color: " << forma->getColor() << std::endl;
}
int main() {
    FormaGeometrica* ptrCirculo = new Circulo("Mi Circulo", "Rojo", 7.0);
    FormaGeometrica* ptrRectangulo = new Rectangulo("Mi Rectangulo", "Azul", 4.0, 5.0);
    describirForma(ptrCirculo);
    describirForma(ptrRectangulo);
    std::vector<FormaGeometrica*> misFormas;
    misFormas.push_back(ptrCirculo);
    misFormas.push_back(ptrRectangulo);
    misFormas.push_back(new Circulo("Otro Circulo", "Verde", 3.0));
    std::cout << "\n--- Procesando todas las formas del vector ---" << std::endl;
    for (const FormaGeometrica* f : misFormas) {
        f->dibujar();
    }
    std::cout << "\n--- Liberando memoria ---" << std::endl;
    delete misFormas[2]; // Borra "Otro Circulo"
    delete ptrRectangulo;
    delete ptrCirculo;
    return 0;
}

