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

void Prenda::setPrecioUnitario(float precioBase){
    this->precioUnitario = precioBase;
}

void Prenda::setCalidad(char c){
    this->calidad = c;
}

char Prenda::getCalidad(){
    return this->calidad;
}