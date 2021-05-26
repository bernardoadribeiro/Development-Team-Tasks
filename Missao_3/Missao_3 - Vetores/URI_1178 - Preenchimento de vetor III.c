#include <stdio.h>

int main(){
	
    double n[100],x;
    
    scanf(" %lf", &x);
	
	for(int i=0; i<100; i++){
		n[i] = x;
		printf("N[%d] = %.4lf\n", i, n[i]);
		x = x/2;
	}
    
    return 0;
}
