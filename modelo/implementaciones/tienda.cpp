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

//En este ejemplo yo se donde se guarda cada tipo de prenda
//Tambien se podria filtrar en base a sus caracteristicas.
Prenda* Tienda::getPrenda(int index){
    return this->listaDePrendas[index];
}

void Tienda::addPrendas(Prenda* p){
    this->listaDePrendas.push_back(p);
}
