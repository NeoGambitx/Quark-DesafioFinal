#pragma once
#include <string>
#include <vector>
#include "prenda.h"
#include "pantalon.h"
#include "camisa.h"

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
        void addPantalon(Pantalon* p);
        void addCamisas(Camisa* c);
        bool compararCamisas(Camisa* c1, Camisa* c2);
        bool compararPantalones(Pantalon* p1, Pantalon* p2);
};