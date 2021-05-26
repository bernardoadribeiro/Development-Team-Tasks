#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, ("Portuguese"));
    srand(time(NULL));
    int cartas[3][3]; //aux[15];
    
    //INICIO - Distribuicao das cartas
    for(int i=0;i<3;i++)
		for(int k=0;k<3;k++)
			cartas[i][k]= rand() % 14;
    
    
    int trincaFormada[4], cartasMesa[3][3], primeiroMatch=0;
    int trocaFeita=0, contTrinca=0, troca; 
    for(int i=0; i<4;i++)	
		trincaFormada[i]=0;
    //SUBSTITUICAO E VERIFICACAO DAS CARTAS
    while(1){
		int menor, maior, cartaMaior, cartaMenor ;
		//ORDENA AS CARTAS
		for(int k=0;k<3-contTrinca;k++){
			if(k)
				printf("|| ");
				
			for(int i=0; i<3-contTrinca; i++){
				menor = maior = i;
				for(int j=i+1; j<3; j++){
					if(cartas[k][j] < cartas[k][menor])
						menor = j;
					if(cartas[k][j] > cartas[k][maior])
						maior = j;
				}
						
				int t = cartas[k][menor];
				cartas[k][menor] = cartas[k][i];
				cartas[k][i] = t;
				
				cartaMaior = cartas[k][maior];
				cartaMenor = cartas[k][menor];
				
				if(primeiroMatch==1){
					if(trincaFormada[k]!=1){
						cartasMesa[k][i] = cartas[k][i];
						printf("%d ", cartasMesa[k][i]);
					}
				} else printf("%d ", cartas[k][i]);
			}
			
		}
		
		
		printf("\n");
		printf("Deseja trocar alguma carta?\n");
		scanf(" %d", &troca);
		
		if(troca>cartaMaior || troca<cartaMenor){
			printf("Carta não encontrada.\n");
		}
		else{
			for(int i=0; i<3-contTrinca; i++){
				for(int j=0; j<3; j++){
					if(primeiroMatch==0){
						if(cartas[i][j]==troca){
							cartas[i][j]= rand() % 14;
							trocaFeita=1;
							printf("Carta %d substituída pela %d\n\n", troca, cartas[i][j]);
							break;
						}
					} else{
						if(cartasMesa[i][j]==troca){
							cartasMesa[i][j]= rand() % 14;
							trocaFeita=1;
							printf("Carta %d substituída pela %d\n\n", troca, cartasMesa[i][j]);
							break;
						}
					  }
					
					//VERIFICA AS CARTAS E TIRA CASO HAJA TRINCA
					if(primeiroMatch==0){
						if(((cartas[i][j] == cartas[i][j+1]-1) && (cartas[i][j] == cartas[i][j+2]-2)) || ((cartas[i][j] == cartas[i][j+1]) && (cartas[i][j] == cartas[i][j+2]))){
							contTrinca++;
							trincaFormada[i] = 1;
							primeiroMatch=1;
							
						}
					} else {
						if(((cartasMesa[i][j] == cartasMesa[i][j+1]-1) && (cartasMesa[i][j] == cartasMesa[i][j+2]-2)) || ((cartasMesa[i][j] == cartasMesa[i][j+1]) && (cartasMesa[i][j] == cartasMesa[i][j+2]))){
							contTrinca++;
							trincaFormada[i] = 1;
							primeiroMatch=1;
							
						}
					  }
				}
				if(trocaFeita)
					break;
			}
			printf("\n %d \n", contTrinca);
			if(contTrinca==3){
				printf("PARABÉNS! Você ganhou!");
				break;
			}
		}
    }
    
    return 0;
}
