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

float cotizar(Prenda* p, int cant){
    return (p->getPrecioUnitario() * cant);
}


void iniciarPrograma(Modelo* model, Vista* view){

    //Inicializamos las prendas para ir modificando en el flujo del programa y luego cotizar
    Pantalon* pantalon = new Pantalon('c', 1, 1, false); //Datos random despues se modifica
    

    //Limpiamos pantalla
    view->limpiarPantalla();
    int opcion;

    view->printMenuPrincipal(&model->tienda, &model->vendedor);
    opcion = view->getInput();

    //Main Switch - 1) Historial  2) Cotizar  3) SALIR
    switch (opcion)
    {
    case 1: //CASO 1 - HISTORIAL - 
        view->mostrarHistorial();
        break;
    case 2: //CASO 2 - COTIZACION -
        view->cotizadorPaso1();
        
        //Variable auxiliar - se va comparando para llevar el flujo del programa
        int subOpcion;
        float precio;
        subOpcion = view->getInput();

        //Siempre la opcion de volver al menu principal
        if(subOpcion == 3){
            iniciarPrograma(model, view);
            return;
        }
        //Camisa y sus subopciones  ▼ ▼ ▼ ▼ 
        else if(subOpcion == 1){

            Camisa* camisa = new Camisa('c', 1, 1, 'c', 'm'); 
            
            //PASO 2A CAMISA
            view->cotizadorPaso2Camisa();
            subOpcion = view->getInput();

            if(subOpcion == 3){
                delete camisa;
                iniciarPrograma(model, view);
                return;
            }
            else{ 
                
                if(subOpcion == 1){ // Si = es manga corta
                    camisa->setTipo('c');
                }
                else if(subOpcion == 2){ // NO es manga corta
                    camisa->setTipo('l');
                }

                view->cotizadorPaso2bCamisa();
                subOpcion = view->getInput();

                //PASO 2B CAMISA

                if(subOpcion == 3){
                    delete camisa;
                    iniciarPrograma(model, view);
                    return;
                }
                else{
                    if(subOpcion == 1){ // SI =  es cuello MAO
                        camisa->setCuello('m');
                    } 
                    else if(subOpcion == 2){
                        camisa->setCuello('c');
                    }

                    //PASO 3 - CALIDAD CAMISA
                    view->cotizadorPaso3Calidad();
                    subOpcion = view->getInput();

                    if(subOpcion == 3){
                        delete camisa;
                        iniciarPrograma(model, view);
                    return;
                    }
                    else{
                        if(subOpcion == 1){ //Standard
                            camisa->setCalidad('s');
                        } 
                        else if(subOpcion == 2){ //Premium
                            camisa->setCalidad('p');
                        }

                        //PASO 4 - PRECIO CAMISA
                        view->cotizadorPaso4Precio();
                        precio = view->getInputPrecio();
                        
                        //Por el enunciado se puede volver al menu principal 
                        //Incluso en esta pantalla
                        if(precio == 3){
                            delete camisa;
                            iniciarPrograma(model, view);
                            return;
                        }
                        else{
                            camisa->setPrecioUnitario(precio);

                            //PASO 5 - CANTIDAD
                            // INT 5 prueba
                            //BUSCAR PRENDA EN LA TIENDA, para ver el STOCK actual
                            view->cotizadorPaso5Cantidad(5);
                            subOpcion = view->getCantidad();
                            //COTIZAR AQUI ▼  ▼  ▼  ▼  ▼  ▼
                        
                            //FIN DEL PROGRAMA

                            //TECLA RANDOM Y VOLVER A EMPEZAR - GUARDAR HISTORIAL

                        }
                        
                        

                    }

                }

            }

        }
        //Pantalon y su subopcion ▼ ▼ ▼ ▼ 
        else if(subOpcion == 2){

            //PASO 2 - PANTALON
            view->cotizadorPaso2Pantalon();
            view->getInput();
            if(subOpcion == 3){
                    iniciarPrograma(model, view);
                    return;
            }
            else{
                if(subOpcion == 1){ //SI - es chupín

                } 
                else if(subOpcion == 2){ //NO es chupin

                }

                // PASO 3 - CALIDAD PANTALON
                view->cotizadorPaso3Calidad();
                view->getInput();

                if(subOpcion == 3){
                    iniciarPrograma(model, view);
                    return;
                }
                else{
                    if(subOpcion == 1){ //1) Standard

                    } 
                    else if(subOpcion == 2){ //2) Premium

                    }

                    // PASO 4 - PANTALON PRECIO
                    view->cotizadorPaso4Precio();
                    view->getInputPrecio(); 

                    //PASO 5 - PANTALON - CANTIDAD
                    view->cotizadorPaso5Cantidad(5);
                    view->getCantidad();

                    //COTIZAR + GUARDAR HISTORIAL 
                    //CUALQUIER TECLA PARA CONTINUAR
                }
            
            }
        }

        break;
    case 3:
        break;
    default:
        break;
    }

    //Liberamos espacio de memoria
    delete pantalon;
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