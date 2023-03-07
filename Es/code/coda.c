#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct node {
    char parentesi;
    struct node *next;
} Node;

int is_empty(struct node *head){
    if (head==NULL) return 1;
    else return 0;
}

void enqueue(struct node **head, struct node **tail, struct node *element){
    if(is_empty(*head))
        *head=element;
    else
      (*tail)->next=element;
    *tail=element;
    element->next=NULL;
}


struct node * dequeue(struct node **head, struct node **tail){
    struct node *ret=*head;
    if(is_empty(*head))
        return NULL;
    else
        *head=ret->next;
    if(*head==NULL)
        *tail=NULL;
    return ret;
}


void main(){
    t=0;

    for(t=0;t<720;t++){}

}