#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	char linha1[61], linha2[61], cpf[13], valorStr[18], valorStr2[18];;
	int tam1, tam2;
	float valorFloat, valorFloat2, propina;
	
		scanf(" %s", linha1);
		scanf(" %s", linha2);
		
		tam1 = strlen(linha1);
		tam2 = strlen(linha2);
		
		int cont=0;
		while(linha1 !='\0'){   //concatenar as string, juntar as duas e formar uma só
			if(cont==11){
				if((linha1[i]>='0' && linha1[i]<='9') || linha1[i]=='.')
					valorStr[i] = linha1[i];
			} else if(linha1[i]>='0' && linha1[i]<='9')
				cpf[i] = linha1[i];
			
			cont++;
		}
		
		for(int i=0; i<tam2; i++){
			if((linha1[i]>='0' && linha1[i]<='9') || linha1[i]=='.')
				valorStr2[i] = linha2[i];
		}
		
		
		//printf("%s", valorStr);
		valorFloat = atof(valorStr);
		valorFloat2 = atof(valorStr2);
		
		propina = valorFloat + valorFloat2;
		
		printf("cpf %s\n", cpf);
		printf("%.2f\n", propina);
		
			
		
	return 0;
}
