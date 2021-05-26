#include <stdio.h>
#include <string.h>

int main() {
	char str1[1002],str2[1002];
	int N;
  
	scanf(" %d",&N);
	for(int j=0; j<N; j++){
		scanf(" %s",str1);
		scanf(" %s",str2);
		
		int tam1 = strlen(str1);
		int tam2 = strlen(str2);
		int k = tam1, encaixa=0;
		
		for(int i=0; i<tam2; i++){
			if(str1[tam1-i] == str2[tam2-i]){
				encaixa++;
					if(encaixa==tam2)
						printf("encaixa\n");
				} else {
					printf("nao encaixa\n");
					break;
				  }
				  
			k--;
		}
	}
	
  return 0;
}
