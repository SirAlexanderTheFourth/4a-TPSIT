/*crea  una  lista e la  stampa*/
#include  <stdio.h>
#include  <stdlib.h>
typedef struct  node 
{
    int  valore;
    struct  node* next;
}Node;

void stampalista(Node* lista){
    Node *l;
    l=lista;
    printf("numeri  inseriti: ");
    while (l!=NULL)
    {
        printf("\n%d - %p ",l->valore, l->next);
        l=l->next;
    }
}

/*
void printList(Node* l){
    printf("\n%d - %p ",l->valore, l->next);
    if(l->next!=NULL){
        printlist(l->next)
    }
}

int N_Nodes(Node* l){
    if(l!=NULL)
}
*/

void insertHEAD(struct node** head, int new_valore){
    struct node* new_testa =(struct node*)malloc(sizeof(struct node));

    new_testa->valore = new_valore;//carico il buovo valore nel node nuovo
    new_testa->next=(*head);//il next punterà alla testa attuale
    (*head)=new_testa;//assegno la nuova testa

}

int  lunchezzalista(Node* lista){
    Node* l;
    l=lista;
    int cont = 0;
     while (l!=NULL){
         l=l->next;
         cont ++;
     }

     return cont;
}
int  main()
{
    int n;
    Node* lista;
    Node* l;
    lista=NULL;
    int cont=0;
    do
    {
        printf("Inserisci  un  naturale o  -1 per  terminare\n");
        scanf("%d",&n);
        if (n>=0) 
        {
            if (lista==NULL) /*  prima  iterazione  */ 
            {
                lista = (Node*)  malloc(sizeof(Node));
                l = lista;
            }
            else /*  iterazioni  successive  */
            {
                l->next = (Node*)  malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
            
        }
    } while (n>=0);
    l=lista;
    stampalista(l);
    printf("\n");
    printf("\nelementi nella lista: %d", lunchezzalista(l));
    return  0;
    }