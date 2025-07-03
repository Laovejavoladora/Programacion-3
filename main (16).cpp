#include <iostream>
#include <string>
#include <vector>

// Declaraciones de las funciones 'mostrar' (prototipos)
void mostrar(int valor);
void mostrar(double valor);
void mostrar(const std::string& valor);
void mostrar(char valor);
void mostrar(const std::vector<int>& miVector);

int main() {
    std::cout << "--- Demostracion de 'mostrar' sobrecargado por Mateo Perez Nomey ---" << std::endl;
    mostrar(100);
    mostrar(3.14159);
    mostrar(std::string("Hola desde Programacion III!"));
    mostrar('Z');

    std::vector<int> numeros = {10, 20, 30, 40, 50};
    mostrar(numeros);

    mostrar("Esto es un literal de C-string.");

    std::cout << "Fin del programa de sobrecarga, gracias por usarlo, Mateo Perez Nomey." << std::endl;

    return 0;
}

// Implementaciones de las funciones 'mostrar'
void mostrar(int valor) {
    std::cout << "Tipo Entero (int): " << valor << std::endl;
}

void mostrar(double valor) {
    std::cout << "Tipo Decimal (double): " << valor << std::endl;
}

void mostrar(const std::string& valor) {
    std::cout << "Tipo Cadena (std::string): \"" << valor << "\"" << std::endl;
}

void mostrar(char valor) {
    std::cout << "Tipo Caracter (char): '" << valor << "'" << std::endl;
}

void mostrar(const std::vector<int>& miVector) {
    std::cout << "Tipo Vector de Enteros (std::vector<int>): [ ";
    for (size_t i = 0; i < miVector.size(); ++i) {
        std::cout << miVector[i] << (i == miVector.size() - 1 ? "" : ", ");
    }
    std::cout << " ]" << std::endl;
}
