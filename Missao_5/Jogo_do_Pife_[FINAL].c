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
    
    //INICIO - Distribuicao das cartas
    for(int i=0;i<9;i++)
	cartas[i]= (rand() % 13) + 1;

    //SUBSTITUICAO E VERIFICACAO DAS CARTAS
    int troca, contTrinca, exibePhantom=0;
    char troca_Str[2];
    while(1){
	int trocaFeita=0;
	//ORDENA AS CARTAS
	
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

	
	//Imprime baralho inicial
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

	
	//VERIFICA AS CARTAS E TIRA CASO HAJA TRINCA
	for(int i=0; i<(3-contTrinca);i++)
	    for(int j=0; j<3; j++)
		if(((cartas[i][j] == cartas[i][j+1]-1) && (cartas[i][j] == cartas[i][j+2]-2)) || ((cartas[i][j] == cartas[i][j+1]) && (cartas[i][j] == cartas[i][j+2]))){
		    contTrinca++;
		    exibePhantom=1;
		    
		    int x=0;
		    while(x<3){
			cartas[i][j]=cartas[i+1][j];
			cartas[i+1][j]=cartas[i+2][j];
			j++; x++;
		    }
		}
	
	if(exibePhantom==1){
	    phantom("PARABÉNS!! Você formou uma trinca!");
	    sleep(0.5);
	    exibePhantom=0;
	}	
	
	if(contTrinca==3){
	    printf("\n\n");
	    phantom("PARABÉNS! Você venceu o jogo!");
	    sleep(4);
	    printf("\n\n");
	    system("echo Develop by the team: ");
	    system("figlet Binary Phantoms");
	    
	    break;
	}
	
	printf("\nDeseja trocar qual carta?\n");
	scanf(" %s", troca_Str);
	
	//Converte a escolha - transformar a face da carta em numero
	for(int i=0; i<9; i++){
	    if(troca_Str == "A")
		cartas[i] = 1;
	    else if(troca_Str == "J")
		cartas[i] = 11;
	    else if(troca_Str == "Q")
		cartas[i] = 12;
	    else if(troca_Str == "K")
		cartas[i] = 13;
	    else cartas[i] = atoi(troca_Str);
		
	    if(i==2 || i==5) printf(" || ");
	}
	
	int OK=0;
	for(int i=0; i<qtdCartas; i++){
	    if(troca == cartas[i]){
		OK=1;
		break;
	    } else OK=0;
	    
	    if(OK==1)
		break;
	    if(OK==0 && i==(2-contTrinca)){
		system("cowsay Ops! Carta não encontrada. Tente novamente.");
		sleep(0.5);
		printf("\n\n");
	    }
	}
	    
	if(OK)
	    for(int i=0; i<(3-contTrinca); i++){
		for(int j=0; j<3; j++){
		    if(cartas[i][j]==troca){
			cartas[i][j]= rand() % 14;
			trocaFeita=1;
			printf("Carta %d substituída pela %d\n\n", troca, cartas[i][j]);
			break;
		    }
		}
		if(trocaFeita) break;
	    }

    }

    return 0;
}
