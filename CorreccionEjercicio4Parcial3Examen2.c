//
// Created by picha on 27/04/2022.
//
#include <stdio.h>
#define MAX 10

typedef struct cola{
    int datos[MAX + 1];
    int inicio;
    int fin;
}Cola;

void inicializaCola(Cola *c);
int estaVacia(Cola cola);
int estaLlena(Cola cola);
int insertar(Cola *c, int valor);
int eliminar(Cola *c, int *v);
void algoritmo_examen(Cola *c1, Cola *c2);
void imprimir(Cola c);

int main()
{
    Cola cola2;
    Cola cola1;
    int r;

    inicializaCola(&cola1);
    r = estaVacia(cola1);

    printf("Valor de r: %d", r);
//Insertar en la cola 1
    r = insertar(&cola1, 2);
    r = insertar(&cola1, 3);
    r = insertar(&cola1, 9);
//Insertar en la cola 2
    r = insertar(&cola2, 1);
    r = insertar(&cola2, 4);
    r = insertar(&cola2, 8);
    r = insertar(&cola2, 9);
    algoritmo_examen(&cola1, &cola2);

    return 0;
}
void imprimir(Cola c){
    for (int i = 0; i<MAX+1;i++){
        printf("El valor es: %d ",c.datos[i]);

    }
}
void algoritmo_examen(Cola *c1, Cola *c2)
{
    int valor1, valor2;
    int contador = 0;

    while (contador < 3)
    {
        if (eliminar(c1, &valor1) == 1){
            if(valor1 % 2 == 0)
                insertar(c2, valor1);
            else
                insertar(c1, valor1);
        }

        if (eliminar(c2, &valor2) == 1)
        {
            if (valor2 % 2 != 0)
                insertar(c1, valor2);
            else
                insertar(c2, valor2);
        }
        contador++;

        printf("\n");
        imprimir(*c1);
        printf("\n");
        imprimir(*c2);
    }
}

int eliminar(Cola *c, int *v)
{
    int r = 0;
    if (estaVacia(*c)== 0){
        *v = c->datos[c->inicio];
        // *v = (c*).datos[(*c).inicio];

        c->inicio = (c->inicio + 1) % (MAX + 1);
        r = 1;
    }
    return r;
}

int insertar(Cola *c, int valor)
{
    int r = 0;

    if (estaLlena(*c) == 0)  //hay espacio para insertar, la cola no esta llena
    {
        //Poner el valor dentro del arreglo en la posicion que dice fin
        c->datos[c->fin] = valor;
        c->fin++;

        if(c->fin == MAX+1)   // Incremento el valor de fin
            c->fin=0;


        r = 1;
    }

    return r;
}

int estaLlena(Cola cola){
    if (cola.inicio == cola.fin -1 || (cola.inicio == 0 && cola.fin == MAX))
        return 1;

    return 0;
}

int estaVacia(Cola cola)
{
    int r=0;

    if(cola.inicio == cola.fin)
    {
        r=1;
    }
    return r;
}

void inicializaCola(Cola *c)
{
    c->inicio = 0;
    c->fin = 0;
}
