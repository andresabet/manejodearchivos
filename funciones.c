#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu ()
{
    int opcion;
    printf("1. Crear factura\n");
    printf("2. Leer factura\n");
    printf("3. Salir\n");
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

void createFactura()

{struct Factura *factura;

    printf("Ingrese el nombre del cliente: ");
   leerCadena(factura->nombre, 20);
    printf("Ingrese la cedula del cliente: ");
    scanf("%d", &factura->cedula);
    printf("Ingrese el numero de productos: ");
    scanf("%d", &factura->numProductos);
    factura->total = 0;
    for (int i = 0; i < factura->numProductos; i++)
    {
        printf("Ingrese el nombre del producto %d: ", i+1);
        leerCadena(factura->productos[i].nombre, 50);
        printf("Ingrese la cantidad del producto %d: ", i+1);
        scanf("%d", &factura->productos[i].cantidad);
        printf("Ingrese el precio del producto %d: ", i+1);
        scanf("%f", &factura->productos[i].precio);
        factura->total += factura->productos[i].cantidad * factura->productos[i].precio;
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

