#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>


int main(){
	setlocale(LC_ALL, "Portuguese"); //para aceitar acentuação e Ç
	
	printf("---------------------------------------\n");
	printf("---------- JOGO DA MEMÓRIA ------------\n");
	printf("---------------------------------------\n");
	printf("Informe quantas palavras desejar (Máximo 30).\nPara finalizar, informe a palavra 'fim'.\n");
	
	
	char palavra[32], cartas[60][32], backupCartas[60][32], cartasAbertas[60][32];
	int qtdCartas=0;
	
	
	//SCANEIA E DUPLICA AS CARTAS
	for(int i=0; i<30; i+=2){
		scanf(" %[^\n]s", palavra);
		
		if(!strstr(palavra, "fim")){
			strcpy(cartas[i], palavra);
			strcpy(cartas[i+1], palavra);
			strcpy(backupCartas[i], palavra);
			strcpy(backupCartas[i+1], palavra);
			qtdCartas+=2;
		} else
			break;
	}
	
	
	system("clear"); //limpa tela
	
	
	//EMBARALHADOR DE CARTAS 
	srand(time(NULL)); 				//Altera a semente de geracao de nums aleatorios
	int embaralhador[30], cont=0;;
	do{
		int repetido=0; 
		int x = rand() % qtdCartas;
		
		for(int i=0; i<cont; i++)
			if(x == embaralhador[i])
				repetido++;
				
		if(!repetido){
			embaralhador[cont] = x;
			cont++;
		}
		
		for(int i=0; i<cont; i++){
			int y=embaralhador[i];
			strcpy(cartas[i], backupCartas[y]);
		}
		
	}while(cont<qtdCartas);
	
	
	//INICIO DO JOGO - Escolher cartas
	int escolha1=0, escolha2=0, jogadas=0, contEncontradas=0, primeiroMatch=0, numCartasAbertas[60];
	
	
	for(int i=0; i<qtdCartas;i++)	//inializando o vetor com o valor zero, para que n receba lixo de memoria etc.
		numCartasAbertas[i]=0;
    
	
	while(1){
		setbuf(stdin, NULL); //limpa buffer do teclado
		
		for(int i=0; i<qtdCartas; i++){
			if(primeiroMatch==1){			 //verifica se ja ocorreu o primeiro match
				if(numCartasAbertas[i]==1)   //caso tenha ocorrido, imprime as cartas ja encontradas
					printf("%.2d: [%s]\n", i, cartasAbertas[i]);
				else printf("%.2d\n", i);  //caso ocorreu, mas incide diferente, printf apenas o indice das cartas
			} else printf("%.2d\n", i);    //caso nao tenha ocorrido, imprime apenas o indice das cartas
			
		}
		printf("Escolha sua carta 1: ");
		scanf(" %d", &escolha1);
		
		system("clear");
		
		for(int i=0; i<qtdCartas; i++){
			if(i==escolha1)				//verifica a carta da escolha 1 para abri-la
				printf("%.2d: [%s]\n", escolha1,cartas[escolha1]);
			  					
			else if(primeiroMatch==1){             
				if(numCartasAbertas[i]==1)			
					printf("%.2d: [%s]\n", i, cartasAbertas[i]);
				else printf("%.2d\n", i); 
			} else printf("%.2d\n", i); 	  
		}
			
		printf("Escolha sua carta 2: ");
		scanf(" %d", &escolha2);
		
		
		//VERIFICANDO AS CARTAS
		if(escolha1==escolha2){    		//msg de erro caso o usuario escolha a mesma carta
			printf("As cartas escolhidas devem ser DIFERENTES!");
			setbuf(stdin, NULL);
			getchar();
			system("clear");
			
		} 
		else if( (strstr(cartasAbertas[escolha1], cartas[escolha1])) || (strstr(cartasAbertas[escolha1], cartas[escolha2])) || (strstr(cartasAbertas[escolha2], cartas[escolha1])) || (strstr(cartasAbertas[escolha2], cartas[escolha2])) || (escolha1>qtdCartas || escolha2>qtdCartas) ){ 
			printf("Escolha de Cartas INVALIDA!");   //Nao deixa o usuario escolher um par que ja foi encontrado ou uma carta que n existe
			setbuf(stdin, NULL);
			getchar();
			system("clear");
		}
		else {				//caso as cartas escolhidas forem diferentes...
			system("clear");
			
			for(int i=0; i<qtdCartas; i++){
				if(i==escolha1)				//verifica a carta da escolha 1 para abri-la
					printf("%.2d: [%s]\n", i,cartas[i]);					
				 
				else if(i==escolha2)			//verifica a carta da escolha 2 para abri-la
					printf("%.2d: [%s]\n", i,cartas[i]);
					
				else if(primeiroMatch==1){
					if(numCartasAbertas[i]==1)
						printf("%.2d: [%s]\n", i, cartasAbertas[i]);
					else printf("%.2d\n", i); 
				} else printf("%.2d\n", i);   
			}
			
			
			//VERIFICA SE AS CARTAS SAO IGUAIS OU NAO
			if(strstr(cartas[escolha1],cartas[escolha2])){   //compara se sao iguais
				printf("PAR ENCONTRADO!\n");
				jogadas++; contEncontradas++;
				setbuf(stdin, NULL);
				getchar();
				system("clear");
				
				strcpy(cartasAbertas[escolha1], cartas[escolha1]); //copia da carta encontrada p/ vetor cartasAbertas
				strcpy(cartasAbertas[escolha2], cartas[escolha2]); 
				
				numCartasAbertas[escolha1] = 1; //variavel para confirmar as cartas que foram abertas
				numCartasAbertas[escolha2] = 1; 
				
				primeiroMatch=1; //confirma que pelo menos um o par foi feito
								
			} else{
				printf("Tente novamente...\n"); //Caso nao forem iguais...
				jogadas++;
				setbuf(stdin, NULL);
				getchar();
				system("clear");
			}
		}
		
		if(contEncontradas==(qtdCartas/2)){
			printf("VOCÊ VENCEU O JOGO APÓS %d JOGADAS!\n", jogadas);
			break;
		}
		
	}
	
	return 0;
}
