#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
	int id, qtd_estoque;
	float preco;
	char descricao[100];
} Produto;

typedef struct{
	int produtosVendidos[10000], contProdVendidos;
	float totalVenda;
} Venda;

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	char nome_supermercado[100], nome_usuario[100];;
	
	printf("Insira o nome do supermercado: ");
	scanf("%[^\n]s", nome_supermercado);
	getchar();
	printf("\nInsira o nome de usuario: ");
	scanf("%[^\n]s", nome_usuario);
	getchar();
	system("clear");
	
	printf("Bem vindo(a) ao Sistema de Vendas [usuário: %s]\t[ Supermercado %s ]", nome_usuario, nome_supermercado);
	
	
	//CADASTRO DE PRODUTOS -----
	Produto produtos[1000];
	int cont=0, resp=1;   //cont conta os produtos cadastrados
	
	while(resp){
		printf("\n\n=============== CADASTRO DE PRODUTOS ===============\n\n");
		
		printf("ID: "); 					scanf("%d", &produtos[cont].id);
		setbuf(stdin, NULL);
		printf("Descrição: "); 				scanf("%[^\n]s", produtos[cont].descricao);
		printf("Qtd. Estoque: "); 			scanf("%d", &produtos[cont].qtd_estoque);
		printf("Preço: R$"); 					scanf("%f", &produtos[cont].preco);
		//printf("Validade (dd/mm/aaaa): "); 	scanf("%d %d", &produtos[cont].validade);
		cont++;
		
		printf("\nDeseja cadastrar outro produto? [ 1-Sim | 0-Não ]\n"); 
		scanf("%d", &resp);
		if(resp!=0 && resp!=1)
			while(resp!=0 && resp!=1){
				printf("ERROR! Digite uma opção válida\n");
				printf("Deseja cadastrar outro produto? [ 1-Sim | 0-Não ]\n"); 
				scanf("%d", &resp);
			}
		else if(resp==0) break;
	}
	
	//imprime produtos cadastrados - teste::::
	printf("\n\n=============== PRODUTOS CADASTRADOS ===============\n\n");
	for(int i=0; i<cont; i++){
		printf("ID: %.4d\n", produtos[i].id);
		printf("Descrição: %s\n", produtos[i].descricao);
		printf("Qtd. Estoque: %d\n", produtos[i].qtd_estoque);
		printf("Preço: R$%.2f\n", produtos[i].preco);
		printf("\n====================================================\n\n");
	}
	
	
	
	
	
	return 0;
}
