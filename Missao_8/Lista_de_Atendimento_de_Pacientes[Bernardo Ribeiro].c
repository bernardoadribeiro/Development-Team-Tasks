#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*TEMA: Programa de atendimento de clientes por ordem de chegada(listas - Fila)
 * Functions: 1. Cadastrar paciente 	 3. Listar pacientes na fila		5. Apagar tudo
 * 			  2. Atender paciente	     4. Pacientes atendidos				6. Sair
*/

/*typedef struct Medico{
	char nome[100], sexo;
	int certReg, idade, telefone;
	struct Medico* prox;
}Medico;
* */

typedef struct Paciente{
	char nome[100], tipoExame[150], sexo, medico[100];
	int id, idade, telefone, status;
	int numPlanoSaude;
	struct Paciente* prox;
}Paciente;


void tecleEnter_continuar(char *mensagem){
	printf("\n Pressione 'Enter' para %s.", mensagem);
	setbuf(stdin, NULL);
	getchar();
}


Paciente* setPacientes(Paciente *inicio, int *contPacientes){
	Paciente *novo = (Paciente*)malloc(sizeof(Paciente));
	*contPacientes+=1;
	
	novo->id = *contPacientes;
	
	system("clear");
	printf("\n ______________________________________________________________________________\n");
	printf(" 					  					\n");
	printf("  \t\t    FICHA DE IDENTIFICAÇÃO DO PACIENTE\t\t\t	\n");
	printf(" ______________________________________________________________________________\n\n");
	
	printf(" ID: %.5d\n", novo->id);
	
	printf(" Situação (1- Atendido | 2- Não atendido): " );
	scanf(" %d", &novo->status);
	novo->status -= 1;
	
	printf(" Nome completo: ");
	scanf(" %[^\n]s", novo->nome);
	
	printf(" Idade: ");
	scanf(" %d", &novo->idade);
	
	printf(" Sexo (M/F): ");
	scanf(" %c", &novo->sexo);
	
	printf(" Nº do plano de sáude/Cartão SUS (somente números): ");
	scanf(" %d", &novo->numPlanoSaude);
	
	printf(" Telefone (somente números): ");
	scanf(" %d", &novo->telefone);
	
	printf(" Selecione o médico do paciente: ");
	scanf(" %[^\n]s", novo->medico);
	
	printf(" Tipo do exame/sintomas: ");
	scanf(" %[^\n]s", novo->tipoExame);
	
	novo->prox = NULL;
	
	Paciente *atual = malloc(sizeof(Paciente));
	atual = inicio;
	
	if(inicio == NULL){
		inicio = novo;
	}
	else{
		while(atual->prox != NULL){
			atual = atual->prox;
		}
		atual->prox = novo;
	}
	
	printf("\n Paciente cadastrado com sucesso!\n");
	tecleEnter_continuar("retornar ao menu principal");
	
	return inicio;
}


void imprimeCadastros(Paciente *listaP){ //gera um arquivo .txt com as info. de pacientes do dia 
	int imprime;
	
	printf(" Deseja gerar um relatório dos pacientes cadastrados? [ 1-Sim | 0-Não ]: ");
	scanf(" %d", &imprime);
	
	if(imprime){
		FILE * pont_File_txt; 
		pont_File_txt = fopen("Relatório de pacientes.txt", "w"); //cria novo arquivo - substitui o antigo
		
		fprintf(pont_File_txt,"\n ______________________________________________________________________________\n");
		fprintf(pont_File_txt," 					  					\n");
		fprintf(pont_File_txt,"  \t\t    RELATÓRIO DE PACIENTES CADASTRADOS\t\t\t	\n");
		fprintf(pont_File_txt," ______________________________________________________________________________\n\n");
		
		Paciente *aux = listaP;
		char situacao[2][15] = {"Atendido", "Não atendido"};
		
		while(aux != NULL){
			fprintf(pont_File_txt," ID: %.5d\n", aux->id);
			fprintf(pont_File_txt," Situação: %s\n", situacao[aux->status]);
			fprintf(pont_File_txt," Nome completo: %s\n", aux->nome);
			fprintf(pont_File_txt," Idade: %d\n", aux->idade);
			fprintf(pont_File_txt," Sexo (M/F): %c\n", aux->sexo);
			fprintf(pont_File_txt," Número do plano de sáude/Cartão SUS: %d\n", aux->numPlanoSaude);
			fprintf(pont_File_txt," Telefone (somente números): %d\n", aux->telefone);
			fprintf(pont_File_txt," Médico do paciente: %s\n", aux->medico);
			fprintf(pont_File_txt," Tipo do exame/sintomas: %s\n", aux->tipoExame);
			aux = aux->prox;
			fprintf(pont_File_txt," ______________________________________________________________________________\n\n");
		}
		fclose(pont_File_txt);
		
		printf("\n Relatório gerado com sucesso no diretório atual.\n");
	}
}


