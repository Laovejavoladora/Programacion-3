#include <iostream>
#include <string>
#include <vector>
#include <cmath> // Para M_PI (en algunos compiladores <cmath> lo define, en otros <math.h> o definirlo manualmente)
                 // const double PI = 3.1415926535; // Alternativa manual

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

    // Un método normal, no virtual puro, heredado por todos
    std::string getColor() const { return color; }
    std::string getNombre() const { return nombreForma; }

    // Destructor virtual (¡siempre!)
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

    void dibujar() const override { // Obligatorio implementar
        std::cout << getNombre() << " (" << getColor() << "): Dibujando CIRCULO con radio " << radio << "." << std::endl;
    }
    double calcularArea() const override { // Obligatorio implementar
        return M_PI * radio * radio;
    }
    ~Circulo() override {
        std::cout << "  DESTRUCTOR Circulo: " << getNombre() << std::endl;
    }
};




#// Clase Derivada CONCRETA: Rectangulo
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

void describirForma(const FormaGeometrica* forma) { // Recibe puntero a la base abstracta
    std::cout << "\n--- Descripcion de Forma ---" << std::endl;
    forma->dibujar(); // Llamada polimórfica
    std::cout << "   Area: " << forma->calcularArea() << std::endl; // Llamada polimórfica
    std::cout << "   Color: " << forma->getColor() << std::endl; // Método normal de la base
}

int main() {
    // FormaGeometrica formaGenerica("Generica", "Transparente"); // ¡ERROR! No se puede instanciar.

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
        f->dibujar(); // Polimorfismo en acción
    }

    std::cout << "\n--- Liberando memoria ---" << std::endl;
    // OJO: ptrCirculo y ptrRectangulo están tanto sueltos como en el vector.
    // Para este ejemplo, borraremos los originales, y el "Otro Circulo"
    // Si el vector fuera el único dueño, iteraríamos y borraríamos.
    delete misFormas[2]; // Borra "Otro Circulo"
    delete ptrRectangulo;
    delete ptrCirculo;

    // Alternativa más limpia si el vector es el dueño:
    // for (FormaGeometrica* f : misFormas) { delete f; }
    // misFormas.clear();

    return 0;
}

