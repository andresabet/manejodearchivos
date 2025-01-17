#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu ()
{
    int opcion;
    printf("1. Crear factura\n");
    printf("2. Leer factura\n");
     printf("3. Editar factura\n");
      printf("4. Buscar factura\n");
    printf("5. Salir\n");
    printf(">> ");
    scanf("%d", &opcion);
    return opcion;
}

void saveFactura(struct Factura *factura)
{
    FILE *file;
    file = fopen("factura.dat", "ab+");
    if (file == NULL)
    {
        printf("Error al abrir el archivo\n");
        return ;
    }else{
        fwrite(factura, sizeof(struct Factura), 1, file);
        printf("Factura guardada con exito\n");
    }
   
    
    fclose(file);
    
}

void leerCadena(char *cadena, int num)
{
    fflush(stdin);
    fgets(cadena, num, stdin);
    int len = strlen (cadena) -1;
   
    cadena[len] = '\0';
}

void createFactura() {
    struct Factura factura;

    printf("Ingrese el nombre del cliente: ");
    leerCadena(factura.nombre, 20);
    printf("Ingrese la cedula del cliente: ");
    scanf("%d", &factura.cedula);
    printf("Ingrese el numero de productos: ");
    scanf("%d", &factura.numProductos);
    factura.total = 0;

    for (int i = 0; i < factura.numProductos; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        leerCadena(factura.productos[i].nombre, 50);
        printf("Ingrese la cantidad del producto %d: ", i + 1);
        scanf("%d", &factura.productos[i].cantidad);
        printf("Ingrese el precio del producto %d: ", i + 1);
        scanf("%f", &factura.productos[i].precio);
        factura.total += factura.productos[i].cantidad * factura.productos[i].precio;
    }

    saveFactura(&factura);
}


void readFactura()
{
    FILE *file= fopen("factura.dat", "rb");
    struct Factura factura;
   
    if (file == NULL)
    {
        printf("Error al abrir el archivo\n");
        return ;
    }
    printf("Cedula\t\tNombre\t\tTotal\n");

    while (fread(&factura, sizeof(struct Factura), 1, file))
    {
        printf("%d\t\t%s\t\t%.2f\n", factura.cedula, 
                                     factura.nombre, 
                                     factura.total);
        
    }
     
        fclose(file);
    }

    void editarFactura(int cedula) {
    FILE *file = fopen("factura.dat", "rb+");
    struct Factura factura;
    int encontrado = 0;

    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    while (fread(&factura, sizeof(struct Factura), 1, file)) {
        if (factura.cedula == cedula) {
            encontrado = 1;
            printf("\nFactura encontrada:\n");
            printf("Cedula: %d\n", factura.cedula);
            printf("Nombre: %s\n", factura.nombre);
            printf("Total: %.2f\n", factura.total);

            // Editar la factura
            printf("\nIngrese el nuevo nombre del cliente: ");
            leerCadena(factura.nombre, 20);

            // Validar número de productos
            do {
                printf("Ingrese el nuevo numero de productos: ");
                scanf("%d", &factura.numProductos);
                if (factura.numProductos <= 0) {
                    printf("Error: El numero de productos debe ser mayor que 0.\n");
                }
            } while (factura.numProductos <= 0);

            factura.total = 0;
            for (int i = 0; i < factura.numProductos; i++) {
                printf("Ingrese el nombre del producto %d: ", i + 1);
                leerCadena(factura.productos[i].nombre, 50);

                // Validar cantidad
                do {
                    printf("Ingrese la cantidad del producto %d: ", i + 1);
                    scanf("%d", &factura.productos[i].cantidad);
                    if (factura.productos[i].cantidad <= 0) {
                        printf("Error: La cantidad debe ser mayor que 0.\n");
                    }
                } while (factura.productos[i].cantidad <= 0);

                // Validar precio
                do {
                    printf("Ingrese el precio del producto %d: ", i + 1);
                    scanf("%f", &factura.productos[i].precio);
                    if (factura.productos[i].precio <= 0) {
                        printf("Error: El precio debe ser mayor que 0.\n");
                    }
                } while (factura.productos[i].precio <= 0);

                factura.total += factura.productos[i].cantidad * factura.productos[i].precio;
            }

            // Mover el puntero del archivo para sobrescribir la factura
            fwrite(&factura, sizeof(struct Factura), 1, file);
            printf("Factura editada con exito\n");
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontro una factura con la cedula %d\n", cedula);
    }

    fclose(file);
}
void buscarFactura()   {                    


    FILE *file = fopen("factura.dat", "rb");
    struct Factura factura;
    int cedula;
    int encontrado = 0;

    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    printf("Ingrese la cedula del cliente: ");
    scanf("%d", &cedula);

    while (fread(&factura, sizeof(struct Factura), 1, file)) {
        if (factura.cedula == cedula) {
            encontrado = 1;
            printf("\nFactura encontrada:\n");
            printf("Cedula: %d\n", factura.cedula);
            printf("Nombre: %s\n", factura.nombre);
            printf("Total: %.2f\n", factura.total);
            printf("Productos:\n");

            for (int i = 0; i < factura.numProductos; i++) {
                printf("Nombre: %s\n", factura.productos[i].nombre);
                printf("Cantidad: %d\n", factura.productos[i].cantidad);
                printf("Precio: %.2f\n", factura.productos[i].precio);
            }

            break;
        }
    }

    if (!encontrado) {
        printf("No se encontro una factura con la cedula %d\n", cedula);
    }

    fclose(file);    
   

}
void eliminarFactura() {
    FILE *file = fopen("factura.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Factura factura;
    int cedula;
    int encontrado = 0;

    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    printf("Ingrese la cedula del cliente: ");
    scanf("%d", &cedula);

    while (fread(&factura, sizeof(struct Factura), 1, file)) {
        if (factura.cedula == cedula) {
            encontrado = 1;
            printf("Factura eliminada con exito\n");
        } else {
            fwrite(&factura, sizeof(struct Factura), 1, temp);
        }
    }

    if (!encontrado) {
        printf("No se encontro una factura con la cedula %d\n", cedula);
    }

    fclose(file);
    fclose(temp);

    remove("factura.dat");
    rename("temp.dat", "factura.dat");

}

