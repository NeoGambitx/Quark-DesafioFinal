/* #include "../headers/modelo.h" */

#include <iostream>
#include "../headers/modelo.h"
#include <string>

Modelo::Modelo(std::string nombreTienda, std::string direccion, std::string nombreV, std::string apellidoV, int codigo):vendedor(nombreV, apellidoV, codigo),tienda(nombreTienda, direccion)
    {
        // Inicializamos la tienda
        // Sus Prendas:
        // Camisas cortas cuello MAO - Calidad Com. y Premium
         Prenda* c1 = new Camisa('c', 100, 6000.0, 'c', 'm');
         Prenda* c2 = new Camisa('p', 100, 6000.0, 'c', 'm');
         //Camisas cortas cuello Comun - Calidad Com. y premium
         Prenda* c3 = new Camisa('c', 150, 6000.0, 'c', 'c');
         Prenda* c4 = new Camisa('p', 150, 6000.0, 'c', 'c');

         //Camisas Largas cuello MAO - Cal. Com y Premium
         Prenda* c5 = new Camisa('c', 75, 6000.0, 'l', 'm');
         Prenda* c6 = new Camisa('p', 75, 6000.0, 'l', 'm');

         //Camisas Largas Cuello Comun - Cal com y premium
         Prenda* c7 = new Camisa('c', 175, 6000.0, 'l', 'c');
         Prenda* c8 = new Camisa('p', 175, 6000.0, 'l', 'c');

         //PANTALONES

         //Chupines - calidad p y c
         Prenda* p1 = new Pantalon('c', 750, 7000.0, true);
         Prenda* p2 = new Pantalon('p', 750, 7000.0, true);

         //Comun - Calidad p y c
         Prenda* p3 = new Pantalon('c', 250, 7000.0, false);
         Prenda* p4 = new Pantalon('p', 250, 7000.0, false);

        // Añadimos las prendas a la tienda
        tienda.addPrendas(c1);
        tienda.addPrendas(c2);
        tienda.addPrendas(c3);
        tienda.addPrendas(c4);
        tienda.addPrendas(c5);
        tienda.addPrendas(c6);
        tienda.addPrendas(c7);
        tienda.addPrendas(c8);
        tienda.addPrendas(p1);
        tienda.addPrendas(p2);
        tienda.addPrendas(p3);
        tienda.addPrendas(p4);
    }

    /* void Modelo::guardarHistorial(historial* nuevoH){
        this->hist.push_back(nuevoH);
    }

    std::vector<historial> Modelo::getHistorial(){
        return this->hist;
    } */
