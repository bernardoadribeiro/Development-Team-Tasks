#include <stdio.h>

int main(){
	int num1=0, num2=0, aux, result;
	
	while(num1>=0 && num2>=0){
		
		int num1, num2, aux, result = 0;
			
		scanf(" %d", &num1);
		scanf(" %d", &num2);
		
		if (num1<=0 || num2<=0){
			break;
		}
		
		if (num1>num2){
			aux = num2;
			num2 = num1;
			num1 = aux;
		} 
		
		for (int i=num1; i<=num2; i++){
			result = result+i;
			printf("%d ", i);
		}
		printf("Sum=%d\n", result);
		
	}
	return 0;
}
