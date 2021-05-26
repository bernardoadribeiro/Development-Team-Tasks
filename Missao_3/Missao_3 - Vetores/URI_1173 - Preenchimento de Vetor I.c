#include <stdio.h>

int main(){
	
    int n[10],v;
    
    scanf(" %d", &v);
	
	if(v<=50)
		for(int i=0; i<=9; i++){
			n[i] = v;
			printf("N[%d] = %d\n", i, n[i]);
			v *= 2;
		}
    
    return 0;
}
