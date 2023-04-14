#include "../headers/camisa.h"

Camisa::Camisa(char calidad, int stock, float precio, char _tipo, char _cuello): Prenda(calidad, stock, precio){
    this->tipo = _tipo;
    this->cuello = _cuello;
};

float Camisa::getPrecioUnitario(){
    float precioFinal = this->precioUnitario;
    if(this->tipo == 'c'){
        precioFinal*=0.90; //-10%
    }
    if(this->cuello == 'm'){
        precioFinal*=1.03; //+3%
    }
    if(this->calidad == 'p'){
        precioFinal*=1.30;
    }
    return precioFinal;
}

void Camisa::setTipo(char c){
    this->tipo = c;
}

void Camisa::setCuello(char c){
    this->cuello = c;
}

char Camisa::getTipo(){
    return this->tipo;
}

char Camisa::getCuello(){
    return this->cuello;
}