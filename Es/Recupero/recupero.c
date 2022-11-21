#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 1024 //costante per la lunchezza della riga


typedef struct caratteristiche{
    char* tipo_dato;
    char* nome;
    int dato;
}Caratteristiche;

int contarighe(int *alt){  //funzione che legge il numero di righe e di persone alte
    int cont=0, altezza;
    FILE *fp;
    char *cc =(char*)malloc(LUNG*sizeof (char));
    fp=fopen("dati_4AROB_TPSIT RECUPERO.csv", "r");
    if(fp==NULL){
        printf("errore nell'apertura del file");
    }else{
        while(!feof(fp)){
            fgets(cc, LUNG, fp);
                strtok(cc,";"); // prende la parte della riga che non ci serve
                if(strcmp(strtok(NULL, ";"), "altezza")==0){ //controlla se il tipo del dato è l'altezza
                    strtok(NULL, ";");// prende la parte della riga che non ci serve
                    if(atoi(strtok(NULL,";"))>=190){//controlla se l'altezza rientra nel parametro 
                        *alt=*alt+1;
                    }
                }else{//se il tipo non è altezza finisce di leggere la riga ma non memorizza i dati
                    strtok(NULL, ";");
                    atoi(strtok(NULL,";"));
                }
            cont ++;
        }
    }
    fclose(fp);
    free(cc);
    return cont;
}


void caricarisultati(Caratteristiche *classe, int cont){
    char *riga; 
    riga=(char*)malloc(100*sizeof(char)); 
    Caratteristiche *rig=classe;
    FILE *fp;
    fp=fopen("dati_4AROB_TPSIT RECUPERO.csv", "r");
    if(fp==NULL){
        printf("errore nell'apertura del file");
    }else{
        while(!feof(fp)){
                fgets(riga, LUNG, fp);
                strtok(riga,";");
                *(rig)->tipo_dato=strtok(NULL, ";");
                *(rig)->nome=strtok(NULL, ";");
                *(rig)->dato=atoi(strtok(NULL,";"));

                *rig++;
        }
    }
}

void salvaAlti(){}

void stampaclasse(Caratteristiche *classe, int cont){
    Caratteristiche* pos=classe; 
   for(classe=pos; classe<pos + cont; classe++){
        printf("%s, %s, %d\n", classe->tipo_dato, classe->nome, classe->dato);
   }
   classe=pos;
}

main(){
    Caratteristiche *classe, *alti;
    int alt;
    int cont=contarighe(&alt); // conta le righe e utilizza &alt per restituire il numero di persone alte
    classe=(Caratteristiche*)malloc(cont*sizeof(Caratteristiche));
    caricarisultati(classe, cont);
    free(classe);
}