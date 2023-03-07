#include  <stdio.h>
#include  <stdlib.h>
typedef struct  node 
{
    int  valore;
    struct  node* next;
}Node;

void insert_ordered(Node **head, Node *element){
    Node*curr=*head, *prev=NULL;
    while(curr!=NULL){
        if (element->valore<=curr->valore){
            break;
        }
        prev=curr;
        curr=curr->next;
    }
    if(prev==NULL){
        *head=element;
    }else{
        prev->next=element;
    }
    element->next=curr;
}

void insertHEAD(struct node** head, int new_valore){
    struct node* new_testa =(struct node*)malloc(sizeof(struct node));

    new_testa->valore = new_valore;//carico il n2uovo valore nel node nuovo
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