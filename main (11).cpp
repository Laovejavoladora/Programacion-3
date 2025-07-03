#include <iostream>
#include <string>

// Clase de autor
class MateoPerezNomey {
public:
    void presentarse() const {
        std::cout << "👨‍💻 Programa realizado por: Mateo Perez Nomey\n"
                  << "📚 Clase: Gestión de Estudiantes\n" << std::endl;
    }

    void despedirse() const {
        std::cout << "\n🧠 Fin del programa. ¡Gracias por utilizar este sistema educativo!" << std::endl;
    }
};

class Estudiante {
private:
    std::string nombre;
    int edad;
    std::string matricula;
    double promedio;

public:
    Estudiante(std::string nom, int ed, std::string matr) {
        nombre = nom;
        setEdad(ed);
        matricula = matr;
        promedio = 0.0;
        std::cout << "Estudiante '" << nombre << "' creado." << std::endl;
    }

    std::string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    std::string getMatricula() const { return matricula; }
    double getPromedio() const { return promedio; }

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
            std::cout << "Error: Edad '" << nuevaEdad << "' inválida para el estudiante " 
                      << nombre << ". Edad no modificada." << std::endl;
        }
    }

    void setPromedio(double nuevoPromedio) {
        if (nuevoPromedio >= 0.0 && nuevoPromedio <= 10.0) {
            promedio = nuevoPromedio;
        } else {
            std::cout << "Error: Promedio '" << nuevoPromedio << "' inválido para " 
                      << nombre << ". Promedio no modificado." << std::endl;
        }
    }

    void mostrarInformacion() const {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Edad: " << edad << " años" << std::endl;
        std::cout << "Matrícula: " << matricula << std::endl;
        std::cout << "Promedio: " << promedio << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
};

int main() {
    MateoPerezNomey autor;
    autor.presentarse();

    Estudiante estudiante1("Juaquin Soliz", 20, "A123");
    estudiante1.mostrarInformacion();

    std::cout << "\nIntentando actualizar edad y promedio..." << std::endl;
    estudiante1.setEdad(21);
    estudiante1.setPromedio(8.5);
    estudiante1.setEdad(150);      
    estudiante1.setPromedio(-2.0); 

    std::cout << "\nInformación actualizada de " << estudiante1.getNombre() << ":" << std::endl;
    estudiante1.mostrarInformacion();

    Estudiante estudiante2("Priscila Vaca", -10, "B456"); 
    estudiante2.mostrarInformacion();

    autor.despedirse();
    return 0;
}
