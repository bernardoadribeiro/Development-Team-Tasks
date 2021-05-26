#include <stdio.h>

int main(){
	
	int num, neg=0, pos=0, impar=0, par=0;
	
	for (int i=1; i<=5; i++){
		scanf(" %d", &num);
		
		if (num<0)
			neg++;
			
			else if(num>0)
				pos++;
				
		if (num % 2 == 0)
			par++;
			else
				impar++;
	
	}
	
	printf("%d valor(es) par(es)\n", par);
	printf("%d valor(es) impar(es)\n", impar);
	printf("%d valor(es) positivo(s)\n", pos);
	printf("%d valor(es) negativo(s)\n", neg);
	
	return 0;
}
