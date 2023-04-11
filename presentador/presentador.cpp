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

class ClaseB{
    private:
        int numero2;
    public:
        ClaseA a;
        ClaseB(int num2);
};

ClaseB::ClaseB(int num2):a(60){
    this->numero2 = num2;
}



int main(){

    ClaseB* cb = new ClaseB(20);
    cb->a.printNum(); 
}