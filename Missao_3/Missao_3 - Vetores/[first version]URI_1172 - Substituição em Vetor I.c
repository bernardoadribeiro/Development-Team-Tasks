#include <stdio.h>

int main(){
	
	int X[10];
	
	for(int i=0; i<=9; i++){
		scanf(" %d", &X[i]);
		
		if(X[i] <= 0)
			X[i] = 1;
	}
	
	printf("X[0] = %d\n",X[0]);
	printf("X[1] = %d\n",X[1]);
	printf("X[2] = %d\n",X[2]);
	printf("X[3] = %d\n",X[3]);
	printf("X[4] = %d\n",X[4]);
	printf("X[5] = %d\n",X[5]);
	printf("X[6] = %d\n",X[6]);
	printf("X[7] = %d\n",X[7]);
	printf("X[8] = %d\n",X[8]);
	printf("X[9] = %d\n",X[9]);
	
	return 0;
}
