#include <iostream>
#include <string>
using namespace std;

// ===========================================
//   PROYECTO BOTÓN - by Mateo Perez Nomey 🖱️
// ===========================================

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

// Función para mostrar el autor del programa
void mostrarAutor() {
    cout << "\n👨‍💻 Autor del proyecto: Mateo Perez Nomey\n";
    cout << "Gracias por probar este botón interactivo 🖱️✅\n";
}

int main() {
    cout << "=== PROYECTO BOTÓN - Código creado por Mateo Perez Nomey ===\n" << endl;

    BotonOk b;
    b.mostrar();
    b.presionar();

    // Opción interactiva
    char respuesta;
    cout << "\n¿Deseas conocer al autor del proyecto? (s/n): ";
    cin >> respuesta;

    if (respuesta == 's' || respuesta == 'S') {
        mostrarAutor();
    } else {
        cout << "Autor oculto. ¡Hasta la próxima! 👋\n";
    }

    return 0;
}

