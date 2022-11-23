#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p; 
    int *p1 = 0;
    int i = 10;
    int a = 10;
    *&i;
    p = &a;
    *p = 20;
    printf("\n%d", p1);
    p1 = p1+1;
    printf("\n%d", p1);
}
