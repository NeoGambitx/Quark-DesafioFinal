#pragma once

class Prenda{

    protected:
        char calidad; // 'n' = Normal - 'p' Premium
        int stock;
        float precioUnitario;   
    public:
        Prenda(char calidad, int stock, float precio);
        int getStock();
        virtual float getPrecioUnitario() = 0; //Cada subClase tiene su propia implementación (Camisa, Pantalon)
        void setStock(int nuevoStock);
        // setPrecio y setCalidad no es necesario basado en el enunciado
};

//Fin Header Prenda.h