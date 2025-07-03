#include <iostream> // ¡Esta línea es la que faltaba!

class Punto {
public:
    double x, y;
    
    // Constructor 1: Por defecto (en el origen)
    Punto() : x(0.0), y(0.0) {
        std::cout << "Punto creado en el origen (0,0) por constructor por defecto." << std::endl;
    }
    
    // Constructor 2: Con coordenadas específicas
    Punto(double coord_x, double coord_y) : x(coord_x), y(coord_y) {
        std::cout << "Punto creado en (" << x << "," << y << ") por constructor con coords." << std::endl;
    }
    
    // Constructor 3: Copia (se genera uno por defecto, pero podemos hacerlo explícito)
    Punto(const Punto& otroPunto) : x(otroPunto.x), y(otroPunto.y) {
        std::cout << "Punto copiado de (" << otroPunto.x << "," << otroPunto.y << ")." << std::endl;
    }
    
    // Destructor (opcional, para demostrar el ciclo de vida)
    ~Punto() {
        std::cout << "Punto en (" << x << "," << y << ") destruido." << std::endl;
    }
    
    // Método para mostrar las coordenadas
    void mostrar() const {
        std::cout << "Punto(" << x << ", " << y << ")" << std::endl;
    }
};

// Función main para probar la clase
int main() {
    std::cout << "=== Demostrando constructores ===" << std::endl;
    
    // Constructor por defecto
    Punto p1;
    
    // Constructor con coordenadas
    Punto p2(5.0, 3.0);
    
    // Constructor de copia
    Punto p3(p2);
    
    std::cout << "\n=== Mostrando puntos ===" << std::endl;
    p1.mostrar();
    p2.mostrar();
    p3.mostrar();
    
    return 0;
}