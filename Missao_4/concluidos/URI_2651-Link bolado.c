#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	int linkBolado=0;
	char nome[100000];
	
	scanf(" %s", nome);
	
	int tam1 = strlen(nome);
	
	
	for(int i=0; i<tam1; i++)
		nome[i] = tolower(nome[i]);
	
	for(int i=0; i<tam1; i++){
		if(nome[i]=='z' && nome[i+1]=='e' && nome[i+2]=='l' && nome[i+3]=='d' && nome[i+4]=='a')
			linkBolado = 1;
	}
	
	
	if(linkBolado != 0){
			printf("Link Bolado\n");
		} else printf("Link Tranquilo\n");

	return 0;
}
