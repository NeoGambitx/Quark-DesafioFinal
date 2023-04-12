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

void iniciarPrograma(Modelo* model, Vista* view){
    
    view->limpiarPantalla();
    int opcion;
/*     view->printMenuPrincipal(model->tienda.getNombre(), model->tienda.getDireccion(), model->vendedor.getNombre(), model->vendedor.getApellido(), model->vendedor.getCodigoVendedor());
 */

    view->printMenuPrincipal(&model->tienda, &model->vendedor);
    opcion = view->getInput();

    switch (opcion)
    {
    case 1: //CASO 1 - HISTORIAL - 
        view->mostrarHistorial();
        break;
    case 2: //CASO 2 - COTIZACION -
        view->cotizadorPaso1();
        
        int subOpcion;
        subOpcion = view->getInput();

        //Siempre la opcion de volver al menu principal
        if(subOpcion == 3){
            iniciarPrograma(model, view);
            return;
        }
        //Camisa y sus subopciones  ▼ ▼ ▼ ▼ 
        else if(subOpcion == 1){

            //PASO 2A CAMISA
            view->cotizadorPaso2Camisa();
            subOpcion = view->getInput();

            if(subOpcion == 3){
                iniciarPrograma(model, view);
                return;
            }
            else{ // Si = es manga corta
                
                if(subOpcion == 1){

                }
                else if(subOpcion == 2){

                }

                view->cotizadorPaso2bCamisa();
                subOpcion = view->getInput();

                //PASO 2B CAMISA

                if(subOpcion == 3){
                    iniciarPrograma(model, view);
                    return;
                }
                else{
                    if(subOpcion == 1){ // SI =  es cuello MAO

                    } 
                    else if(subOpcion == 2){

                    }

                    //PASO 3 - CALIDAD
                    view->cotizadorPaso3Calidad();
                    subOpcion = view->getInput();
                }

            }

        }
        //Pantalon y su subopcion ▼ ▼ ▼ ▼ 
        else if(subOpcion == 2){

        }

        break;
    case 3:
        break;
    default:
        break;
    }
}

int main(){
    //Preparamos el modelo con datos ficticios, a su vez el modelo inicializa las prendas de la tienda, con el stock y condiciones especificadas en el enunciado
    Modelo *model = new Modelo("Glam Palace", "Galileo 2441 - Recoleta - Bs As Argentina", "Carolina", "Pryzbylewski", 645);

    //Preparamos la vista, y llamamos al menu principal con sus respectivos parámetros
    Vista* view = new Vista(); 

    //Logica declarada en una funcion para optar por la recursividad al volver al menu principal
    iniciarPrograma(model, view);

    delete model;
    delete view;
    /* Prenda* p = model->tienda.getPrenda(1); */
}