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


struct node * pop(struct node **head){
    struct node * ret=*head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

void push(struct node **head, struct node *element){
    if(is_empty(*head)){
        *head=element;
        element->next=NULL;
    }else{
        element->next=*head;
        *head=element;
    }
}

int main() {
    struct node *stack = NULL;
     char frase[100];
    printf("inserire frase: ");
    Scanf("%s", frase);
    int i;
    bool is_balanced =true;
    for (i = 0; i < strlen(frase); i++) {
        if (frase[i] == '(' || frase[i] == '[' || frase[i] == '{') {
            struct node *new_node = (struct node*) malloc(sizeof(struct node));
            new_node->parentesi = frase[i];
            new_node->next = NULL;
            push(&stack, new_node);
        } else if (frase[i] == ')' || frase[i] == ']' ||frase[i] == '}') {
            if (is_empty(stack)) {
                is_balanced = false;
                break;
            } else {
                struct node *top = pop(&stack);
                if((frase[i] == ')' && top->parentesi != '(') || (frase[i] == ']' && top->parentesi != '[') || (frase[i] == '}' && top->parentesi != '{')){
                    is_balanced = false;
                    break;
                }
            }
        }
    }
    if (is_balanced && is_empty(stack)) {
        printf("la stringa e' bilanciata.\n");
    } else {
        printf("Errore parentesi\n");
    }
    system("PAUSE");
}

