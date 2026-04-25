#ifndef INVENTARIO_H
#define INVENTARIO_H

#define MAX_PRODUCTOS 10

#define MAX_NOMBRE 50

void ingresarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE],
                       float precios[MAX_PRODUCTOS],
                       int n);


float calcularTotal(float precios[MAX_PRODUCTOS], int n);

float calcularPromedio(float precios[MAX_PRODUCTOS], int n);

void encontrarMasCaro(char nombres[MAX_PRODUCTOS][MAX_NOMBRE],
                      float precios[MAX_PRODUCTOS],
                      int n);

void encontrarMasBarato(char nombres[MAX_PRODUCTOS][MAX_NOMBRE],
                        float precios[MAX_PRODUCTOS],
                        int n);

void buscarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE],
                    float precios[MAX_PRODUCTOS],
                    int n,
                    char busqueda[MAX_NOMBRE]);

void mostrarInventario(char nombres[MAX_PRODUCTOS][MAX_NOMBRE],
                       float precios[MAX_PRODUCTOS],
                       int n);


int leerEntero(char mensaje[]);

float leerFlotante(char mensaje[]);

#endif