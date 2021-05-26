#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	
	char texto[51], textoFormatado[51];
	long long int saida;

	int valido = scanf("%[^\n]s", texto);
	
	int tam = strlen(texto), valor[];
	int k=0;
	for(int i=0, k=0; i<tam; i++){
		if(texto[0]=='0' && texto[1]){
			printf("0\n"); break; }
			
		
		if ((texto[0]=='-' || (texto[i]>='A' && texto[i]<='Z') || (texto[i]>='a' && texto[i]<='z') || texto[i]=='\0') && (texto[i]!='l' || texto[i]!='o' || texto[i]!=',' || texto[i]!=' ')){
			printf("error\n");
			return 0;
		}
			
			else if(texto[i]>='0' && texto[i]<='9'){
				//printf("%c", texto[i]);
				textoFormatado[k] = texto[i];

			} else if(texto[i]=='o' || texto[i]=='O'){
				texto[i]='0';
				//printf("%c", texto[i]);
				textoFormatado[k] = texto[i];
			
			} else if(texto[i]=='l'){
				texto[i]='1';
				//printf("%c", texto[i]);
				textoFormatado[k] = texto[i];
					
			} else if((valido==0)){
				printf("error\n");
				return 0;
			} else{
				textoFormatado[k] = texto[i];
			}
			k++;
	}
	
	for (int i=0, j=0; i < k; i++) {
            if (textoFormatado[i] >= '0' && textoFormatado[i] <='9') {
                valor[j] = textoFormatado[i];
                j++;
            }
	}
	saida = atoll(valor);
	
	if(saida> 2147483647LL)
		printf("error\n")
	
	printf("\n");
	
	return 0;
}

//if ((texto[0]=='-' || (texto[i]!='l' || texto[i]!='o' || texto[i]!=',' || texto[i]!=' ')) && (texto[i]<'0' && texto[i]>'9')){
