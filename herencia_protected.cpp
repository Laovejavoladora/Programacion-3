#include <iostream>
#include <string>
using namespace std;

// 1. Uso de 'protected' con herencia
class Persona {
protected:
    string nombre;
    int edad;
public:
    Persona(string nom, int ed) : nombre(nom), edad(ed) {}
    void mostrar() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }
};

class Empleado : public Persona {
private:
    string cargo;
public:
    Empleado(string nom, int ed, string c) : Persona(nom, ed), cargo(c) {}
    void mostrarEmpleado() {
        cout << "Empleado: " << nombre << ", Edad: " << edad << ", Cargo: " << cargo << endl;
    }
};

// 2. Clase y función 'friend'
class Caja {
private:
    double largo;
    double ancho;
    friend class Inspector; // Clase amiga
    friend void mostrarArea(const Caja&); // Función amiga
public:
    Caja(double l, double a) : largo(l), ancho(a) {}
};

class Inspector {
public:
    void verificar(const Caja& c) {
        cout << "Caja verificada: " << c.largo << " x " << c.ancho << endl;
    }
};

void mostrarArea(const Caja& c) {
    cout << "Área de la caja: " << c.largo * c.ancho << endl;
}

// 3. Principio de menor privilegio e invariantes
class CuentaBancaria {
private:
    double saldo;
public:
    CuentaBancaria(double inicial) {
        if (inicial >= 0) saldo = inicial;
        else saldo = 0; // Invariante: saldo no puede ser negativo
    }
    void depositar(double cantidad) {
        if (cantidad > 0) saldo += cantidad;
    }
    bool retirar(double cantidad) {
        if (cantidad > 0 && cantidad <= saldo) {
            saldo -= cantidad;
            return true;
        }
        return false;
    }
    double consultar() const { return saldo; }
};

int main() {
    cout << "--- Herencia y protected ---" << endl;
    Empleado emp("Luis", 30, "Ingeniero");
    emp.mostrarEmpleado();

    cout << "\n--- Friend ---" << endl;
    Caja caja(2.5, 4.0);
    Inspector insp;
    insp.verificar(caja);
    mostrarArea(caja);

    cout << "\n--- Invariante de Clase ---" << endl;
    CuentaBancaria cuenta(-100); // Forzamos validación
    cuenta.depositar(500);
    cuenta.retirar(150);
    cout << "Saldo actual: " << cuenta.consultar() << endl;
    return 0;
}
