#include <stdio.h>


int main() {
 
	int num1,num2,soma=0, menor, maior;
	
	scanf(" %d", &num1);
	scanf(" %d", &num2);
	
	if (num1>num2){
		menor=num2;
		maior=num1;
	} else {
		menor=num1;
		maior=num2;
	}
	
	if(menor % 2 ==0){
		menor=menor+1;
		for (int i=menor;i<maior;i=i+2){
				soma=i+soma;
		}
	} 
	else{
		menor=menor+2;
		for (int i=menor;i<maior;i=i+2){
				soma=i+soma;
		}
	}
		
	printf("%d\n",soma);
    return 0;
}
