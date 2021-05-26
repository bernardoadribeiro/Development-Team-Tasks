#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int valor, situacao, naipe;
}Baralho;

typedef struct{
	int id, cartas_mao[48];
}Jogador;


//CRIAR BARALHO
Baralho criarBar(Baralho* cartas){
	Baralho baralho[52];
	
	for(int i=0; i<13; i++){ //naipe 0
		cartas[i].valor = i+1;
		cartas[i].naipe = 0;
		cartas[i].situacao = 0;
	}
	
	for(int i=13; i<26; i++){ //naipe 1
		cartas[i].valor = (i+1)-13;
		cartas[i].naipe = 1;
		cartas[i].situacao = 0;
	}
	
	for(int i=26; i<39; i++){ //naipe 2
		cartas[i].valor = (i+1)-26;
		cartas[i].naipe = 2;
		cartas[i].situacao = 0;
	}
	
	for(int i=39; i<52; i++){ //naipe 3
		cartas[i].valor = (i+1)-39;
		cartas[i].naipe = 3;
		cartas[i].situacao = 0;
	}
	
	return baralho[52];
}


//DISTRIBUIR CARTAS E ORDENAR
Jogador distrCartas(Jogador* jogadores, Baralho* cartas){
	srand(time(NULL));
	for(int i = 0; i <2; i++){
		jogadores[i].id = i;
		for(int j = 0; j < 4; j++){
			while(1){
				jogadores[i].cartas_mao[j] = rand()%52;
				if(cartas[ jogadores[i].cartas_mao[j] ].situacao == 0){
					cartas[ jogadores[i].cartas_mao[j] ].situacao = i+1;
					break;
				}
			}
		}
		for(int j=0; j<4;j++){
			for(int k=0; k<4-1; k++){
				if(cartas[ jogadores[i].cartas_mao[k] ].valor > cartas[ jogadores[i].cartas_mao[j] ].valor){
					int aux = jogadores[i].cartas_mao[k];
					jogadores[i].cartas_mao[k] = jogadores[i].cartas_mao[j];
					jogadores[i].cartas_mao[j] = aux;
				}
			}
		}
	}
	return jogadores[2];
}

/*
void verificaCartas(Jogador* jogadores, Baralho* cartas, int cartaUser, int cartaPC){
	int id_vencedor;
	
	return id_vencedor;
}
*/

int cartaBot(Jogador* jogadores, Baralho* cartas, int naipeMesa){
	int ind_cartaBot;
	for(int j = 0; j < 52; j++){
		while(1){
			ind_cartaBot = rand()%52;
			if(cartas[ ind_cartaBot ].situacao == 2 && cartas[ ind_cartaBot ].naipe == naipeMesa){
				cartas[ ind_cartaBot ].situacao = -1;
				break;
			}
		}
	}
	return ind_cartaBot;
}

void escolhaJogadores(Jogador* jogadores, Baralho* cartas){
	int id_vencedor = 0;
	//while(1){
		int cartaUser, cartaPC;
		id_vencedor = verificaCartas(jogadores, cartas, cartaUser, cartaPC); //usuario inicia partida
		for(int i=0; i<2; i++){
			if(id_vencedor == 0){
				printf("\nUsuário(a), escolha sua carta: ");
				scanf(" %d", &cartaUser);
			}
			if(id_vencedor == 1){
				printf("\nÉ a vez do Computador: ");
				cartaPC = cartaBot(jogadores, cartas, naipeMesa);
			}
		}
	//}
	
}

/*SORTEIA NOVA CARTA PRO JOGADOR i
Baralho sorteia_novaCarta(Jogador* id_Jogador, Baralho* cartas, int* escolhaJogadores),{
	Baralho nova_Carta;
	for(int i = 0; i <2; i++){
		if(jogadores[i].id == id_Jogador){
			for(int j = 0; j < 4; j++){
				while(1){
					jogadores[i].cartas_mao[j] = rand()%52;
					if(cartas[ jogadores[i].cartas_mao[j] ].situacao == 0){
						cartas[ jogadores[i].cartas_mao[j] ].situacao = i+1;
						break;
					}
				}
			}
			for(int j=0; j<4;j++){
				for(int k=0; k<4-1; k++){
					if(cartas[ jogadores[i].cartas_mao[k] ].valor > cartas[ jogadores[i].cartas_mao[j] ].valor){
						int aux = jogadores[i].cartas_mao[k];
						jogadores[i].cartas_mao[k] = jogadores[i].cartas_mao[j];
						jogadores[i].cartas_mao[j] = aux;
					}
				}
			}
		}
	}
	return nova_Carta;
}
*/



//IMPRIME CARTAS
void imprime_CartasJogadores(Jogador* jogadores, Baralho* cartas){
	char naipes[4][4] = {"♥", "♦", "♣", "♠" };
	for(int i = 0; i < 2; i++){
		printf("Jogador %d\n", jogadores[i].id);
		for(int j = 0; j < 4; j++){
			int ind_cartaJogador = jogadores[i].cartas_mao[j];
			printf("[%d%s]", cartas[ ind_cartaJogador ].valor, naipes[ cartas[ ind_cartaJogador ].naipe ]);
		}
		printf("\n\n");
	}
}



int main(){
	printf("================ BEM-VINDO AO JOGO DO BURRO ===================\n");
	setbuf(stdin, NULL);
	
	Baralho cartas[52];
	
	criarBar(cartas);
	
	for(int i=0; i<52; i++)
		printf("%d\n",cartas[i].valor);
	
	Jogador jogadores[2];
	
	distrCartas(jogadores,cartas);
	
	//Inicio do programa ------
	while(1){
		imprime_CartasJogadores(jogadores, cartas);
		//escolhaJogadores(jogadores, cartas);
		break;
	}
	
	
	return 0;
}

