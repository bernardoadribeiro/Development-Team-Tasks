#include <stdio.h>

int main(){
	
	int num, impar[4], par[4], contPar=0, contImpar=0;
	
	for(int i=1; i<=15; i++){
		scanf(" %d", &num);
		
		if (num % 2 == 0){
			par[contPar] = num;
			contPar++;
		} else {
			impar[contImpar] = num;
			contImpar++;
		  }
		
		
		if(contPar==5){
			for(int j=0; j<=4; j++)
				printf("par[%d] = %d\n", j,par[j]);
			contPar=0;
			
		} else if(contImpar==5){
			for(int k=0; k<=4; k++)
				printf("impar[%d] = %d\n", k, impar[k]);
			contImpar=0;
		  }
		
	}
	
	for(int k=0; k<=contImpar; k++)
		printf("impar[%d] = %d\n", k, impar[k]);
	
	for(int j=0; j<=contImpar; j++)
		printf("par[%d] = %d\n", j, par[j]);
	
	return 0;
}
