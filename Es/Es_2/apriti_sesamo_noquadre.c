#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

typedef struct classifica{
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
    Classifica classifica[MAX];
    FILE *fp;
    Classifica *rig=classifica;
    char riga[MAX];
    fp = fopen("vgsales.csv", "r");
    if(fp == NULL){
        printf("Errore nell'apertura del file");
    }else{
        int k=0;
        fgets(riga, MAX, fp);
        while(!feof(fp)){
        fgets(riga, MAX, fp);
        (*rig).rank = atoi(strtok(riga, ","));
        (*rig).name = strtok(NULL, ",");
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
        *rig++;
        }
    }

    fclose(fp);
    system("PAUSE");
    return 0;
    //prova
}
