//SOLO DEBE TENER METODOS PARA MOSTRAR INFORMACION - MENU - ETC

//METODOS PARA LA ENTRADA DEL USUARIO
//FORMATEAR HISTORIAL
// PANTALLA PRINCIPAL CON VARIOS PARAMETROS - NOMBRE TIENDA - VENDEDOR
// RESTO DE PANTALLAS CON PARAMETROS - SIEMPRE INVOCADAS DESDE EL PRESENTADOR
// PARAMETROS TAMBIEN PASADOS POR PRESENTADOR

// INVOCA AL PRESENTADOR CUANDO EL USUARIO INGRESA UNA OPCION.

#include "vista.h"
#include <iostream>

void Vista::printMenuPrincipal(std::string nombreT, std::string dir, std::string nombreV, std::string apellidoV, int cod){
    std::cout << "COTIZADOR EXPRESS - MENU PRINCIPAL" << std::endl;
    std::cout << "-------------------------------------------------" <<std::endl;
    printTienda(nombreT, dir);
    std::cout << "-------------------------------------------------" <<std::endl;
    printVendedor(nombreV, apellidoV, cod);
    std::cout << "-------------------------------------------------" <<std::endl;
    std::cout << "" << std::endl;
    std::cout << "SELECCIONE UNA OPCION DEL MENU:" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "1) Historial de cotizaciones" << std::endl;
    std::cout << "2) Realizar cotizacion" << std::endl;
    std::cout << "3) Salir";

    
}

void Vista::printTienda(std::string nombre, std::string direccion){
    std::cout << nombre << "  |  " << direccion << std::endl;
}

void Vista::printVendedor(std::string nombre, std::string apellido, int codigo){
    std::cout << nombre << " " << apellido << "  |  " << codigo << std::endl;
}