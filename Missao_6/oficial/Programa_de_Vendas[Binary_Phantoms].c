#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
	int id, estoque;
	float preco;
	char descricao[100];
} Produto;

typedef struct{
	Produto produtosVendidos;
	int quantidade;
	float totalVenda;
	char nome_cliente[200];
	int qtdtotal;
} Venda;

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	char nome_supermercado[100], nome_usuario[100];;
	
	printf("Insira o nome do estabelecimento: ");
	scanf("%[^\n]s", nome_supermercado);
	setbuf(stdin, NULL);
	printf("Insira o nome do usuário: ");
	scanf("%[^\n]s", nome_usuario);
	setbuf(stdin, NULL);
	
	//variaveis
	Produto p[1000];
	
	Venda v[1000];
	int match=0, executa=1, x=0, cnc=0;
	float valor_total_geral;
	
	int cont=0, resp=1;
	
	//LAÇO DE TODO O PROGRAMA;
	int primeiraExec=1;
	while(1){
		system("clear");
		
		printf("Bem vindo(a) ao Sistema de Vendas [usuário: %s]\t[ %s ]\n", nome_usuario, nome_supermercado);
		
		//MENU PRINCIPAL
		int opcao=0, cadastro=0, venda=0, fecharCaixa=0, mostraCadastrados=0;
		
		if(primeiraExec){
			printf("\nAVISO!\nÉ preciso que faça o cadastro de pelo menos um produto antes de continuar.\n\nPressione 'Enter' para continuar.\n");
			setbuf(stdin, NULL);
			getchar();
			cadastro=1, opcao=1;
			primeiraExec=0;
		} else{
			printf("\n\n----====== MENU PRINCIPAL ======----\n\nSelecione umas das opções abaixo:\n\n");
			printf("1- Cadastrar produtos \n2- Realizar vendas \n3- Fechar o caixa\n4- Mostrar produtos cadastrados\n");
			printf("\nOpção: "); 
			scanf(" %d", &opcao);
			if(opcao==1) cadastro=1;
			else if(opcao==2) venda=1;
			else if(opcao==3) fecharCaixa=1;
			else if(opcao==4) mostraCadastrados=1;
			else {
				printf("Digite uma opção válida.\n\nPressione 'Enter' para continuar.\n"); 
				setbuf(stdin, NULL);
				getchar();
			}
			opcao=0;
		}
		system("clear");
		
		//CADASTRO DE PRODUTOS -----
		if(cadastro==1){
			while(1){
				printf("\nSistema de Vendas \t\t[usuário: %s]\t[ %s ]\n", nome_usuario, nome_supermercado);
				printf("\n\n=============== CADASTRO DE PRODUTOS ===============\n\n");
				
				printf("ID: ");
				scanf(" %d", &p[cont].id);
				int repetiu=1;
				while(repetiu){
					repetiu=0;
					for(int i=0; i<cont; i++)
						for(int j=i; i<cont; j++)
							if(p[i].id == p[cont].id){
									printf("\nERROR! ID já cadastrado! Digite outro.\n");
									printf("ID: ");
									scanf(" %d", &p[cont].id);
									repetiu=1;
							} else break;
				}
						
				setbuf(stdin, NULL);
				printf("Descrição: "); 				
				scanf(" %[^\n]s", p[cont].descricao);
				printf("Qtd. Estoque: "); 			
				scanf(" %d", &p[cont].estoque);
				printf("Preço unitário: R$"); 				
				scanf(" %f", &p[cont].preco);
				cont++;
				
				printf("\nDeseja cadastrar outro produto? [ 1-Sim | 0-Não ]\n"); 
				scanf(" %d", &resp);
				if(resp!=0 && resp!=1)
					while(resp!=0 && resp!=1){
						printf("\nERROR! Digite uma opção válida\n");
						printf("Deseja cadastrar outro produto? [ 1-Sim | 0-Não ]\n"); 
						scanf(" %d", &resp);
					}
				else if(resp==0) break;
				system("clear");
			}
			
		} 
		
		if(mostraCadastrados){
			system("clear");
			printf("\nSistema de Vendas \t\t[usuário: %s]\t[ %s ]\n", nome_usuario, nome_supermercado);
			printf("\n\n===================== PRODUTOS CADASTRADOS =====================\n\n");
			for(int i=0;i<cont;i++){
				printf("ID: %.5d\n", p[i].id);
				printf("Descrição: %s\n", p[i].descricao);
				printf("Qtd. Estoque: %d\n", p[i].estoque);
				printf("Preço unitário: R$%.2f\n\n", p[i].preco);
			}
			printf("Pressione 'Enter' para voltar ao Menu Principal.");
			setbuf(stdin, NULL);
			getchar();
		}
		
		
		
		system("clear");
		
		//FAZENDO AS VENDAS DOS PRODUTOS ----
		if(venda==1){
			do{
				while(1){
					system("clear");
					printf("\nSistema de Vendas \t\t[usuário: %s]\t[ %s ]\n", nome_usuario, nome_supermercado);
					printf("\n\n===================== PRODUTOS CADASTRADOS =====================\n\n");
					for(int i=0;i<cont;i++){
						printf("ID: %.5d\n", p[i].id);
						printf("Descrição: %s\n", p[i].descricao);
						printf("Qtd. Estoque: %d\n", p[i].estoque);
						printf("Preço unitário: R$%.2f\n\n", p[i].preco);
					}
					
					printf("\n\n====================== VENDA DE PRODUTOS =======================\n\n");
					setbuf(stdin, NULL);
					if(!match){
						printf("Nome do(a) cliente: "); 
						scanf(" %[^\n]", v[x].nome_cliente); 
						match=1;
						setbuf(stdin, NULL);
					}
					printf("\n================================================================\n\n");
					
					int num=0, num2=0;;
					printf("--=== Dados do produto ===--\n");
					printf("ID do produto: ");
					scanf(" %d", &num);
					
					for(int i=0;i<cont;i++){
						if(num!=p[i].id){
							continue;
						}
						printf("\n>>> [ID %d] Descrição: %s \t Estoque: %d \t Preço unitário: R$%.2f\n", num, p[i].descricao, p[i].estoque, p[i].preco);
							
						while(1){
							if(p[i].estoque==0){
								printf("\nProduto sem estoque.\n");
								break;
							}
							
							printf("Quantidade: ");
							scanf(" %d", &v[i].quantidade);
							v[i].qtdtotal+=v[i].quantidade;
							if(v[i].quantidade>p[i].estoque){
								printf("Produto com estoque insuficiente.\n");
								continue;
							}
							
							v[cnc].totalVenda += (p[i].preco) * (v[i].quantidade); //valor da venda
							p[i].estoque -= v[i].quantidade;
							
							printf("\n>>> [%d] Descrição: %s \t Estoque: %d \t Preço unitário: R$%.2f\n", num, p[i].descricao, p[i].estoque, p[i].preco);
							printf("\nDeseja comprar mais %s? [ 1-Sim | 0-Não ]\n", p[i].descricao);
							scanf(" %d", &num2);
							if(num2!=0 && num2!=1){
								while(num2!=0 && num2!=1){
									printf("\nERROR! Digite uma opção válida!\n");
									printf("\nDeseja incluir outro produto na venda? [ 1-Sim | 0-Não ]\n"); 
									scanf(" %d", &num2);
								}
							}
							if(num2==1) continue;
							else break;
						}
					}
					
					printf("Continuar a compra?: [ 1-Sim | 0-Não ]\n");
					scanf(" %d", &num);
					if(num!=0 && num!=1){ 
						while(num!=0 && num!=1){
							printf("ERROR! Digite uma opção válida!\n");
							printf("Continuar a compra?: [ 1-Sim | 0-Não ]\n");
							scanf(" %d", &num);
						}
					}
					
					if(num==1) continue;
					if(num==0){
						system("clear");
						printf("\n\n[ %s ] \t\t Vendedor: %s\n\n", nome_supermercado, nome_usuario);
						printf("Cliente: %s \n", v[x].nome_cliente);
						printf("================================================================\n");
						printf("Produtos comprados:\n\n");
						printf("QTD x UNIT.\t DESCRIÇÃO\t\t\t\tVALOR\n");
						for(int j=0; j<cont; j++){
							if(v[j].qtdtotal !=0){
								
								printf("[%d x %.2f]\t %s\t\t\tR$%.2f\n", v[j].qtdtotal, p[j].preco, p[j].descricao, (p[j].preco * v[j].qtdtotal));
							}
						}
						printf("\n================================================================\n");
						printf("Total: R$%.2f\n\n", v[cnc].totalVenda);
						match=0; //recebe zero para ler novamente o nome de um novo cliente
						
						//GERA UM NOME DO ARQUIVO DE ACORDO O NOME DO CLIENTE
						char nomeArquivo[300]; //tam=300 para que ele caiba o nomeArquivo + nome_Cliente
						sprintf(nomeArquivo, "Comprovante de Venda[%s]", v[x].nome_cliente); //traduzindo: nomeArquivo = "Comprovante(...) [nome_cliente]"
						
						//CRIA UM COMPROVANTE DE VENDA
						int imprime;
						printf("Deseja gerar um comprovante de venda? [ 1-Sim | 0-Não ]\n");
						scanf(" %d", &imprime);
						if(imprime){
							FILE * pont_File_txt; //variavel ponteiro para o arquivo .txt a ser gerado
							pont_File_txt = fopen(nomeArquivo, "a"); //cria arquivo .txt caso n exista. parametro "a"  cria arquivo sem sobrescrever
							
							fprintf(pont_File_txt, "\n\n[ %s ] \t\t Vendedor: %s\n\n", nome_supermercado, nome_usuario);
							fprintf(pont_File_txt, "Cliente: %s \n", v[x].nome_cliente);
							fprintf(pont_File_txt, "================================================================\n");
							fprintf(pont_File_txt, "Produtos comprados:\n\n");
							fprintf(pont_File_txt,"QTD x UNIT.\t DESCRIÇÃO\t\t\t\tVALOR\n");
							for(int j=0; j<cont; j++){
								if(v[j].qtdtotal !=0){
									fprintf(pont_File_txt, "[%d x %.2f]\t %s\t\t\tR$%.2f\n", v[j].qtdtotal, p[j].preco, p[j].descricao, (p[j].preco * v[j].qtdtotal));
								}
							}
							fprintf(pont_File_txt, "\n================================================================\n");
							fprintf(pont_File_txt, "Total: R$%.2f\n\n", v[cnc].totalVenda);
							fprintf(pont_File_txt, "\n\nObrigado pela preferência!\nVolte sempre! :]");
							fclose(pont_File_txt);
							printf("\nComprovante gerado com sucesso no diretório atual.\n");
						}
						x++;
						
						break; 
					}
				}
				valor_total_geral += v[cnc].totalVenda;
				cnc++;
				for(int i=0;i<cont;i++){
					v[i].quantidade=0;
					v[i].qtdtotal=0;
				}
				
				printf("\nDeseja realizar uma nova venda? [ 1-Sim | 0-Não ]\n");
				scanf(" %d", &executa);
				if(executa!=0 && executa!=1){ 
					while(executa!=0 && executa!=1){
						printf("\nERROR! Digite uma opção válida!\n");
						printf("Deseja realizar uma nova venda? [ 1-Sim | 0-Não ]\n");
						scanf(" %d", &executa);
					}
				}
				if(executa) {
					//cnc++;
					continue;
				}
				else { match=0; break;}
				
			} while(executa);
		} 
		
		//FECHAMENTO DO CAIXA ----
		if(fecharCaixa==1){
			printf("\n\n====================== FECHAMENTO DE CAIXA ======================\n\n");
			printf("\n====================== RELAÇÃO DAS VENDAS ======================\n\n");
			for(int i=0; i<x; i++)
				printf("[%d] %s \t Valor: R$%.2f\n", i+1, v[i].nome_cliente, v[i].totalVenda);
				
			
			printf("\n================================================================\n");	
			printf("\nVALOR TOTAL GERAL: R$%.2f\n\n", valor_total_geral);
			
			int imprime;
			printf("Deseja gerar um Relatório de Vendas? [ 1-Sim | 0-Não ]\n");
			scanf(" %d", &imprime);
			if(imprime){
				FILE * pont_File_txt; //variavel ponteiro para o arquivo .txt a ser gerado
				pont_File_txt = fopen("Relatória de Vendas.txt", "a"); //cria arquivo .txt caso n exista com permissao "a", ou seja, abre o arquivo para gravação.
				
				fprintf(pont_File_txt, "\n\n====================== FECHAMENTO DE CAIXA ======================\n\n");
				fprintf(pont_File_txt, "\n====================== RELAÇÃO DAS VENDAS ======================\n\n");
				for(int i=0; i<x; i++)
					fprintf(pont_File_txt, "[%d] %s \t Valor: R$%.2f\n", i+1, v[i].nome_cliente, v[i].totalVenda);
		
				fprintf(pont_File_txt, "\n================================================================\n");	
				fprintf(pont_File_txt, "\nVALOR TOTAL GERAL: R$%.2f\n\n", valor_total_geral);
				fclose(pont_File_txt);
				
				printf("Relatório gerado com sucesso no diretório atual.\n");
			}
			
			return 0;
		}
	}
	
	return 0;
}
