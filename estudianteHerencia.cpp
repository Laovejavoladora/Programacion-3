#include <iostream>
#include <string>
using namespace std;

class Estudiante {
protected:
    string nombre;
    string carrera;

public:
    Estudiante(string n, string c) : nombre(n), carrera(c) {
        cout << "Estudiante creado: " << nombre << " - " << carrera << endl;
    }

    ~Estudiante() {
        cout << "Estudiante destruido: " << nombre << endl;
    }

    void estudiar() const {
        cout << nombre << " está estudiando..." << endl;
    }
};

class EstudianteGraduado : public Estudiante {
private:
    string grado;

public:
    EstudianteGraduado(string n, string c, string g) : Estudiante(n, c), grado(g) {
        cout << "Estudiante graduado con grado: " << grado << endl;
    }

    ~EstudianteGraduado() {
        cout << "Graduado destruido: " << nombre << endl;
    }

    void investigar() const {
        cout << nombre << " está investigando como parte de su " << grado << "." << endl;
    }
};

int main() {
    EstudianteGraduado eg("Laura", "Ingeniería", "Maestría");
    eg.estudiar();
    eg.investigar();
    return 0;
}
