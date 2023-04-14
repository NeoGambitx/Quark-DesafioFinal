#pragma once
#include "prenda.h"
#include <string>

class Camisa: public Prenda{
    private:
        std::string tipo; //Larga / corta
        std::string cuello; // Mao / Común
    public:
        Camisa(std::string calidad, int stock, float precio, std::string tipo, std::string cuello);
        float getPrecioUnitario(); //Cada subClase tiene su propia implementación (Camisa, Pantalon)
        void setTipo(std::string c);
        void setCuello(std::string c);
        std::string getTipo();
        std::string getCuello();
        std::string getCaracteristicas();
};