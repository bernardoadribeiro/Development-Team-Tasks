#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, ("Portuguese"));
    srand(time(NULL));
    
    int cartas[3][3];
    
    //INICIO - Distribuicao das cartas
    for(int i=0;i<3;i++)
	for(int k=0;k<3;k++)
	    cartas[i][k]= rand() % 14;
    
    //SUBSTITUICAO E VERIFICACAO DAS CARTAS
    int troca, trocaFeita=0, contTrinca=0, trincas[3], numTrinca[3], match=0;
    while(1){
	//ORDENA AS CARTAS
	for(int k=0;k<3;k++){
	    for(int i=0; i<3; i++){
		int menor = i;
		for(int j=i+1; j<3; j++)
		    if(cartas[k][j] < cartas[k][menor])
			menor = j;
		int t = cartas[k][menor];
		cartas[k][menor] = cartas[k][i];
		cartas[k][i] = t;
		
		printf("%d ", cartas[k][i]);
	    }
	    if(k!=2)
		printf("|| ");
	}
	
	printf("\n");
	printf("Deseja trocar qual carta?\n");
	scanf(" %d", &troca);
	
	for(int i=0; i<3; i++){
	    for(int j=0; j<3; j++){
		if(cartas[i][j]==troca){
			cartas[i][j]= rand() % 14;
			trocaFeita=1;
			printf("Carta %d substituída pela %d\n", troca, cartas[i][j]);
			//break;
		}
		
		//VERIFICA AS CARTAS E TIRA CASO HAJA TRINCA
		if(((cartas[i][j] == cartas[i][j+1]-1) && (cartas[i][j] == cartas[i][j+2]-2)) || ((cartas[i][j] == cartas[i][j+1]) && (cartas[i][j] == cartas[i][j+2]))){
		    contTrinca++;
		    numTrinca[i]=i
		}
		
		if()
		
	    }
	    if(trocaFeita)
		    break;
	}
	
	if(contTrinca==3){
		printf("PARABÉNS! Você ganhou!");
		break;
	}
    }
    
    return 0;
}

