#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int numero, naipe, estado;
}Baralho;

typedef struct{
	int id, mao[4], pontos, somaCartas;
}Jogador;


int main(){
	Baralho cartas[52];
	
	//Inicialização do baralho forma expandida
	/*for(int i = 0; i < 13; i++){
		cartas[i].numero = i + 1;
		cartas[i].naipe = 0;
		cartas[i].estado = 0;
	}
	
	for(int i = 13; i < 26; i++){
		cartas[i].numero = (i + 1) - 13;
		cartas[i].naipe = 1;
		cartas[i].estado = 0;
	}
	
	for(int i = 26; i < 39; i++){
		cartas[i].numero = (i + 1) - 26;
		cartas[i].naipe = 2;
		cartas[i].estado = 0;
	}
	
	for(int i = 39; i < 52; i++){
		cartas[i].numero = (i + 1) - 39;
		cartas[i].naipe = 3;
		cartas[i].estado = 0;
	}*/
	
	//Inicialização do baralho forma compacta
	for(int naipe = 0; naipe < 4; naipe++){
		for(int numero = 0; numero < 13; numero++){
			cartas[(naipe * 13) + numero].numero = numero + 1;
			cartas[(naipe * 13) + numero].naipe = naipe;
			cartas[(naipe * 13) + numero].estado = 0;
		}
	}
	
	int qJogadores;
	do{
		printf("Quantos jogadores irão jogar? (mínimo 2, máximo 10) ");
		scanf(" %d", &qJogadores);
		if((qJogadores >= 2) && (qJogadores <= 10))
			break;
		else
			printf("Quantida inválida! Tente novamente.\n");
	}while(1);
	
	//inicializa jogadores
	srand(time(NULL));
	Jogador jogadores[qJogadores];
	for(int i = 0; i < qJogadores; i++){
		jogadores[i].id = i + 1;
		jogadores[i].pontos = 0;
		jogadores[i].somaCartas = 0;
		
		//Distribui cartas
		for(int j = 0; j < 4; j++){
			do{
				jogadores[i].mao[j] = rand()%52;
				if(cartas[ jogadores[i].mao[j] ].estado == 0){
					cartas[ jogadores[i].mao[j] ].estado = 1;
					break;
				}
			}while(1);
			jogadores[i].somaCartas	+= cartas[ jogadores[i].mao[j] ].numero;
		}
		
		//Ordena cartas (insertion)
		for(int j = 1; j < 4; j++){
			for(int k = j; k > 0; k--){
				int icj1 = jogadores[i].mao[k-1];
				int icj2 = jogadores[i].mao[k];
				if(cartas[ icj2 ].numero < cartas[ icj1 ].numero){
					int troca = jogadores[i].mao[k];
					jogadores[i].mao[k] = jogadores[i].mao[k-1];
					jogadores[i].mao[k-1] = troca;
				}
			}
		}
	}
	
	//Printa Relação dos jogadores e seuas cartas
	char naipes[4] = {'@', '#', '$', '&'};
	printf("\nRelação dos jogadores e seuas cartas:\n");
	for(int i = 0; i < qJogadores; i++){
		printf("Jogador %d\n", jogadores[i].id);
		for(int j = 0; j < 4; j++){
			int icj = jogadores[i].mao[j];
			printf("[%d%c]", cartas[ icj ].numero, naipes[ cartas[ icj ].naipe ]);
		}
		printf("\n\n");
	}
	
	
	
	//Atribui pontos
	for(int i = 0; i < qJogadores; i++){
		int numerosIguais = 0, sequencia = 0, numerosDistintos = 0, naipesDistintos = 0;
		//Sequência e igualdade numérica numeros distintos
		for(int j = 0; j+1 < 4; j++){
			int icj_j = jogadores[i].mao[j];
			int icj_j1 = jogadores[i].mao[j + 1];
			if(cartas[ icj_j ].numero == cartas[ icj_j1 ].numero){
				numerosIguais++;
			}
			
			if((cartas[ icj_j ].numero - cartas[ icj_j1 ].numero) == -1){
				sequencia++;
			}
			
			if(cartas[ icj_j ].numero != cartas[ icj_j1 ].numero){
				numerosDistintos++;
			}
			
		}
		 //1 2 3 4
		
		//naipes distintos
		for(int j = 0; j < 4; j++){
			int icj_j = jogadores[i].mao[j];
			for(int k = j+1; k < 4; k++){
				int icj_k = jogadores[i].mao[k];
				if(cartas[ icj_j ].naipe != cartas[ icj_k ].naipe){
					naipesDistintos++;
				}
			}
		}

		int pontos = 0;
		if(numerosDistintos == 3)
			pontos += 5;
			
		if(naipesDistintos == 6)
			pontos += 10;
		
		if(sequencia == 3)
			pontos += 15;
		
		if(numerosIguais == 3)
			pontos += 20;
			
		jogadores[i].pontos = pontos;
	}
	
	//Ordena cartas (insertion)
	
	
	for(int j = 1; j < qJogadores; j++){
		for(int k = j; k > 0; k--){
			if(jogadores[k].pontos > jogadores[k - 1].pontos){
				Jogador troca = jogadores[k];
				jogadores[k] = jogadores[k - 1];
				jogadores[k - 1] = troca;
			}
			
			if((jogadores[k].pontos == jogadores[k - 1].pontos) && ((jogadores[k].somaCartas > jogadores[k - 1].somaCartas))){
				Jogador troca = jogadores[k];
				jogadores[k] = jogadores[k - 1];
				jogadores[k - 1] = troca;
			}
		}
	}
	
	//printa ranking
	printf("\nRanking dos jogadores:\n");
	printf("Posição	Id	Pontos	Soma de cartas\n");
	for(int i = 0; i < qJogadores; i++){
		printf("%d	%d	%d	%d\n",i+1, jogadores[i].id, jogadores[i].pontos, jogadores[i].somaCartas);
	}

	return 0;
}