void getPacientes(Paciente *listaP, int contPacientes){  //mostra todos pacientes (atendido e nao atendidos)
	Paciente *aux = listaP;
	char situacao[2][15] = {"Atendido", "Não atendido"};
	
	system("clear");
	printf("\n ______________________________________________________________________________\n");
	printf(" 					  					\n");
	printf("  \t\t    LISTA DE TODOS PACIENTES CADASTRADOS\t\t\t	\n");
	printf(" ______________________________________________________________________________\n\n");
	
	if(listaP != NULL){
		while(aux){
			printf(" ID: %.5d\n", aux->id);
			printf(" Situação: %s\n", situacao[aux->status]);
			printf(" Nome completo: %s\n", aux->nome);
			printf(" Idade: %d\n", aux->idade);
			printf(" Sexo (M/F): %c\n", aux->sexo);
			printf(" Número do plano de sáude/Cartão SUS: %d\n", aux->numPlanoSaude);
			printf(" Telefone (somente números): %d\n", aux->telefone);
			printf(" Médico do paciente: %s\n", aux->medico);
			printf(" Tipo do exame/sintomas: %s\n", aux->tipoExame);
			
			aux = aux->prox;
			printf(" ______________________________________________________________________________\n\n");
		}
		
		imprimeCadastros(listaP); //para gerar arquivo .txt com os clientes
	}
	else
		printf("\n No momento ainda não há pacientes cadastrados.\n\n");
	
	tecleEnter_continuar("para retornar ao menu principal");
	
}


void getByStatus(Paciente *listaP, int contPacientes, int estado){
	Paciente *aux = listaP;
	char situacao[2][15] = {"ATENDIDO", "NÃO ANTENDIDO"};
	int existe=0; 
	
	system("clear");
	printf("\n ______________________________________________________________________________\n");
	printf(" 					  					\n");
	printf("  \t\t    LISTA DE TODOS PACIENTES %sS\t\t\t	\n", situacao[estado]);
	printf(" ______________________________________________________________________________\n\n");
	
	if(listaP != NULL){
		while(aux){
			if(aux->status == estado){
				printf(" ID: %.5d\n", aux->id);
				printf(" Situação: %s\n", situacao[aux->status]);
				printf(" Nome completo: %s\n", aux->nome);
				printf(" Idade: %d\n", aux->idade);
				printf(" Sexo (M/F): %c\n", aux->sexo);
				printf(" Número do plano de sáude/Cartão SUS: %d\n", aux->numPlanoSaude);
				printf(" Telefone (somente números): %d\n", aux->telefone);
				printf(" Médico do paciente: %s\n", aux->medico);
				printf(" Tipo do exame/sintomas: %s\n", aux->tipoExame);
				printf(" ______________________________________________________________________________\n\n");
				
				existe=1;
			}
			aux = aux->prox;
		}
		if(!existe && estado==0)
			printf("\n Nenhum paciente foi antendido ainda.\n");
		if(!existe && estado==1)
			printf("\n Não há mais pacientes na fila.\n");
	}
	else
		printf("\n No momento ainda não há pacientes cadastrados.\n\n");
	
	tecleEnter_continuar("para retornar ao menu principal");
}


void resetar(Paciente **listaP, int *contPacientes){
	Paciente *p;
	p = *listaP;
	
	if(*listaP == NULL)
		printf("\n A lista de pacientes já está vazia.\n");
	else{
		while(p != NULL){
			*listaP = p->prox;
			free(p);
			p = *listaP;
		}
		printf("\n O cadastro de todos os pacientes foram apagados.\n");
	}
	
	*contPacientes = 0;
	tecleEnter_continuar("continuar");
}

