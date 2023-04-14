#pragma once

class Prenda{

    protected:
        char calidad; // 's' = Standard - 'p' Premium
        int stock;
        float precioUnitario;   
    public:
        Prenda(char calidad, int stock, float precio);
        int getStock();
        virtual float getPrecioUnitario() = 0; //Cada subClase tiene su propia implementación (Camisa, Pantalon)
        void setStock(int nuevoStock);
        void setPrecioUnitario(float precioBase);
        void setCalidad(char c);
        char getCalidad();
};

//Fin Header Prenda.h