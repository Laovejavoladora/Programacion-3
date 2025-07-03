#include <iostream>
#include <string>

class RecursoSimple {
private:
    std::string nombreRecurso;
    int* datosDinamicos; // Un puntero para demostrar la gestión de memoria dinámica

public:
    // Constructor
    RecursoSimple(const std::string& nombre) : nombreRecurso(nombre) {
        std::cout << "CONSTRUCTOR: Creando RecursoSimple '" << nombreRecurso << "'." << std::endl;
        // Simulamos que este recurso necesita un pequeño bloque de memoria dinámica
        datosDinamicos = new int[5]; // Pide memoria para 5 enteros
        std::cout << "   RecursoSimple '" << nombreRecurso << "' asigno memoria dinamica en " 
                  << datosDinamicos << std::endl;
        for (int i=0; i<5; ++i) datosDinamicos[i] = i*10; // Inicializa
    }

    // Destructor
    ~RecursoSimple() {
        std::cout << "DESTRUCTOR: Destruyendo RecursoSimple '" << nombreRecurso << "'." << std::endl;
        // ¡MUY IMPORTANTE! Liberar la memoria dinámica asignada en el constructor
        delete[] datosDinamicos; 
        datosDinamicos = nullptr; // Buena práctica
        std::cout << "   RecursoSimple '" << nombreRecurso << "' libero su memoria dinamica." << std::endl;
    }

    void usarRecurso() const {
        std::cout << "Usando RecursoSimple '" << nombreRecurso << "'. Datos[0]: " 
                  << (datosDinamicos ? datosDinamicos[0] : -1) << std::endl;
    }
}; // Fin de la clase RecursoSimple

void funcionDePrueba() {
    std::cout << "\n-- Entrando a funcionDePrueba --" << std::endl;
    RecursoSimple recursoLocal("LocalEnFuncion"); // Objeto en el Stack
    recursoLocal.usarRecurso();
    std::cout << "-- Saliendo de funcionDePrueba (recursoLocal se destruira) --" << std::endl;
    // El destructor de 'recursoLocal' se llama aquí automáticamente
}

int main() {
    std::cout << "-- Inicio de main --" << std::endl;

    RecursoSimple* recursoEnHeap = nullptr;
    // Creando objeto en el Heap
    recursoEnHeap = new RecursoSimple("DinamicoEnHeap"); 
    if (recursoEnHeap) {
        recursoEnHeap->usarRecurso();
    }

    funcionDePrueba(); // Llamamos a la función que crea un objeto local

    // Liberando objeto del Heap
    std::cout << "\n-- Antes de delete recursoEnHeap --" << std::endl;
    delete recursoEnHeap; // ¡Se llama al destructor de recursoEnHeap!
    recursoEnHeap = nullptr;

    std::cout << "\n-- Fin de main --" << std::endl;
    return 0;
}