#include <stdio.h>
#include <string.h>

int main(){
	int n;
	
	scanf(" %d", &n);
	char ListaPokemon[n][101], pokemon[n][1001];
	
	for(int i=0; i<n; i++){
		scanf(" %s", ListaPokemon[i]);
		strcpy(pokemon[i],ListaPokemon[i]);
	}
	
	
	int contPokemon = 0, repetido=0; //verificador;
	
	for(int i=0; i<n; i++){
		contPokemon = 0, repetido=0;
		int tam = strlen(pokemon[i]);
		
		for(int j=0; j<n; j++){
			for(int k=0; k<tam; k++){
				
				if(pokemon[j][k] != ListaPokemon[j][k]){
					for(int k=0; k<n; n++){
						for(int l=0; l<tam; l++)
							if(pokemon[j][l] != ListaPokemon[0+k][l]){
								contPokemon++;
							} else {repetido++; break;}
					}
				} else {repetido++; break;}
				
				
			}
		}
		
	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	printf("Falta(m) %d pokemon(s).\n", 151-contPokemon);
	printf("repetido: %d.\n", repetido);
	printf("contPokemon: %d\n", contPokemon);


	for(int j=0; j<n; j++){
		for(int k=0; k<strlen(pokemon[j]); k++){
			printf("%c",pokemon[j][k]);
		}
		printf("\n");
	}
	printf("==============================================================\n");
	for(int j=0; j<n; j++){
		for(int k=0; k<strlen(pokemon[j]); k++){
			printf("%c",pokemon[j][k]);
		}
		printf("\n");
	}
	
	return 0;
}
