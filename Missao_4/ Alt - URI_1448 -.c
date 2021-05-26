#include <stdio.h>
#include <string.h>

int main(){
	int T; 				//T=numero de instancias
	char frase[102], fraseTimeA[102], fraseTimeB[102];
	
	scanf(" %d", &T);
	
	int resultado, desempate=0, primeiroMatch=0;
	
	for(int j=0; j<T; j++){
		scanf(" %[^\n]s", frase);
		scanf(" %[^\n]s", fraseTimeA);
		scanf(" %[^\n]s", fraseTimeB);
		
		int tamFrase=strlen(frase), scoreTimeA=0, scoreTimeB=0; 
		desempate=0, primeiroMatch=0, resultado=0;
		
		for(int i=0; i<tamFrase; i++){
			if(fraseTimeA[i] == frase[i])
				scoreTimeA++;
			if(fraseTimeB[i] == frase[i])
				scoreTimeB++;
				
			if(fraseTimeA[i] == frase[i] && fraseTimeB[i] != frase[i] && primeiroMatch==0)
				desempate = 1, primeiroMatch=1;
				
			if(fraseTimeB[i] == frase[i] && fraseTimeA[i] != frase[i] && primeiroMatch==0)
				desempate = 2, primeiroMatch=2;
				
		}
		
		if(scoreTimeA>scoreTimeB)
			resultado = 1;
			 else if(scoreTimeB>scoreTimeA)
				resultado = 2;
				else if(scoreTimeA==scoreTimeB){
					if(desempate==1)
						resultado = 1;
						else if(desempate==2)
							resultado = 2;
							else resultado = 0;
				}
				
		printf("Instancia %d\n", j+1);
		if(resultado == 1)
			printf("time 1\n");
			 else if(resultado == 2)
				printf("time 2\n");
				else printf("empate\n");
				
		printf("\n");
	}

	return 0;
}
