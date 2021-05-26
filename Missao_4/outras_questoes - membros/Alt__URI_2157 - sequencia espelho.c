#include <stdio.h>

int main (){

	int numero1, numero2, casos; //unsigned = sem sinal, short=curto  == numeros inteiros positvos curtos
	int aux, aux2;

	scanf("%d", &casos);

	while (casos--){

		scanf("%d %d", &numero1, &numero2);

		for (int i = numero1; i <= numero2; i++)
			printf("%d", i);


		for (int i = numero2; i >= numero1; i--){
			aux = i;
			
			while (aux){
				aux2 = aux%10;
				printf("%d", aux2);
				aux = aux/10;
			}

		}	

		printf("\n");
	}
}
