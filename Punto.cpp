#include <iostream>
#include <string>
using namespace std;

// Clase Punto para representar coordenadas en 2D
class Punto {
private:
    double x;
    double y;

public:
    // Constructor por defecto (sin argumentos)
    Punto() : x(0.0), y(0.0) {
        cout << "Constructor por defecto llamado. x = " << x << ", y = " << y << endl;
    }

    // Constructor con parámetros
    Punto(double xVal, double yVal) : x(xVal), y(yVal) {
        cout << "Constructor con parámetros llamado. x = " << x << ", y = " << y << endl;
    }

    // Constructor copia (recibe otro Punto por referencia constante)
    Punto(const Punto& otro) : x(otro.x), y(otro.y) {
        cout << "Constructor copia llamado. Copiando punto: x = " << x << ", y = " << y << endl;
    }

    // Método para mostrar el punto
    void mostrar() {
        cout << "Punto en coordenadas: (" << x << ", " << y << ")" << endl;
    }
};

// Función principal
int main() {
    // Crear un punto con el constructor por defecto
    Punto p1;
    p1.mostrar();

    // Crear un punto con valores personalizados
    Punto p2(5.5, 7.3);
    p2.mostrar();

    // Crear un punto copiando otro (constructor copia)
    Punto p3(p2);
    p3.mostrar();

    return 0;
}
