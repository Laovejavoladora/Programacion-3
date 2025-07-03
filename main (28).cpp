#include <iostream>
#include <vector>
#include <string>

// Código desarrollado por Mateo Perez Nomey

// Clase Direccion
class Direccion {
private:
    std::string calle;
    std::string ciudad;
    std::string codigoPostal;

public:
    Direccion(std::string c, std::string ciu, std::string cp)
        : calle(c), ciudad(ciu), codigoPostal(cp) {}

    void mostrar() const {
        std::cout << "Dirección de envío: " << calle << ", " << ciudad << ", " << codigoPostal << std::endl;
    }
};

// Clase Cliente
class Cliente {
private:
    std::string nombre;
    std::string email;

public:
    Cliente(std::string nom, std::string mail)
        : nombre(nom), email(mail) {}

    void mostrar() const {
        std::cout << "Cliente: " << nombre << " - Email: " << email << std::endl;
    }
};

// Clase LineaDePedido
class LineaDePedido {
private:
    std::string nombreProducto;
    int cantidad;
    double precioUnitario;

public:
    LineaDePedido(std::string producto, int cant, double precio)
        : nombreProducto(producto), cantidad(cant), precioUnitario(precio) {}

    double subtotal() const {
        return cantidad * precioUnitario;
    }

    void mostrar() const {
        std::cout << cantidad << " x " << nombreProducto 
                  << " @ $" << precioUnitario 
                  << " = $" << subtotal() << std::endl;
    }
};

// Clase PedidoOnline
class PedidoOnline {
private:
    std::string idPedido;
    Cliente datosDelCliente;
    std::vector<LineaDePedido> listaDeItems;
    Direccion direccionDeEnvio;
    std::string fecha;

public:
    PedidoOnline(std::string id, const Cliente& cliente,
                 const std::vector<LineaDePedido>& items,
                 const Direccion& direccion, std::string f)
        : idPedido(id), datosDelCliente(cliente), 
          listaDeItems(items), direccionDeEnvio(direccion), fecha(f) {}

    void mostrarResumen() const {
        std::cout << "----- Pedido realizado por Mateo Perez Nomey -----" << std::endl;
        std::cout << "Pedido ID: " << idPedido << " - Fecha: " << fecha << std::endl;
        datosDelCliente.mostrar();
        direccionDeEnvio.mostrar();
        std::cout << "\nItems del pedido:\n";
        double total = 0;
        for (const auto& item : listaDeItems) {
            item.mostrar();
            total += item.subtotal();
        }
        std::cout << "\nTOTAL: $" << total << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
    }
};

// Función principal
int main() {
    // Crear un cliente
    Cliente cliente("Ana Pérez", "ana@example.com");

    // Crear una dirección
    Direccion direccion("Av. Siempre Viva 742", "Springfield", "12345");

    // Crear una lista de productos
    std::vector<LineaDePedido> items = {
        LineaDePedido("Camisa", 2, 25.5),
        LineaDePedido("Pantalón", 1, 45.0),
        LineaDePedido("Zapatos", 1, 60.0)
    };

    // Crear el pedido
    PedidoOnline pedido("PED12345", cliente, items, direccion, "2025-06-20");

    // Mostrar resumen del pedido
    pedido.mostrarResumen();

    return 0;
}
