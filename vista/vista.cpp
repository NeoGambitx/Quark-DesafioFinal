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
    std::cout << "Ingrese una opcion:  ";
    
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
    std::cout << "Valor Ingresado Invalido - Vuelva a ingresar un numero...";
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

void Vista::getAnyInput(){

        std::cin.get();
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<int>::max(), '\n' );

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

void Vista::mostrarHistorial(std::vector<historial> his){
    limpiarPantalla();
    std::cout << "COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES" << std::endl;
    linea();
    for(int x=0; x < his.size(); x++){
        std::cout << "Numero de identificacion: " << his[x].numIdentificacion << std::endl;
        std::cout << "Fecha y hora de la cotizacion: "<< his[x].FechayHora << std::endl;
        std::cout << "Codigo del Vendedor: " << his[x].codigoV << std::endl;
        std::cout << "Prenda cotizada: " << his[x].prendaCotizada << std::endl;
        std::cout << "Precio Unitario: " << his[x].precioUnitario << std::endl;
        std::cout << "Cantidad de prendas cotizadas: " << his[x].cantidadUnidades << std::endl;
        std::cout << "Precio Final: " << his[x].precioFinal << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
    }
    std::cout << "Presione cualquier tecla para continuar" << std::endl;
}

void Vista::siNo(){
    std::cout << "1) Si" << std::endl;
    std::cout << "2) No" << std::endl;
}

void Vista::linea(){
    std::cout << "------------------------------------------------------------" << std::endl;
}

void Vista::limpiarPantalla(){
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

void Vista::encabezadoCotizacion(){
    std::cout << "COTIZADOR EXPRESS - COTIZAR " << std::endl;
}

void Vista::cotizadorPaso1(){
    limpiarPantalla();
    encabezadoCotizacion();
    print3msg();
    std::cout << "PASO 1: Selecciona la prenda a cotizar" << std::endl;
    std::cout << "1) Camisa" << std::endl;
    std::cout << "2) Pantalon" << std::endl;
    linea();
}

void Vista::cotizadorPaso2Camisa(){
    limpiarPantalla();
    encabezadoCotizacion();
    print3msg();
    std::cout << "PASO 2.A: La camisa a cotizar, es manga corta?" << std::endl;
    siNo();
    linea();
}

void Vista::cotizadorPaso2bCamisa(){
    limpiarPantalla();
    encabezadoCotizacion();
    print3msg();
    std::cout << "PASO 2.B: La camisa a cotizar, es cuello Mao?" << std::endl;
    siNo();
    linea();
}

void Vista::cotizadorPaso2Pantalon(){
    limpiarPantalla();
    encabezadoCotizacion();
    print3msg();
    std::cout << "PASO 2: El pantalon a cotizar, es chupin?" << std::endl;
    siNo();
    linea();
}

void Vista::cotizadorPaso3Calidad(){
    limpiarPantalla();
    encabezadoCotizacion();
    print3msg();
    std::cout << "PASO 3: Seleccione la calidad de la prenda" << std::endl;
    std::cout << "1) Standard" << std::endl;
    std::cout << "2) Premium" << std::endl;
    linea();
}

void Vista::cotizadorPaso4Precio(){
    limpiarPantalla();
    encabezadoCotizacion();
    print3msg();
    std::cout << "PASO 4: Ingrese el precio unitario de la prenda a cotizar" << std::endl;
    linea();
}

void Vista::cotizadorPaso5Cantidad(int stock){
    limpiarPantalla();
    encabezadoCotizacion();
    print3msg();
    std::cout << "INFORMACION" << std::endl;
    std::cout << "Existe " << stock << " cantidad de unidades en stock de la prenda seleccionada" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "PASO 5: Ingrese la cantidad de unidades a cotizar:" << std::endl;
}

void Vista::cotizadorResultado(Camisa* c, Vendedor v, int id, int cant, float precioFinal, std::string fecha){
    limpiarPantalla();
    encabezadoCotizacion();
    linea();
    std::cout << "Numero de identificacion: " << id << std::endl;
    std::cout << "Fecha y hora de la cotizacion: " << fecha << std::endl;
    std::cout << "Codigo del Vendedor: " << v.getCodigoVendedor() << std::endl;
    std::cout << "Prenda cotizada: " << c->getCaracteristicas() << std::endl;
    std::cout << "Precio Unitario: " << c->getPrecioUnitario() << std::endl;
    std::cout << "Cantidad de prendas cotizadas: " << cant << std::endl;
    std::cout << "Precio Final: " << precioFinal << std::endl;
    linea();
    std::cout << "Presione cualquier tecla para continuar" << std::endl;
}

void Vista::cotizadorResultado(Pantalon* p, Vendedor v, int id, int cant, float precioFinal, std::string fecha){
    limpiarPantalla();
    encabezadoCotizacion();
    linea();
    std::cout << "Numero de identificacion: " << id << std::endl;
    std::cout << "Fecha y hora de la cotizacion: " << fecha << std::endl;
    std::cout << "Codigo del Vendedor: " << v.getCodigoVendedor() << std::endl;
    std::cout << "Prenda cotizada: " << p->getCaracteristicas() << std::endl;
    std::cout << "Precio Unitario: " << p->getPrecioUnitario() << std::endl;
    std::cout << "Cantidad de prendas cotizadas: " << cant << std::endl;
    std::cout << "Precio Final: " << precioFinal << std::endl;
    linea();
    std::cout << "Presione cualquier tecla para continuar" << std::endl;
}

void Vista::cotizadorError(){
    limpiarPantalla();
    encabezadoCotizacion();
    linea();
    std::cout << "ERROR" << std::endl;
    linea();
    std::cout << "La cantidad a presupuestar supera al stock actual " << std::endl;
    std::cout << "Vuelva a intertarlo" << std::endl;
    linea();
    std::cout << "Presione cualquier tecla para continuar" << std::endl;
}