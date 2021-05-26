#include <stdio.h>

int main(){
	
	int num, testes,result = 0; 
	 
	scanf(" %d", &testes);
	
	for (int j=1; j<=testes; j++) {
		scanf(" %d", &num); 
			
		result = 0;
			
		if (num== 0 || num ==1){
			printf("%d nao eh primo\n", num);
		} 
			
		if(num > 1){						  
			for (int i = 2; i <= num / 2; i++){ 	
				if (num % i == 0) {
				   result++;
				}
			}
				 
				
			if (result == 0) {
				printf("%d eh primo\n", num);
			} else {
				printf("%d nao eh primo\n", num);
			  }
			
		}
	}	
	return 0;
}
