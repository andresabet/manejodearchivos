#include <stdio.h>
#include  "Funciones.h"
int cedula; 
char busqueda[20];

int main (int argc, char *argv[]) {
    int opc;

     do {
        opc = menu();

        switch (opc) {
            case 1:
                createFactura();
                break;
            case 2:
                readFactura();
                break;
            case 3:
                printf("Ingrese la cedula del cliente para editar la factura: ");
                scanf("%d", &cedula);
                editarFactura(cedula);
                break;
           
           case 4:
                printf("Ingrese la cedula o el nombre del cliente para buscar: ");
                scanf("%s", busqueda);
                buscarFactura(busqueda);
                break;
            case 5:
           printf("Ingrese la cedula del cliente para eliminar la factura: ");
                scanf("%d", &cedula);
                eliminarFactura(cedula);
                break;
            case 6:
                printf("Saliendo...\n");
                break;
                
            default:
                printf("Opcion no valida\n");
                break;
        }
    } while (opc != 5);

    return 0;
}