#include <iostream>
#include <string>

// ===================================================
//    PROYECTO DE EJEMPLO - by Mateo Perez Nomey 🧠
// ===================================================

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
    Motor motorInterno;
public:
    Automovil(std::string ma, std::string mo, int hpDelMotor) 
        : marca(ma), modelo(mo), motorInterno(hpDelMotor) {
        std::cout << "CONSTRUCTOR Automovil: Ensamblado un " << marca << " " << modelo 
                  << " con un motor." << std::endl;
    }
    ~Automovil() {
        std::cout << "DESTRUCTOR Automovil: Desguazando el " << marca << " " << modelo << "." << std::endl;
    }
    void encender() {
        std::cout << modelo << ": Intentando encender..." << std::endl;
        motorInterno.arrancar();
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

// Función interactiva para mostrar el autor del proyecto
void mostrarAutor() {
    std::cout << "\n👨‍💻 Este proyecto fue realizado por: Mateo Perez Nomey\n";
    std::cout << "¡Gracias por revisar este código! 🚗🔧\n";
}

int main() {
    std::cout << "=== Proyecto Automovil - Código creado por Mateo Perez Nomey ===\n" << std::endl;

    std::cout << "--- Creando un Automovil en el Stack ---" << std::endl;
    Automovil miAuto("SuperMarca", "ModeloX", 200);
    miAuto.verDiagnostico();
    miAuto.encender();
    miAuto.verDiagnostico();
    miAuto.apagar();

    std::cout << "\n--- Saliendo de main (miAuto se destruira) ---" << std::endl;

    // Pregunta interactiva
    char respuesta;
    std::cout << "\n¿Deseas ver el autor del proyecto? (s/n): ";
    std::cin >> respuesta;

    if (respuesta == 's' || respuesta == 'S') {
        mostrarAutor();
    } else {
        std::cout << "Autor oculto. ¡Hasta la próxima! 👋\n";
    }

    return 0;
}

