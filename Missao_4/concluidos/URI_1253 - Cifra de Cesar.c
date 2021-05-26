#include <stdio.h>
#include <string.h>

int main(){
	
	char palavra[52], decodificada[52];
	int N, desloca;
	
	scanf(" %d", &N);
	
	for(int j=1; j<=N; j++){
		scanf(" %[^\n]s", palavra);
		scanf(" %d", &desloca);
	
		int tam = strlen(palavra);
		for(int i=0; i<tam; i++){
			if(palavra[i]-desloca<65){
				printf("%c", palavra[i] - desloca + 26);
				strcpy(decodificada, palavra);
			} else
				printf("%c", palavra[i] - desloca);
		}
		printf("\n");
	}
	return 0;
}
