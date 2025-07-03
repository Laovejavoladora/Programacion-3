#include <iostream>
#include <string>
// Definición de la CLASE 'Perro'
class Perro {
public: // Especificador de acceso (lo veremos más adelante)
    // Atributos (Variables Miembro)
    std::string nombre;
    std::string raza;
    int edad;
    // Métodos (Funciones Miembro)
    void ladrar() {
        std::cout << nombre << " dice: ¡Guau! ¡Guau!" << std::endl;
    }
    void presentar() {
        std::cout << "Hola, soy " << nombre << ", un " << raza 
                  << " de " << edad << " anios." << std::endl;
    }
}; // ¡OJO con el punto y coma al final de la clase!
int main() {
    // Creación de OBJETOS (Instancias de la clase Perro)
    Perro perro1; // Objeto llamado perro1 de tipo Perro
    Perro perro2; // Objeto llamado perro2 de tipo Perro
    perro1.nombre = "Firulais"; // Asignando valores a los atributos de perro1
    perro1.raza = "Mestizo Jugueton";
    perro1.edad = 3;
    perro2.nombre = "Rex"; // Asignando valores a los atributos de perro2
    perro2.raza = "Pastor Aleman";
    perro2.edad = 5;
    std::cout << "--- Conozcamos a nuestras mascotas ---" << std::endl;
    perro1.presentar(); // Llamando a los métodos de los objetos
    perro1.ladrar();
    std::cout << std::endl;
    perro2.presentar();
    perro2.ladrar();
    return 0;
}
