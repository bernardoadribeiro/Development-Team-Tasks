#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>



int main(){
	setlocale(LC_ALL, "Portuguese"); //para aceitar acentuação e Ç
	srand(time(NULL)); //Altera a semente de geracao de nums aleatorios
	
	printf("---------------------------------------\n");
	printf("---------- JOGO DA MEMÓRIA ------------\n");
	printf("---------------------------------------\n");
	printf("Informe quantas palavras desejar (Máximo 30).\nPara finalizar, informe a palavra 'fim'.\n");
	
	
	char palavra[32], cartas[60][32], backupCartas[60][32], cartasAbertas[60][32];
	int qtdCartas=0; //embaralhador[30];
	
	//scaneia e duplica as cartas
	for(int i=0; i<30; i+=2){
		scanf(" %s", palavra);
		
		if(!strstr(palavra, "fim")){
			strcpy(cartas[i], palavra);
			strcpy(cartas[i+1], palavra);
			strcpy(backupCartas[i], palavra);
			strcpy(backupCartas[i+1], palavra);
			qtdCartas+=2;
		} else
			break;
	}
	
	
	system("clear"); //limpa tela
	
	
	//Embaralhador de cartas
	/*
	for(int i=0; i<qtdCartas; i++){
		int x = rand() % qtdCartas+1;
		embaralhador[i] = x;
		
		for(int j=0; j<qtdCartas; j++){
			if(embaralhador[j] == x){
				x = rand()%qtdCartas+1;
				embaralhador[i] = x;
				strcpy(cartas[x], backupCartas[i]);
				
			}
		}
		printf("x=%d\n", x);
	}
	*/
	
	//print cartas - para testes
	for(int i=0; i<qtdCartas; i++){
		printf("%.2d %s\n", i, cartas[i]);
	}
	printf("Qtd. cartas: %d", qtdCartas);
	
	
	
	//Inicio do jogo - escolher cartas.
	int escolha1=0, escolha2=0, jogadas=0, primeiroMatch=0;
	while(1){
		for(int i=0; i<qtdCartas; i++){
			printf("%.2d: [%s]\n", i, cartasAbertas[i]);
		}
		printf("Escolha sua carta 1: ");
		scanf(" %d", &escolha1);
		
		system("clear");
		
		//Escolhas
		for(int i=0; i<qtdCartas; i++){
			if(i==escolha1){
				printf("%.2d: [%s]\n", escolha1,cartas[escolha1]);
			} else printf("%.2d: [%s]\n", i, cartasAbertas[i]);
		}
			
		printf("Escolha sua carta 2: ");
		scanf(" %d", &escolha2);
		if((cartas[escolha1] == cartasAbertas[escolha1]) || (cartas[escolha1] == cartasAbertas[escolha2]) || 
		  ((cartas[escolha2] == cartasAbertas[escolha1]) || (cartas[escolha2] == cartasAbertas[escolha2]))){
			printf("Escolha de Cartas INVALIDA!");
			setbuf(stdin, NULL);
			getchar();
			system("clear");
		}
		else if(escolha1==escolha2){
			printf("As cartas escolhidas devem ser DIFERENTES!");
			setbuf(stdin, NULL);
			getchar();
			system("clear");
			
		} else {
			system("clear");
			
			for(int i=0; i<qtdCartas; i++){
				if(i==escolha1){
					printf("%.2d: [%s]\n", i,cartas[i]);					
				} 
				else if(i==escolha2){
					printf("%.2d: [%s]\n", i,cartas[i]);
				} else printf("%.2d: [%s]\n", i, cartasAbertas[i]);
			}
			
			//verifica cartas
			if(strstr(cartas[escolha1],cartas[escolha2])){
				printf("PAR ENCONTRADO!\n");
				jogadas++;
				setbuf(stdin, NULL);
				getchar();
				system("clear");
				
				strcpy(cartasAbertas[escolha1], cartas[escolha1]);
				strcpy(cartasAbertas[escolha2], cartas[escolha2]);
				primeiroMatch=1;
				
			} else{
				printf("Tente novamente...\n");
				jogadas++;
				setbuf(stdin, NULL);
				getchar();
				system("clear");
			}
		}
		
	}
	
	
	return 0;
}
