#include <stdio.h>
#include <string.h>  
#include "inventario.h"

void ingresarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE],
                       float precios[MAX_PRODUCTOS],
                       int n)
{
    int i;

    printf("\n=== INGRESO DE PRODUCTOS ===\n");

    for (i = 0; i < n; i++) {
        printf("\nProducto %d:\n", i + 1);

        printf("  Nombre : ");
        scanf(" %[^\n]", nombres[i]);

        do {
            precios[i] = leerFlotante("  Precio : $");
            if (precios[i] < 0) {
                printf("  [!] El precio no puede ser negativo. Intente de nuevo.\n");
            }
        } while (precios[i] < 0);
    }

    printf("\nDatos ingresados correctamente.\n");
}

float calcularTotal(float precios[MAX_PRODUCTOS], int n)
{
    int i;
    float total = 0.0;

    for (i = 0; i < n; i++) {
        total += precios[i];
    }

    return total;
}

float calcularPromedio(float precios[MAX_PRODUCTOS], int n)
{
    if (n == 0) {
        return 0.0;
    }
    return calcularTotal(precios, n) / n;
}

void encontrarMasCaro(char nombres[MAX_PRODUCTOS][MAX_NOMBRE],
                      float precios[MAX_PRODUCTOS],
                      int n)
{
    int i;
    int indiceMayor = 0;

    for (i = 1; i < n; i++) {
        if (precios[i] > precios[indiceMayor]) {
            indiceMayor = i;
        }
    }

    printf("\nProducto mas caro  : %s ($%.2f)\n",
           nombres[indiceMayor], precios[indiceMayor]);
}

void encontrarMasBarato(char nombres[MAX_PRODUCTOS][MAX_NOMBRE],
                        float precios[MAX_PRODUCTOS],
                        int n)
{
    int i;
    int indiceMenor = 0;

    for (i = 1; i < n; i++) {
        if (precios[i] < precios[indiceMenor]) {
            indiceMenor = i;
        }
    }

    printf("Producto mas barato: %s ($%.2f)\n",
           nombres[indiceMenor], precios[indiceMenor]);
}

void buscarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE],
                    float precios[MAX_PRODUCTOS],
                    int n,
                    char busqueda[MAX_NOMBRE])
{
    int i;
    int encontrado = 0;

    for (i = 0; i < n; i++) {
        if (strcmp(nombres[i], busqueda) == 0) {
            printf("\nProducto encontrado:\n");
            printf("  Nombre : %s\n", nombres[i]);
            printf("  Precio : $%.2f\n", precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n[!] Producto \"%s\" no encontrado en el inventario.\n", busqueda);
    }
}

int leerEntero(char mensaje[])
{
    int valor;
    int resultado;
    char caracter;

    do {
        printf("%s", mensaje);

        resultado = scanf("%d", &valor);

        if (resultado != 1) {
            printf("  [!] Entrada invalida. Ingrese solo numeros enteros.\n");
        }

        do {
            caracter = getchar();
        } while (caracter != '\n' && caracter != EOF);

    } while (resultado != 1);

    return valor;
}

float leerFlotante(char mensaje[])
{
    float valor;
    int resultado;
    char caracter;

    do {
        printf("%s", mensaje);

        resultado = scanf("%f", &valor);

        if (resultado != 1) {
            printf("  [!] Entrada invalida. Ingrese solo numeros (ej: 3.50).\n");
        }

        do {
            caracter = getchar();
        } while (caracter != '\n' && caracter != EOF);

    } while (resultado != 1);

    return valor;
}

void mostrarInventario(char nombres[MAX_PRODUCTOS][MAX_NOMBRE],
                       float precios[MAX_PRODUCTOS],
                       int n)
{
    int i;

    printf("\n=== INVENTARIO DE PRODUCTOS ===\n");
    printf("%-5s %-30s %10s\n", "No.", "Nombre", "Precio");
    printf("--------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-5d %-30s $%9.2f\n", i + 1, nombres[i], precios[i]);
    }

    printf("--------------------------------------------------\n");
}