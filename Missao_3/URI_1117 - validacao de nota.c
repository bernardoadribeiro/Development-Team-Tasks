#include <stdio.h>
 
int main() {
	int nota1, nota2, validador, validador2;
	float media;
   
	validador = scanf(" %d", &nota1);
	
	if(validador==0 || nota1<0 || nota1>10){
		while(nota1>=0 || nota1<=10){
			printf("nota invalida\n");
			validador = scanf(" %d", &nota1);
			
			if(nota1>0 && nota1<10)
				break;
		}
		
	} else {
		validador2 = scanf(" %d", &nota2);
	
		if(validador2==0 || nota2<0 || nota2>10){
			while(nota2>=0 || nota2<=10){
				printf("nota invalida\n");
				validador2 = scanf(" %d", &nota2);
				
				if(nota2>0 && nota2<10)
					break;
			}
			
		}
	   }	
	
	media = (nota1+nota2)/2;
	
	printf("media = %.2f\n", media);
	
    return 0;
}

