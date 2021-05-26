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

//IMPRIME CARTAS
void imprime_CartasJogadores(Jogador* jogadores, Baralho* cartas){
	char naipes[4][4] = {"♥", "♦", "♣", "♠" };
	for(int i = 1; i <= 0; i--){
		printf("Jogador %d\n", jogadores[i].id);
		for(int j = 0; j < 4; j++){
			int ind_cartaJogador = jogadores[i].cartas_mao[j];
			printf("%d: [%d%s]\n", j+1, cartas[ ind_cartaJogador ].valor, naipes[ cartas[ ind_cartaJogador ].naipe ]);
		}
		printf("\n\n");
	}
}

int cartaBot(Jogador* jogadores, Baralho* cartas, int naipeMesa, int *qtdCartas_bot, int *contCompras, int *qtdCartasMao_bot){
	int ind_cartaBot, comprados=0;
	while(1){
		if(naipeMesa == -1){ //se o bote tiver vencido
			int x = rand()% *qtdCartas_bot;
			if(cartas[ jogadores[1].cartas_mao[x] ].situacao == 2){
				ind_cartaBot = x;
				break;
			}
		}
		else {  //se o bot tiver q jogar o mesmo naipe do adversario
			int encontrou=0;;
			for(int i=0; i< *qtdCartas_bot; i++){
				if(cartas[ jogadores[1].cartas_mao[i] ].naipe == naipeMesa){
					encontrou=1;
					break;
				}
			}
			if(!encontrou){
				
				while(1){
					
					*contCompras+=1;
					*qtdCartasMao_bot+=1;
					
					jogadores[1].cartas_mao[ *qtdCartas_bot ] = rand()%52;
					//printf("\n!!! %d\n\n", jogadores[1].cartas_mao[ *qtdCartas_bot ]);
					if(cartas[ jogadores[1].cartas_mao[ *qtdCartas_bot ] ].situacao == 0){
						cartas[ jogadores[1].cartas_mao[ *qtdCartas_bot ] ].situacao = 2;
						ind_cartaBot = jogadores[1].cartas_mao[ *qtdCartas_bot ];
						comprados+=1;
						*qtdCartas_bot+=1;						
						break;
					}
				}
			} 
			if(encontrou){
				int x = rand()% *qtdCartas_bot;
				if((cartas[ jogadores[1].cartas_mao[x] ].situacao == 2) && (cartas[ jogadores[1].cartas_mao[x] ].naipe == naipeMesa)){
					ind_cartaBot = x;
					printf("\nO computador não tinha uma carta com mesmo naipe.\n");
					printf("\nO computador recebeu %d cartas do monte até encontrar uma de mesmo naipe.\n", comprados);
					break;
				}
			}
		}
		
	}

	return ind_cartaBot;
}


int userResponde(Jogador* jogadores, Baralho* cartas, int naipeMesa, int *qtdCartas_user, int *contCompras, int *qtdCartasMao_user){
	int ind_cartaUser;
	char naipes[4][4] = {"♥", "♦", "♣", "♠" };
	
	while(1){
		int encontrou=0;
		for(int i=0; i< *qtdCartas_user; i++){
			if(cartas[ jogadores[0].cartas_mao[i] ].naipe == naipeMesa){
				encontrou=1;
				return -1;
				break;
			}
		}
		if(!encontrou){
			printf("\nVocê não tem uma carta com mesmo naipe.\n");
			while(1){
				*contCompras+=1;
				*qtdCartasMao_user +=1;
				
				jogadores[0].cartas_mao[ *qtdCartas_user ] = rand()%52;
				//printf("\n!!! %d\n\n", jogadores[0].cartas_mao[ *qtdCartas_user ]);
				if(cartas[ jogadores[0].cartas_mao[ *qtdCartas_user ] ].situacao == 0){
					cartas[ jogadores[0].cartas_mao[ *qtdCartas_user ] ].situacao = 1;
					ind_cartaUser = jogadores[0].cartas_mao[ *qtdCartas_user ];
					*qtdCartas_user+=1;
					printf("\nVocê recebeu do monte a carta: [%d%s].\n\n", cartas[ ind_cartaUser ].valor, naipes[cartas[ind_cartaUser].naipe]);
					return (*qtdCartas_user-1);
					break;
				}
			}
		}
		if(encontrou) break;

		
	}

	return 0;
}


