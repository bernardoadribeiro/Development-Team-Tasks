#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h> //biblioteca usar a funcao sleep();

/* IMPORTANTE: 
 * 	Este programa funcionara apenas no ambiente linux devido alguns comandos utilizados.
 * 	Para que nao haja erros de execucao, antes de iniciar o jogo, instale estes dois pacotes pelo terminal:
 *	   1- sudo apt-get install cowsay
 *	   2- sudo apt-get install figlet
 * 
 * 	   Feito isso, feche o terminal e ja pode iniciar o jogo.
 * 
 * Divirta-se! :D
 * 
 * Developed by the team: Binary Phantoms.
 */

int main(){
    setlocale(LC_ALL, ("Portuguese"));
    
    //APRESENTACAO INICIAL DO GAME
    /*
    system("echo Developed by the team: ");
    system("figlet Binary Phantoms");
    sleep(4);
    system("clear");
    system("cowsay Olá humano, eu sou a Cowsay.");
    sleep(2);
    system("clear");
    system("cowsay Seja bem-vindo ao JOGO DO PIFE!");
    sleep(3);
    system("clear");
    system("cowsay Caso não saiba como jogar, irei te ensinar.");
    sleep(3);
    system("clear");
    system("cowsay Basicamente o que precisa fazer é formar 3 trincas Ex.: 9 9 9...");
    sleep(5);
    system("clear");
    system("cowsay e/ou 3 sequências. Ex.: 1 2 3.");
    sleep(3);
    system("clear");
    system("cowsay Pronto para começar? hehe");
    sleep(1);
    printf("\nAperte 'Enter' para começar a jogar...");
    setbuf(stdin, NULL);
    getchar();
    system("clear");
    */
    //----------------------------------------------------
    
    srand(time(NULL));
    int cartas[9];

    //INICIO - Distribuicao das cartas
    for(int i=0;i<9;i++){
	cartas[i]= (rand() % 13)+1;
	printf("%d ", cartas[i]);
    }
    printf("\n\n");

    //SUBSTITUICAO E VERIFICACAO DAS CARTAS
    int troca=0, contTrinca=0, exibeCowSay=0;
    while(1){
	int trocaFeita=0;
	//ORDENA AS CARTAS
	for(int i=0;i < 9-(contTrinca*3);i++){
	    int menor = i;
	    for(int j=i+1; j<9; j++)
		if(cartas[j] < cartas[menor])
		    menor = j;
	    
	    int aux = cartas[menor];
	    cartas[menor] = cartas[i];
	    cartas[i] = aux;

	    printf("%d ", cartas[i]);
	    
	    if(i==2 || i==5) printf("|| ");
	}
	


	//VERIFICA AS CARTAS E TIRA CASO HAJA TRINCA
	for(int i=0; i<9-(contTrinca*3);i++)
	    if(((cartas[i] == cartas[i+1]-1) && (cartas[i] == cartas[i+2]-2)) || ((cartas[i] == cartas[i+1]) && (cartas[i] == cartas[i+2]))){
		contTrinca++;
		exibeCowSay=1;
		
		int x=0;
		while(x<9){
		    cartas[i]=cartas[i+1];
		    cartas[i+1]=cartas[i+2];
		    x++;
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
	for(int i=0; i<9-(contTrinca*3); i++){
	    
	    if(troca == cartas[i]){
		OK=1; break;
	    } else OK=0;
	    
	    if(OK==1)
		break;
	    if(OK==0 && i==(2-(contTrinca*3))){
		system("cowsay Ops! Carta não encontrada. Tente novamente.");
		sleep(0.5);
		printf("\n\n");
	    }
	}
	    
	if(OK)
	    for(int i=0; i<9-(contTrinca*3); i++){

		if(cartas[i]==troca){
		    cartas[i]= (rand() % 13)+1;
		    trocaFeita=1;
		    printf("Carta %d substituída pela %d\n\n", troca, cartas[i]);
		    break;
		}

		if(trocaFeita) break;
	    }

    }

    return 0;
}
