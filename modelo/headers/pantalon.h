#include "prenda.h"

class Pantalon: public Prenda{
    private:
        bool tipo; // true = CHUPIN / false = COMUN
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
