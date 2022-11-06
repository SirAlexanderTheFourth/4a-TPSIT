#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
procedere all'ordinamento di un array di interi utilizzando 
l'algoritmo di bubble sort senza l'utilizzo di partentesi quadre 
(ad esclusione della dichiarazione dell'array)
*/

#define MAX 10



void bubbleSort(int *d, int n){
	int k, sup;
	int scam;
	for (sup = n-1; sup > 0; sup--){
		for (k = 0; k < sup ; k++){
			if (*(d+k) > *(d+(k+1)))
                scam = *(d+k);
	            *(d+k) = *(d+(k+1));
	            *(d+(k+1)) = scam;
		}
	}
}

void caricavett(int *d,int k){
	for(int a = 0; a < k; a++){
		*(d+a) = rand()%MAX;
	}
}
void stampavett(int *d,int k){
	printf("Vettore: ");
	for(int a = 0; a < k; a++){
		printf("%d ",*(d+a));
	}
	printf("\n");
}

int main(){
	srand(time(NULL));
	int a;
	printf("Inserisci la dimensione del vettore: ");
	scanf("%d",&a);
	int *d = (int*)malloc(a*sizeof(int));
	caricavett(d,a); //carico il vettore con numeri casuali
	stampavett(d,a);
	bubbleSort(d,a);
	stampavett(d,a);
	free(d);
	return 0;
}