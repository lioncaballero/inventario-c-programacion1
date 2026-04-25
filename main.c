#include <stdio.h>
#include <string.h>
#include "inventario.h"

int main(void)
{
    char  nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];

    int   n       = 0;
    int   opcion  = 0;
    char  busqueda[MAX_NOMBRE];
    printf("=============================================\n");
    printf("   SISTEMA DE GESTION DE INVENTARIO\n");
    printf("   ISWZ1102 - Programacion I\n");
    printf("=============================================\n");

    do {
        n = leerEntero("\nCuantos productos desea registrar (1 - 10): ");
        if (n < 1 || n > MAX_PRODUCTOS) {
            printf("[!] Cantidad invalida. Ingrese entre 1 y %d.\n", MAX_PRODUCTOS);
        }
    } while (n < 1 || n > MAX_PRODUCTOS);

    ingresarProductos(nombres, precios, n);

    do {
        printf("\n=============================================\n");
        printf("              MENU PRINCIPAL\n");
        printf("=============================================\n");
        printf("  1. Mostrar inventario completo\n");
        printf("  2. Ver precio total del inventario\n");
        printf("  3. Ver precio promedio\n");
        printf("  4. Ver producto mas caro y mas barato\n");
        printf("  5. Buscar producto por nombre\n");
        printf("  6. Salir\n");
        printf("---------------------------------------------\n");
        opcion = leerEntero("Seleccione una opcion: ");

        switch (opcion) {

            case 1:
                mostrarInventario(nombres, precios, n);
                break;

            case 2:
                mostrarInventario(nombres, precios, n);
                printf("PRECIO TOTAL DEL INVENTARIO: $%.2f\n",
                       calcularTotal(precios, n));
                break;

            case 3:
                printf("\nPrecio promedio de los productos: $%.2f\n",
                       calcularPromedio(precios, n));
                break;

            case 4:
                encontrarMasCaro(nombres, precios, n);
                encontrarMasBarato(nombres, precios, n);
                break;

            case 5:
                printf("\nIngrese el nombre del producto a buscar: ");
                scanf(" %[^\n]", busqueda);
                buscarProducto(nombres, precios, n, busqueda);
                break;

            case 6:
                printf("\nSaliendo del programa. Hasta luego!\n");
                break;

            default:
                printf("\n[!] Opcion invalida. Elija entre 1 y 6.\n");
        }

    } while (opcion != 6);

    return 0;
}