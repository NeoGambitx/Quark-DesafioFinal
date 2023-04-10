#include "../headers/pantalon.h"

Pantalon::Pantalon(char calidad, int stock, float precio, bool _tipo): Prenda(calidad, stock, precio){
                this->tipo = _tipo;
        };

float Pantalon::getPrecioUnitario(){
            float precioFinal = this->precioUnitario;
            if(this->tipo == true){ 
                precioFinal*=0.88; //-12% Chupin
            }
            if(this->calidad == 'p'){
                precioFinal*=1.30;
            }
            return precioFinal;
};
//Fin Implementacion Pantalon.cpp