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
#include <string>
#include "../vista/vista.h"
#include "../modelo/headers/modelo.h"
#include "../modelo/headers/vendedor.h"


int main(){
    //Preparamos el modelo con datos ficticios, a su vez el modelo inicializa las prendas de la tienda, con el stock y condiciones especificadas en el enunciado
    Modelo *model = new Modelo("Glam Palace", "Galileo 2441 - Recoleta - Bs As Argentina", "Carolina", "Pryzbylewski", 645);
    
    //Preparamos la vista, y llamamos al menu principal con sus respectivos parámetros
    Vista* view = new Vista(); 
    view->printMenuPrincipal(model->tienda.getNombre(), model->tienda.getDireccion(), model->vendedor.getNombre(), model->vendedor.getApellido(), model->vendedor.getCodigoVendedor());

    
    Prenda* p = model->tienda.getPrenda(1);
}