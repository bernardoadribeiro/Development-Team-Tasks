#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <unistd.h> //para usar função sleep

typedef struct{
	int num, naipe, status;
} Baralho;

typedef struct{
	int id, score, soma_Cartas, cartas_mao[4]; //cartas_mao armazena o indice das cartas
	
} Jogador;


int main(){
	printf("Olá, antes iniciar, MAXIMIZE a janela do terminal para que o programa exiba as cartas corretamente.\n");
	printf("\nPressione 'Enter' para continuar.");
	setbuf(stdin, NULL);
	getchar();
	system("clear");
	
	
	setlocale(LC_ALL, "Portuguese");
	
	int qtd_jogadores;
	printf("============================== Bem-vindo(a) ao MINI POKER ===================================\n\n");
	printf("Quantas pessoas irão jogar? (Min=2, Max=10): ");
	scanf(" %d", &qtd_jogadores);
	if(qtd_jogadores<2 || qtd_jogadores>10){ 
		while(qtd_jogadores<2 || qtd_jogadores>10){
			printf("\nERROR! Para jogar é preciso ter no mínimo 2 jogadores e no máximo 10.\n");
			printf("Quantas pessoas irão jogar? (Min=2, Max=10): ");
			scanf(" %d", &qtd_jogadores);
		}
	}
	
	//INICIALIZA BARALHO -----
	Baralho cartas[52];
	
	for(int i=0; i<13; i++){ //naipe 0
		cartas[i].num = i+1;
		cartas[i].naipe = 0;
		cartas[i].status = 0;
	}
	
	for(int i=13; i<26; i++){ //naipe 1
		cartas[i].num = (i+1)-13;
		cartas[i].naipe = 1;
		cartas[i].status = 0;
	}
	
	for(int i=26; i<39; i++){ //naipe 2
		cartas[i].num = (i+1)-26;
		cartas[i].naipe = 2;
		cartas[i].status = 0;
	}
	
	for(int i=39; i<52; i++){ //naipe 3
		cartas[i].num = (i+1)-39;
		cartas[i].naipe = 3;
		cartas[i].status = 0;
	}
	
	//DISTRIBUI CARTAS AOS JOGADORES
	srand(time(NULL));
	Jogador jogadores[qtd_jogadores];
	//char naipes[4] = {'@', '#', '$', '&' };
	char naipes[4][4] = {"♥", "♦", "♣", "♠" };
	
	for(int i = 0; i < qtd_jogadores; i++){
		jogadores[i].id = i + 1;
		jogadores[i].score = 0;
		jogadores[i].soma_Cartas = 0;
		
		//Distribui cartas
		for(int j = 0; j < 4; j++){
			while(1){
				jogadores[i].cartas_mao[j] = rand()%52;
				if(cartas[ jogadores[i].cartas_mao[j] ].status == 0){
					cartas[ jogadores[i].cartas_mao[j] ].status = 1;
					break;
				}
			}
			jogadores[i].soma_Cartas += cartas[ jogadores[i].cartas_mao[j] ].num; //soma dos valores das cartas para o desempate;
		}
		
		//Ordena cartas 
		for(int j=0; j<4;j++){
			for(int k=0; k<4-1; k++){
				if(cartas[ jogadores[i].cartas_mao[k] ].num > cartas[ jogadores[i].cartas_mao[j] ].num){
					int aux = jogadores[i].cartas_mao[k];
					jogadores[i].cartas_mao[k] = jogadores[i].cartas_mao[j];
					jogadores[i].cartas_mao[j] = aux;
				}
			}
		}
		
	}  
	
	//IMPRIME CARTAS DOS JOGADORES
	printf("\n\n================================= CARTAS DOS JOGADORES ======================================\n\n");
	for(int i = 0; i < qtd_jogadores; i++){
		printf("\n\n=============================================================================================\n");
		printf("\nJogador %d: \n", jogadores[i].id);
		//for(int j = 0; j < 4; j++){
			int j=0;
			int ind_cartaJogador = jogadores[i].cartas_mao[j];
			int ind2_cartaJogador = jogadores[i].cartas_mao[j+1];
			int ind3_cartaJogador = jogadores[i].cartas_mao[j+2];
			int ind4_cartaJogador = jogadores[i].cartas_mao[j+3];
			//printf("[%d %s] ", );
			printf(" ________________	 ________________	 ________________	 ________________\n ");
			printf("|   	  	|	|   	  	|	|   	  	|	|   	  	|\n ");
			printf("| %d%s\t   	|	| %d%s\t   	|	| %d%s\t   	|	| %d%s\t   	|\n ", cartas[ ind_cartaJogador ].num, naipes[ cartas[ ind_cartaJogador ].naipe ], cartas[ ind2_cartaJogador ].num, naipes[ cartas[ ind2_cartaJogador ].naipe ], cartas[ ind3_cartaJogador ].num, naipes[ cartas[ ind3_cartaJogador ].naipe ], cartas[ ind4_cartaJogador ].num, naipes[ cartas[ ind4_cartaJogador ].naipe ]);
			printf("|         	|	|         	|	|         	|	|         	|\n ");
			printf("|   	   	|	|   	   	|	|   	   	|	|   	   	|\n ");
			printf("|     	%s\t|	|     	%s\t|	|     	%s\t|	|     	 %s\t|\n ", naipes[ cartas[ ind_cartaJogador ].naipe ], naipes[ cartas[ ind2_cartaJogador ].naipe ], naipes[ cartas[ ind3_cartaJogador ].naipe ], naipes[ cartas[ ind4_cartaJogador ].naipe ]);
			printf("|         	|	|         	|	|         	|	|         	|\n ");
			printf("|         	|	|         	|	|         	|	|         	|\n ");
			printf("|	  %d%s	|	|	  %d%s	|	|	  %d%s	|	|	  %d%s	|\n ", cartas[ ind_cartaJogador ].num, naipes[ cartas[ ind_cartaJogador ].naipe ], cartas[ ind2_cartaJogador ].num, naipes[ cartas[ ind2_cartaJogador ].naipe ], cartas[ ind3_cartaJogador ].num, naipes[ cartas[ ind3_cartaJogador ].naipe ], cartas[ ind4_cartaJogador ].num, naipes[ cartas[ ind4_cartaJogador ].naipe ]);
			printf("|______________|	|_______________|	|_______________|	|_______________|\n ");
		//} 
		printf("\n\n=============================================================================================\n");
		printf("\n\n");
	}
	
	//SCORE
	/*
	Regras de pontuação:
	  -Quatro cartas com NÚMEROS distintos entre si: 5 Pontos;
	  -Quatro cartas com NAIPES distintos entre si: 10 Pontos;
	  -Quatro cartas em SEQUENCIA numérica (p.ex.: 3,4,5,6 ou 8,9,10,11): 15 pontos;
	  -Quatro cartas com NÚMEROS identicos: 20 Pontos;
	*/
	for(int i = 0; i < qtd_jogadores; i++){
		int numIguais = 0, sequencia = 0, numDiferentes = 0, naipesDiferentes = 0;
		
		//VERIFICA SEQUENCIA, NUM IGUAIS E NUM DIFERENTES
		for(int j = 0; j+1 < 4; j++){
			int ind_cartasJogador_J = jogadores[i].cartas_mao[j];
			int ind_cartasJogador_J1 = jogadores[i].cartas_mao[j + 1];
			if(cartas[ ind_cartasJogador_J ].num == cartas[ ind_cartasJogador_J1 ].num){
				numIguais++;
			}
			
			if((cartas[ ind_cartasJogador_J ].num - cartas[ ind_cartasJogador_J1 ].num) == -1){
				sequencia++;
			}
			
			if(cartas[ ind_cartasJogador_J ].num != cartas[ ind_cartasJogador_J1 ].num){
				numDiferentes++;
			}
			
		}
		
		//VERIFICA NAIPES DIFERENTES
		for(int j = 0; j < 4; j++){
			int ind_cartasJogador_J = jogadores[i].cartas_mao[j];
			for(int k = j+1; k < 4; k++){
				int ind_cartaJogador_K = jogadores[i].cartas_mao[k];
				if(cartas[ ind_cartasJogador_J ].naipe != cartas[ ind_cartaJogador_K ].naipe){
					naipesDiferentes++;
				}
			}
		}

		int pontos = 0;
		if(numDiferentes == 3)
			pontos += 5;
			
		if(naipesDiferentes == 6)
			pontos += 10;
		
		if(sequencia == 3)
			pontos += 15;
		
		if(numIguais == 3)
			pontos += 20;
			
		jogadores[i].score = pontos;
	}
	
	for(int j = 1; j < qtd_jogadores; j++){
		for(int k = 0; k < qtd_jogadores-1; k++){
			if(jogadores[k].score < jogadores[k+1].score){
				Jogador troca = jogadores[k];
				jogadores[k] = jogadores[k+1];
				jogadores[k+1] = troca;
			}
			
			if((jogadores[k].score == jogadores[k+1].score) && ((jogadores[k].soma_Cartas < jogadores[k+1].soma_Cartas))){
				Jogador troca = jogadores[k];
				jogadores[k] = jogadores[k+1];
				jogadores[k+1] = troca;
			}
			
		}
	}
	
	//IMPRIME O RANKING
	printf("\n__________________________________________\n");
	printf("|					  |\n");
	printf("| \t   RANKING DE JOGADORES\t\t  |\n");
	printf("|_________________________________________|\n");
	printf("| Posição | Id	| Pontos | Soma de cartas |\n");
	for(int i = 0; i < qtd_jogadores; i++){
		printf("|   %dº\t  | %d\t|   %d	 | \t%d	  |\n", i+1, jogadores[i].id, jogadores[i].score, jogadores[i].soma_Cartas);
	}
	printf("|_________|_____|________|________________|");
	
	printf("\n\n\nDeveloped by the team: \n");
    printf("      Binary Phantoms\n\n");
    printf("Obrigado por jogar!");
	
	return 0;
}
