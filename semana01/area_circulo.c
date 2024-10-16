// Exercício 1002 do beecrowd

#include <stdio.h>
 
int main() {
    double pi = 3.14159;
    double r;
    scanf("%lf\n", &r);
    
    double a;
    a = pi * r * r;
    printf("A=%.4lf\n", a);
 
    return 0;
}