#include "nodo.h"
#include <stdio.h>
#include <stdlib.h>

/* Ejercicio 1 */
Nodo* crearNodo(int valor){
    Nodo *n = (Nodo*)malloc(sizeof(Nodo));
    if(n!=NULL){
    n->dato = valor;
    n->siguiente = NULL;
    }
    return n;
}

/* Ejercicio 2 */
Nodo* crearArregloNodos(int n){
    Nodo *arreglo = (Nodo*)calloc(n, sizeof(Nodo));
    return arreglo;
}

/* Ejercicio 3 */
Nodo* agregarNodo(Nodo* arreglo, int* n, int valor){
    Nodo *newNode = (Nodo*)realloc(arreglo, (*n+1)*sizeof(Nodo));
    if(newNode!=NULL){
        newNode[*n].dato=valor;
        newNode[*n].siguiente=NULL;
        (*n)++;
        return newNode;
    }
    return arreglo;
}

/* Ejercicio 4 */
void liberarNodos(Nodo* arreglo, int n){
    if(!n) return;
    free(arreglo);
    arreglo=NULL;
}

/* Ejercicio 5 */
Nodo* construirTresNodos(){
    Nodo *n1= crearNodo(1);
    Nodo *n2= crearNodo(2);
    Nodo *n3= crearNodo(3);
    if(n1!=NULL && n2!=NULL && n3!=NULL){
        n1->siguiente = n2;
        n2->siguiente = n3;
        n3->siguiente = NULL;
        return n1;
    }
    return NULL;
}

/* Ejercicio 6 */
int contarNodos(Nodo* inicio){
    int contador=0;
    Nodo *actual=inicio;
    while(actual!=NULL){
        contador++;
        actual=actual->siguiente;
    }
    return contador;
}

/* Ejercicio 7 */
Nodo* crearNodosPorEntrada(){
    int n, valor;
    printf("Cuántos nodos desea crear?");
    scanf("%d", &n);
    Nodo *inicio=NULL, *actual=NULL;
    for(int i=0; i<n; i++){
        printf("Ingrese el valor del nodo %d: ", i + 1);
        scanf("%d", &valor);
        Nodo *newNode = crearNodo(valor);
        if(newNode!=NULL){
            if(inicio==NULL){
                inicio=newNode;
                actual=inicio;
            }else{
                actual->siguiente=newNode;
                actual=actual->siguiente;
            }
        }
    }
    return inicio;
}
