#pragma once

#include "prenda.h"

class Pantalon: public Prenda{
    private:
        bool tipo; // true = CHUPIN / false = COMUN
    public:
        Pantalon(char calidad, int stock, float precio, bool _tipo);
        float getPrecioUnitario();
        void setTipo(bool b);
        bool getTipo();
};
