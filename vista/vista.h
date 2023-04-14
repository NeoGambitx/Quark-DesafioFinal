#include <string>

//Prueba ▼ ▼ ▼ 
#include "../modelo/headers/tienda.h"
#include "../modelo/headers/vendedor.h"
#include "../modelo/headers/historial.h"
#include <vector>
#include <stdlib.h>
#include <Windows.h>


class Vista{

    public:
        void printMenuPrincipal(std::string nombreT, std::string dir, std::string nombreV, std::string apellidoV, int cod);
        void printMenuPrincipal(Tienda* t, Vendedor* v);
        void print3msg();
        void printTienda(std::string nombre, std::string direccion);
        void printVendedor(std::string nombre, std::string apellido, int codigo);
        int getInput();
        void getAnyInput();
        int getCantidad();
        float getInputPrecio();
        bool validar(int x);
        void printError();
        void mostrarHistorial(std::vector<historial> his);
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
        void cotizadorResultado(Camisa* c, Vendedor v, int id, int cant, float precioFinal, std::string fecha);/*  */
        void cotizadorResultado(Pantalon* p, Vendedor v, int id, int cant, float precioFinal, std::string fecha);/*  */
        void cotizadorError();
}; 