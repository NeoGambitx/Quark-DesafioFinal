#pragma once
#include <string>

class Prenda{

    protected:
        std::string calidad; // Standard - Premium
        int stock;
        float precioUnitario;   
    public:
        Prenda(std::string calidad, int stock, float precio);
        int getStock();
        virtual float getPrecioUnitario() = 0; //Cada subClase tiene su propia implementación (Camisa, Pantalon)
        virtual std::string getCaracteristicas() = 0;
        void setStock(int nuevoStock);
        void setPrecioUnitario(float precioBase);
        void setCalidad(std::string c);
        std::string getCalidad();

};

//Fin Header Prenda.h