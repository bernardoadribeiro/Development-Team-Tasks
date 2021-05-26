#include <stdio.h>

int main(){
	
	int N, pos, menor=1000;
	
	scanf(" %d", &N);
	int X[N];
	
	if (N>1 && N<1000){
		for(int i=0; i<N; i++){
			scanf(" %d", &X[i]);
			
			if (X[i] < menor){
				menor = X[i];
				pos = i;
			}
		}
		
		printf("Menor valor: %d\n", menor);
		printf("Posicao: %d\n", pos);
	}
	
	return 0;
}
