//DATOS de
//VENDEDOR
//TIENDA
//PRENDAS

//GUARDAR HISTORIAL
#include <iostream>

class Prenda{

    protected:
        // 'n' = Normal - 'p' Premium
        char calidad;
        int stock;
        float precioUnitario;   
    public:
        //Contructor
        Prenda(char calidad, int stock, float precio){
            this->calidad = calidad;
            this->stock = stock;
            this->precioUnitario = precio;
        };
        //Getters
        char getCalidad();
        int getStock();
        virtual float getPrecioUnitario() = 0;
        //Setters
        void setStock();
        // setPrecio y setCalidad no es necesario basado en el enunciado


};

class Camisa: public Prenda{
    private:
        //'l' = Manga Larga / 'c' Manga corta
        char tipo;
        // 'm' = Mao / 'c' = Común
        char cuello;
    public:
        Camisa(char tipo, char cuello, char calidad, int stock, float precio): Prenda(calidad, stock, precio){};

};

class Pantalon: public Prenda{
    private:
        // true = CHUPIN / false = COMUN
        bool tipo;
    public:
        Pantalon(bool _tipo, char calidad, int stock, float precio): Prenda(calidad, stock, precio){
                this->tipo = _tipo;
        };
        float getPrecioUnitario(){
            // Normal ▼ ▼ ▼
            if(this->tipo == false){
                return this->precioUnitario;
            }
            //Chupin ▼ ▼ ▼
            else{
                return (this->precioUnitario - this->precioUnitario*0.12);
            }
        };
};


//SIM
main(){
    bool pant = false;
    char c = 'c';
    int stock = 100;
    float precio = 5100.20;
    Prenda* p = new Pantalon(pant, c, stock, precio); 
    return 0;
}