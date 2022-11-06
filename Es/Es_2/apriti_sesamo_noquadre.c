#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

typedef struct classifica{ //creo la struttura
    int rank;
    char* name;
    char* platform;
    int year;
    char* genre;
    char* publisher;
    float NA_Sales;
    float EU_Sales;
    float JP_Sales;
    float Other_Sales;
    float Global_Sales;
}Classifica;

int main(){

    Classifica *rig;
    rig=(Classifica*)malloc(16599*sizeof(Classifica)); //creo la variabile rig di tipo classifica
    FILE *fp;
    char *riga;
    riga=(char*)malloc(MAX*sizeof(char)); //creo la stringa della riga
    fp = fopen("vgsales.csv", "r");
    if(fp == NULL){ //controllo esistenza file
        printf("Errore nell'apertura del file");
    }else{
        int k=0;
        fgets(riga, MAX, fp); //tolgo prima riga
        while(!feof(fp)){ //ciclo fino alla fine del file
        fgets(riga, MAX, fp);
        (*rig).rank = atoi(strtok(riga, ",")); //parto dall'inizio della stringa riga e arrivo fino a ,
        (*rig).name = strtok(NULL, ","); // parto dal punto precendente e arrivo fino alla , succesiva
        (*rig).platform = strtok(NULL, ",");
        (*rig).year = atoi(strtok(NULL, ","));
        (*rig).genre = strtok(NULL, ",");
        (*rig).publisher = strtok(NULL, ",");
        (*rig).NA_Sales = atof(strtok(NULL, ","));
        (*rig).EU_Sales = atof(strtok(NULL, ","));
        (*rig).JP_Sales = atof(strtok(NULL, ","));
        (*rig).Other_Sales = atof(strtok(NULL, ","));
        (*rig).Global_Sales = atof(strtok(NULL, ","));


        printf("\n %d, %s, %s, %d, %s, %s, %.3f, %.3f, %.3f, %.3f, %.3f" , (*rig).rank, (*rig).name, (*rig).platform, (*rig).year, (*rig).genre, (*rig).publisher, (*rig).NA_Sales, (*rig).EU_Sales, (*rig).JP_Sales, (*rig).Other_Sales, (*rig).Global_Sales);
        *rig++; //incremento puntatore
        }
        
    }
    free(rig); //libero la memoria occupata dalla variabile
    fclose(fp); //chiudo il file
    system("PAUSE");
    return 0;
    //prova
}
