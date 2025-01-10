#include <stdio.h>
#include  "Funciones.h" 

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
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    } while (opc != 3);


    return 0;
}