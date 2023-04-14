#pragma once

#include "prenda.h"

class Pantalon: public Prenda{
    private:
        bool tipo; // true = CHUPIN / false = COMUN
    public:
        Pantalon(std::string calidad, int stock, float precio, bool _tipo);
        float getPrecioUnitario();
        void setTipo(bool b);
        bool getTipo();
        std::string getCaracteristicas();
};
