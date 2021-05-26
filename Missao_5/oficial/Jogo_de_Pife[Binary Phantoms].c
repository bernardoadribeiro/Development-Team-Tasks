#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> //para usar a funcao sleep

/* IMPORTANTE: 
 *  EXECUTANDO EM AMBIENTE LINUX
 * 	  Para que nao haja erros de execucao, antes de iniciar o jogo, instale este pacote pelo terminal:
 *	   	  " sudo apt-get install figlet " (sem as aspas)
 *    Feito isso, feche o terminal e ja pode iniciar o jogo.
 * 
 * EXECUTANDO EM OUTRO AMBIENTE
 * 	  Este programa podera apresentar erros caso nao seja executado no ambiente linux devido alguns 
 * 	  comandos utilizados. Mas para que  isso nao ocorra e ele funcione em outro OS diferente de Linux, 
 * 	  basta remover ou comentar a linha onde tem: system("figlet Binary Phantoms");
 * 
 * 
 * Divirta-se! :D
 * 
 * Developed by the team: Binary Phantoms.
 */
 
typedef struct{     //serve para 'armazenar' as caracteriscticas da carta
	int num, estado;
} baralho;

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

int main(){

	srand(time(NULL));
	baralho cartas[9];
	char letrasCartas[8][2] = {"A", "J", "Q", "K", "a", "j", "q", "k"};
	int numerosCartasLetra[8]    = {1,   11,  12,  13,  1,  11,   12,  13};
	char nomesCartas[13][3] = {"A", "2","3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

	
	//APRESENTACAO INICIAL DO GAME
    system("echo Developed by the team: ");
    system("figlet Binary Phantoms");
    sleep(5);
    system("clear");
    phantom("Olá humano, eu sou o Phantom.");
    sleep(3);
    system("clear");
    phantom("Seja bem-vindo ao JOGO DE PIFE!");
    sleep(4);
    system("clear");
    phantom("Caso não saiba como jogar, irei te ensinar.");
    sleep(4);
    system("clear");
    phantom("Você precisa formar 3 trincas Ex.: 9 9 9...");
    sleep(4);
    system("clear");
    phantom("e/ou 3 sequências. Ex.: 1 2 3.");
    sleep(4);
    system("clear");
    phantom("Pronto para começar? hehe");
    sleep(2);
    printf("\nAperte 'Enter' para começar a jogar...");
    setbuf(stdin, NULL);
    getchar();
    system("clear");
    //----------------------------------------------------

	
	//INICIO - Distribuicao das cartas
	for(int i=0; i<9; i++){
		cartas[i].num = (rand()%13) + 1;
		cartas[i].estado = 1; //estado == 1 significa que nao foi formado trinca com a carta
	}
	
	
	//INICIO DO JOGO
	char carta_str[2];
	int numero_escolhido, qtdCartas = 9, contTrinca = 0, qtdCartas_anterior;
	baralho nova_carta;
	
	while(1){	
		//ORDENA AS CARTAS (selection)
		for(int i=0; i<qtdCartas-1; i++){
			int menor = i;
			for(int j=i+1; j<qtdCartas; j++){
				if(cartas[menor].num > cartas[j].num)
					menor = j;
			}
			baralho aux = cartas[i];
			cartas[i] = cartas[menor];
			cartas[menor] = aux;
		}
		
		//IMPRIME O BARALHO
		for(int i=0; i<qtdCartas; i++){
			printf("[%s] ", nomesCartas[cartas[i].num-1]);
			if(i==2 || i==5) printf(" ||  ");
		}
		
		//VERIFICA AS CARTAS E ALTERA O ESTADO PARA ZERO CASO HAJA TRINCA
		int trinca=0;
		qtdCartas_anterior =  qtdCartas;
		
		for(int i=0; i<qtdCartas; i+=3){
			if(((cartas[i].num == cartas[i+1].num) && (cartas[i].num == cartas[i+2].num)) || (((cartas[i+2].num - cartas[i+1].num) == 1) && ((cartas[i+1].num - cartas[i].num) == 1))){
				cartas[i].estado = 0;
				cartas[i+1].estado = 0;
				cartas[i+2].estado = 0;
				contTrinca++;
				qtdCartas -= 3;
				trinca = 1;
			}
		}
		
		//Move as trincas para o final do vetor - ordena em ordem decrescente pelo valor do estado [selection]
		for(int i=1; i<qtdCartas_anterior;i++){
			for(int j=0; j<qtdCartas_anterior; j++){
				if(cartas[i].estado > cartas[j].estado){
					baralho aux = cartas[i];
					cartas[i] = cartas[j];
					cartas[j] = aux;
				}
			}
		}
		
		if(trinca){ printf("\n"); phantom("PARABÉNS! Você formou trinca(s) e/ou sequencia(s)!"); printf("\n"); } 
			
		if(contTrinca == 3) break; //encerra o jogo caso seja formado as 3 trincas
		
		//TROCAR CARTA DA MAO
		printf("\nQual carta deseja trocar?");
		printf("\nCarta: ");
		scanf(" %s", carta_str);
		
		//CONVERSOR - transformar a face da carta em numero
		numero_escolhido = 0;
		for(int i=0; i<8; i++){
			if(strcmp(carta_str, letrasCartas[i]) == 0){
				numero_escolhido = numerosCartasLetra[i];
				break;
			}
		}
		
		if(!numero_escolhido){
			numero_escolhido = atoi(carta_str);
		}
		
		//VERIFICA PARA FAZER A SUBSTITUICAO DA CARTA
		int encontrou = 0;
		for(int i=0; i<qtdCartas; i++){
			if((cartas[i].num == numero_escolhido)){
				encontrou = 1;
				nova_carta.num = (rand()%13) + 1;;
				cartas[i] = nova_carta;
				printf("A carta [%s] foi trocada pela carta [%s]\n\n",nomesCartas[numero_escolhido-1], nomesCartas[cartas[i].num-1]);
				break;
			}
		}
		
		if(!encontrou){ phantom("Ops! Carta não encontrada. Tente novamente..."); printf("\n\n");}

	}
	
	sleep(4);
	system("clear");
	printf("\n\n");
	phantom("Uau!");
	sleep(2);
	system("clear");
	phantom("PARABÉNS! Você venceu o jogo!");
    sleep(4);
    printf("\n\n");
    system("echo Developed by the team: ");
    system("figlet Binary Phantoms");
    printf("Obrigado por jogar!");
    
	return 0;
}
