#include <iostream>
#include <string>
#include <vector>
#include <cmath> // Para M_PI

// ===================================================
//   PROYECTO FORMAS GEOMÉTRICAS - Mateo Perez Nomey 🧠
// ===================================================

// Clase Base ABSTRACTA
class FormaGeometrica {
protected:
    std::string nombreForma;
    std::string color;
public:
    FormaGeometrica(std::string nf, std::string c) : nombreForma(nf), color(c) {}

    // FUNCIONES VIRTUALES PURAS
    virtual void dibujar() const = 0;
    virtual double calcularArea() const = 0;

    // Métodos comunes
    std::string getColor() const { return color; }
    std::string getNombre() const { return nombreForma; }

    virtual ~FormaGeometrica() {
        std::cout << "DESTRUCTOR FormaGeometrica: " << nombreForma << std::endl;
    }
};

// Clase Derivada: Circulo
class Circulo : public FormaGeometrica {
private:
    double radio;
public:
    Circulo(std::string nf, std::string c, double r) : FormaGeometrica(nf, c), radio(r) {}

    void dibujar() const override {
        std::cout << getNombre() << " (" << getColor() << "): Dibujando CIRCULO con radio " << radio << "." << std::endl;
    }
    double calcularArea() const override {
        return M_PI * radio * radio;
    }
    ~Circulo() override {
        std::cout << "  DESTRUCTOR Circulo: " << getNombre() << std::endl;
    }
};

// Clase Derivada: Rectangulo
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

// Función para mostrar descripción de forma
void describirForma(const FormaGeometrica* forma) {
    std::cout << "\n--- Descripción de Forma ---" << std::endl;
    forma->dibujar();
    std::cout << "   Área: " << forma->calcularArea() << std::endl;
    std::cout << "   Color: " << forma->getColor() << std::endl;
}

// Función interactiva para mostrar autor
void mostrarAutor() {
    std::cout << "\n👨‍💻 Autor del proyecto: Mateo Perez Nomey\n";
    std::cout << "Gracias por revisar este código de formas geométricas 🟦🔵📐\n";
}

int main() {
    std::cout << "=== PROYECTO FORMAS GEOMÉTRICAS - Código creado por Mateo Perez Nomey ===\n" << std::endl;

    FormaGeometrica* ptrCirculo = new Circulo("Mi Círculo", "Rojo", 7.0);
    FormaGeometrica* ptrRectangulo = new Rectangulo("Mi Rectángulo", "Azul", 4.0, 5.0);

    describirForma(ptrCirculo);
    describirForma(ptrRectangulo);

    std::vector<FormaGeometrica*> misFormas;
    misFormas.push_back(ptrCirculo);
    misFormas.push_back(ptrRectangulo);
    misFormas.push_back(new Circulo("Otro Círculo", "Verde", 3.0));

    std::cout << "\n--- Procesando todas las formas del vector ---" << std::endl;
    for (const FormaGeometrica* f : misFormas) {
        f->dibujar();
    }

    std::cout << "\n--- Liberando memoria ---" << std::endl;
    delete misFormas[2];      // Borra "Otro Círculo"
    delete ptrRectangulo;     // Ya estaba en el vector
    delete ptrCirculo;        // Ya estaba en el vector

    // Interacción final
    char opcion;
    std::cout << "\n¿Deseas conocer al autor del proyecto? (s/n): ";
    std::cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        mostrarAutor();
    } else {
        std::cout << "Autor oculto. ¡Hasta la próxima! 👋\n";
    }

    return 0;
}
