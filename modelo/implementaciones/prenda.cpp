#include "..\headers\prenda.h"

Prenda::Prenda(std::string calidad, int stock, float precio){
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

void Prenda::setCalidad(std::string c){
    this->calidad = c;
}

std::string Prenda::getCalidad(){
    return this->calidad;
}