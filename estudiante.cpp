#include <iostream>
#include <string>
class Estudiante {
private: // DATOS PROTEGIDOS
    std::string nombre;
    int edad;
    std::string matricula;
    double promedio;
public:
    // Constructor
    Estudiante(std::string nom, int ed, std::string matr) {
        nombre = nom;
        // Usamos el setter para edad para aprovechar la validación
        setEdad(ed); // ¡Llamando a nuestro propio setter!
        matricula = matr;
        promedio = 0.0; // Promedio inicial
        std::cout << "Estudiante '" << nombre << "' creado." << std::endl;
    }
    // Getters
    std::string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    std::string getMatricula() const { return matricula; }
    double getPromedio() const { return promedio; }
    // Setters (con validación donde aplique)
    void setNombre(const std::string& nuevoNombre) {
        if (!nuevoNombre.empty()) {
            nombre = nuevoNombre;
        } else {
            std::cout << "Error: El nombre no puede estar vacio." << std::endl;
        }
    }
    void setEdad(int nuevaEdad) {
        if (nuevaEdad >= 5 && nuevaEdad <= 100) { // Ejemplo de validación
            edad = nuevaEdad;
        } else {
            std::cout << "Error: Edad '" << nuevaEdad << "' invalida para el estudiante " 
                      << nombre << ". Edad no modificada." << std::endl;
        }
    }
    // No ponemos un setter para matricula, asumiendo que no cambia.
    // Pero podríamos tener uno si fuera necesario.
    void setPromedio(double nuevoPromedio) {
        if (nuevoPromedio >= 0.0 && nuevoPromedio <= 10.0) { // Asumiendo escala 0-10
            promedio = nuevoPromedio;
        } else {
            std::cout << "Error: Promedio '" << nuevoPromedio << "' invalido para " 
                      << nombre << ". Promedio no modificado." << std::endl;
        }
    }
    // Otros métodos públicos
    void mostrarInformacion() const {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Edad: " << edad << " anios" << std::endl;
        std::cout << "Matricula: " << matricula << std::endl;
        std::cout << "Promedio: " << promedio << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}; // Fin de la clase Estudiante
int main() {
    Estudiante estudiante1("Juaquin Soliz", 20, "A123");
    estudiante1.mostrarInformacion();
    // Intentando modificar datos
    // estudiante1.edad = 21; // ¡ERROR! 'edad' es private.
    std::cout << "\nIntentando actualizar edad y promedio..." << std::endl;
    estudiante1.setEdad(21);       // Uso correcto del setter
    estudiante1.setPromedio(8.5);
    estudiante1.setEdad(150);      // Intentando edad inválida
    estudiante1.setPromedio(-2.0); // Intentando promedio inválido
    std::cout << "\nInformacion actualizada de " << estudiante1.getNombre() << ":" << std::endl;
    estudiante1.mostrarInformacion();
    Estudiante estudiante2("Priscila Vaca", -10, "B456"); // Prueba de validación en constructor
    estudiante2.mostrarInformacion(); // Veremos qué edad tiene Priscila
    return 0;
}



