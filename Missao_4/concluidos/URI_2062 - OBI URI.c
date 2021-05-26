#include <stdio.h>
#include <string.h>

int main(){
	int n=0, tam;
	
	scanf(" %d", &n);
	char palavra[n][21]; 
	
	for(int i=0; i<n; i++)
		scanf(" %s", palavra[i]);
	
	
	for(int i=0; i<n; i++){
		tam = strlen(palavra[i]);
		
		if(tam==3 && (palavra[i][2]!='I' && ((palavra[i][0]=='O' && palavra[i][1]=='B') || (palavra[i][0]=='U' && palavra[i][1]=='R')))){
			palavra[i][2] = 'I';
			if(i==n-1)
				printf("%s\n", palavra[i]);
				else
					printf("%s ", palavra[i]);
		} else
			if(i==n-1)
				printf("%s\n", palavra[i]);
				else
					printf("%s ", palavra[i]);
	}
	
	return 0;
}
