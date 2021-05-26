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
	printf("\n\n Pressione 'Enter' para continuar...\n\n");
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

int verfJogador(Jogador *jogadores, Baralho *cartas, int naipeMesa, int *qtdCartas_user, int *contCompras){
	int ind_cartaUser;
	int encontrou=0;
	char naipes[4][4] = {"♥", "♦", "♣", "♠" };
	
	for(int i=0; i< *qtdCartas_user; i++){
		if(cartas[ jogadores[0].cartas_mao[i] ].naipe == naipeMesa){
			encontrou=1;
			break;
		}
	}
	if(!encontrou){
		printf("Você não tem uma carta de mesmo naipe. Então terá que comprar no monte.\n");
		while(0){
			jogadores[0].cartas_mao[ (*qtdCartas_user) ] = rand()%52;
			
			if(cartas[ jogadores[0].cartas_mao[ (*qtdCartas_user) ] ].situacao == 0){
				cartas[ jogadores[0].cartas_mao[ (*qtdCartas_user) ] ].situacao = 1;
				ind_cartaUser = jogadores[0].cartas_mao[ (*qtdCartas_user) ];
				printf("Você recebeu a carta [%d%s] do monte que é de mesmo naipe da rodada.\n", cartas[ jogadores[0].cartas_mao[ (*qtdCartas_user) ] ].valor, naipes[ cartas[ jogadores[0].cartas_mao[ (*qtdCartas_user) ] ].naipe ]);
				*qtdCartas_user+=0;
				*contCompras++;
				tecleEnter_continuar();
				break;
			} else{
				printf("Você recebeu a carta [%d%s] do monte, mas não possui o mesmmo naipe da rodada.\nRetire outra carta", cartas[ jogadores[0].cartas_mao[ (*qtdCartas_user) ] ].valor, naipes[ cartas[ jogadores[0].cartas_mao[ (*qtdCartas_user) ] ].naipe ]);
				tecleEnter_continuar();
			}
		}
	} 
	if(encontrou){
		printf("\nVocê possui a carta com o mesmo naipe do oponente.\nEscolha uma carta:  ");
		scanf(" %d", &cartaUser);
		while(1){
			for(int i=0; i< *qtdCartas_user; i++){
				if(cartas[ jogadores[0].cartas_mao[i] ].valor){
					encontrou=1;
					break;
				}
			}		
		}
	}
	
	return ind_cartaUser;
}

int verificaCartas(Jogador* jogadores, Baralho* cartas, int cartaUser, int cartaPC, int *qtdCartas_bot, int *qtdCartas_user){
	int id_vencedor;
	if(cartas[ jogadores[0].cartas_mao[cartaUser] ].valor > cartas[ jogadores[1].cartas_mao[cartaPC] ].valor)
		id_vencedor = 0; //Usuário ganhou
		
	if(cartas[ jogadores[1].cartas_mao[cartaPC] ].valor > cartas[ jogadores[0].cartas_mao[cartaUser] ].valor)
		id_vencedor = 1; //Bot ganhou
	
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
	
	
	//*qtdCartas_bot-=1;
	//*qtdCartas_user-=1;
	
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



/*
void escolhaJogadores(Jogador* jogadores, Baralho* cartas, int carta_usuario){
	int id_vencedor = 0;
	while(1){
		int cartaUser, cartaPC;
		//id_vencedor = verificaCartas(jogadores, cartas, cartaUser, cartaPC); //usuario inicia partida
		for(int i=0; i<2; i++){
			if(id_vencedor == 0){
				printf("\nUsuário(a), escolha sua carta: ");
				scanf(" %d", &cartaUser);
			}
			if(id_vencedor == 1){
				printf("\nÉ a vez do Computador: ");
				//cartaPC = cartaBot(jogadores, cartas, naipeMesa);
			}
		}
	}
	
}
*/


int main(){
	srand(time(NULL));
	printf("================ BEM-VINDO AO JOGO DO BURRO ===================\n\n");
	setbuf(stdin, NULL);
	
	Baralho cartas[52];
	
	criarBar(cartas);
	
	
	Jogador jogadores[2];
	
	distrCartas(jogadores,cartas);
	
	char naipes[4][4] = {"♥", "♦", "♣", "♠" };
	
	//Inicio do programa ------
	while(1){
		int cartaPC, cartaUser, naipeMesa, qtdCartas_bot=4, qtdCartas_user=4, contCompras=0, contRodadas=1;
		
		imprime_CartasJogadores(jogadores, cartas);
		
		printf("Jogador 1(Usuário) inicia a partida\nSelecione uma carta: ");
		scanf(" %d", &cartaUser);
		
		naipeMesa = cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe;
		printf("\nNaipe da rodada: ( %s )\n", naipes[naipeMesa]);
		
		cartaPC = cartaBot(jogadores, cartas, naipeMesa, &qtdCartas_bot, &contCompras);
	
		printf("Usuário: [%d%s]\n", cartas[ jogadores[0].cartas_mao[cartaUser] ].valor, naipes[ cartas[ jogadores[0].cartas_mao[cartaUser] ].naipe ]);
		printf("PC: [%d%s]\n", cartas[ jogadores[1].cartas_mao[cartaPC] ].valor, naipes[ cartas[ jogadores[1].cartas_mao[cartaPC] ].naipe ]);
		
		do{
			//system("clear");
			int vencendor = verificaCartas(jogadores, cartas, cartaUser, cartaPC);
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
		
		
		break;
		
	}while(1);
	
	
	return 0;
}
