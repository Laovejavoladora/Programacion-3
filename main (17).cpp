#include <iostream>
#include <string>
#define PI 3.14159

class Figura {
protected:
    std::string color;
    std::string nombreFigura;
public:
    Figura(std::string c, std::string nf) : color(c), nombreFigura(nf) {
        std::cout << "  CONSTRUCTOR Figura: '" << nombreFigura << "' de color " << color << " - Mateo Perez Nomey" << std::endl;
    }

    virtual void dibujar() const {
        std::cout << "Figura '" << nombreFigura << "': Dibujando una figura geometrica generica de color " 
                  << color << "." << std::endl;
    }

    // Nuevo método virtual para calcular perímetro
    virtual double calcularPerimetro() const {
        std::cout << "Figura genérica: no se puede calcular perímetro específico." << std::endl;
        return 0.0;
    }

    virtual ~Figura() {
        std::cout << "  DESTRUCTOR Figura: '" << nombreFigura << "' - Mateo Perez Nomey" << std::endl;
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
                  << ", Area = " << (PI * radio * radio) << " - Mateo Perez Nomey" << std::endl;
    }

    // Override para calcular perímetro del círculo
    double calcularPerimetro() const override {
        return 2 * PI * radio;
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

    // Override para calcular perímetro del rectángulo
    double calcularPerimetro() const override {
        return 2 * (base + altura);
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
        std::cout << "    CONSTRUCTOR Triangulo: Base " << base << ", Altura " << altura << std::endl;
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
    std::cout << "Perímetro: " << fig.calcularPerimetro() << std::endl;

    std::cout << "\n--- Creando y dibujando un Circulo (con llamada a Figura::dibujar) ---" << std::endl;
    Circulo circ("Rojo", 5.0);
    circ.dibujar();
    std::cout << "Perímetro: " << circ.calcularPerimetro() << std::endl;

    std::cout << "\n--- Creando y dibujando un Rectangulo ---" << std::endl;
    Rectangulo rect("Verde", 4.0, 6.0);
    rect.dibujar();
    std::cout << "Perímetro: " << rect.calcularPerimetro() << std::endl;

    std::cout << "\n--- Creando y dibujando un Triangulo ---" << std::endl;
    Triangulo tri("Amarillo", 3.0, 4.0);
    tri.dibujar();
    std::cout << "Perímetro (no implementado): " << tri.calcularPerimetro() << std::endl;

    std::cout << "\n--- Fin de main ---" << std::endl;
    return 0;
}

