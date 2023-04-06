#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
}typedef Cliente;

float costoTotal(Producto producto);

int main(){
    Cliente *clientes;
    int cant;
    float suma;
    char *buff;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    
    srand(time(NULL));
    buff = (char *)malloc(20*sizeof(char));

    printf("Ingrese la cantidad de clientes: ");
    fflush(stdin);
    scanf("%d", &cant);

    clientes = (Cliente *)malloc(sizeof(Cliente)*cant);

    //Carga de datos
    printf("\n======= CARGAR DATOS =======\n");
    for (int i = 0; i < cant; i++){
        clientes[i].ClienteID = i;
        printf("Ingrese el nombre del cliente: ");
        fflush(stdin);
        gets(buff);
        clientes[i].NombreCliente = (char *)malloc((strlen(buff)+1) * sizeof(char));
        strcpy(clientes[i].NombreCliente, buff);
        clientes[i].CantidadProductosAPedir = 1 + rand() % 5;
        clientes[i].Productos = (Producto *)malloc(sizeof(Producto)*clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++){
            clientes[i].Productos[j].ProductoID = j; 
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1; 
            strcpy(buff, TiposProductos[rand()%5]);
            clientes[i].Productos[j].TipoProducto = (char *)malloc((strlen(buff)+1) * sizeof(char));
            strcpy(clientes[i].Productos[j].TipoProducto, buff);
            clientes[i].Productos[j].PrecioUnitario = (float)(rand() % 9001 + 1000) / 100.; 
        }
    }

    //Muestra de datos
    printf("\n======= MOSTRAR DATOS =======\n");
    for (int i = 0; i < cant; i++){
        suma = 0;
        printf("\n======= Cliente nro: %d =======\n", i+1);
        printf("Cliente ID: %d\n", clientes[i].ClienteID);
        printf("Nombre del cliente: %s\n", clientes[i].NombreCliente);
        printf("Cantidad de productos: %d\n", clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++){
            printf("\n***** Producto nro: %d *****\n", j+1);
            printf("Producto ID: %d\n", clientes[i].Productos[j].ProductoID);
            printf("Cantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("Tipo de producto: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("Precio unitario: $%.2f\n", clientes[i].Productos[j].PrecioUnitario);
            suma += costoTotal(clientes[i].Productos[j]);
            printf("***** ************** *****\n", j+1);
        }
        printf("Costo total a pagar: $%.2f", suma);
        printf("\n======= =========== =======\n", i+1);
    }


    //Libero la memoria reservada
    for (int i = 0; i < cant; i++){
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++){
            free(clientes[i].Productos[j].TipoProducto);
        }
        free(clientes[i].Productos);
        free(clientes[i].NombreCliente);
    }
    free(clientes);
    free(buff);


    return 0;
}

float costoTotal(Producto producto){
    float total;
    total = producto.Cantidad * producto.PrecioUnitario;
    return total;
}