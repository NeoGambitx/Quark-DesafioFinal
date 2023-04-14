#pragma once
#include "camisa.h"
#include "pantalon.h"
#include "prenda.h"
#include "tienda.h"
#include "vendedor.h"
#include <string>
#include "historial.h"
#include <vector>

class Modelo{

    private:
        std::vector<historial> hist;
        
    public:
        Tienda tienda;
        Vendedor vendedor;
        Modelo(std::string nombreTienda, std::string direccion, std::string nombreV, std::string apellidoV, int codigo);
        void guardarHistorial(Vendedor v, Camisa* c, int cant, float precioFinal, int id, std::string fechayHora);
        void guardarHistorial(Vendedor v, Pantalon* p, int cant, float precioFinal, int id, std::string fechayHora);
        std::vector<historial> getHistorial();
};