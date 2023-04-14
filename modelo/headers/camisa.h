#pragma once
#include "prenda.h"

class Camisa: public Prenda{
    private:
        char tipo; //'l' = Manga Larga / 'c' Manga corta
        char cuello; // 'm' = Mao / 'c' = Común
    public:
        Camisa(char calidad, int stock, float precio, char tipo, char cuello);
        float getPrecioUnitario(); //Cada subClase tiene su propia implementación (Camisa, Pantalon)
        void setTipo(char c);
        void setCuello(char c);
        char getTipo();
        char getCuello();
};