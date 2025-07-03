#include <iostream>
using namespace std;

// Clase base
class ClaseBase {
public:
    int atributoBasePublico;

    void metodoBasePublico() {
        cout << "   métodoBasePublico() ejecutado." << endl;
    }

protected:
    int atributoBaseProtegido;

private:
    int atributoBasePrivado; // No accesible desde la derivada
};

// Clase derivada que HEREDA PÚBLICAMENTE de ClaseBase
class ClaseDerivada : public ClaseBase {
public:
    int atributoDerivadoPublico;

    void metodoDerivadoPublico() {
        cout << "Mateo Perez Nomey: Accediendo a miembros de la clase base desde la derivada:" << endl;

        atributoBasePublico = 10;
        cout << " - atributoBasePublico = " << atributoBasePublico << endl;

        metodoBasePublico();  // Válido

        atributoBaseProtegido = 20;
        cout << " - atributoBaseProtegido = " << atributoBaseProtegido << endl;

        // atributoBasePrivado = 30; // ❌ ERROR DE COMPILACIÓN si se descomenta
    }
};

int main() {
    cout << "--- Ejemplo de Herencia Pública en C++ ---" << endl;

    ClaseDerivada obj;

    // Acceso desde fuera de la clase:
    obj.atributoBasePublico = 1;  // ✅ Válido: heredado como público
    obj.metodoBasePublico();      // ✅ Válido
    obj.atributoDerivadoPublico = 2; // ✅ Válido

    // obj.atributoBaseProtegido = 3; // ❌ ERROR: protegido, no accesible desde fuera
    // obj.atributoBasePrivado = 4;   // ❌ ERROR: privado en ClaseBase

    obj.metodoDerivadoPublico();  // Ejecuta método que accede a miembros válidos

    return 0;
}

