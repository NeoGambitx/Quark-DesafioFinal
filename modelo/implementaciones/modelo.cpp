/* #include "../headers/modelo.h" */

#include <iostream>
#include "../headers/modelo.h"

Modelo::Modelo(std::string nombreTienda, std::string direccion, std::string nombreV, std::string apellidoV, int codigo):vendedor(nombreV, apellidoV, codigo),tienda(nombreTienda, direccion)
    {
        // Inicializamos la tienda
        // Sus Prendas:
        // Camisas cortas cuello MAO - Calidad Com. y Premium
         Camisa* c1 = new Camisa("Standard", 100, 6000.0, "Corta", "Mao");
         Camisa* c2 = new Camisa("Premium", 100, 6000.0, "Corta", "Mao");
         //Camisas cortas cuello Comun - Calidad Com. y premium
         Camisa* c3 = new Camisa("Standard", 150, 6000.0, "Corta", "Comun");
         Camisa* c4 = new Camisa("Premium", 150, 6000.0, "Corta", "Comun");

         //Camisas Largas cuello MAO - Cal. Com y Premium
         Camisa* c5 = new Camisa("Standard", 75, 6000.0, "Larga", "Mao");
         Camisa* c6 = new Camisa("Premium", 75, 6000.0, "Larga", "Mao");

         //Camisas Largas Cuello Comun - Cal com y premium
         Camisa* c7 = new Camisa("Standard", 175, 6000.0, "Larga", "Comun");
         Camisa* c8 = new Camisa("Premium", 175, 6000.0, "Larga", "Comun");

         //PANTALONES

         //Chupines - calidad p y c
         Pantalon* p1 = new Pantalon("Standard", 750, 7000.0, true);
         Pantalon* p2 = new Pantalon("Premium", 750, 7000.0, true);

         //Comun - Calidad p y c
         Pantalon* p3 = new Pantalon("Standard", 250, 7000.0, false);
         Pantalon* p4 = new Pantalon("Premium", 250, 7000.0, false);

        // Añadimos las prendas a la tienda
        tienda.addCamisas(c1);
        tienda.addCamisas(c2);
        tienda.addCamisas(c3);
        tienda.addCamisas(c4);
        tienda.addCamisas(c5);
        tienda.addCamisas(c6);
        tienda.addCamisas(c7);
        tienda.addCamisas(c8);
        tienda.addPantalon(p1);
        tienda.addPantalon(p2);
        tienda.addPantalon(p3);
        tienda.addPantalon(p4);
    }

    void Modelo::guardarHistorial(Vendedor v, Camisa* c, int cant, float precioFinal, int id, std::string fechayHora){

        historial h;
        h.numIdentificacion = id;
        h.FechayHora = fechayHora;
        h.codigoV = v.getCodigoVendedor();
        h.prendaCotizada = c->getCaracteristicas();
        h.precioUnitario = c->getPrecioUnitario();
        h.cantidadUnidades = cant;
        h.precioFinal = precioFinal;
        this->hist.push_back(h);
    }


    void Modelo::guardarHistorial(Vendedor v, Pantalon* p, int cant, float precioFinal, int id,  std::string fechayHora){

        historial h;
        h.numIdentificacion = id;
        h.FechayHora = fechayHora;
        h.codigoV = v.getCodigoVendedor();
        h.prendaCotizada = p->getCaracteristicas();
        h.precioUnitario = p->getPrecioUnitario();
        h.cantidadUnidades = cant;
        h.precioFinal = precioFinal;
        this->hist.push_back(h);
    }
    

    std::vector<historial> Modelo::getHistorial(){
        return this->hist;
    }
