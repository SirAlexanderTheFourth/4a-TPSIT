#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int arrivalTime;
    int serviceTime;
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

int main(){
    int t, maxQueueSize = 0;
    int arrivalTime = rand() % 4 + 1;
    int serviceTime = 0;
    int nextArrivalTime = arrivalTime;
    int waitTime = 0;
    int maxWaitTime = 0;
    struct node *head = NULL;
    struct node *tail = NULL;
    struct node *current = NULL;
    for(t = 0; t < 720; t++){
        if(t == nextArrivalTime){
            current = (struct node*) malloc(sizeof(struct node));
            current->arrivalTime = arrivalTime;
            enqueue(&head, &tail, current);
            if(maxQueueSize < (t-arrivalTime))
                maxQueueSize = (t-arrivalTime);
            serviceTime = rand() % 4 + 1;
            nextArrivalTime = t + rand() % 4 + 1;
        }
        if(t == serviceTime){
            current = dequeue(&head, &tail);
            if(current != NULL){
                current->serviceTime = serviceTime;
                if(maxWaitTime < (t-arrivalTime))
                    maxWaitTime = (t-arrivalTime);
                waitTime = rand() % 4 + 1;
            }
        }
    }
    printf("Numero massimo di clienti in coda: %d\n", maxQueueSize);
    printf("Attesa piu' lunga sperimentata dai clienti: %d\n", maxWaitTime);
    return 0;
}