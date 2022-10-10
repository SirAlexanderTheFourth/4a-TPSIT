#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    int a[3] = {1,2,3};
    int i;
    int *p;
    p=a;
    //da terza
    for(i=0; i<3; i++){ printf("%d", a[i]);}
    //da inizio quarta
    for(i=0; i<3; i++){printf("%d", *(a+i));}
    //da quarta
    for(p=a;p<a+3;p++){printf("%d", *p);}
}