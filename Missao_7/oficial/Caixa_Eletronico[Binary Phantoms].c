#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAX 1000  //qtd maxima de contas

typedef struct{
	char nomeTitular[200];
	int numConta;
	float saldo;
}Conta_Bancaria;

typedef struct{
	int tipo; //1-debito ou 0-credito
	char descricao[200]; //descricao textual
	int contaOrigem, contaDestino;
	float valor;
}Transacao_Bancaria;

void tecleEnter_continuar(){
	printf("\n\n Pressione 'Enter' para continuar...\n\n");
	setbuf(stdin, NULL);
	getchar();
}

int gerador_NumConta(Conta_Bancaria *clientes, int cont){ //funcao para gerar novo numero de conta
	srand(time(NULL));
	int repetiu=0, numero_conta;
	do{
		int x = rand() % MAX;
		repetiu = 0;
		if((x>99 && x<MAX) && (x%7==0)){
			for(int i=0; i<cont; i++){
				if(x == clientes[i].numConta){
					repetiu=1; 
					break;
				}
			}
		} else repetiu=1;
		if(!repetiu) numero_conta = x;
	}while(repetiu);
	
	return numero_conta;
}


Conta_Bancaria cadastrarContas(Conta_Bancaria *clientes, int cont){ //funcao que cadastra novas contas
	system("clear");
	Conta_Bancaria novoCliente;
	novoCliente.numConta = gerador_NumConta(clientes, cont);
	novoCliente.saldo = 0;
	
	printf("\n ______________________________________________________________________________\n");
	printf(" 					  					\n");
	printf("  \t\t\t    CADASTRO DE CONTA\t\t\t	\n");
	printf(" ______________________________________________________________________________\n");
	printf("\n Número da conta: %d", novoCliente.numConta);
	printf("\n Nome completo: ");
	scanf(" %[^\n]s", novoCliente.nomeTitular);
	printf(" ______________________________________________________________________________\n");
	printf("\n Conta cadastrada com sucesso.");
	tecleEnter_continuar();
	
	return novoCliente;
}


void getContas(Conta_Bancaria *clientes, int cont){ //funcao para imprimir as contas cadastradas
	system("clear");
	for(int i=1; i<cont; i++){
		for(int j=0; j<cont-1; j++){
			if(clientes[i].saldo > clientes[j].saldo){
				Conta_Bancaria aux = clientes[i];
				clientes[i] = clientes[j];
				clientes[j] = aux;
			}
		}
		
	}
	printf("\n ______________________________________________________________________________\n");
	printf(" 					  					\n");
	printf("  \t\t   RELATÓRIO DE CONTAS CADASTRADAS\t\t\t	\n");
	printf(" ______________________________________________________________________________\n");
	for(int i=0; i<cont; i++){
		printf("\n Número da conta: %d", clientes[i].numConta);
		printf("\n Nome do Titular: %s", clientes[i].nomeTitular);
		printf("\n Saldo: %.2f\n", clientes[i].saldo);
		printf(" ______________________________________________________________________________\n");
	}
	tecleEnter_continuar();
}


int existeConta(int num_conta, Conta_Bancaria *clientes, int cont){
	int indice, existe=0;
	for(indice=0; indice<cont; indice++){
		if(num_conta == clientes[indice].numConta || num_conta==0){
			existe=1;
			break;
		}
	}
	
	if(!existe)
		indice = -1;
	if( ((num_conta>0 && num_conta<=99) || num_conta>=MAX) )
		indice = -2;
	return indice;
}

