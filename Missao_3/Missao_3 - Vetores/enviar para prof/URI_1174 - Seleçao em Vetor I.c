#include <stdio.h>

int main(){
	
	float vetor[100];
	
	for(int i=0; i<=99; i++)
		scanf(" %f", &vetor[i]);
	
	for(int i=0; i<=99; i++){
	
		if (vetor[i] <= 10)
			printf("A[%i] = %.1f\n", i, vetor[i]);
	}
	
	return 0;
}
