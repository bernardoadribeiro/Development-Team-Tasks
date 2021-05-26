#include <stdio.h>
#include <string.h>

int main(){
	int T; 				//T=numero de instancias
	char frase[102], fraseTimeA[102], fraseTimeB[102];
	
	scanf(" %d", &T);
	
	int resultado[T];
	
	for(int j=0; j<T; j++){
		scanf(" %[^\n]s", frase);
		scanf(" %[^\n]s", fraseTimeA);
		scanf(" %[^\n]s", fraseTimeB);
		
		int tamFrase=strlen(frase), scoreTimeA=0, scoreTimeB=0; //, tamA=strlen(fraseTimeA), tamB=strlen(fraseTimeB);
	
		for(int i=0; i<=tamFrase; i++){
			if(fraseTimeA[i] == frase[i])
				scoreTimeA++;
			if(fraseTimeB[i] == frase[i])
				scoreTimeB++;
		}
		
		if(scoreTimeA>scoreTimeB)
			resultado[j] = 1;
			 else if(scoreTimeB>scoreTimeA)
				resultado[j] = 2;
				else if(scoreTimeA==scoreTimeB)
					resultado[j] = 0;
	}
		
	for (int j=0; j<T; j++){
		printf("Instancia %d\n", j+1);
		if(resultado[j] == 1)
			printf("time 1\n");
			 else if(resultado[j] == 2)
				printf("time 2\n");
				else if(resultado[j] == 0)
					printf("empate\n");
		
		printf("\n");
	}
	

	return 0;
}
