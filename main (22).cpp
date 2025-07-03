#include <iostream> // Para std::cout, std::endl
#include <string>   // Para std::string

// Versión 1: Suma dos enteros
int sumar(int a, int b) {
    std::cout << "Mateo Perez Nomey ejecuta sumar(int, int)... ";
    return a + b;
}

// Versión 2: Suma dos números de punto flotante (double)
double sumar(double a, double b) {
    std::cout << "Mateo Perez Nomey ejecuta sumar(double, double)... ";
    return a + b;
}

// Versión 3: Concatena dos cadenas (std::string)
std::string sumar(const std::string& a, const std::string& b) {
    std::cout << "Mateo Perez Nomey ejecuta sumar(const std::string&, const std::string&)... ";
    return a + b;
}

// Versión 4: Suma tres enteros
int sumar(int a, int b, int c) {
    std::cout << "Mateo Perez Nomey ejecuta sumar(int, int, int)... ";
    return a + b + c;
}

int main() {
    std::cout << "Suma de enteros (5, 3): " << sumar(5, 3) << std::endl;
    std::cout << "Suma de doubles (5.5, 3.3): " << sumar(5.5, 3.3) << std::endl;
    std::cout << "Concatenacion de strings (\"Hola, \", \"Mundo!\"): " 
              << sumar(std::string("Hola, "), std::string("Mundo!")) << std::endl;
    std::cout << "Suma de tres enteros (1, 2, 3): " << sumar(1, 2, 3) << std::endl;

    return 0;
}

