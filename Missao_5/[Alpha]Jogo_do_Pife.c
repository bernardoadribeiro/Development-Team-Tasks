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
    srand(time(NULL));
    char cartas[9][5];

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
	

    //INICIO - Distribuicao das cartas
    for(int i=0;i<3;i++)
	for(int k=0;k<3;k++)
	    cartas[i][k]= rand() % 14;

    //SUBSTITUICAO E VERIFICACAO DAS CARTAS
    int troca, contTrinca, exibeCowSay=0;
    while(1){
	int trocaFeita=0;
	//ORDENA AS CARTAS
	for(int k=0;k < (3-contTrinca);k++){
	    for(int i=0; i<3; i++){
		int menor = i;
		for(int j=i+1; j<3; j++)
		    if(cartas[k][j] < cartas[k][menor])
			menor = j;
		int t = cartas[k][menor];
		cartas[k][menor] = cartas[k][i];
		cartas[k][i] = t;

		printf("%d ", cartas[k][i]);
	    }
	    if(k!=2) printf("|| ");
	}
	
	//VERIFICA AS CARTAS E TIRA CASO HAJA TRINCA
	for(int i=0; i<(3-contTrinca);i++)
	    for(int j=0; j<3; j++)
		if(((cartas[i][j] == cartas[i][j+1]-1) && (cartas[i][j] == cartas[i][j+2]-2)) || ((cartas[i][j] == cartas[i][j+1]) && (cartas[i][j] == cartas[i][j+2]))){
		    contTrinca++;
		    exibeCowSay=1;
		    
		    int x=0;
		    while(x<3){
			cartas[i][j]=cartas[i+1][j];
			cartas[i+1][j]=cartas[i+2][j];
			j++; x++;
		    }
		}
	
	if(exibeCowSay==1){
	    system("cowsay PARABÉNS!! Você formou uma trinca!");
	    sleep(0.5);
	    exibeCowSay=0;
	}	
	
	if(contTrinca==3){
	    printf("\n\n");
	    system("cowsay PARABÉNS! Você venceu o jogo!");
	    sleep(4);
	    printf("\n\n");
	    system("echo Develop by the team: ");
	    system("figlet Binary Phantoms");
	    
	    break;
	}
	
	printf("\nDeseja trocar qual carta?\n");
	scanf(" %d", &troca);
	
	int OK=0;
	for(int i=0; i<(3-contTrinca); i++){
	    for(int j=0; j<3; j++){
		if(troca == cartas[i][j]){
		    OK=1; break;
		} else OK=0;
	    }
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