Transacao_Bancaria movimentacaoBancaria(Conta_Bancaria *clientes, int cont){
	Transacao_Bancaria nova_transacao;
	system("clear");
	printf("\n ______________________________________________________________________________\n");
	printf(" 					  					\n");
	printf("  \t\t\t   OPERAÇÃO BANCÁRIA\t\t\t	\n");
	printf(" ______________________________________________________________________________\n");
	int repete=0;
	do{     //lê os dados das contas
		repete=0;
		
		do{ //le e verifica existencia de contaOrigem
			printf("\n Digite o número da conta de ORIGEM (Digite 0, caso seja DEPÓSITO): ");
			scanf(" %d", &nova_transacao.contaOrigem);
			
			if(existeConta(nova_transacao.contaOrigem, clientes, cont) == -1)
				printf(" Conta não encontrada. Tente novamente.\n\n");
			else if(existeConta(nova_transacao.contaOrigem, clientes, cont) == -2)
				printf(" Número da conta inválido. Tente novamente.\n\n");
			else break;
			
		}while(existeConta(nova_transacao.contaOrigem, clientes, cont) == -1 || existeConta(nova_transacao.contaOrigem, clientes, cont) == -2);
		
		do{  //le e verifica existencia de contaDestino
			printf(" Digite o número da conta de DESTINO (Digite 0, caso seja SAQUE): ");
			scanf(" %d", &nova_transacao.contaDestino);
			
			if(existeConta(nova_transacao.contaDestino, clientes, cont) == -1)
				printf(" Conta não encontrada. Tente novamente.\n\n");
			else if(existeConta(nova_transacao.contaDestino, clientes, cont) == -2)
				printf(" Número da conta inválido. Tente novamente.\n\n");
			else break;
			
		}while(existeConta(nova_transacao.contaDestino, clientes, cont) == -1 || existeConta(nova_transacao.contaDestino, clientes, cont) == -2);
		
		int indice_ContaOrigem = existeConta(nova_transacao.contaOrigem, clientes, cont);
		do{
			printf(" Digite o valor: R$ ");
			scanf(" %f", &nova_transacao.valor);
			if(nova_transacao.valor > clientes[ indice_ContaOrigem ].saldo && nova_transacao.contaOrigem!=0)
				printf(" Valor digitado é maior que o saldo. Tente novamente.\n\n");
		} while(nova_transacao.valor > clientes[ indice_ContaOrigem ].saldo && nova_transacao.contaOrigem!=0);
		printf(" Escreva uma descrição: ");
		scanf(" %[^\n]s", nova_transacao.descricao);
		
		
		//Requisita Confirmacao dos dados bancarios
		system("clear");
		printf("\n\n Confirme os dados: ");
		if(nova_transacao.contaOrigem!=0){
			printf("\n _____________________________________\n");
			printf(" 	   CONTA DE ORIGEM 		\n");
			printf(" _____________________________________\n\n");
			for(int i=0; i<cont; i++){
				if(clientes[i].numConta == nova_transacao.contaOrigem){
					printf(" Titular: %s", clientes[i].nomeTitular);
					printf("\n Número da conta: %d\n", clientes[i].numConta);
					printf(" _____________________________________\n");
					
					break;
				}
			}
		}
		if(nova_transacao.contaDestino!=0){
			printf("\n _____________________________________\n");
			printf(" 	   CONTA DE DESTINO 		\n");
			printf(" _____________________________________\n\n");
			for(int i=0; i<cont; i++){
				if(clientes[i].numConta == nova_transacao.contaDestino){
					printf(" Titular: %s", clientes[i].nomeTitular);
					printf("\n Número da conta: %d\n", clientes[i].numConta);
					printf(" _____________________________________\n");
					break;
				}
			}
		}
		printf(" Descrição: %s\n", nova_transacao.descricao);
		printf(" Valor: R$%.2f\n", nova_transacao.valor);
		printf(" _____________________________________\n");
		
		int escolha;
		do{
			printf("\n Selecione uma opção:\n 1- Confirmar transação\n 2- Corrigir os dados\n Opção: ");
			scanf(" %d", &escolha);
			if(escolha<=0 || escolha>=3)
				printf(" Opção inválida. Tente novamente!\n");
		}while(escolha<=0 || escolha>=3);
		
		if(escolha==1) repete=0;
		else if(escolha==2) repete=1;
		
	}while(repete);
	
	if(nova_transacao.contaOrigem==0){ //Deposito
		nova_transacao.tipo = 0;
		
		for(int i=0; i<cont; i++){
			if(clientes[i].numConta == nova_transacao.contaDestino)
				clientes[i].saldo += nova_transacao.valor;
		}
		printf("\n Depósito realizado com sucesso!");
		tecleEnter_continuar();
	}
	
	if(nova_transacao.contaDestino==0){ //Saque
		nova_transacao.tipo = 1;
		for(int i=0; i<cont; i++){
			if(clientes[i].numConta == nova_transacao.contaOrigem)
				clientes[i].saldo -= nova_transacao.valor;
		}
		printf("\n Saque realizado com sucesso!");
		tecleEnter_continuar();
	}
	
	if(nova_transacao.contaOrigem!=0 && nova_transacao.contaDestino!=0){ //Transferencia
		nova_transacao.tipo = 1;
		for(int i=0; i<cont; i++){
			if(clientes[i].numConta == nova_transacao.contaOrigem)
				clientes[i].saldo -= nova_transacao.valor;
			if(clientes[i].numConta == nova_transacao.contaDestino)
				clientes[i].saldo += nova_transacao.valor;
		}
		printf("\n Transferência realizada com sucesso!");
		tecleEnter_continuar();
	}
	return nova_transacao;
}


