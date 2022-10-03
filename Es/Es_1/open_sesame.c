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
}classifica;

int main(){
    classifica classifica[MAX];
    FILE *fp;
    char riga[MAX];
    fp = fopen("vgsales.csv", "r");
    if(fp == NULL){
        printf("Errore nell'apertura del file");
    }else{
        int k=0;
        fgets(riga, MAX, fp);
        while(fgets(riga, MAX, fp)!=EOF){
        classifica[k].rank = atoi(strtok(riga, ","));
        classifica[k].name = strtok(NULL, ",");
        classifica[k].platform = strtok(NULL, ",");
        classifica[k].year = atoi(strtok(NULL, ","));
        classifica[k].genre = strtok(NULL, ",");
        classifica[k].publisher = strtok(NULL, ",");
        classifica[k].NA_Sales = atof(strtok(NULL, ","));
        classifica[k].EU_Sales = atof(strtok(NULL, ","));
        classifica[k].JP_Sales = atof(strtok(NULL, ","));
        classifica[k].Other_Sales = atof(strtok(NULL, ","));
        classifica[k].Global_Sales = atof(strtok(NULL, ","));

        printf("\n %d, %s, %s, %d, %s, %s, %.3f, %.3f, %.3f, %.3f, %.3f" , classifica[k].rank, classifica[k].name, classifica[k].platform, classifica[k].year, classifica[k].genre, classifica[k].publisher, classifica[k].NA_Sales, classifica[k].EU_Sales, classifica[k].JP_Sales, classifica[k].Other_Sales, classifica[k].Global_Sales);
        k++;
        }
    }

    fclose(fp);
    return 0;
}
