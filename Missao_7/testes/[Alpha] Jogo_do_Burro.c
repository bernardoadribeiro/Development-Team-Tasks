#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int valor, situacao, naipe;
}Baralho;

typedef struct{
	int id, cartas_mao[52];
}Jogador;

void tecleEnter_continuar(){
	printf("\n\nPressione 'Enter' para continuar...\n\n");
	setbuf(stdin, NULL);
	getchar();
}


//CRIAR BARALHO
Baralho criaBaralho(Baralho* cartas){
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


//DISTRIBUIR CARTAS
Jogador distribuiCartas(Jogador* jogadores, Baralho* cartas){
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
	}
	return jogadores[2];
}

//IMPRIME CARTAS INICIAIS
void imprime_CartasJogadores(Jogador* jogadores, Baralho* cartas){
	char naipes[4][4] = {"♥", "♦", "♣", "♠" };
	for(int i = 0; i < 2; i++){
		printf("Jogador %d\n", jogadores[i].id);
		for(int j = 0; j < 4; j++){
			int ind_cartaJogador = jogadores[i].cartas_mao[j];
			printf("%d: [%d%s]\n", j, cartas[ ind_cartaJogador ].valor, naipes[ cartas[ ind_cartaJogador ].naipe ]);
		}
		printf("\n\n");
	}
}


int cartaBot(Jogador* jogadores, Baralho* cartas, int naipeMesa, int *qtdCartas_bot, int *contCompras){
	int ind_cartaBot;
	while(1){
		if(naipeMesa == -1){
			int x = rand()% *qtdCartas_bot;
			if(cartas[ jogadores[1].cartas_mao[x] ].situacao == 2){
				ind_cartaBot = x;
				break;
			}
		} else{
			int encontrou=0;;
			for(int i=0; i< *qtdCartas_bot; i++){
				if(cartas[ jogadores[1].cartas_mao[i] ].naipe == naipeMesa){
					encontrou=1;
					break;
				}
			}
			if(!encontrou){
				while(1){
					jogadores[1].cartas_mao[ (*qtdCartas_bot) ] = rand()%52;
					if(cartas[ jogadores[1].cartas_mao[ (*qtdCartas_bot) ] ].situacao == 0){
						cartas[ jogadores[1].cartas_mao[ (*qtdCartas_bot) ] ].situacao = 2;
						ind_cartaBot = jogadores[1].cartas_mao[ (*qtdCartas_bot) ];
						*contCompras++;
						*qtdCartas_bot++;
						break;
					}
				}
			} 
			if(encontrou){
				int x = rand()% *qtdCartas_bot;
				if((cartas[ jogadores[1].cartas_mao[x] ].situacao == 2) && (cartas[ jogadores[1].cartas_mao[x] ].naipe == naipeMesa)){
					ind_cartaBot = x;
					break;
				}
			}
		}
		
	}

	return ind_cartaBot;
}




int verificaCartas(Jogador* jogadores, Baralho* cartas, int cartaUser, int cartaPC, int *qtdCartasMao_bot, int *qtdCartasMao_user){
	int id_vencedor;
	if(cartas[ jogadores[0].cartas_mao[cartaUser] ].valor > cartas[ jogadores[1].cartas_mao[cartaPC] ].valor){
		printf("\nPARABÈNS! Você venceu esta rodada.\n\n\n");
		id_vencedor = 1; //Usuário ganhou
	}
		
	if(cartas[ jogadores[1].cartas_mao[cartaPC] ].valor > cartas[ jogadores[0].cartas_mao[cartaUser] ].valor){
		printf("\nO computador venceu esta rodada.\n\n\n");
		id_vencedor = 2; //Bot ganhou
	}
	
	cartas[ jogadores[0].cartas_mao[cartaUser] ].situacao = -1; //tira as cartas do jogo 
	cartas[ jogadores[1].cartas_mao[cartaPC] ].situacao = -1;
	
	/*//REORDENA AS CARTAS P/ Q APENAS AS ATIVAS FIQUEM NO INICIO
	for(int j=0; j < *qtdCartas_user;j++){	//ordena cartas User
		for(int k=0; k < *qtdCartas_user-1; k++){
			if(cartas[ jogadores[0].cartas_mao[k] ].situacao > cartas[ jogadores[0].cartas_mao[j] ].situacao){
				int aux = jogadores[0].cartas_mao[k];
				jogadores[0].cartas_mao[k] = jogadores[0].cartas_mao[j];
				jogadores[0].cartas_mao[j] = aux;
			}
		}
	}
	for(int j=0; j < *qtdCartas_bot;j++){ 	//ordena cartas PC
		for(int k=0; k < *qtdCartas_bot-1; k++){
			if(cartas[ jogadores[1].cartas_mao[k] ].situacao > cartas[ jogadores[1].cartas_mao[j] ].situacao){
				int aux = jogadores[1].cartas_mao[k];
				jogadores[1].cartas_mao[k] = jogadores[1].cartas_mao[j];
				jogadores[1].cartas_mao[j] = aux;
			}
		}
	}*/
	
	
	*qtdCartasMao_bot--;
	*qtdCartasMao_user--;
	
	return id_vencedor;
}

