#include <iostream>
#include <string>

class Motor {
public:
    int cilindros;

    // Constructor que recibe el número de cilindros
    Motor(int c) : cilindros(c) {
        std::cout << "Motor(int) creado con " << cilindros << " cilindros" << std::endl;
    }

    // Constructor por defecto
    Motor() : cilindros(4) {
        std::cout << "Motor() por defecto creado con 4 cilindros" << std::endl;
    }
};

class Auto {
public:
    std::string marca;
    Motor miMotor; // Objeto miembro (composición)

    // Constructor usando lista de inicializadores (forma recomendada)
    Auto(std::string m, int cil) 
        : marca(m), miMotor(cil) {
        std::cout << "Auto '" << marca << "' creado con motor de " << miMotor.cilindros << " cilindros" << std::endl;
    }

    /* 
    // Forma alternativa (menos eficiente)
    Auto(std::string m, int cil) {
        marca = m;
        // Aquí primero se crea miMotor usando el constructor por defecto (Motor())
        // Luego se reasigna con un nuevo Motor(cil), lo cual es menos eficiente:
        // - Se hacen dos operaciones: construcción y luego reasignación.
        // - Puede ser problemático si Motor no tiene constructor por defecto.
        // - No se puede usar así si el miembro es const o una referencia.
        miMotor = Motor(cil);
        std::cout << "Auto '" << marca << "' creado (forma menos eficiente)" << std::endl;
    }
    */
};

int main() {
    // Crear un Auto utilizando la forma recomendada (con lista de inicializadores)
    Auto miAuto("Toyota", 6);

    return 0;
}
