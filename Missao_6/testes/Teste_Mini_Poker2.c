#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

typedef struct{
	int num, naipe, status;
} Baralho;

typedef struct{
	int id, score, soma_cartas;
	int cartas_mao[4]; //armazena o indice das cartas
} Jogador;


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qtd_jogadores;
	printf("======================= Bem-vindo(a) ao MINI POKER =======================\n\n");
	printf("Quantas pessoas irão jogar? (Min=2, Max=10): ");
	scanf(" %d", &qtd_jogadores);
	if(qtd_jogadores<2 || qtd_jogadores>10){ 
		while(qtd_jogadores<2 || qtd_jogadores>10){
			printf("\nERROR! Para jogar é preciso ter no mínimo 2 jogadores e no máximo 10.\n");
			printf("Quantas pessoas irão jogar? (Min=2, Max=10): ");
			scanf(" %d", &qtd_jogadores);
		}
	}
	
	int qtd_cartas = qtd_jogadores*4;
	
	Baralho cartas[52];
	char naipes[4] = {'@', '#', '$', '&' };
	
	//Atribui cartas aos jogadores
	srand(time(NULL));
	Jogador jogadores[qtd_jogadores];
	for(int i=0; i<qtd_jogadores; i++){
		jogadores[i].id = i + 1;
		jogadores[i].score = 0;
		cartas[i].status = 0;
		
		//Distribui cartas::
		for(int j=0; j<4; j++){
			do{
				jogadores[i].mao[j] = rand() % 52;
				if(cartas[ jogadores[i].mao[j] ].estado == 0){
					cartas[ jogadores[i].mao[j] ].estado =1;
					break;
				}
			} while(1);
			jogadores[i].soma_cartas += cartas[jogadores[i].mao[j]].num;
		}
		
		//Ordena cartas [insertion]
		for(int j=1; j<4; j++){
			for(int k=j; k>0; k--){
				int indice_carta_Player = jogadores[i].map[k-1];
				int indice_carta_Player2 = jogadores[i].map[k];
				
				if(cartas[indice_carta_Player1].num > cartas[indice_carta_Player2].numero){
					int aux = jogadores[i].map[k];
					jogadores[i].map[k] = jogadores[i].map[k-1]; 
					jogadores[i].map[k] = aux;
				}
			}
		}
		
	}
	
	
	//Imprime cartas jogadores;
	for(int i=0; i<qtd_jogadores; i++){
		printf("ID Jogador: %d\n", jogadores[i].id);
		for(int j=0; j<4; j++){
			int indice_carta_Player = jogadores[i].mao[j]
			printf("[%d %c]", cartas[ indice_carta_Player ].numero, cartas[ indice_carta_Player ].naipe);
		}
		printf("\n\n");
	}
	
	
	
	//PONTUACAO DOS JOGADORES
	//num_Diferentes = 5;
	//naipes_Diferentes = 10;
	//sequencia = 15;
	//num_iguais = 20; //cartas_iguais
	
	int facesIguais=0, sequencia=0;
	for(int i=0; i < qtd_jogadores; i++){
		int indice_carta_Player1 = jogadores[i].map[i-1];
		int indice_carta_Player2 = jogadores[i].map[i];
		for(int j=0; j+1 < 4; j++){
			if(cartas[ indice_carta_Player1].num == cartas[ indice_carta_Player2 ].num )
				facesIguais++;
			
			if(cartas[ indice_carta_Player1].num != cartas[ indice_carta_Player2 ].num )
				sequencia++;
		}
		
		for(int j=0; j<4; j++){
			
		}
			
	}
	
	
	
	//IMPRIME QUADRO DE PONTUACAO
	for(int i=0; i<qtd_jogadores; i++){
		printf("\n ---==== RAKNING DE JOGADORES ====---\n")
		printf("ID Jogador:%d \nPontos:%d \nSomaCartas:%d %d", jogadores[i])
	}
	
	
	return 0;
}
