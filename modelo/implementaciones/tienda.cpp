#include "../headers/tienda.h"

Tienda::Tienda(std::string _nombre, std::string _direccion){
    this->nombre = _nombre;
    this->direccion = _direccion;
}

std::string Tienda::getNombre(){
    return this->nombre;
}

std::string Tienda::getDireccion(){
    return this->direccion;
}

//
bool Tienda::compararPantalones(Pantalon* p1, Pantalon* p2){

    if(p1->getCalidad() == p2->getCalidad()){
        if(p1->getTipo() == p2->getTipo()){
            return true;
        }
    }
    else{
        return false;
    }
    return false; //Compilador
}

bool Tienda::compararCamisas(Camisa* c1, Camisa* c2){
    
    if(c1->getCalidad() == c2->getCalidad()){
        if(c1->getCuello() == c2->getCuello()){
            if(c1->getTipo() == c2->getTipo()){
                return true;
            }
        }
    }
    else{
        return false;
    }
    return false; //Compilador
}

//En este ejemplo yo se donde se guarda cada tipo de prenda
//Tambien se podria filtrar en base a sus caracteristicas.
Camisa* Tienda::getCamisa(Camisa* prendaABuscar){
    
    for(int i=0; i < this->listaCamisas.size(); i++){
        if(compararCamisas(prendaABuscar, this->listaCamisas[i])){
            return this->listaCamisas[i];
        }
    }
    return this->listaCamisas[0]; //Compilador
}

Pantalon* Tienda::getPantalon(Pantalon* prendaABuscar){
    for(int i=0; i < this->listaPantalones.size(); i++){
        if(compararPantalones(prendaABuscar, this->listaPantalones[i])){
            return this->listaPantalones[i];
        }
    }
    return this->listaPantalones[0]; //Compilador   
}

void Tienda::addPantalon(Pantalon* p){
    this->listaPantalones.push_back(p);
}

void Tienda::addCamisas(Camisa* c){
    this->listaCamisas.push_back(c);
}