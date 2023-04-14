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
#include <ctime>

float cotizar(Camisa* c, int cant){
    return (c->getPrecioUnitario() * cant);
}

float cotizar(Pantalon* p, int cant){
    return (p->getPrecioUnitario() * cant);
}

//Variables Globales
int identificador = 1;
int subOpcion;
float precio;
float precioFinal;
int cantidad;

void iniciarPrograma(Modelo* model, Vista* view){

    //Limpiamos pantalla
    view->limpiarPantalla();
    int opcion;

    view->printMenuPrincipal(&model->tienda, &model->vendedor);
    opcion = view->getInput();

    //Main Switch - 1) Historial  2) Cotizar  3) SALIR
    switch (opcion)
    {
    case 1: //CASO 1 - HISTORIAL -
    { 
        view->mostrarHistorial(model->getHistorial());

        std::cin.get();
        std::cin.get();

        iniciarPrograma(model, view);
        return;

        break;
    }
    case 2: //CASO 2 - COTIZACION -
    {
        view->cotizadorPaso1();
        
        //Variable auxiliar - se va comparando para llevar el flujo del programa
  
        subOpcion = view->getInput();

        //Siempre la opcion de volver al menu principal
        if(subOpcion == 3){
            iniciarPrograma(model, view);
            return;
        }
        //Camisa y sus subopciones  ▼ ▼ ▼ ▼ 
        else if(subOpcion == 1){

            Camisa* camisa = new Camisa("Standard", 1, 1, "Corta", "Mao"); 
            
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
                    camisa->setTipo("Corta");
                }
                else if(subOpcion == 2){ // NO es manga corta
                    camisa->setTipo("Larga");
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
                        camisa->setCuello("Mao");
                    } 
                    else if(subOpcion == 2){
                        camisa->setCuello("Comun");
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
                            camisa->setCalidad("Standard");
                        } 
                        else if(subOpcion == 2){ //Premium
                            camisa->setCalidad("Premium");
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
                            //BUSCAR PRENDA EN LA TIENDA, para ver el STOCK actual

                            view->cotizadorPaso5Cantidad(model->tienda.getCamisa(camisa)->getStock());
                            cantidad = view->getCantidad();


                            //COTIZAR AQUI ▼  ▼  ▼  ▼  ▼  ▼
                            //Primero verificamos que el numero ingresado no supera el stock2
                            if(cantidad > model->tienda.getCamisa(camisa)->getStock()){
                                view->cotizadorError();
                                view->getAnyInput();
                                //Volvemos al menu principal
                                delete camisa;
                                iniciarPrograma(model, view);
                                //FIN DEL PROGRAMA
                            }
                            else{

                                precioFinal = cotizar(camisa, cantidad);
                            
                                    //obtenemos fecha y hora
                                std::time_t t = std::time(nullptr);
                                std::tm* now = std::localtime(&t);
                                char buffer[128];
                                strftime(buffer, sizeof(buffer), "%m-%d-%Y %X", now);
        
                                //Guardamos en el historial
                                model->guardarHistorial(model->vendedor, camisa, cantidad, precioFinal, identificador, buffer);

                             //Mostramos en pantalla
                                view->cotizadorResultado(camisa, model->vendedor, identificador, cantidad, precioFinal, buffer);
                            
                                //Sumamos 1 unidad al id, para la proxima cotizacion/registro
                                identificador+=1;

                                view->getAnyInput();
                            
                            
                                //Volvemos al menu principal
                                delete camisa;
                                iniciarPrograma(model, view);
                                //FIN DEL PROGRAMA
                            }
                            

                        }
                        
                        

                    }

                }

            }

        }
        //Pantalon y su subopcion ▼ ▼ ▼ ▼ 
        else if(subOpcion == 2){

            Pantalon* pantalon = new Pantalon("Standard", 1, 1, false);

            //PASO 2 - PANTALON
            view->cotizadorPaso2Pantalon();
            subOpcion = view->getInput();
            if(subOpcion == 3){
                    delete pantalon;
                    iniciarPrograma(model, view);
                    return;
            }
            else{
                if(subOpcion == 1){ //SI - es chupín
                    pantalon->setTipo(true);
                } 
                else if(subOpcion == 2){ //NO es chupin
                    pantalon->setTipo(false);
                }

                // PASO 3 - CALIDAD PANTALON
                view->cotizadorPaso3Calidad();
                subOpcion = view->getInput();

                if(subOpcion == 3){
                    delete pantalon;
                    iniciarPrograma(model, view);
                    return;
                }
                else{
                    if(subOpcion == 1){ //1) Standard
                        pantalon->setCalidad("Standard");
                    } 
                    else if(subOpcion == 2){ //2) Premium
                        pantalon->setCalidad("Premium");
                    }

                    // PASO 4 - PANTALON PRECIO
                    view->cotizadorPaso4Precio();
                    precio = view->getInputPrecio(); 

                    if(precio == 3){
                    delete pantalon;
                    iniciarPrograma(model, view);
                    return;
                    }
                    else{
                        pantalon->setPrecioUnitario(precio);
                        
                        //PASO 5 - CANTIDAD
                            //BUSCAR PRENDA EN LA TIENDA, para ver el STOCK actual

                            view->cotizadorPaso5Cantidad(model->tienda.getPantalon(pantalon)->getStock());
                            cantidad = view->getCantidad();


                            //COTIZAR AQUI ▼  ▼  ▼  ▼  ▼  ▼
                            //Primero verificamos que el numero ingresado no supera el stock2
                            if(cantidad > model->tienda.getPantalon(pantalon)->getStock()){
                                view->cotizadorError();
                                view->getAnyInput();
                                //Volvemos al menu principal
                                delete pantalon;
                                iniciarPrograma(model, view);
                                //FIN DEL PROGRAMA
                            }
                            else{

                                precioFinal = cotizar(pantalon, cantidad);
                            
                                    //obtenemos fecha y hora
                                std::time_t t = std::time(nullptr);
                                std::tm* now = std::localtime(&t);
                                char buffer[128];
                                strftime(buffer, sizeof(buffer), "%m-%d-%Y %X", now);
        
                                //Guardamos en el historial
                                model->guardarHistorial(model->vendedor, pantalon, cantidad, precioFinal, identificador, buffer);

                             //Mostramos en pantalla
                                view->cotizadorResultado(pantalon, model->vendedor, identificador, cantidad, precioFinal, buffer);
                            
                                //Sumamos 1 unidad al id, para la proxima cotizacion/registro
                                identificador+=1;

                                view->getAnyInput();
                            
                            
                                //Volvemos al menu principal
                                delete pantalon;
                                iniciarPrograma(model, view);
                                //FIN DEL PROGRAMA
                            }

                    }
                    

                    //COTIZAR + GUARDAR HISTORIAL 
                    //CUALQUIER TECLA PARA CONTINUAR
                }
            
            }
        }
        break;
    }
    case 3:{
        break;
        }
    default:{
        break;
        }
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