int verificaCartas(Jogador* jogadores, Baralho* cartas, int cartaUser, int cartaPC, int *qtdCartas_bot, int *qtdCartas_user, int *qtdCartasMao_bot, int *qtdCartasMao_user){
	int id_vencedor;
	if(cartas[ jogadores[0].cartas_mao[cartaUser] ].valor > cartas[ jogadores[1].cartas_mao[cartaPC] ].valor){
		printf("\nPARABÈNS! Você venceu esta rodada.");
		id_vencedor = 1; //Usuário ganhou
	}
		
	if(cartas[ jogadores[1].cartas_mao[cartaPC] ].valor > cartas[ jogadores[0].cartas_mao[cartaUser] ].valor){
		printf("\nO computador venceu esta rodada.");
		id_vencedor = 2; //Bot ganhou
	}
	cartas[ jogadores[0].cartas_mao[cartaUser] ].situacao = -1; //tira as cartas do jogo 
	cartas[ jogadores[1].cartas_mao[cartaPC] ].situacao = -1;
	
	//REORDENA AS CARTAS P/ Q APENAS AS ATIVAS FIQUEM NO INICIO
	for(int i=0; i<2; i++){
		for(int j=0; j<4;j++){
			for(int k=0; k<4-1; k++){
				if(cartas[ jogadores[i].cartas_mao[k] ].situacao < cartas[ jogadores[i].cartas_mao[j] ].situacao){
					int aux = jogadores[i].cartas_mao[k];
					jogadores[i].cartas_mao[k] = jogadores[i].cartas_mao[j];
					jogadores[i].cartas_mao[j] = aux;
				}
			}
		}
	}
	
	*qtdCartasMao_bot-=1;
	*qtdCartasMao_user-=1;
	
	return id_vencedor;
}

//imprime Cartas atuais dos jogadores
void imprime_Cartas(Jogador* jogadores, Baralho* cartas,  int qtdCartas_bot, int qtdCartas_user){
	char naipes[4][4] = {"♥", "♦", "♣", "♠" };
	printf("\nCartas do Computador:\n");
	for(int j = 0; j < qtdCartas_bot; j++){
		int ind_cartaJogador = jogadores[1].cartas_mao[j];
		if(cartas[ ind_cartaJogador ].situacao==2)
			printf("[%d%s] ", cartas[ ind_cartaJogador ].valor, naipes[ cartas[ ind_cartaJogador ].naipe ]);
	}
	
	printf("\n\nCartas do usuário:\n");
	for(int j = 0; j < qtdCartas_user; j++){
		int ind_cartaJogador = jogadores[0].cartas_mao[j];
		if(cartas[ ind_cartaJogador ].situacao==1)
			printf("%d: [%d%s]\n", j+1, cartas[ ind_cartaJogador ].valor, naipes[ cartas[ ind_cartaJogador ].naipe ]);
	}
	
	printf("\n\n");
}

int finalizaJogo(Baralho* cartas, int quemJoga, int contCompras, int qtdCartasMao_bot, int qtdCartasMao_user){
	int continua =0;
	for(int  i = 0; i < 52; i++){
		if(cartas[i].situacao == 0){
			continua=1;
		}
	}
	
	if(contCompras == 52){
		if(quemJoga == 2){
			printf("O computador esgotou o monte.\n");
			printf("Parabéns, você venceu a partida!\n");
		}else{
			printf("Você esgotou o monte.\n");
			printf("O computador venceu a partida!\n");
		}
		return 1;
	}
	
	if((continua == 0)  && (quemJoga == 1)){
		printf("Você esgotou a mão e venceu a partida!");
		return 1;
	}

	
	if(qtdCartasMao_bot == 0){
		printf("O computador esgotou a mão e venceu a partida!");
		return 1;
	}
	
	if(qtdCartasMao_user == 0){
		printf("Você esgotou a mão e venceu a partida!");
		return 1;
	}
	return 0;
}

