//
// Created by picha on 26/04/2022.
//
#include <stdio.h>
#define MAX 10
int capturaDatos(int arr[MAX], int tamanio);
int Buscar(int arr[MAX], int tamanio, int objetivo);
int main(){
int arreglo[MAX];
int tam, objetivo, posicion;

    printf("Tamanio:");
    scanf("%i", &tam);
    capturaDatos(arreglo, tam);
    printf("\n");
    printf("Objetivo: ");
    scanf("%i", &objetivo);
    posicion= Buscar(arreglo, tam, objetivo);
    printf("Salida: %i", posicion);
    return 0;
}
int capturaDatos(int arr[MAX], int tamanio){
    for(int i=0; i<tamanio; i++){
        printf("[%i]: ", i);
        scanf("%i", &arr[i]);
    }
    for(int i=0; i<tamanio; i++){
        printf("%i ", arr[i]);
    }
}
int Buscar(int arr[MAX], int tamanio, int objetivo){
    int pos=0;
    for(int i=0; i<tamanio; i++){
        if(objetivo==arr[i]){
            return i;
        }
        if(objetivo>arr[i]){
            pos++;
        }
    }
    return pos;
}

