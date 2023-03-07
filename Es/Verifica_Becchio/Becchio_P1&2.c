#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


#define MAXN 10
#define MINN 1

typedef struct elemento{
    int numero_arrivo;
    int valore;
    struct elemento *next;
}Elemento;

int is_empty(Elemento* head){
    if(head == NULL) return 1;
    else return 0;
}

void enqueue(Elemento** head, Elemento** tail, Elemento* element){
    if(is_empty(*head))
        *head = element;
    else
        (*tail)->next = element;
    
    *tail = element;
    element->next = NULL;
}

Elemento* dequeue(Elemento** head, Elemento** tail){
    Elemento* ret = *head;

    if(is_empty(*head))
        return NULL;
    else
        *head = ret->next;
    
    if(*head == NULL)
        *tail = NULL;
    
    return ret;
}

struct Elemento * pop(struct Elemento **head){
    struct Elemento * ret=*head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

void push(struct Elemento **head, struct Elemento *element){
    if(is_empty(*head)){
        *head=element;
        element->next=NULL;
    }else{
        element->next=*head;
        *head=element;
    }
}

int Casuale(){
    int casuale;

    casuale = rand()%MAXN+MINN;
    
    return casuale;
}

int main(){
    srand(time(NULL)); 
    Elemento* current_head = NULL;       
    Elemento* current_tail = NULL; 
    Elemento* head_pila =NULL;

    Elemento* el_coda;
    Elemento* el_pila;

    for(int k=0; k<5; k++){
        el_coda=(Elemento*)malloc(sizeof(Elemento));
        el_coda->numero_arrivo=k+1;
        el_coda->valore=Casuale();
        enqueue(&current_head, &current_tail, el_coda);

        el_pila=(Elemento*)malloc(sizeof(Elemento));
        el_pila->numero_arrivo=k+1;
        el_pila->valore=Casuale();
        push(&head_pila, el_pila);
    }
}