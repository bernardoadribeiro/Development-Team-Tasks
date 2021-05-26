#include <stdio.h>
#include <string.h>

int main() {

	int nCasos,inicio,fim;
	//char sequencia[10000];
	
	scanf(" %d", &nCasos);
	
	for (int i=0; i<nCasos; i++){
		scanf(" %d", &inicio);
		scanf(" %d", &fim);
		if(fim<10){
			for(int j=inicio; j<=fim; j++){
				printf("%d", j%10);
			}
			for(int j=fim; j>=inicio; j--){
				printf("%.1d", j%10);
			}
			
	
		} else if (inicio>=10 && fim<99){
			for(int j=inicio; j<=fim; j++){
				printf("%d", j/10);
				printf("%d", j%10);
			}
			for(int j=fim; j>=inicio; j--){
				printf("%d", j%10);
				printf("%d", j/10);
			}			
		}
		else {
			for(int j=inicio; j<=fim; j++){
				printf("%d", j/10);
				printf("%d", j/10);
				printf("%d", j/10);
				printf("%d", j%10);
				
			}
			printf("\n");
			for(int j=fim; j>=inicio; j--){
				printf("%.1d", j/10);
				printf("%.1d", j%10);
				printf("%d", j/10);
				printf("%d", j/10);
				
			}
			}
			
		
	}

	return 0; 
}
