#include <iostream>
#include <string>
using namespace std;

class Boton {
protected:
    string etiqueta;

public:
    Boton(string e) : etiqueta(e) {
        cout << "Botón creado: [" << etiqueta << "]" << endl;
    }

    ~Boton() {
        cout << "Botón destruido: [" << etiqueta << "]" << endl;
    }

    void mostrar() const {
        cout << "Mostrando botón: [" << etiqueta << "]" << endl;
    }
};

class BotonOk : public Boton {
public:
    BotonOk() : Boton("OK") {
        cout << "Botón OK personalizado listo." << endl;
    }

    ~BotonOk() {
        cout << "Botón OK destruido." << endl;
    }

    void presionar() const {
        cout << "¡Botón OK presionado!" << endl;
    }
};

int main() {
    BotonOk b;
    b.mostrar();
    b.presionar();
    return 0;
}
