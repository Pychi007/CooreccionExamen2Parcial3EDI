//
// Created by picha on 26/04/2022.
//
#include <stdio.h>
#include <string.h>
#define MAX 20
char imprimeArreglo(char arr[MAX], int tamanio);
void invierteArreglo(char arr[MAX], int tamanio, int pos);
int main(){
    char arreglo[MAX];
    int tam;

    printf("Escriba la frase: ");
    scanf("%s", &arreglo);
    tam= strlen(arreglo);
    imprimeArreglo(arreglo,tam);
    printf("\n");
    invierteArreglo(arreglo, tam,0);
    printf("La palabra volteada es: ");
    imprimeArreglo(arreglo,tam);
}
char imprimeArreglo(char arr[MAX], int tamanio){
    for(int i=0; i<tamanio; i++){
        printf("%c", arr[i]);
    }
}
void invierteArreglo(char arr[MAX], int tamanio, int pos){
    char aux;
    if(tamanio!=pos){
        aux=arr[pos];
        arr[pos]=arr[tamanio-1];
        arr[tamanio-1]=aux;
        invierteArreglo(arr, tamanio-1,pos+1);
    }
}
