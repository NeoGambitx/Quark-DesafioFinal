#include "../headers/pantalon.h"

Pantalon::Pantalon(std::string calidad, int stock, float precio, bool _tipo): Prenda(calidad, stock, precio){
                this->tipo = _tipo;
        };

float Pantalon::getPrecioUnitario(){
            float precioFinal = this->precioUnitario;
            if(this->tipo == true){ 
                precioFinal*=0.88; //-12% Chupin
            }
            if(this->calidad == "Premium"){
                precioFinal*=1.30;
            }
            return precioFinal;
};

void Pantalon::setTipo(bool b){
    this->tipo = b;
}

bool Pantalon::getTipo(){
    return this->tipo;
}

std::string Pantalon::getCaracteristicas(){
    std::string s;
    if(this->getTipo()){
         s = "Chupin";
    }
    else{
        s = "Normal";
    }
    return ("Pantalon " + s + " " + this->getCalidad());
}
//Fin Implementacion Pantalon.cpp