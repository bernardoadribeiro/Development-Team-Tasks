#include <stdio.h>
#include <string.h>

int main(){
	int idade, diaAtual[4], mesAtual[4], anoAtual[6], novaDataAtual[10], novaDataNasc[10];
	int diaNasc[4], mesNasc[4], anoNasc[6];
	char nome[52], dataNasc[12], dataAtual[12];
	
	scanf(" %[^\n]s", nome);
	scanf(" %s", dataAtual);
	scanf(" %s", dataNasc);
	
	
	
	for(int i=0; i<strlen(dataAtual); i++){
		if(dataAtual[i] != '/')
			novaDataAtual[i] = dataAtual[i];
		
		if(dataNasc[i]!='/')
			novaDataNasc[i] = dataNasc[i];
		
	}
	
	printf("novaDataAtual = %ls\n", novaDataAtual);
	printf("novaDataNasc = %ls\n\n", novaDataNasc);
	
	for(int i=0; i<2; i++)
		diaAtual[i] = novaDataAtual[i];
		
	for(int i=2; i<4; i++)
		mesAtual[i] = novaDataAtual[i];
	
	for(int i=4; i<8; i++)
		anoAtual[i] = novaDataAtual[i];
	
	for(int i=0; i<2; i++)
		diaNasc[i] = novaDataNasc[i];
		
	for(int i=2; i<=3; i++)
		mesNasc[i] = novaDataNasc[i];
	
	for(int i=4; i<=8; i++)
		anoNasc[i] = novaDataNasc[i];
	
	/*idade = anoAtual-anoNasc;
	
	printf("anoAtual %s\n", anoAtual);
	printf("anoNasc %s\n", anoNasc);
	printf("mesAtual %s\n", mesAtual);
	printf("mesNasc %s\n", mesNasc);
	printf("diaAtual %s\n", diaAtual);
	printf("diaNasc %s\n", diaNasc);
	
	if(mesAtual<mesNasc)
		printf("Voce tem %d anos %s.\n", idade-1, nome);
		else if(mesAtual>mesNasc)
			printf("Voce tem %d anos %s.\n", idade-1, nome);
			else if(mesAtual==mesNasc){
				if(diaAtual<diaNasc)
					printf("Voce tem %d anos %s.\n", idade-1, nome);
					else if(diaAtual>diaNasc)
						printf("Voce tem %d anos %s", idade, nome);
			}
	if(mesAtual==mesNasc && diaAtual==diaNasc)
		printf("Feliz aniversario!\nVoce tem %d anos %s.\n", idade, nome);
	*/
	return 0;
}
