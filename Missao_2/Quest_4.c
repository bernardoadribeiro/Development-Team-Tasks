/*Faça um programa que receba um número informado pelo usuário e imprima a informação se este
número é um primo ou não. 
* Lembre-se que um número é primo se for divisível apenas por 1 e
próprio. 
* O programa deve testar vários números, e só encerra quando o usuário informar um valor
negativo. 
* */


#include <stdio.h>

int main(){
	
	int i, num, resto;

	
		printf("Digite um número");
		scanf("%d", &num);
		
		resto = num % 7;
		
		if (resto != 0) {
			printf("O número %d é primo", num);				
			} else {
				printf("Este número NÃO é primo");
				}
			
		printf("Encerrar programa? (-1 = sim  | 2 = não)");
		scanf("%d", &i);
	

}
