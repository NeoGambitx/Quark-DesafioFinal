//SOLO DEBE TENER METODOS PARA MOSTRAR INFORMACION - MENU - ETC

//METODOS PARA LA ENTRADA DEL USUARIO
//FORMATEAR HISTORIAL
// PANTALLA PRINCIPAL CON VARIOS PARAMETROS - NOMBRE TIENDA - VENDEDOR
// RESTO DE PANTALLAS CON PARAMETROS - SIEMPRE INVOCADAS DESDE EL PRESENTADOR
// PARAMETROS TAMBIEN PASADOS POR PRESENTADOR

// INVOCA AL PRESENTADOR CUANDO EL USUARIO INGRESA UNA OPCION.

#include "vista.h"
#include <iostream>
#include <limits>

void Vista::printMenuPrincipal(Tienda* t, Vendedor* v){
    std::cout << "COTIZADOR EXPRESS - MENU PRINCIPAL" << std::endl;
    std::cout << "-------------------------------------------------" <<std::endl;
    printTienda(t->getNombre(), t->getDireccion());
    std::cout << "-------------------------------------------------" <<std::endl;
    printVendedor(v->getNombre(), v->getApellido(), v->getCodigoVendedor());
    std::cout << "-------------------------------------------------" <<std::endl;
    std::cout << "" << std::endl;
    std::cout << "SELECCIONE UNA OPCION DEL MENU:" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "1) Historial de cotizaciones" << std::endl;
    std::cout << "2) Realizar cotizacion" << std::endl;
    std::cout << "3) Salir" << std::endl;
    std::cout << "" <<std::endl;
    std::cout << "" <<std::endl;
    std::cout << "Ingrese una opción:  ";
    
}

void Vista::print3msg(){
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "Presiona 3 para volver al menu principal         " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
}

void Vista::printTienda(std::string nombre, std::string direccion){
    std::cout << nombre << "  |  " << direccion << std::endl;
}

void Vista::printVendedor(std::string nombre, std::string apellido, int codigo){
    std::cout << nombre << " " << apellido << "  |  " << codigo << std::endl;
}

bool Vista::validar(int x){
    if(x == 1 || x == 2 || x == 3){
        return true;
    }
    else{
        return false;
    }
}

void Vista::printError(){
    std::cout << "Valor Ingresado Inválido - Vuelva a ingresar un número...";
}

int Vista::getInput(){
    int x;
    bool esValido;
    do{

        std::cin >> x;
        if(validar(x)){
            return x;
        }
        else{
            esValido = false;
            printError();
        }

        std::cin.clear();
        std::cin.ignore( std::numeric_limits<int>::max(), '\n' );

    }while(!esValido);
    
    return x; //No usado, Para que no joda el compilador
}

int Vista::getCantidad(){
    int x;
    bool esValido;
    do{

        std::cin >> x;
        if(x>0){
            return x;
        }
        else{
            esValido = false;
            printError();
        }

        std::cin.clear();
        std::cin.ignore( std::numeric_limits<int>::max(), '\n' );

    }while(!esValido);
    
    return x; //No usado, Para que no apareza la advertencia del compilador
}

float Vista::getInputPrecio(){
    float x;
    bool esValido;
    do{

        std::cin >> x;
        if(x>0){
            return x;
        }
        else{
            esValido = false;
            printError();
        }

        std::cin.clear();
        std::cin.ignore( std::numeric_limits<int>::max(), '\n' );

    }while(!esValido);
    
    return x; //No usado, Para que no apareza la advertencia del compilador
}

void Vista::mostrarHistorial(){
    std::cout << "COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES" << std::endl;
    print3msg();

    //Historial aqui (for o bucle)
    print3msg();
}

void Vista::siNo(){
    std::cout << "1) Si" << std::endl;
    std::cout << "2) No" << std::endl;
}

void Vista::linea(){
    std::cout << "------------------------------------------------------------" << std::endl;
}

void Vista::limpiarPantalla(){
   /*  system("cls"); */
}

void Vista::encabezadoCotizacion(){
    std::cout << "COTIZADOR EXPRESS - COTIZAR " << std::endl;
}

void Vista::cotizadorPaso1(){
    encabezadoCotizacion();
    print3msg();
    std::cout << "PASO 1: Selecciona la prenda a cotizar" << std::endl;
    std::cout << "1) Camisa" << std::endl;
    std::cout << "2) Pantalon" << std::endl;
    linea();
}

void Vista::cotizadorPaso2Camisa(){
    encabezadoCotizacion();
    print3msg();
    std::cout << "PASO 2.A: La camisa a cotizar, ¿es manga corta?" << std::endl;
    siNo();
    linea();
}

void Vista::cotizadorPaso2bCamisa(){
    encabezadoCotizacion();
    print3msg();
    std::cout << "PASO 2.B: La camisa a cotizar, ¿es cuello Mao?" << std::endl;
    siNo();
    linea();
}

void Vista::cotizadorPaso2Pantalon(){
    encabezadoCotizacion();
    print3msg();
    std::cout << "PASO 2: El pantalon a cotizar, ¿es chupin?" << std::endl;
    siNo();
    linea();
}

void Vista::cotizadorPaso3Calidad(){
    encabezadoCotizacion();
    print3msg();
    std::cout << "PASO 3: Seleccione la calidad de la prenda" << std::endl;
    std::cout << "1) Standard" << std::endl;
    std::cout << "2) Premium" << std::endl;
    linea();
}

void Vista::cotizadorPaso4Precio(){
    encabezadoCotizacion();
    print3msg();
    std::cout << "PASO 4: Ingrese el precio unitario de la prenda a cotizar" << std::endl;
    linea();
}

void Vista::cotizadorPaso5Cantidad(int stock){
    encabezadoCotizacion();
    print3msg();
    std::cout << "INFORMACION" << std::endl;
    std::cout << "Existe " << stock << " cantidad de unidades en stock de la prenda seleccionada" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "PASO 5: Ingrese la cantidad de unidades a cotizar:" << std::endl;
}

void Vista::cotizadorResultado(){

}

void Vista::cotizadorError(){
    
}