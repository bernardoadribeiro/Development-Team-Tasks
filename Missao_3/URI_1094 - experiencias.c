#include <stdio.h>

int main(){
	int n;
	float  quantia, totalCobaias, percentualCoelho, percentualRato, percentualSapo, coelho, rato, sapo;
	char tipo;
	
	scanf(" %d", &n);
	
	for(int i=1; i<=n; i++){
		scanf(" %f", &quantia);
		scanf(" %c", &tipo);
		
		if (quantia>=1 && quantia<=15){
			if (tipo == 'C')
				coelho = coelho + quantia;
			
				else if (tipo == 'R')
					rato = rato + quantia;
			
					else if (tipo == 'S')
						sapo = sapo + quantia;	
		}
		
		totalCobaias = coelho + rato + sapo;
	}
	
		percentualCoelho = coelho*100/totalCobaias;
		percentualRato = rato*100/totalCobaias;
		percentualSapo = sapo*100/totalCobaias;
		
		printf("Total: %.0f cobaias\n", totalCobaias);
		printf("Total de coelhos: %.0f\n", coelho);
		printf("Total de ratos: %.0f\n", rato);
		printf("Total de sapos: %.0f\n", sapo);
		printf("Percentual de coelhos: %.2f %%\n", percentualCoelho);
		printf("Percentual de ratos: %.2f %%\n", percentualRato);
		printf("Percentual de sapos: %.2f %%\n", percentualSapo);

	
	return 0;
}
