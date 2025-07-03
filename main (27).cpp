#include <iostream> 
#include <string>
#define PI 3.14159

class Figura {
protected:
    std::string color;
    std::string nombreFigura;
public:
    Figura(std::string c, std::string nf) : color(c), nombreFigura(nf) {
        std::cout << "  CONSTRUCTOR Figura: '" << nombreFigura << "' de color " << color << " (Mateo Perez Nomey)" << std::endl;
    }

    virtual void dibujar() const {
        std::cout << "Figura '" << nombreFigura << "': Dibujando una figura geometrica generica de color " 
                  << color << "." << std::endl;
    }

    virtual ~Figura() {
        std::cout << "  DESTRUCTOR Figura: '" << nombreFigura << "' (Mateo Perez Nomey)" << std::endl;
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
        std::cout << "Circulo '" << nombreFigura << "': Dibujando un circulo perfecto de color " << color 
                  << " y radio " << radio << "." << std::endl;
        std::cout << "       Area: " << (PI * radio * radio) << std::endl;
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

int main() {
    std::cout << "--- Creando y dibujando una Figura generica ---" << std::endl;
    Figura fig("Azul", "Figura Misteriosa");
    fig.dibujar();

    std::cout << "\n--- Creando y dibujando un Circulo ---" << std::endl;
    Circulo circ("Rojo", 5.0);
    circ.dibujar();

    std::cout << "\n--- Creando y dibujando un Rectangulo ---" << std::endl;
    Rectangulo rect("Verde", 4.0, 6.0);
    rect.dibujar();

    std::cout << "\n--- Fin de main --- (Trabajo de Mateo Perez Nomey)" << std::endl;
    return 0;
}
