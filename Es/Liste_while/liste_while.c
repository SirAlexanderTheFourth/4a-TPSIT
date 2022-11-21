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
    Node *cursore= (Node*)malloc(sizeof(Node));
    char r;
    do{
        printf("Inserisci un nome: ");
	    gets(lista->nome);
        temp->next=NULL;
    	lista->next = temp;
	    printf("Nome: %s",lista->nome);

        printf("aggiungere elementi a lista?    y/n");
        scanf("%c", r);
    }while(r!='n');

}