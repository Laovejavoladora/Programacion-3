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
        if (!encendido) {
            encendido = true;
            std::cout << "   Motor: ¡BRUM! Encendido." << std::endl;
        } else {
            std::cout << "   Motor: Ya estaba encendido." << std::endl;
        }
    }

    void detener() {
        if (encendido) {
            encendido = false;
            std::cout << "   Motor: ...silencio. Apagado." << std::endl;
        } else {
            std::cout << "   Motor: Ya estaba apagado." << std::endl;
        }
    }

    void mostrarEstado() const {
        std::cout << "   Estado del Motor: " << (encendido ? "Encendido" : "Apagado")
                  << ", HP: " << caballosDeFuerza << std::endl;
    }
};

// Clase 'Parte': Rueda
class Rueda {
private:
    std::string tipo;

public:
    Rueda(std::string t = "Normal") : tipo(t) {
        std::cout << "  CONSTRUCTOR Rueda: Tipo = " << tipo << std::endl;
    }

    ~Rueda() {
        std::cout << "  DESTRUCTOR Rueda: Tipo = " << tipo << std::endl;
    }
};

// Clase 'Todo' o 'Contenedora': Automovil
class Automovil {
private:
    std::string marca;
    std::string modelo;
    Motor motorInterno;    // ¡COMPOSICIÓN! Motor es miembro.
    Rueda ruedaDelantera;  // Nuevo miembro: una rueda

public:
    // Lista de inicialización usada para construir miembros
    Automovil(std::string ma, std::string mo, int hpDelMotor)
        : marca(ma), modelo(mo), motorInterno(hpDelMotor), ruedaDelantera("Deportiva") {
        std::cout << "CONSTRUCTOR Automovil: Ensamblado un " << marca << " " << modelo << std::endl;
    }

    ~Automovil() {
        std::cout << "DESTRUCTOR Automovil: Desguazando el " << marca << " " << modelo << std::endl;
    }

    void encender() {
        std::cout << modelo << ": Intentando encender..." << std::endl;
        motorInterno.arrancar();  // delegación al motor
    }

    void apagar() {
        std::cout << modelo << ": Intentando apagar..." << std::endl;
        motorInterno.detener();  // delegación al motor
    }

    void verDiagnostico() const {
        std::cout << "Diagnóstico del " << modelo << ":" << std::endl;
        motorInterno.mostrarEstado();
    }
};

int main() {
    std::cout << "--- Creando un Automovil en el Stack ---" << std::endl;
    Automovil miAuto("SuperMarca", "ModeloX", 200);

    miAuto.verDiagnostico();
    miAuto.encender();
    miAuto.verDiagnostico();
    miAuto.apagar();

    std::cout << "\n--- Saliendo de main (miAuto se destruirá) ---" << std::endl;

    // Al salir de main:
    // 1. Se llama al destructor de Automovil
    // 2. Luego al destructor de ruedaDelantera
    // 3. Luego al destructor de motorInterno
    return 0;
}
