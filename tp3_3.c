#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void liberar(char **nombres);


int main(){
    char **nombres = (char **)malloc(sizeof(char *) * 5), *buffer;
    int len;

    buffer = (char *)malloc(100*sizeof(char));
    for (int i = 0; i < 5; i++){
        printf("Ingrese un nombre: ");
        fflush(stdin);
        gets(buffer);
        len = strlen(buffer);
        nombres[i] = (char *)malloc(sizeof(char)*(len+1));
        strcpy(nombres[i], buffer);
    }

    for (int i = 0; i < 5; i++){
        printf("Nombre %d: ", i+1); 
        puts(nombres[i]);
    }

    for (int i = 0; i < 5; i++){
        free(nombres[i]);
    }
    free(nombres);
    free(buffer);
    return 0;
}
