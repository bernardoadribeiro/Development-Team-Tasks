
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

void phantom(char * mensagem){ //funcao simples para exibir o phantom ('cuz we are the Binary Phantoms)
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
    

/*	
    //APRESENTACAO INICIAL DO GAME
    system("echo Developed by the team: ");
    system("figlet Binary Phantoms");
    sleep(5);
    system("clear");
    phantom("Olá humano, eu sou o Phantom.");
    sleep(3);
    system("clear");
    phantom("Seja bem-vindo ao JOGO DO PIFE!");
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
    phantom("Por definição o jogo dará cartas com pintas diferentes");
    sleep(6);
    system("clear");
    phantom("Pronto para começar? hehe");
    sleep(2);
    printf("\nAperte 'Enter' para começar a jogar...");
    setbuf(stdin, NULL);
    getchar();
    system("clear");
    //----------------------------------------------------
*/	

    srand(time(NULL));
    char cartas[9];
	
	for(int i=0; i<9; i++)
		cartas[i] = (rand() % 13)+1;
	
	//SUBSTITUICAO E VERIFICACAO DAS CARTAS
	char carta_str[2];
	int numero_escolhido, qtdCartas = 9, contTrinca = 0, qtdCartas_anterior, troca, exibePhantom=0;
	while(1){
		int trocaFeita=0;
		
		//Ordena as cartas [selection]
		for(int i=0; i<9-1; i++){
		    int menor = i;
		    for(int j=i+1; j<9; j++){
			if(cartas[menor] > cartas[j])
			    menor = j;
		    }
		    int aux = cartas[i];
		    cartas[i] = cartas[menor];
		    cartas[menor] = aux;
		}
	
		
		//Imprime baralho 
		for(int i=0; i<9; i++){
		    if(cartas[i] == 1)
			printf("[A] ");
		    else if(cartas[i] == 11)
			printf("[J] ");
		    else if(cartas[i] == 12)
			printf("[Q] ");
		    else if(cartas[i] == 13)
			printf("[K] ");
		    else printf("[%d] ", cartas[i]);
			
		    if(i==2 || i==5) printf(" || ");
		}
		
		//Verifica a existencia de trinca
		int trinca=0;
		
		qtdCartas_anterior =  qtdCartas;
		
		for(int i=0; i<qtdCartas; i+=3){
			if(((cartas[i] == cartas[i+1]) && (cartas[i] == cartas[i+2])) || (((cartas[i+2] - cartas[i+1]) == 1) && ((cartas[i+1] - cartas[i]) == 1))){
				contTrinca++;
				qtdCartas -= 3;
				trinca = 1;
				
				int x=0;
				while(x<3){
					cartas[i]=cartas[i+1];
					cartas[i+1]=cartas[i+2];
					x++;
				}
			}
		}
		
		if(trinca){ printf("\n"); phantom("PARABÉNS! Você formou trinca(s) e/ou sequencia(s)!" ); printf("\n"); } 		
			
		if(contTrinca == 3) break; //encerra o jogo caso seja formado as 3 trincas
		
	}	
	
	return 0;
}
