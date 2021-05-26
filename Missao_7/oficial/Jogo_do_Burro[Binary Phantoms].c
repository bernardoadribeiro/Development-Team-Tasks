#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> //para funcao sleep

typedef struct{
	int valor, situacao, naipe;
}Baralho;

typedef struct{
	int id, cartas_mao[52];
}Jogador;

void tecleEnter_continuar( char *mensagem){
	printf("\n Pressione 'Enter' para %s\n", mensagem);
	setbuf(stdin, NULL);
	getchar();
}


void phantom(char * mensagem){//funcao simples para exibir o phantom ('cuz we are the Binary Phantoms)
	printf("     .-----.\n");
	printf("   .\' -   - \'.\n");
	printf("  /  .-. .-.  \\\n");
	printf("  |  | | | |  |\n");
	printf("   \\ \\o/ \\o/ /     [ %s ]  \n", mensagem);
	printf("  _/    ^    \\_   / \n");
	printf(" | \\  \'---\'  / |\n");
	printf(" / /`--. .--`\\ \\\n");
	printf("/ /\'---` `---\'\\ \\\n");
	printf("\'.__.       .__.\'\n");
	printf("    `|     |`\n");
	printf("     |     \\\n");
	printf("     \\      \'--.\n");
	printf("      \'.        `\\\n");
	printf("        `\'---.   |\n");
	printf("           ,__) /\n");
	printf("            `..\'\n");	
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


//DISTRIBUIR CARTAS
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


int cartaBot(Jogador* jogadores, Baralho* cartas, int naipeMesa, int *qtdCartas_bot, int *contCompras, int *qtdCartasMao_bot){
	int ind_cartaBot, comprados=0, encontrou=0, comprou=0;
	while(1){
		if(naipeMesa == -1){ //se o bote tiver vencido
			int x = rand()% *qtdCartas_bot;
			if(cartas[ jogadores[1].cartas_mao[x] ].situacao == 2){
				ind_cartaBot = x;
				break;
			}
		}
		else {  //se o bot tiver q jogar o mesmo naipe do adversario
			for(int i=0; i< *qtdCartas_bot; i++){
				if(cartas[ jogadores[1].cartas_mao[i] ].naipe == naipeMesa){
					if(comprou){
						printf("\n O computador não tinha uma carta com mesmo naipe.\n");
						printf("\n O computador recebeu %d cartas do monte até encontrar uma de mesmo naipe.\n", comprados);
					}
		
					return i;
					break;
				}
			}
			if(!encontrou){
				//int encontrou=0;
				while(1){
					jogadores[1].cartas_mao[ *qtdCartas_bot ] = rand()%52;
					if(cartas[ jogadores[1].cartas_mao[ *qtdCartas_bot ] ].situacao == 0){
						*contCompras+=1;
						*qtdCartasMao_bot+=1;
						comprados++;
						comprou=1;
						cartas[ jogadores[1].cartas_mao[ *qtdCartas_bot ] ].situacao = 2;
						ind_cartaBot = jogadores[1].cartas_mao[ *qtdCartas_bot ];	
						*qtdCartas_bot+=1;						
						break;
					}
				}
				
			} 
			
		}
		
	}
	
	return ind_cartaBot;
}


int userResponde(Jogador* jogadores, Baralho* cartas, int naipeMesa, int *qtdCartas_user, int *contCompras, int *qtdCartasMao_user){
	int ind_cartaUser;
	char naipes[4][4] = {"♥", "♦", "♣", "♠" };
	
	//while(1){
		int encontrou=0;
		for(int i=0; i< *qtdCartas_user; i++){
			if(cartas[ jogadores[0].cartas_mao[i] ].naipe == naipeMesa && cartas[ jogadores[0].cartas_mao[i] ].situacao==1){
				encontrou=1;
				break;
			}
		}
		
		if(encontrou){
			return -1;
		}
		if(encontrou==0){
			printf("\n Você não tem uma carta com mesmo naipe.\n");
			tecleEnter_continuar("pegar uma carta do monte.");
			while(1){
				
				jogadores[0].cartas_mao[ *qtdCartas_user ] = rand()%52;
				if(cartas[ jogadores[0].cartas_mao[ *qtdCartas_user ] ].situacao == 0){
					cartas[ jogadores[0].cartas_mao[ *qtdCartas_user ] ].situacao = 1;
					ind_cartaUser = jogadores[0].cartas_mao[ *qtdCartas_user ];
					*contCompras+=1;
					*qtdCartasMao_user+=1;
				
					if(cartas[ jogadores[0].cartas_mao[ *qtdCartas_user] ].naipe == naipeMesa){
						printf("\n Você recebeu do monte a carta [%d%s] e ela é do mesmo naipe.\n\n", cartas[ ind_cartaUser ].valor, naipes[cartas[ind_cartaUser].naipe]);
						tecleEnter_continuar("jogar.");
						
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
						
						
						return *qtdCartas_user;
					} else {
						printf("\n Você recebeu do monte a carta [%d%s] mas ela possui naipe diferente.\n\n", cartas[ ind_cartaUser ].valor, naipes[cartas[ind_cartaUser].naipe]);
						tecleEnter_continuar("pegar mais uma carta do monte.");
					}
					
					*qtdCartas_user+=1;
					
				}
			}
		}
		
	//}
	return 0;
}



int verificaCartas(Jogador* jogadores, Baralho* cartas, int cartaUser, int cartaPC, int *qtdCartas_bot, int *qtdCartas_user, int *qtdCartasMao_bot, int *qtdCartasMao_user){
	int id_vencedor;
	if(cartas[ jogadores[0].cartas_mao[cartaUser] ].valor > cartas[ jogadores[1].cartas_mao[cartaPC] ].valor){
		printf("\n PARABÈNS! Você venceu esta rodada.");
		id_vencedor = 1; //Usuário ganhou
	}
		
	if(cartas[ jogadores[1].cartas_mao[cartaPC] ].valor > cartas[ jogadores[0].cartas_mao[cartaUser] ].valor){
		printf("\n O computador venceu esta rodada.");
		id_vencedor = 2; //Bot ganhou
	}
	cartas[ jogadores[0].cartas_mao[cartaUser] ].situacao = -1; //tira as cartas do jogo 
	cartas[ jogadores[1].cartas_mao[cartaPC] ].situacao = -1;
	
	//REORDENA AS CARTAS P/ Q APENAS AS ATIVAS FIQUEM NO INICIO
	//for(int i=0; i<2; i++){
		for(int j=0; j< *qtdCartasMao_bot;j++){
			for(int k=0; k< *qtdCartasMao_bot-1; k++){
				if(cartas[ jogadores[1].cartas_mao[k] ].situacao < cartas[ jogadores[1].cartas_mao[j] ].situacao){
					int aux = jogadores[1].cartas_mao[k];
					jogadores[1].cartas_mao[k] = jogadores[1].cartas_mao[j];
					jogadores[1].cartas_mao[j] = aux;
				}
			}
		}
		for(int j=0; j < *qtdCartasMao_user;j++){
			for(int k=0; k < *qtdCartasMao_user-1; k++){
				if(cartas[ jogadores[0].cartas_mao[k] ].situacao < cartas[ jogadores[0].cartas_mao[j] ].situacao){
					int aux = jogadores[0].cartas_mao[k];
					jogadores[0].cartas_mao[k] = jogadores[0].cartas_mao[j];
					jogadores[0].cartas_mao[j] = aux;
				}
			}
		}
	//}
	
	*qtdCartasMao_bot-=1;
	*qtdCartasMao_user-=1;
	
	return id_vencedor;
}



//imprime Cartas dos jogadores
void imprime_Cartas(Jogador* jogadores, Baralho* cartas,  int qtdCartas_bot, int qtdCartas_user){
	char naipes[4][4] = {"♥", "♦", "♣", "♠" };
	printf("\n Cartas do Computador:\n");
	for(int j = 0; j < qtdCartas_bot; j++){
		int ind_cartaJogador = jogadores[1].cartas_mao[j];
		if(cartas[ ind_cartaJogador ].situacao==2)
			printf(" [%d%s] ", cartas[ ind_cartaJogador ].valor, naipes[ cartas[ ind_cartaJogador ].naipe ]);
	}
	
	printf("\n\n Cartas do usuário:\n");
	for(int j = 0; j < qtdCartas_user; j++){
		int ind_cartaJogador = jogadores[0].cartas_mao[j];
		if(cartas[ ind_cartaJogador ].situacao==1)
			printf(" %d: [%d%s]\n", j+1, cartas[ ind_cartaJogador ].valor, naipes[ cartas[ ind_cartaJogador ].naipe ]);
	}
	
	printf("\n\n");
}


int finalizaJogo(Baralho* cartas, int quemJoga){
	int  contContasDispoviveis = 0, contCartasPlayer = 0, contCartasComp = 0;

	for(int  i = 0; i < 52; i++){
		if(cartas[i].situacao == 0){
			contContasDispoviveis ++;
		}
		if(cartas[i].situacao == 1){
			contCartasPlayer ++;
		}
		if(cartas[i].situacao == 2){
			contCartasComp ++;
		}
	}
	
	if(contContasDispoviveis == 0){
		if(quemJoga == 2){
			phantom("OPS! O computador esgotou o monte.");
			sleep(4);
			system("clear");
			phantom("PARABÉNS! Você venceu a partida!");
		}else{
			phantom("OPS! Você esgotou o monte.\n");
			sleep(4);
			system("clear");
			phantom("O computador venceu a partida!\n");
		}
		return 1;
	}
	
	if((contCartasPlayer == 0)  && (quemJoga == 1)){
		phantom("PARABÉNS! Você esgotou a mão e venceu a partida!");
		return 1;
	}

	
	if(contCartasComp == 0){
		phantom("O computador esgotou a mão e venceu a partida!");
		return 1;
	}
	
	if(contCartasPlayer == 0){
		phantom("PARABÉNS! Você esgotou a mão e venceu a partida!");
		return 1;
	}
	
	
	return 0;
}


int main(){
	srand(time(NULL));
	setbuf(stdin, NULL);
	
	Baralho cartas[52];
	Jogador jogadores[2];
	
	criarBar(cartas);
	distrCartas(jogadores,cartas);
	
	char naipes[4][4] = {"♥", "♦", "♣", "♠" };
	int contCompras=0, contRodadas=1;
	int cartaPC, cartaUser, naipeMesa, qtdCartas_bot=4, qtdCartas_user=4, qtdCartasMao_bot=4, qtdCartasMao_user=4;
	
	printf("\n ______________________________________________________________________________\n");
	printf(" 					  					\n");
	printf("  \t\t   BEM-VINDO AO JOGO DO BURRO\t\t\t	\n");
	printf(" ______________________________________________________________________________\n\n");
	
	printf(" [ %dº Rodada ]\t\t\t\t\t   ", contRodadas++);
	printf("[Restam no monte %d cartas]\n\n", 44 - contCompras);
	
	imprime_Cartas(jogadores, cartas,  qtdCartas_bot, qtdCartas_user);
	
	
	//Inicio do programa ------
	printf(" Você inicia a partida\n");
	do{
		printf("\n Escolha uma carta:  ");
		scanf(" %d", &cartaUser);
		cartaUser -= 1;
		if(cartaUser>=0 && cartaUser<qtdCartasMao_user){
			printf("  Você jogou: [%d%s]\n\n", cartas[ jogadores[0].cartas_mao[cartaUser] ].valor, naipes[ cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe ]);
			break;
		} else 
			printf("\n >>> Opção inválida! Tente novamente.\n");
	}while(1);
	
	naipeMesa = cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe;
	printf("\n Naipe da rodada: %s\n", naipes[naipeMesa]);
	
	cartaPC = cartaBot(jogadores, cartas, naipeMesa, &qtdCartas_bot, &contCompras, &qtdCartasMao_bot);

	printf("\n O Computador escolheu a carta: [%d%s]\n\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
	printf(" ***** Cartas na mesa *****\n");
	printf(" * Usuário: [%d%s] 	 *\n", cartas[ jogadores[0].cartas_mao[cartaUser] ].valor, naipes[ cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe ]);
	printf(" * PC: [%d%s]\t\t *\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
	printf(" **************************\n");
	
	do{
		naipeMesa = -1;
		int vencedor = verificaCartas(jogadores, cartas, cartaUser, cartaPC, &qtdCartas_bot, &qtdCartas_user, &qtdCartasMao_bot, &qtdCartasMao_user);
		tecleEnter_continuar("continuar");
		
		system("clear");
		
		printf("\n ______________________________________________________________________________\n");
		printf(" 					  					\n");
		printf("  \t\t   BEM-VINDO AO JOGO DO BURRO\t\t\t	\n");
		printf(" ______________________________________________________________________________\n\n");
		
		printf(" [ %dº Rodada ]\t\t\t\t\t   ", contRodadas++);
		printf("[Restam no monte %d cartas]\n\n", 44 - contCompras);
		
		imprime_Cartas(jogadores, cartas,  qtdCartas_bot, qtdCartas_user);
		
		if(finalizaJogo(cartas, vencedor)){
			sleep(2);
			printf("\nJogo finalizado\n\n\t\t     Developed by the team: Binary Phantoms\n");
			printf("\t\t    Copyright © 2021  |  Team Binary Phantoms");
			return 0;
		}
		
		if(vencedor==1){
			naipeMesa = -1;
			printf("\n Você inicia a rodada.\nEscolha uma carta: ");
			scanf(" %d", &cartaUser);
			cartaUser -= 1;
			
			naipeMesa = cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe;
			printf("\n Naipe da rodada: %s\n", naipes[naipeMesa]);
			
			printf("\n Agora é a vez do computador: ");
			
			cartaPC = cartaBot(jogadores, cartas, naipeMesa, &qtdCartas_bot, &contCompras, &qtdCartasMao_bot);
			
			printf("\n O computador escolheu a carta: [%d%s]\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
		}
		if(vencedor==2){
			naipeMesa = -1;
			printf("\n Computador inicia a rodada.");
			cartaPC = cartaBot(jogadores, cartas, naipeMesa, &qtdCartas_bot, &contCompras, &qtdCartasMao_bot);
			printf("\n O computador escolheu a carta: [%d%s]\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
			
			naipeMesa = cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe;
			printf("\n Naipe da rodada: %s\n", naipes[naipeMesa]);
			
			printf("\n Agora é a sua vez.\n");
			int respostaUser = userResponde(jogadores, cartas, naipeMesa, &qtdCartas_user, &contCompras, &qtdCartasMao_user);
			
			if(respostaUser == -1){
				do{
					printf("\n Escolha uma carta:  ");
					scanf(" %d", &cartaUser);
					cartaUser -= 1;
					if((cartaUser>=0 && cartaUser<qtdCartasMao_user) && (cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe == naipeMesa)){
						printf("Você jogou: [%d%s]\n\n", cartas[ jogadores[0].cartas_mao[cartaUser] ].valor, naipes[ cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe ]);
						break;
					} else 
						printf("\n >>> Opção inválida! Tente novamente.\n");
				}while(1);
				
			} else cartaUser = respostaUser;
		}
		
		printf(" ***** Cartas na mesa *****\n");
		printf(" * Usuário: [%d%s] 	 *\n", cartas[ jogadores[0].cartas_mao[cartaUser] ].valor, naipes[ cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe ]);
		printf(" * PC: [%d%s]\t\t *\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
		printf(" **************************\n");
		

	}while(1);
	
	
	return 0;
}
