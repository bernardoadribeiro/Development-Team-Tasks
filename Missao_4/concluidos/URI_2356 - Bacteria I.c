#include <stdio.h>
#include <string.h>

int main(){
	char D[101], S[101];
	int OK;
	
	while(scanf(" %s", D) != EOF){
		scanf(" %s", S);
		
		for(int i=0; i<strlen(D); i++){
			if((D[i]=='A') || (D[i]=='C')||  (D[i]=='G') || (D[i]=='T'))
				OK = 1;
			else OK=0;
		}
		
		for(int i=0; i<strlen(S); i++){
			if((S[i]=='A') || (S[i]=='C')||  (S[i]=='G') || (S[i]=='T'))
				OK = 1;
			else OK=0;
		}
		
		if(OK){
			if(strstr(D, S)){ //Se verdade retorna 1, se nao, retorna 0 
				printf("Resistente\n");
				} else printf("Nao resistente\n");
		}
	}	
	return 0;
}
