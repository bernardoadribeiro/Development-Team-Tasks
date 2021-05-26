#include <stdio.h>


int main(){
	
	int valor, cedula100, cedula50, cedula20, cedula10, cedula5, cedula2, cedula1,  novo_valor;
	
	scanf(" %d", &valor);
	
	cedula100 = valor/100;	
	novo_valor = valor - (cedula100*100);
	
	cedula50 = novo_valor/50;
	novo_valor = novo_valor - (cedula50*50);
	
	cedula20 = novo_valor/20;	
	novo_valor = novo_valor - (cedula20*20);
	
	cedula10 = novo_valor/10;	
	novo_valor = novo_valor - (cedula10*10);
	
	cedula5 = novo_valor/5;	
	novo_valor = novo_valor - (cedula5*5);
	
	cedula2 = novo_valor/2;	
	novo_valor = novo_valor - (cedula2*2);
	
	cedula1 = novo_valor/1;	
	novo_valor = novo_valor - (cedula1*1);
	
	printf("%d\n", valor);
	printf("%d nota(s) de R$100,00\n", cedula100);
	printf("%d nota(s) de R$50,00\n", cedula50);
	printf("%d nota(s) de R$20,00\n", cedula20);
	printf("%d nota(s) de R$10,00\n", cedula10);
	printf("%d nota(s) de R$5,00\n", cedula5);
	printf("%d nota(s) de R$2,00\n", cedula2);
	printf("%d nota(s) de R$1,00\n", cedula1);
	
	return 0 ;
}
