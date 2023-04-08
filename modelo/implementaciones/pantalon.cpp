#include "../headers/pantalon.h"

Pantalon::Pantalon(bool _tipo, char calidad, int stock, float precio): Prenda(calidad, stock, precio){
                this->tipo = _tipo;
};