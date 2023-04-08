#include "prenda.h"

class Camisa: public Prenda{
    private:
        char tipo; //'l' = Manga Larga / 'c' Manga corta
        char cuello; // 'm' = Mao / 'c' = Común
    public:
        Camisa(char tipo, char cuello, char calidad, int stock, float precio): Prenda(calidad, stock, precio){};

};