int main(){
	srand(time(NULL));
	setbuf(stdin, NULL);
	
	Baralho cartas[52];
	
	criarBar(cartas);
	
	
	Jogador jogadores[2];
	
	distrCartas(jogadores,cartas);
	
	char naipes[4][4] = {"♥", "♦", "♣", "♠" };
	int contCompras=0, contRodadas=1;
	int cartaPC, cartaUser, naipeMesa, qtdCartas_bot=4, qtdCartas_user=4, qtdCartasMao_bot=4, qtdCartasMao_user=4;
	
	printf("\n______________________________________________________________________________\n");
	printf(" 					  					\n");
	printf("  \t\t   BEM-VINDO AO JOGO DO BURRO\t\t\t	\n");
	printf("______________________________________________________________________________\n\n");
	
	printf("[ %dº Rodada ]\t\t\t\t\t   ", contRodadas++);
	printf("[Restam no monte %d cartas]\n\n", 44 - contCompras);
	
	imprime_Cartas(jogadores, cartas,  qtdCartas_bot, qtdCartas_user);
	
	
	
	//Inicio do programa ------
	
	
	printf("Você inicia a partida\nSelecione uma carta: ");
	scanf(" %d", &cartaUser);
	cartaUser -= 1;
	
	naipeMesa = cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe;
	printf("\nNaipe da rodada: %s\n", naipes[naipeMesa]);
	
	cartaPC = cartaBot(jogadores, cartas, naipeMesa, &qtdCartas_bot, &contCompras, &qtdCartasMao_bot);

	printf("\nO Computador escolheu a carta: [%d%s]\n\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
	printf("***** Cartas na mesa *****\n");
	printf("Usuário: [%d%s]\n", cartas[ jogadores[0].cartas_mao[cartaUser] ].valor, naipes[ cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe ]);
	printf("PC: [%d%s]\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
	printf("**************************\n");
	
	do{
		naipeMesa = -1;
		int vencendor = verificaCartas(jogadores, cartas, cartaUser, cartaPC, &qtdCartas_bot, &qtdCartas_user, &qtdCartasMao_bot, &qtdCartasMao_user);
		tecleEnter_continuar();
		
		printf("\n______________________________________________________________________________\n");
		printf(" 					  					\n");
		printf("  \t\t   BEM-VINDO AO JOGO DO BURRO\t\t\t	\n");
		printf("______________________________________________________________________________\n\n");
		
		printf("[ %dº Rodada ]\t\t\t\t\t   ", contRodadas++);
		printf("[Restam no monte %d cartas]\n\n", 44 - contCompras);
		
		imprime_Cartas(jogadores, cartas,  qtdCartas_bot, qtdCartas_user);
		
		if(vencendor==1){
			printf("\nVocê inicia a rodada.\nEscolha uma carta: ");
			scanf(" %d", &cartaUser);
			cartaUser -= 1;
			naipeMesa = cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe;
			printf("\nNaipe da rodada: %s\n", naipes[naipeMesa]);
			
			printf("\nAgora é a vez do computador: ");
			cartaPC = cartaBot(jogadores, cartas, naipeMesa, &qtdCartas_bot, &contCompras, &qtdCartasMao_bot);
			cartaPC = cartaBot(jogadores, cartas, naipeMesa, &qtdCartas_bot, &contCompras, &qtdCartasMao_bot);
			if(finalizaJogo(cartas, 1, contCompras, qtdCartasMao_bot, qtdCartasMao_user))
				return 0;
			printf("\nO computador escolheu a carta: [%d%s]\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
		}
		if(vencendor==2){
			printf("\nComputador inicia a rodada.");
			cartaPC = cartaBot(jogadores, cartas, naipeMesa, &qtdCartas_bot, &contCompras, &qtdCartasMao_bot);
			printf("\nO computador escolheu a carta: [%d%s]\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
			
			naipeMesa = cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe;
			printf("\nNaipe da rodada: %s\n", naipes[naipeMesa]);
			
			
			printf("\nAgora é a sua vez.\n");
			int respostaUser = userResponde(jogadores, cartas, naipeMesa, &qtdCartas_user, &contCompras, &qtdCartasMao_user);
			if(finalizaJogo(cartas, vencedor, contCompras, qtdCartasMao_bot, qtdCartasMao_user))
				return 0;
			
			if(respostaUser == -1){
				printf("Escolha uma carta:");
				scanf(" %d", &cartaUser);
				cartaUser -= 1;
				while(cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe != cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe){
					printf("\nCarta com naipe diferente da carta do oponente! Tente novamente.\n");
					printf("\nEscolha uma carta:  ");
					scanf(" %d", &cartaUser);
					cartaUser -= 1;
				}
			} else cartaUser = respostaUser;
		}
		
		printf("***** Cartas na mesa *****\n");
		printf("Usuário: [%d%s]\n", cartas[ jogadores[0].cartas_mao[cartaUser] ].valor, naipes[ cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe ]);
		printf("PC: [%d%s]\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
		printf("**************************\n\n");
		
		
		
	}while(1);
	
	
	return 0;
}
