/*
  Autor: Mateo Pérez Nomey
  Proyecto: Ejemplo de gestión de recursos dinámicos en C++
*/

#include <iostream>
#include <string>

class RecursoSimple {
private:
    std::string nombreRecurso;
    int* datosDinamicos; // Puntero para demostrar gestión de memoria dinámica

public:
    // Constructor
    RecursoSimple(const std::string& nombre) : nombreRecurso(nombre) {
        std::cout << "CONSTRUCTOR: Creando RecursoSimple '" << nombreRecurso << "'." << std::endl;
        datosDinamicos = new int[5]; // Reserva memoria para 5 enteros
        std::cout << "   RecursoSimple '" << nombreRecurso << "' asignó memoria dinámica en " 
                  << datosDinamicos << std::endl;
        for (int i = 0; i < 5; ++i) datosDinamicos[i] = i * 10; // Inicializa
    }

    // Destructor
    ~RecursoSimple() {
        std::cout << "DESTRUCTOR: Destruyendo RecursoSimple '" << nombreRecurso << "'." << std::endl;
        delete[] datosDinamicos; 
        datosDinamicos = nullptr; // Buena práctica
        std::cout << "   RecursoSimple '" << nombreRecurso << "' liberó su memoria dinámica." << std::endl;
    }

    void usarRecurso() const {
        std::cout << "Usando RecursoSimple '" << nombreRecurso << "'. Datos[0]: " 
                  << (datosDinamicos ? datosDinamicos[0] : -1) << std::endl;
    }
};

// Función que crea un objeto local en el stack
void funcionDePrueba() {
    std::cout << "\n-- Entrando a funcionDePrueba --" << std::endl;
    RecursoSimple recursoLocal("LocalEnFuncion");
    recursoLocal.usarRecurso();
    std::cout << "-- Saliendo de funcionDePrueba (recursoLocal se destruirá) --" << std::endl;
}

int main() {
    std::cout << "-- Inicio de main --" << std::endl;

    RecursoSimple* recursoEnHeap = nullptr;
    recursoEnHeap = new RecursoSimple("DinamicoEnHeap");
    if (recursoEnHeap) {
        recursoEnHeap->usarRecurso();
    }

    funcionDePrueba(); // Crea un objeto local temporal

    std::cout << "\n-- Antes de delete recursoEnHeap --" << std::endl;
    delete recursoEnHeap; // Libera memoria del heap
    recursoEnHeap = nullptr;

    std::cout << "\n-- Fin de main --" << std::endl;
    return 0;
}

