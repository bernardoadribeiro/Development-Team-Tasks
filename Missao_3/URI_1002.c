#include <stdio.h>

int main() {
 
    double raio, area, PI = 3.14159;
    
    scanf("%lf", &raio);
    
    area = PI * (raio*raio);
    
    printf("A=%.4f\n", area);
    
    return 0;
}
