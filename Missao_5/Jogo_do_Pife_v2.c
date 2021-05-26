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
 * 	   Feito isso, feche o terminal e ja pode iniciar o jogo.
 * 
 * Divirta-se! :D
 * 
 * Developed by the team: Binary Phantoms.
 */

typedef struct{
	int num, estado;
} baralho;

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
    
    baralho cartas[9];
    char letrasCartas[8][2] = {"A", "J", "Q", "K", "a", "j", "q", "k"};
    int numerosCartasLetra[8] = {1, 11, 12, 13, 1, 11, 12, 13}; //valor das cartasEspeciais
    char nomesCartas[13][3] = {"A", "2","3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}; //usado na hora do printf
    
    //Preencher vetor cartas sem repeticao de naipes
    int repetiu = 0;
	for(int i=0; i<9; i++){
		cartas[i].num = (rand()%13) + 1;
		cartas[i].estado = 1;
	
		do{
			repetiu = 0;
			for(int j=0; j<i; j++){
				if(cartas[i].num == cartas[j].num){
					cartas[i].num = (rand()%13) + 1;
					repetiu = 1;
					break;
				}
			}
		}while(repetiu);	
	}
	
	//Ordena baralho (selection)
	for(int i=0; i<9-1; i++){
		int menor = i;
		for(int j=i+1; j<9; j++){
			if(cartas[menor].num > cartas[j].num)
				menor = j;
		}
		baralho aux = cartas[i];
		cartas[i] = cartas[menor];
		cartas[menor] = aux;
	}
	
	
	//Imprime o baralho
	for(int i=0; i<9; i++){
		printf("[%s]", nomesCartas[cartas[i].num-1]);
		if(i==2 || i==5) printf(" || ");
	}
	
	
    //INICIO DO JOGO
    while(1){
		//Identifica trincas
		
		
		//Move trincas para o final do vetor / ordenação ordem decrescente pelo valor do estado (insertion)
		
		//Printa baralho
		
		//Troca carta do baralho
		
		//Trata a escolha
		
		//Verifica a existencia da carta escolhida e substitui caso seja encontrada
		
			//substitui carta escolhida sem repetiro o naipe
		
		//Ordena baralho (selection)
		
		//Printa baralho
	}
    
    
    
    
    
    
    
    return 0;
}
