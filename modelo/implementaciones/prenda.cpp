#include "..\headers\prenda.h"

Prenda::Prenda(char calidad, int stock, float precio){
            this->calidad = calidad;
            this->stock = stock;
            this->precioUnitario = precio;
};

int Prenda::getStock(){
    return this->stock;
}

void Prenda::setStock(int nuevoStock){
    this->stock = nuevoStock;
}