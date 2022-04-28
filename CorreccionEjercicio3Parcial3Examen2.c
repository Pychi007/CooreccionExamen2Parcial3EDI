//
// Created by picha on 27/04/2022.
//
#include <stdio.h>
#include <string.h>
int solicitarnombres(char nombres[4][50]);
int solicitarPromedio(int promedio[4], int aux[4]);
void burbuja(int arreglo[4]);

int main() {
    char arregloBi[4][50];
    int promedios[4];
    int aux[4];

    solicitarnombres(arregloBi);
    solicitarPromedio(promedios, aux);
    burbuja(promedios);
    for (int i = 3; i >= 0; i--) {
        printf("%i ", promedios[i]);
    }
    printf("\n");
    for (int j = 0; j < 4; j++) {
        for (int i = 3; i >= 0; i--) {
            if (promedios[i] == aux[j]){
                printf("%s\n", arregloBi[i+1]);
            }
        }
    }
}
int solicitarnombres(char nombres[4][50]){
    for (int i=0; i<4; i++)
    {
        printf("Nombre[%d]: ", i);
        scanf("%s", &nombres[i][50]);
    }
    return 0;
}
int solicitarPromedio(int promedio[4], int aux[4]){
    for (int i=0; i<4; i++){
        printf("Promedio %d: ", i);
        scanf("%i", &promedio[i]);
        aux[i]=promedio[i];
    }
}
void burbuja(int arreglo[4]){
    int aux;
    int actual;
    for(int i=0; i<4; i++){
        for(actual=0;actual<4-1;actual++){
            if(arreglo[actual]>arreglo[actual+1]){
                aux=arreglo[actual];
                arreglo[actual]=arreglo[actual+1];
                arreglo[actual+1]=aux;
            }
        }
    }
}