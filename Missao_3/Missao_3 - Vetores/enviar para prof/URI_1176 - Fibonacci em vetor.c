#include <stdio.h>

int main(){
	
	int T, n;
	long long int fib[64];
	
	scanf(" %d", &T);
	
	fib[0] = 0;
	fib[1] = 1;
	
	for (int i=2; i<=64; i++)
		fib[i] = fib[i-1] + fib[i-2];
	
	for(int j=1; j<=T; j++){
		scanf(" %d", &n);
		printf("Fib(%d) = %lld\n",n,fib[n]);
	}
	
	return 0;
}
