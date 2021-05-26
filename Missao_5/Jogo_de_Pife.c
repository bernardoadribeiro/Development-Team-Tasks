#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, ("Portuguese"));
    srand(time(NULL));
    
    int cartas[3][5]; //aux[15];
    
    //INICIO - Distribuicao das cartas
    for(int i=0;i<3;i++){
	for(int k=0;k<3;k++){
	    int x = rand() % 14;
	    cartas[i][k]=x;
	    printf("%d ", cartas[i][k]);
	}
	if(i==2)
	    break;
	printf("|| ");
    }
    
    printf("\n");
    
    //SUBSTITUICAO E VERIFICACAO DAS CARTAS
    int troca;
    while(1){
	printf("Deseja trocar alguma carta?\n");
	scanf(" %d", &troca);
		
	int trocaFeita=0;
	for(int i=0; i<3; i++){
	    for(int j=0; j<3; j++){
		    if(cartas[i][j]==troca){
			cartas[i][j]= rand() % 14;
			trocaFeita=1;
			break;
		    }
	    }
	    if(trocaFeita)
		break;
	}
	
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
	    }
	}
	
	
	//VERIFICA AS CARTAS E TIRA CASO HAJA TRINCA
	
	
	
	//IMPRESSAO DAS CARTAS	
	for(int i=0;i<3;i++){
	    for(int k=0;k<3;k++){
		printf("%d ", cartas[i][k]);
	    }
	    if(i==2)
		break;
	    printf("|| ");
	}	
    }
    
    return 0;
}
