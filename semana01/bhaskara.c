// Exercício 1036 do beecrowd

#include <stdio.h>
#include <math.h>
 
int main() {
    double a, b, c;
    scanf("%lf %lf %lf\n", &a, &b, &c);
    
    double delta, r1, r2;
    delta = (b*b) - (4*a*c);
    
    if(delta < 0 || a == 0) {
        printf("Impossivel calcular\n");
    }
    
    else {
        r1 = (-b + sqrt(delta)) / (2 * a);
        r2 = (-b - sqrt(delta)) / (2 * a);
        
        printf("R1 = %.5lf\n", r1);
        printf("R2 = %.5lf\n", r2);
    }
 
    return 0;
}