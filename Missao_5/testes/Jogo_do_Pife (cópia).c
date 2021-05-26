#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, ("Portuguese"));
    srand(time(NULL));
    
    int cartas[3][3]; 
    
    for(int i=0;i<3;i++)
		for(int k=0;k<3;k++)
			cartas[i][k]= rand() % 14;
    
    
    int trincasFormada[4], cartasMesa[3][3], primeiroMatch=0, trocaFeita=0, contTrinca=0, troca;

    for(int i=0; i<4;i++)	
		trincasFormada[i]=0;
    
    while(1){
		for(int k=0;k<3;k++){		//ORDENA AS CARTAS
			for(int i=0; i<3; i++){
				int menor = i;
				for(int j=i+1; j<3; j++)
					if(cartas[k][j] < cartas[k][menor])
						menor = j;
				int t = cartas[k][menor];
				cartas[k][menor] = cartas[k][i];
				cartas[k][i] = t;
			}
		}
		
		for(int i=0;i<3;i++){		//IMPRESSAO DAS CARTAS	
			for(int k=0;k<3;k++)
				printf("%d ", cartas[i][k]);
				
			if(i==2)
				break;
			printf("|| ");
		}
		
		printf("\n\n");
		printf("Deseja trocar qual carta?\n");
		scanf(" %d", &troca);
		
		for(int i=0;i<3;i++){
			for(int k=0;k<3;k++){
				if(primeiroMatch==1){
					if(cartasMesa[i][k]==troca){
						cartasMesa[i][k]= rand() % 14;
						trocaFeita=1;
						printf("Carta %d substituída pela %d\n", troca, cartasMesa[i][k]);
						break;
					}
					
				} else {
					if(cartas[i][k]==troca){
						cartas[i][k]= rand() % 14;
						trocaFeita=1;
						printf("Carta %d substituída pela %d\n", troca, cartas[i][k]);
						break;
					}
				  }
			}
			if(trocaFeita) break;
		}
		
		
		
		printf("\n trincas feitas: %d \n", contTrinca);
		if(contTrinca==3){
			printf("PARABÉNS! Você ganhou!");
			break;
		}
    }
    
    return 0;
}
