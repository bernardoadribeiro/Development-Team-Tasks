#include <stdio.h>
#include <string.h>

int main(){
	int T; 				//T=numero de instancias
	char frase[101], fraseTimeA[101], fraseTimeB[101];
	
	scanf(" %d", &T);
	
	int primeiroMatch=0, timeAprimeiro=0, timeBprimeiro=0; //resultado=0 
	
	
	for(int j=0; j<T; j++){
		fgets(frase, 101, stdin);
		fgets(fraseTimeA, 101, stdin);
		fgets(fraseTimeB, 101, stdin);
		
		if (j>=1 && j<T){
            printf("\n");
        }
		
		int scoreTimeA=0, scoreTimeB=0; //tamFrase=strlen(frase)
		primeiroMatch=0, timeAprimeiro=0, timeBprimeiro=0;  // resultado=0 
			
		for(int i=0; i<strlen(frase); i++){
			if(fraseTimeA[i] == frase[i])
				scoreTimeA++;
			if(fraseTimeB[i] == frase[i])
				scoreTimeB++;
					
			if((scoreTimeA > scoreTimeB) && (!primeiroMatch)){
				timeAprimeiro = 1, timeBprimeiro=0; 
				primeiroMatch=1;
					
			} else if((scoreTimeA < scoreTimeB) && (!primeiroMatch)){
					timeBprimeiro = 1, timeAprimeiro=0;
					primeiroMatch=1;
			  }
		}
			
		
			
		printf("Instancia %d\n", j+1);			
		if (scoreTimeA > scoreTimeB){
			printf("time 1\n");
		} else if (scoreTimeA < scoreTimeB){
			printf("time 2\n");
		} else if(timeAprimeiro && !timeBprimeiro){
			printf("time 1\n");
		} else if (!timeAprimeiro && timeBprimeiro){
			printf("time 2\n");
		} else{
			printf("empate\n");
		}
		

	}

	return 0;
}
