struct producto
{
    char nombre[50];
    int cantidad;
    float precio;
    
};

struct Factura        
{
    char nombre[20];
     int cedula;
     int numProductos;
     float total;
     struct producto productos[5];
};

int menu ();
void saveFactura(struct Factura *factura);
void leerCadena(char *cadena, int num);
void createFactura();
void readFactura();
 void editarFactura(int cedula);
void buscarFactura();