/*crea  una  lista e la  stampa*/
#include  <stdio.h>
#include  <stdlib.h>
typedef struct  node 
{
    int  valore;
    struct  node* next;
}Node;

void insertHEAD(struct node** head, int new_valore){
    struct node* new_testa =(struct node*)malloc(sizeof(struct node));

    new_testa->valore = new_valore;//carico il buovo valore nel node nuovo
    new_testa->next=(*head);//il next punterà alla testa attuale
    (*head)=new_testa;//assegno la nuova testa

}

int  main()
{
    Node* head=(Node*) malloc(3*sizeof(Node));
    for(int i=0;i<3;i++){
        insertHEAD(&head, i+1);
    }
    for(int i=0;i<3;i++){
        printf("%d", head->valore);
        head=head->next;
    }
    return  0;
    }