#include "../headers/camisa.h"

Camisa::Camisa(std::string calidad, int stock, float precio, std::string _tipo, std::string _cuello): Prenda(calidad, stock, precio){
    this->tipo = _tipo;
    this->cuello = _cuello;
};

float Camisa::getPrecioUnitario(){
    float precioFinal = this->precioUnitario;
    if(this->tipo == "Corta"){
        precioFinal*=0.90; //-10%
    }
    if(this->cuello == "Mao"){
        precioFinal*=1.03; //+3%
    }
    if(this->calidad == "Premium"){
        precioFinal*=1.30;
    }
    return precioFinal;
}

void Camisa::setTipo(std::string c){
    this->tipo = c;
}

void Camisa::setCuello(std::string c){
    this->cuello = c;
}

std::string Camisa::getTipo(){
    return this->tipo;
}

std::string Camisa::getCuello(){
    return this->cuello;
}

std::string Camisa::getCaracteristicas(){
    return ("Camisa " + this->getTipo() + " cuello "+ this->getCuello() + " " + this->getCalidad());
}
