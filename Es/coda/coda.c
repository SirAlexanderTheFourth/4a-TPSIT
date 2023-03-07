#include <stdio.h>
#include <stdlib.h>

#define DIM 10

typedef struct node {
    char nome[DIM];
    int data;
    struct node *next;
} Node;


void insertHEAD(struct node** head, int new_valore){
    struct node* new_testa =(struct node*)malloc(sizeof(struct node));

    new_testa->data = new_valore;//carico il n2uovo valore nel node nuovo
    new_testa->next=(*head);//il next punterà alla testa attuale
    (*head)=new_testa;//assegno la nuova testa

}

void add_tail(struct node** head, int data) {
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
    return;
  }
  struct node* current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

void deleteElementsList(Node *head) {
    for (int i = 0; i < 5; i++)
    {
        head = head->next;
    }
    Node *tmp = head;
    freeList(tmp);
}

main(){

}