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

bool Tienda::compararPrendas(Prenda* p1, Prenda* p2){

    if(p1->getCalidad() == p2->getCalidad()){
        /* if(p1->) */
    }

}

//En este ejemplo yo se donde se guarda cada tipo de prenda
//Tambien se podria filtrar en base a sus caracteristicas.
Prenda* Tienda::getPrenda(Prenda* prendaABuscar){
    
    for(int i=0; i < this->listaDePrendas.size(); i++){

    }
    return this->listaDePrendas[0];
}

void Tienda::addPrendas(Prenda* p){
    this->listaDePrendas.push_back(p);
}
