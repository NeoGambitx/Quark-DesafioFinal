#pragma once
#include <string>

class Vendedor{

    private:
    std::string nombre;
    std::string apellido;
    int codigoVendedor;

    public:
        Vendedor(std::string nombre, std::string apellido, int codigo);
        std::string getNombre();
        std::string getApellido();
        int getCodigoVendedor();
};