void getRegistro(Transacao_Bancaria *historicoTransacoes, int contHist){
	system("clear");
	char tipo_CredDeb[2][9] = {"Crédito", "Débito"};
	
	printf("\n ______________________________________________________________________________\n");
	printf(" 					  					\n");
	printf("  \t\t   RELATÓRIO GERAL DE MOVIMENTAÇÕES\t\t\t	\n");
	printf(" ______________________________________________________________________________\n");
	
	for(int i=0; i<contHist; i++){
		printf(" _______________________________\n\n");
		printf(" Descrição: %s", historicoTransacoes[i].descricao);
		printf("\n Número da conta (ORIGEM): %d", historicoTransacoes[i].contaOrigem);
		printf("\n Número da conta (DESTINO): %d", historicoTransacoes[i].contaDestino);
		printf("\n Tipo: %s\n", tipo_CredDeb[historicoTransacoes[i].tipo]);
		printf(" Valor: R$%.2f\n", historicoTransacoes[i].valor);
		printf(" _______________________________\n\n");
		
	}
	tecleEnter_continuar();
}

int menuPrincipal(){
	system("clear");
	printf("\n ______________________________________________________________________________\n");
	printf(" 					  					\n");
	printf("  \t\t   MENU PRINCIPAL DO CAIXA ELETRÔNICO\t\t\t	\n");
	printf(" ______________________________________________________________________________\n");
	
	printf("\n 1- Cadastro de conta bancária\n 2- Realizar operação bancária (Depositar, Sacar ou Transferência entre contas)\n 3- Registro Geral de Movimentações\n 4- Relatório de Contas\n 5- Encerra sessão\n");
	printf("\n Opção: ");
	int op;
	scanf(" %d", &op);
	while(op<=0 || op>7){
		printf(" Opção inválida. Tente novamente!\n");
		printf(" Opção: ");
		scanf(" %d", &op);
	}
	
	return op;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	Conta_Bancaria clientes[MAX];
	Transacao_Bancaria historicoTransacoes[10000];
	
	int cont = 0, contHist;
	
	while(1){
		int opcao = menuPrincipal();
		switch(opcao){
			case 1: clientes[cont] = cadastrarContas(clientes, cont);
					cont++;
					break;
					
			case 2: historicoTransacoes[contHist] = movimentacaoBancaria(clientes, cont);
					contHist++;
					break;
			
			case 3: getRegistro(historicoTransacoes, contHist);
					break;
			
			case 4: getContas(clientes, cont);
					break;
					
			case 5: printf("\nSessão encerrada. Programa finalizado.\n\n\n\n\t\t     Developed by the team: Binary Phantoms\n");
					printf("\t\t    Copyright © 2021  |  Team Binary Phantoms");
					return 0;
		}
	}

	return 0;
}
