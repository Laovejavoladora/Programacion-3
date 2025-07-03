#include <iostream>
#include <string>
#define PI 3.14159
class Figura {
protected:
    std::string color;
    std::string nombreFigura;
public:
    Figura(std::string c, std::string nf) : color(c), nombreFigura(nf) {
        std::cout << "  CONSTRUCTOR Figura: '" << nombreFigura << "' de color " << color << std::endl;
    }
    virtual void dibujar() const {
        std::cout << "Figura '" << nombreFigura << "': Dibujando una figura geometrica generica de color " 
                  << color << "." << std::endl;
    }
    virtual ~Figura() {
        std::cout << "  DESTRUCTOR Figura: '" << nombreFigura << "'" << std::endl;
    }
};
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(std::string c, double r) : Figura(c, "Circulo"), radio(r) {
        std::cout << "    CONSTRUCTOR Circulo: Radio " << radio << std::endl;
    }
    void dibujar() const override {
        Figura::dibujar(); // Llamada explícita a la versión de la clase base
        std::cout << " -> Circulo: Radio = " << radio 
                  << ", Area = " << (PI * radio * radio) << std::endl;
    }
    ~Circulo() override {
        std::cout << "    DESTRUCTOR Circulo: Radio " << radio << std::endl;
    }
};
class Rectangulo : public Figura {
private:
    double base, altura;
public:
    Rectangulo(std::string c, double b, double h) : Figura(c, "Rectangulo"), base(b), altura(h) {
        std::cout << "    CONSTRUCTOR Rectangulo: Base " << b << ", Altura " << h << std::endl;
    }
    void dibujar() const override {
        std::cout << "Rectangulo '" << nombreFigura << "': Dibujando un rectangulo de color " << color 
                  << " con base " << base << " y altura " << altura << "." << std::endl;
        std::cout << "       Area: " << (base * altura) << std::endl;
    }
    ~Rectangulo() override {
        std::cout << "    DESTRUCTOR Rectangulo: Base " << base << ", Altura " << altura << std::endl;
    }
};
// ✅ NUEVA CLASE: Triangulo
class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(std::string c, double b, double h) : Figura(c, "Triangulo"), base(b), altura(h) {
        std::cout << "    CONSTRUCTOR Triangulo: Base " << b << ", Altura " << h << std::endl;
    }
    void dibujar() const override {
        std::cout << "Triangulo '" << nombreFigura << "': Dibujando un triangulo de color " << color 
                  << " con base " << base << " y altura " << altura << "." << std::endl;
        std::cout << "       Area: " << (base * altura) / 2 << std::endl;
    }
    ~Triangulo() override {
        std::cout << "    DESTRUCTOR Triangulo: Base " << base << ", Altura " << altura << std::endl;
    }
};
int main() {
    std::cout << "\n--- Creando y dibujando una Figura generica ---" << std::endl;
    Figura fig("Azul", "Figura Misteriosa");
    fig.dibujar();
    std::cout << "\n--- Creando y dibujando un Circulo (con llamada a Figura::dibujar) ---" << std::endl;
    Circulo circ("Rojo", 5.0);
    circ.dibujar();
    std::cout << "\n--- Creando y dibujando un Rectangulo ---" << std::endl;
    Rectangulo rect("Verde", 4.0, 6.0);
    rect.dibujar();
    std::cout << "\n--- Creando y dibujando un Triangulo ---" << std::endl;
    Triangulo tri("Amarillo", 3.0, 4.0);
    tri.dibujar();
    std::cout << "\n--- Fin de main ---" << std::endl;
    return 0;
}
