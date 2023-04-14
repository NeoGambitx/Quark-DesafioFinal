#include <string>

//Prueba ▼ ▼ ▼ 
#include "../modelo/headers/tienda.h"
#include "../modelo/headers/vendedor.h"


class Vista{

    public:
        void printMenuPrincipal(std::string nombreT, std::string dir, std::string nombreV, std::string apellidoV, int cod);
        void printMenuPrincipal(Tienda* t, Vendedor* v);
        void print3msg();
        void printTienda(std::string nombre, std::string direccion);
        void printVendedor(std::string nombre, std::string apellido, int codigo);
        int getInput();
        int getCantidad();
        float getInputPrecio();
        bool validar(int x);
        void printError();
        void mostrarHistorial();
        void encabezadoCotizacion();
        void siNo();
        void linea();
        void limpiarPantalla();
        void cotizadorPaso1();
        void cotizadorPaso2Camisa();
        void cotizadorPaso2bCamisa();
        void cotizadorPaso2Pantalon();
        void cotizadorPaso3Calidad();
        void cotizadorPaso4Precio();
        void cotizadorPaso5Cantidad(int stock);
        void cotizadorResultado();
        void cotizadorError();
}; 