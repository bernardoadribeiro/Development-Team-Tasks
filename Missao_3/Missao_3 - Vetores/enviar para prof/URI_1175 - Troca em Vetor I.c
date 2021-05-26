#include <stdio.h>

int main(){
	int N[20],a;
	
	for(int i=0;i<20;i++)
		scanf(" %d",&N[i]);
		
	for(int i=0;i<10;i++){
		int MAX=19-i;
		
		a=N[i];
		N[i]=N[MAX];
		N[MAX]=a;
	}
	
	for(int i=0;i<20;i++)
		printf("N[%d] = %d\n",i,N[i]);
			
	return 0;
}
