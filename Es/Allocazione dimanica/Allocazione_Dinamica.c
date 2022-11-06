#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    //allocazione statica
    int b[10]; 

    //allocazione dinamica
    //fare sempre il casting a puntatore quando si usa la malloc (int*) altrimenti malloc ritorna void
    int *a, n;
    n=f();//funzione che trova la grandezza dell'array
    a=(int*)malloc(n*sizeof(int));
    //uso a

    free(a);//libero a
    //se dimentico di fare il free si verifica un "memory leak", cioè parte della ram rimane occupata e non ci posso più accedere
}