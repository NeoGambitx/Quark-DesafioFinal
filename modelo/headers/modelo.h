//DATOS de
//VENDEDOR
//TIENDA
//PRENDAS

//GUARDAR HISTORIAL

//SIM
//INICIALIZA TIENDA, VENDEDOR, PRENDAS,

//METODOS PARA PASAR DATOS AL PRESENTADOR
//METODOS PARA GUARDAR EL HISTORIAL
//METODOS PARA ACTUALIZAR EL STOCK
#pragma once
#include "camisa.h"
#include "pantalon.h"
#include "prenda.h"
#include "tienda.h"
#include "vendedor.h"
#include <string>
#include <ctime>
#include "historial.h"
/* #include <vector> */

class Modelo{

    private:
        std::vector<historial> hist;
        
    public:
        Tienda tienda;
        Vendedor vendedor;
        Modelo(std::string nombreTienda, std::string direccion, std::string nombreV, std::string apellidoV, int codigo);
        void guardarHistorial(Vendedor v, Camisa* c, int cant, float precioFinal, int id);
        void guardarHistorial(Vendedor v, Pantalon* p, int cant, float precioFinal, int id);
        std::vector<historial> getHistorial();
};