#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 1024
/*
- creare un file .csv con COGNOME,NOME, NASCITA (annomesegiorno assegno INT) <-fatto 
- scorrere il file con la funzione FGETS e STRTOK <-done
- stampare in ordine DECRESCENTE (dal più grande al più piccolo) utilizzando i puntatori e allocazione dinamica (MALLOC)
*/

typedef struct persona{ //creo la struttura
    char* cognome;
    char* nome;
    int data;
}Persona;

int contarighe(){  //funzione che legge il numero di righe nel file e restituisce il numero
    int cont=0;
    FILE *fp;
    char *cc =(char*)malloc(LUNG*sizeof (char));
    fp=fopen("date.csv", "r");
    if(fp==NULL){
        printf("errore nell'apertura del file");
    }else{
        while(!feof(fp)){
            fgets(cc, 1024, fp);
            cont ++;
        }
    }
    fclose(fp);
    free(cc);
    return cont;
}



void bubble(Persona *dati, int cont){ //riordina il vettore dati dalla persona più grande a quella più giovane
    Persona tmp; //variabile temporanea per scambiare le due variabili dati e (dati+1)
    Persona* p= dati; 
    for(int j=cont-1; j>0; j--){
        for(int k=0; k<j; k++){
            if(dati->data > (dati+1)->data){
                tmp= *(dati+1);
                *(dati+1)= *dati;
                *dati=tmp;
            }
            dati++;
        }
        dati=p;
    }

}

void stampa(Persona *dati, int cont){
   Persona* pos=dati; 
   printf("\nordinato:\n");
   for(dati=pos; dati<pos + cont; dati++){
       printf("%s, %s, %d\n", dati->cognome, dati->nome, dati->data);
   }
   dati=pos;
}

int main(){
    int dim=3;
    int cont;
    cont=contarighe(); 
    Persona *dati; //crea il puntatore di tipo Persona
    dati = (Persona*)malloc(cont*sizeof(Persona)); //alloca il numero di celle necessarie
    FILE *fp;
    Persona *rig=dati;
    char *riga; 
    riga=(char*)malloc(100*sizeof(char)); //crea e alloca la stringa 
    fp = fopen("date.csv", "r");
     if(fp == NULL){ //verifica se il file essite
        printf("Errore nell'apertura del file");
    }else{
        int k=0;
        printf("File:\n");
        while( fgets(riga, 300, fp)){
            (*rig).cognome=strdup(strtok(riga, ","));
            (*rig).nome=strdup(strtok(NULL, ","));
            (*rig).data=atoi(strtok(NULL, ","));
            printf("%s, %s, %d\n", rig->cognome, rig->nome, rig->data);
            

            *rig++;    
        }
        bubble(dati, cont);
        stampa(dati, cont);

    }
    free(dati);
    fclose(fp);
}