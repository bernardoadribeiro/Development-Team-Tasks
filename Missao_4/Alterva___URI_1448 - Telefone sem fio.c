#include <stdio.h>
#include <string.h>

int main(){
	int T, primeiroMatch, scoreTimeA=0, scoreTimeB=0; 				//T=numero de instancias
	char frase[102], fraseTimeA[102], fraseTimeB[102];
	
	scanf(" %d", &T);
	
	int resultado[T];
	
	for(int j=0; j<T; j++){
		primeiroMatch=0, scoreTimeA=0, scoreTimeB=0;
		
		scanf(" %[^\n]s", frase);
		scanf(" %[^\n]s", fraseTimeA);
		scanf(" %[^\n]s", fraseTimeB);
		
		int tamFrase=strlen(frase);
		
		//verifica as frases
		for(int i=0; i<=tamFrase; i++){
			if(fraseTimeA[i] == frase[i])
				scoreTimeA += 1;
			
			if(fraseTimeB[i] == frase[i])
				scoreTimeB += 1;
			
			if(fraseTimeA[i] == fraseTimeB[i]){
				resultado[i] = 0; //empate A e B iguais
				break;
			}
			
			//desempatador
			if(scoreTimeA>scoreTimeB && primeiroMatch==0)
				primeiroMatch = 1;
			if(scoreTimeB>scoreTimeA && primeiroMatch==0)
				primeiroMatch = 2;
				
		} //fim do verifcador das frases
		
		if(scoreTimeA==scoreTimeB)
			resultado[j] = 3;
		if(scoreTimeA>scoreTimeB)
			resultado[j] = 1;
		if(scoreTimeB>scoreTimeA)
			resultado[j] = 2;
					
	}//fim do laço principal
	
	for(int i=0; i<T; i++){
		printf("Instancia %d\n", i+1);
		//if(resultado[i]==0)
			//printf("empate\n");
			
		if(resultado[i]==1)
			printf("time 1\n");
			
		if(resultado[i]==2)
			printf("time 2\n");
			
		if(resultado[i]==3){
			if(primeiroMatch==1)
				printf("time 1\n");
				
				else if(primeiroMatch==2)
					printf("time 2\n");
					else printf("empate\n");
		}
	}
	printf("primeiro match: %d", primeiroMatch);
	return 0;
}
