#pragma once
#include <string>
#include <vector>
#include "prenda.h"

class Tienda{

    private:
        std::string nombre; 
        std::string direccion;
        std::vector<Camisa *> listaCamisas;
        std::vector<Pantalon *> listaPantalones;
    public:
        Tienda(std::string nombre, std::string direccion);
        std::string getNombre();
        std::string getDireccion();
        Pantalon* getPantalon(Pantalon* prendaABuscar);
        Camisa* getCamisa(Camisa* prendaABuscar);
        void addPrendas(Pantalon* p);
        bool compararPrendas(Prenda* p1, Prenda* p2);
};