#include <stdio.h>

int main(){
	
	int num[15], impar[5], par[5], contPar=0, contImpar=0;
	
	for(int i=0; i<=14; i++){
		scanf(" %d", &num[i]);
	}
	
	for(int i=0; i<=14; i++){
		if (num[i] % 2 == 0){
			par[contPar] = num[i];
			contPar++;
			
			if(contPar==5){
				for(int j=0; j<=4; j++)
				printf("par[%d] = %d\n", j,par[j]);
				contPar=0;
			}
			
		} else {
			impar[contImpar] = num[i];
			contImpar++;
			
			if(contImpar==5){
				for(int k=0; k<=4; k++)
				printf("impar[%d] = %d\n", k, impar[k]);
				contImpar=0;
			}
		  }
	}
		
	for(int k=0; k<contImpar; k++)
		printf("impar[%d] = %d\n", k, impar[k]);
	
	for(int j=0; j<contPar; j++)
		printf("par[%d] = %d\n", j, par[j]);
	
	return 0;
}
