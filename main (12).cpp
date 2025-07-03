#include <iostream>
#include <string>
#include <stdexcept>

// Clase de presentación del autor
class MateoPerezNomey {
public:
    void presentarse() const {
        std::cout << "👨‍💻 Programa desarrollado por: Mateo Perez Nomey\n"
                  << "📘 Tema: Encapsulamiento con validaciones y atributos adicionales\n" << std::endl;
    }

    void despedirse() const {
        std::cout << "\n✅ Fin del programa. Gracias por revisar el sistema de estudiantes." << std::endl;
    }
};

// Clase Estudiante con encapsulamiento y validaciones
class Estudiante {
private:
    std::string nombre;
    int edad;
    std::string matricula;
    double promedio;
    std::string carrera;
    std::string correo;

public:
    Estudiante(std::string nom, int ed, std::string matr, std::string carr = "", std::string mail = "") {
        setNombre(nom);
        setEdad(ed);
        matricula = matr;
        promedio = 0.0;
        setCarrera(carr);
        setCorreo(mail);
        std::cout << "Estudiante '" << nombre << "' creado." << std::endl;
    }

    // Getters
    std::string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    std::string getMatricula() const { return matricula; }
    double getPromedio() const { return promedio; }
    std::string getCarrera() const { return carrera; }
    std::string getCorreo() const { return correo; }

    // Setters
    void setNombre(const std::string& nuevoNombre) {
        if (!nuevoNombre.empty()) {
            nombre = nuevoNombre;
        } else {
            std::cout << "Error: El nombre no puede estar vacío." << std::endl;
        }
    }

    void setEdad(int nuevaEdad) {
        if (nuevaEdad >= 5 && nuevaEdad <= 100) {
            edad = nuevaEdad;
        } else {
            std::cout << "Error: Edad '" << nuevaEdad << "' inválida para el estudiante " << nombre << "." << std::endl;
        }
    }

    void setPromedio(double nuevoPromedio) {
        if (nuevoPromedio >= 0.0 && nuevoPromedio <= 10.0) {
            promedio = nuevoPromedio;
        } else {
            std::cout << "Error: Promedio '" << nuevoPromedio << "' inválido para " << nombre << "." << std::endl;
        }
    }

    void setCarrera(const std::string& nuevaCarrera) {
        carrera = nuevaCarrera.empty() ? "No especificada" : nuevaCarrera;
    }

    void setCorreo(const std::string& nuevoCorreo) {
        if (nuevoCorreo.find('@') != std::string::npos) {
            correo = nuevoCorreo;
        } else {
            std::cout << "Error: Correo electrónico inválido." << std::endl;
        }
    }

    void mostrarInformacion() const {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Edad: " << edad << " años" << std::endl;
        std::cout << "Matrícula: " << matricula << std::endl;
        std::cout << "Promedio: " << promedio << std::endl;
        std::cout << "Carrera: " << carrera << std::endl;
        std::cout << "Correo: " << correo << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
};

int main() {
    MateoPerezNomey autor;
    autor.presentarse();

    Estudiante estudiante1("Juaquin Soliz", 20, "A123", "Ingeniería", "juaquin@upds.edu");
    estudiante1.mostrarInformacion();

    std::cout << "\nIntentando actualizar edad, promedio y correo..." << std::endl;
    estudiante1.setEdad(21);
    estudiante1.setPromedio(8.5);
    estudiante1.setCorreo("correo-invalido"); // Inválido
    estudiante1.setEdad(150);                 // Inválido
    estudiante1.setPromedio(-2.0);            // Inválido

    std::cout << "\nInformación actualizada de " << estudiante1.getNombre() << ":" << std::endl;
    estudiante1.mostrarInformacion();

    Estudiante estudiante2("Priscila Vaca", -10, "B456", "", "pvaca.com");
    estudiante2.mostrarInformacion();

    autor.despedirse();
    return 0;
}

