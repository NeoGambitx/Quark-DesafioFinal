//TRAER DATOS DEL MODELO - 
//INICIALIZAR LA TIENDA, VENDEDOR Y PRENDAS

//logica DE COTIZACION
//TRAER HISTORIAL

//INVOCAR A LA VISTA E IR MOSTRANDO DATOS EN PANTALLA
/* 
class Presentador{

    public:
        void mostrarMenu();

}; */
#include <iostream>

/* Test */
#include "../modelo/headers/tienda.h"
#include "../modelo/headers/pantalon.h"

class ClaseA{
    private:
        int numero;
    public:
        ClaseA(int n);
        void printNum(){
            std::cout << numero << std::endl;
        }
};

ClaseA::ClaseA(int n){
    this->numero = n;
}

class ClaseC{
    public:
        char c;
        ClaseC(char _c){
            this->c = _c;
        }
};

class ClaseB{
    private:
        int numero2;
    public:
        ClaseA a;
        ClaseC c;
        ClaseB(int num2);
};

ClaseB::ClaseB(int num2):a(60),c('a'){
    this->numero2 = num2;
}



int main(){

    /* Tienda* t = new Tienda("Carolina herrera", "Calle 58"); */
    Pantalon* p = new Pantalon('c', 200, 159.6, true);
    ClaseB* cb = new ClaseB(20);
    cb->a.printNum(); 
    std::cout << "Char ClaseB dentro de parametro C " <<cb->c.c ;
}