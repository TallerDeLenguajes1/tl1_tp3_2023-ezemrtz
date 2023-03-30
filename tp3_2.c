#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void promedio(int *p);

int main(){
    int matriz[5][12], *p, max=0, min=51000, maxA, minA, maxM, minM;
    p = &matriz[0][0];
    srand(time(NULL));
    printf("\n======== Carga y muestra de datos =========\n");
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 12; j++){
            matriz[i][j] = rand() % 40001 + 10000;
            printf("== Fecha: %d/%d - Valor: %d ==\n",  j+1, 2023+i, matriz[i][j]);
            if(matriz[i][j] > max){
                max = matriz[i][j];
                maxA = i+2023;
                maxM = j+1;
            }
            if(matriz[i][j] < min){
                min = matriz[i][j];
                minA = i+2023;
                minM = j+1;
            }
        } 
    }
    printf("\n======== Promedios =========\n");
    promedio(p);
    printf("\n======== Maximo y minimo =========\n");
    printf("Valor maximo: %d - Fecha: %d/%d\n", max, maxM, maxA);
    printf("Valor minimo: %d - Fecha: %d/%d\n", min, minM, minA);
    
    return 0;
}

void promedio(int *p){
    int prom;
    for (int i = 0; i < 5; i++){
        prom = 0;
        for (int j = 0; j < 12; j++){
            prom += *p++;
        } 
        prom /= 12;
        printf("Promedio de ganancias del anio %d: %d\n", i+2023, prom);
    }
    
}