void listarPacientes(Paciente *pacientes, int contPacientes){
	system("clear");
	printf("\n ______________________________________________________________________________\n");
	printf(" 					  					\n");
	printf("  \t\t\t     LISTAR PACIENTES \t\t\t	\n");
	printf(" ______________________________________________________________________________\n\n");
	
	int opcao;
	printf(" 1- Listar todos os pacientes \n 2- Listar os pacientes antendidos \n 3- Listar os pacientes na fila\n");
	printf(" Selecione uma opção: ");
	scanf(" %d", &opcao);
	while(opcao<0 || opcao>3){
		printf(" Opção inválida. Tente novamente!\n");
		printf(" Opção: ");
		scanf(" %d", &opcao);
	}
	
	switch(opcao){
		case 1: 
			getPacientes(pacientes, contPacientes); //lista todos
			break;
		
		case 2:
			getByStatus(pacientes, contPacientes, 0); //lista atendidos
			break;
			
		case 3: 
			getByStatus(pacientes, contPacientes, 1); //lista nao atendidos
	}
}


void marcar_comoAtendido(Paciente *listaP, int contPacientes){
	Paciente *aux = listaP;
	char situacao[2][15] = {"ATENDIDO", "NÃO ANTENDIDO"};
	int id_paciente,existe=0;
	
	system("clear");
	printf("\n ______________________________________________________________________________\n");
	printf(" 					  					\n");
	printf("  \t\t    MARCAR PACIENTE COMO ATENDIDO\t\t\t	\n");
	printf(" ______________________________________________________________________________\n\n");
	
	if(listaP == NULL)
		printf("\n A lista de pacientes está vazia.\n");
	else{
		printf("\n Digite o ID do paciente que deseja marcar como ATENDIDO: ");
		scanf(" %d", &id_paciente);
		while(aux){
			existe++;
			if(aux->id == id_paciente){
				aux->status = 0;
				printf("\n Situação atualizada com sucesso.\n\n");
				printf(" ID: %.5d\n", aux->id);
				printf(" Situação: %s\n", situacao[aux->status]);
				printf(" Nome completo: %s\n", aux->nome);
				printf(" ______________________________________________________________________________\n\n");
			}
			aux = aux->prox;
			if(existe == contPacientes)
				printf("\n Não foi encontrado nenhum paciente com esse ID.\n");
		}
	}
	tecleEnter_continuar("para retornar ao menu principal");
}


int menuPrincipal(){
	int op;
	system("clear");
	printf("\n ______________________________________________________________________________\n");
	printf(" 					  					\n");
	printf("  \t\t    SISTEMA DE ATENDIMENTO DE PACIENTES\t\t\t	\n");
	printf(" ______________________________________________________________________________\n\n");
	
	printf("\n 1- Cadastrar paciente\n 2- Listar pacientes\n 3- Marcar paciente como atendido\n 4- Apagar todos os cadastros\n\n 0- Encerrar sessão.\n");
	printf("\n Opção: ");
	scanf(" %d", &op);
	while(op<0 || op>4){
		printf(" Opção inválida. Tente novamente!\n");
		printf(" Opção: ");
		scanf(" %d", &op);
	}
	
	return op;
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Paciente *pacientes = NULL;

	int contPacientes=0;	
	
	while(1){
		switch(menuPrincipal()){
			case 1: pacientes = setPacientes(pacientes, &contPacientes); //cadastrar pacientes (ok) [obrigatorio]
					break;
				
			case 2: listarPacientes(pacientes, contPacientes); //printa/imprime pacientes (ok) [obrigatorio]
					break;
			
			case 3: marcar_comoAtendido(pacientes, contPacientes); //Marcar paciente como atendido [opcional]
					break; 
			
			case 4: resetar(&pacientes, &contPacientes); //apagar tudo; resetar; (ok) [opcional]
					break; 
			
			default: 
				printf("\n\nSessão encerrada.\nPrograma finalizado.\n\n\n\n\t\t         Developed by: Bernardo Ribeiro\n");
				printf("\t\t    Copyright © 2021  |  Team Binary Phantoms");
				return 0;
		}
	}
}
