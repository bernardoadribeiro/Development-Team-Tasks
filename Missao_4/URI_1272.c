#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	
	int num,j, tam, cont=0, soEspaco=0;;
	char frase[50];
	
	scanf(" %d", &num);
	
	while (num > cont){
		
		scanf(" %[^\n]s", frase);
		tam = strlen(frase);
		
		j=0, soEspaco=0;
		
		for (int i=0;i<tam;i++){
		
			if (frase[i] == ' ')
				i++;
			if (!(frase[i] == ' ')){
				printf("%c",frase[i]);
					while ((frase[i+1] != ' ') && (i<tam)){
						i++;
					}	
				j++;
			}
			
			if(frase[i]==' '){
				int k=0;
				while(k<tam){
					if(frase[k]==' '){
						soEspaco++;
					}
				}
				if(soEspaco==tam){
					printf(" \n");
				}
			}
		}
		cont++;
		
		printf("\n");
	}
	
	
	return 0;
}
