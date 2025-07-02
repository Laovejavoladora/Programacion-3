#include <iostream>
#include <string>

// ===================================================
//   PROYECTO AUTOMÓVIL - by Mateo Perez Nomey 🧠
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
    Motor motorInterno;
    Rueda ruedaDelantera;

public:
    Automovil(std::string ma, std::string mo, int hpDelMotor)
        : marca(ma), modelo(mo), motorInterno(hpDelMotor), ruedaDelantera("Deportiva") {
        std::cout << "CONSTRUCTOR Automovil: Ensamblado un " << marca << " " << modelo << std::endl;
    }

    ~Automovil() {
        std::cout << "DESTRUCTOR Automovil: Desguazando el " << marca << " " << modelo << std::endl;
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
        std::cout << "Diagnóstico del " << modelo << ":" << std::endl;
        motorInterno.mostrarEstado();
    }
};

// Función para mostrar el autor
void mostrarAutor() {
    std::cout << "\n👨‍💻 Autor del proyecto: Mateo Perez Nomey" << std::endl;
    std::cout << "Gracias por revisar este código 🚗🛠️\n";
}

int main() {
    std::cout << "=== PROYECTO AUTOMÓVIL - Realizado por Mateo Perez Nomey ===\n" << std::endl;

    std::cout << "--- Creando un Automovil en el Stack ---" << std::endl;
    Automovil miAuto("SuperMarca", "ModeloX", 200);

    miAuto.verDiagnostico();
    miAuto.encender();
    miAuto.verDiagnostico();
    miAuto.apagar();

    std::cout << "\n--- Saliendo de main (miAuto se destruirá) ---" << std::endl;

    // Interacción final
    char opcion;
    std::cout << "\n¿Deseas conocer al autor del programa? (s/n): ";
    std::cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        mostrarAutor();
    } else {
        std::cout << "Autor oculto. ¡Hasta la próxima! 👋\n";
    }

    return 0;
}
