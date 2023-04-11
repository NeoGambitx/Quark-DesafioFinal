#include "../headers/vendedor.h"

Vendedor::Vendedor(std::string _nombre, std::string _apellido, int _codigo){
    this->nombre = _nombre;
    this->apellido = _apellido;
    this->codigoVendedor = _codigo;
}

std::string Vendedor::getNombre(){
    return this->nombre;
}

std::string Vendedor::getApellido(){
    return this->apellido;
}

int Vendedor::getCodigoVendedor(){
    return this->codigoVendedor;
}