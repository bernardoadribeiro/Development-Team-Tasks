#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int N[1000], t;
	
	scanf(" %d", &t);
	
	for(int i=0; i<1000; i++){
		N[i] = (i%t);
	}
		
	for(int i=0;i<1000;i++){
		printf("N[%d] = %d\n", i, N[i]);
	}
		
	return 0;
}
