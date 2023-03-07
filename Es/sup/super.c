#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
/*
12.15 (Simulazione di un supermercato) Scrivete un programma che simuli una fila alla cassa di un 
supermercato. La fila è una coda. I clienti arriveranno casualmente in intervalli interi compresi tra 1 e 
4 minuti. Anche i clienti saranno serviti in modo casuale a intervalli interi compresi tra 1 e 4 minuti. 
Ovviamente, i ritmi dovranno essere bilanciati. La coda crescerà all'infinito qualora il ritmo degli arrivi 
sia superiore a quello del servizio. Nonostante i ritmi bilanciati, il caso potrebbe causare delle lunghe 
code. Eseguite la simulazione del supermercato per una giornata lavorativa di 12 ore (72() minuti), 
usando il seguente algoritmo: 
1) Scegliete un intero casuale compreso tra 1 e 4, per determinare il minuto in cui arriverà il primo 
cliente. 
2) Nel momento in cui arriva il primo cliente: 
Determinate il tempo di servizio del cliente (un intero casuale compreso tra 1 e 4); 
Cominciate a servire il cliente; 
Stabilite il tempo di arrivo del prossimo cliente (un intero casuale compreso tra 1 e 4 aggiunto al 
tempo corrente). 
3) Per ogni minuto del giorno: 
Qualora arrivi il cliente successivo: 
Mettete il cliente nella coda; 
Stabilite il tempo di arrivo del prossimo cliente; 
Nel caso in cui sia stato completato il servizio per l'ultimo cliente: 
Comunicatelo 
Togliete dalla coda il prossimo cliente da servire 
Determinate il tempo di completamento del servizio per il cliente (ovverosia, 
un intero casuale da I a 4 aggiunto al tempo corrente). 
Eseguite ora la vostra simulazione e ponetevi le seguenti questioni: 
a) Qual è stato il numero massimo di clienti in coda durante tutta la simulazione? 
b) Qual è stata l'attesa più lunga tra quelle sperimentate dai clienti? 
c) Che cosa succederebbe se l'intervallo di arrivo, compreso tra 1 e 4 minuti, fosse cambiato in uno 
compreso tra 1 e 3 minuti? 

*/

#define MAXN 4 //minuti max per cliente
#define MINN 1 //minuti min per cliente
#define GLAVORATIVA 720 // minuti

typedef struct cliente{
    int nCliente;
    int tempo;
    struct cliente *next;
}Cliente;

int is_empty(Cliente* head){
    if(head == NULL) return 1;
    else return 0;
}

void enqueue(Cliente** head, Cliente** tail, Cliente* element){
    if(is_empty(*head))
        *head = element;
    else
        (*tail)->next = element;
    
    *tail = element;
    element->next = NULL;
}

Cliente* dequeue(Cliente** head, Cliente** tail){
    Cliente* ret = *head;

    if(is_empty(*head))
        return NULL;
    else
        *head = ret->next;
    
    if(*head == NULL)
        *tail = NULL;
    
    return ret;
}

int Casuale(){
    int casuale;

    casuale = rand()%MAXN+MINN;
    
    return casuale;
}


int main(){
    srand(time(NULL)); 
    //coda dei clienti da servire
    Cliente* current_head = NULL;       
    Cliente* current_tail = NULL; 

    int tempoTraClienti = 4; //tempo tra i clienti
    int numCliente = 0; //tiene conto dei clienti
    
    Cliente* cliente;
    Cliente* clienteUscito;

    //per 720 minuti
    for(int k = GLAVORATIVA; k >= 0; k--){
        tempoTraClienti--;

        if(tempoTraClienti == 0){
            cliente = (Cliente*)malloc(sizeof(Cliente));
            numCliente++;
            cliente->nCliente = numCliente;
            cliente->tempo = Casuale();
            cliente->next = NULL;
            printf("al minuto %d e' entrato %d\n", k, numCliente);
            enqueue(&current_head, &current_tail, cliente);
            tempoTraClienti = Casuale();
        }

        if(!is_empty(current_head)) {
            current_head->tempo--;
            if( current_head->tempo == 0){
                clienteUscito = dequeue(&current_head, &current_tail);
                printf("Il cliente %d e' uscito al minuto %d\n", clienteUscito->nCliente, k); 
                free(clienteUscito);
            }
        }   

    }
}