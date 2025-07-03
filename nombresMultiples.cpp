#include <iostream>

// Área de un círculo
double calcularArea(double radio) {
    std::cout << "Calculando área de CÍRCULO..." << std::endl;
    return 3.14159 * radio * radio;
}

// Área de un rectángulo
double calcularArea(double base, double altura) {
    std::cout << "Calculando área de RECTÁNGULO..." << std::endl;
    return base * altura;
}

// Área de un cuadrado
double calcularArea(int lado) {
    std::cout << "Calculando área de CUADRADO..." << std::endl;
    return lado * lado;
}

int main() {
    double areaCirc = calcularArea(5.0);          // Llama a la función de círculo
    double areaRect = calcularArea(4.0, 6.0);     // Llama a la función de rectángulo
    double areaCuad = calcularArea(7);            // Llama a la función de cuadrado

    std::cout << "Área del círculo: " << areaCirc << std::endl;
    std::cout << "Área del rectángulo: " << areaRect << std::endl;
    std::cout << "Área del cuadrado: " << areaCuad << std::endl;
    return 0;
}
