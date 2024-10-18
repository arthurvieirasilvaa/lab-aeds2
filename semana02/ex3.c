#include <stdio.h>
#include <stdlib.h>

void frac(float num, int *inteiro , float *frac) {
    *inteiro = (int) num;
    *frac = num - *inteiro;
}

int main() {
    float num = 38.2;
    int inteiro;
    float fraci;
    
    frac(num, &inteiro, &fraci);
    printf("Parte inteira: %d\n", inteiro);
    printf("Parte fracionária: %f\n", fraci);
    
    return 0;

}