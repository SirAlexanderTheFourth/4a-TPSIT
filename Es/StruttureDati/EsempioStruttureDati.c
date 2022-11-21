#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG 20

typedef struct node{
	char nome[LUNG];
	struct node *next; 
}Node;

int main(){
	Node *lista = (Node*)malloc(sizeof(Node));
	Node *temp = (Node*)malloc(sizeof(Node));
	printf("Inserisci un nome: ");
	gets(lista->nome);
	lista->next = NULL;
	printf("Nome: %s",lista->nome);

	printf("\nInserisci un nome: ");
	gets(temp->nome);
	temp->next=NULL;
	lista->next=temp;
	printf("\nNome temp:%s", lista->next->nome);

	printf("\nInserisci un nome: ");
	gets(temp->nome);
	temp->next=NULL;
	lista->next->next=temp;
	printf("\nNome temp:%s", lista->next->next->nome);
	
	free(lista);
	free(temp);
	return 0;
}