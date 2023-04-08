class Prenda{

    protected:
        char calidad; // 'n' = Normal - 'p' Premium
        int stock;
        float precioUnitario;   
    public:
        Prenda(char calidad, int stock, float precio);
        char getCalidad();
        int getStock();
        virtual float getPrecioUnitario() = 0; //Cada subClase tiene su propia implementación (Camisa, Pantalon)
        void setStock();
        // setPrecio y setCalidad no es necesario basado en el enunciado
};