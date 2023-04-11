#pragma once
#include <string>
#include <vector>
#include "prenda.h"

class Tienda{

    private:
        std::string nombre; 
        std::string direccion;
        std::vector<Prenda *> listaDePrendas;
    public:
        Tienda(std::string nombre, std::string direccion);
        std::string getNombre();
        std::string getDireccion();
        Prenda* getPrenda(int index);
        void addPrendas(Prenda* p);
};