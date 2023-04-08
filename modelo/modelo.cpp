//DATOS de
//VENDEDOR
//TIENDA
//PRENDAS

//GUARDAR HISTORIAL
#include <iostream>
#include "headers/camisa.h"
#include "headers/pantalon.h"

//SIM
main(){
    bool pant = false;
    char c = 'c';
    int stock = 100;
    float precio = 5100.20;
    Prenda* p = new Pantalon(pant, c, stock, precio); 
    return 0;
}