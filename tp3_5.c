#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int len, cant;
    printf("Ingrese la cantidad de nombres que quiere quiere ingresar: ");
    scanf("%d", &cant);

    char **nombres = (char **)malloc(sizeof(char *) * cant), *buffer;
    buffer = (char *)malloc(100*sizeof(char));

    for (int i = 0; i < cant; i++){
        printf("Ingrese un nombre: ");
        fflush(stdin);
        gets(buffer);
        len = strlen(buffer);
        nombres[i] = (char *)malloc(sizeof(char)*(len+1));
        strcpy(nombres[i], buffer);
    }

    for (int i = 0; i < cant; i++){
        printf("Nombre %d: ", i+1); 
        puts(nombres[i]);
    }

    for (int i = 0; i < cant; i++){
        free(nombres[i]);
    }
    free(nombres);
    free(buffer);
    return 0;
}
