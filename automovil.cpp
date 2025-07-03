#include <iostream>
#include <string>
// Clase 'Parte': Motor
class Motor {
private:
    int caballosDeFuerza;
    bool encendido;
public:
    Motor(int hp = 150) : caballosDeFuerza(hp), encendido(false) {
        std::cout << "  CONSTRUCTOR Motor: Creado motor de " << caballosDeFuerza << " HP." << std::endl;
    }
    ~Motor() {
        std::cout << "  DESTRUCTOR Motor: Destruido motor de " << caballosDeFuerza << " HP." << std::endl;
    }
    void arrancar() {
        if (!encendido) { encendido = true; std::cout << "  Motor: ¡BRUM! Encendido." << std::endl;}
        else { std::cout << "  Motor: Ya estaba encendido." << std::endl; }
    }
    void detener() {
        if (encendido) { encendido = false; std::cout << "  Motor: ...silencio. Apagado." << std::endl;}
        else { std::cout << "  Motor: Ya estaba apagado." << std::endl; }
    }
    void mostrarEstado() const {
         std::cout << "  Estado del Motor: " << (encendido ? "Encendido" : "Apagado") 
                   << ", HP: " << caballosDeFuerza << std::endl;
    }
};
// Clase 'Todo' o 'Contenedora': Automovil
class Automovil {
private:
    std::string marca;
    std::string modelo;
    Motor motorInterno; // ¡COMPOSICIÓN! Un objeto Motor es MIEMBRO de Automovil.
public:
    // Constructor de Automovil: INICIALIZA motorInterno usando la lista de inicializadores
    Automovil(std::string ma, std::string mo, int hpDelMotor) 
        : marca(ma), modelo(mo), motorInterno(hpDelMotor) {
        std::cout << "CONSTRUCTOR Automovil: Ensamblado un " << marca << " " << modelo 
                  << " con un motor." << std::endl;
    }
    ~Automovil() {
        std::cout << "DESTRUCTOR Automovil: Desguazando el " << marca << " " << modelo << "." << std::endl;
        // El destructor de motorInterno se llamará AUTOMÁTICAMENTE aquí.
    }
    void encender() {
        std::cout << modelo << ": Intentando encender..." << std::endl;
        motorInterno.arrancar(); // Delega la acción al objeto Motor
    }
    void apagar() {
        std::cout << modelo << ": Intentando apagar..." << std::endl;
        motorInterno.detener();
    }
    void verDiagnostico() const {
        std::cout << "Diagnostico del " << modelo << ":" << std::endl;
        motorInterno.mostrarEstado();
    }
};
int main() {
    std::cout << "--- Creando un Automovil en el Stack ---" << std::endl;
    Automovil miAuto("SuperMarca", "ModeloX", 200); // Llama al constructor de Automovil
                                                   // que llama al constructor de Motor
    miAuto.verDiagnostico();
    miAuto.encender();
    miAuto.verDiagnostico();
    miAuto.apagar();
    std::cout << "\n--- Saliendo de main (miAuto se destruira) ---" << std::endl;
    // Al salir de main, se llama al destructor de miAuto,
    // el cual IMPLÍCITAMENTE llama al destructor de motorInterno.
    return 0;
}
