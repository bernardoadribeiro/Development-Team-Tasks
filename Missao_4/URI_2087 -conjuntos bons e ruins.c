#include <stdio.h>
#include <string.h>

int main() {
	int N;
	
	scanf(" %d", &N);
	char conjunto[N][102];
	
	for(int i=0; i<N; i++)
		scanf(" %s", conjunto[i]);
	
	int k=0, resp=0;
	for(int i=N; i>0; i--){
		k=0;
		if(strstr(conjunto[i],conjunto[i-k]) || strstr(conjunto[i-k],conjunto[i] ) ){
			resp=1; //conjunto ruim
			k++;
		} else resp=2; //conjunto bom
	}
	
	if(resp==1)
		printf("Conjunto ruim");
		else if(resp==2)
			printf("conjunto bom");

	return 0;
}
