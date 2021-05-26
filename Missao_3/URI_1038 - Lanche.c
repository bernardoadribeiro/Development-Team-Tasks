#include <stdio.h>

int main(){

	int cod, qtd;
	float valor_total;
	
	scanf(" %d", &cod);
	scanf(" %d", &qtd);
	
	if (cod == 1){
		valor_total = 4 * qtd; //Cachorro quente
		printf("Total: R$ %.2f\n", valor_total);
	} else if (cod == 2){
		valor_total = 4.50 * qtd; //x-salada
		printf("Total: R$ %.2f\n", valor_total);
		
	  } else if (cod == 3){
			valor_total = 5 * qtd; //x-bacon
			printf("Total: R$ %.2f\n", valor_total);
			
	    } else if (cod == 4){
			valor_total = 2 * qtd; //torrada simles
			printf("Total: R$ %.2f\n", valor_total);
			
		  } else if (cod == 5){
				valor_total = 1.50 * qtd; //refrigerante
				printf("Total: R$ %.2f\n", valor_total);
			}
	
	return 0;
}