//imprime Cartas atuais dos jogadores
void imprime_Cartas(Jogador* jogadores, Baralho* cartas,  int *qtdCartas_bot, int *qtdCartas_user){
	char naipes[4][4] = {"♥", "♦", "♣", "♠" };
	printf("Cartas do usuário:\n");
	for(int j = 0; j < *qtdCartas_user; j++){
		int ind_cartaJogador = jogadores[0].cartas_mao[j];
		if(cartas[ ind_cartaJogador ].situacao==1)
			printf("%d: [%d%s]\n", j, cartas[ ind_cartaJogador ].valor, naipes[ cartas[ ind_cartaJogador ].naipe ]);
	}
	
	printf("\nCartas do Computador:\n");
	for(int j = 0; j < *qtdCartas_bot; j++){
		int ind_cartaJogador = jogadores[1].cartas_mao[j];
		if(cartas[ ind_cartaJogador ].situacao==2)
			printf("%d: [%d%s]\n", j, cartas[ ind_cartaJogador ].valor, naipes[ cartas[ ind_cartaJogador ].naipe ]);
	}
	printf("\n\n");
}

int main(){
	srand(time(NULL));
	setbuf(stdin, NULL);
	
	Baralho cartas[52];
	criaBaralho(cartas);
	
	Jogador jogadores[2];
	distribuiCartas(jogadores,cartas);
	
	char naipes[4][4] = {"♥", "♦", "♣", "♠" };
	
	//Inicio do programa ------
	//int executa=1;
	//do{
		//system("clear");
		int cartaPC, cartaUser, naipeMesa, qtdCartas_bot=4, qtdCartas_user=4, contCompras=0, qtdCartasMao_bot=4, qtdCartasMao_user=4;	
		int contRodadas=1;
		
		printf("\n______________________________________________________________________________\n");
		printf(" 					  					\n");
		printf("  \t\t   BEM-VINDO AO JOGO DO BURRO\t\t\t	\n");
		printf("______________________________________________________________________________\n\n");
		printf("[ %dº Rodada ]\n\n", contRodadas++);
		
		imprime_CartasJogadores(jogadores, cartas);
		
		printf("(Restam no monte %d cartas)\n\n", 52 - contCompras);
		
		printf("Você inicia a partida\nSelecione uma carta: ");
		scanf(" %d", &cartaUser);
		
		naipeMesa = cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe;
		
		printf("\nNaipe da rodada: [%s]\n", naipes[naipeMesa]);
		
		cartaPC = cartaBot(jogadores, cartas, naipeMesa, &qtdCartas_bot, &contCompras);
		printf("\nO Computador escolheu a carta: [%d%s]\n\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
		printf("***** Cartas na mesa *****\n");
		printf("Usuário: [%d%s]\n", cartas[ jogadores[0].cartas_mao[cartaUser] ].valor, naipes[ cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe ]);
		printf("PC: [%d%s]\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
		printf("**************************");
		
		do{
			//system("clear");
			int vencendor = verificaCartas(jogadores, cartas, cartaUser, cartaPC, &qtdCartasMao_bot, &qtdCartasMao_user);
			naipeMesa = -1; //reseta o naipe da mesa
			
			printf("\n______________________________________________________________________________\n");
			printf(" 					  					\n");
			printf("  \t\t   BEM-VINDO AO JOGO DO BURRO\t\t\t	\n");
			printf("______________________________________________________________________________\n\n");
			printf("[ %dº Rodada ]\n\n", contRodadas++);
			
			imprime_Cartas(jogadores, cartas,  &qtdCartas_bot, &qtdCartas_user);
			
			printf("(Restam no monte %d cartas)\n\n", 52 - contCompras);
			
			if(vencendor==1){
				printf("\nVocê inicia a rodada.\nEscolha uma carta: ");
				scanf(" %d", &cartaUser);
				
				naipeMesa = cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe;
				printf("\nNaipe da rodada: [%s]\n", naipes[naipeMesa]);
				
				printf("\nAgora é a vez do computador: ");
				cartaPC = cartaBot(jogadores, cartas, naipeMesa, &qtdCartas_bot, &contCompras);
				printf("\nO computador escolheu a carta: [%d%s]\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
			}
			if(vencendor==1){
				printf("\nO Computador inicia a rodada.");
				cartaPC = cartaBot(jogadores, cartas, naipeMesa, &qtdCartas_bot, &contCompras);
				printf("\nO computador escolheu a carta: [%d%s]\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
				
				naipeMesa = cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe;
				printf("\nNaipe da rodada: [%s]\n", naipes[naipeMesa]);
				
				printf("\nAgora é a sua vez\nEscolha uma carta:  ");
				//cartaUser = verfJogador(jogadores, cartas, naipeMesa, &qtdCartas_user, &contCompras);
			}
			//finalizaJogo();
			
		}while(1);
		
	//}while(executa);
	
	
	return 0;
}
