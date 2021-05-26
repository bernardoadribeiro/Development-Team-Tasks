#include <stdio.h>
#include <string.h>

int main (){

	char senha[100];

	while (scanf(" %[^\n]", senha) != EOF){
		int UPPER=0, lower=0, num=0;
		int valida = 1;
		for(int i=0; i<strlen(senha); i++){		
			if((senha[i]>='A' && senha[i]<='Z'))
				UPPER=1;
			 else if((senha[i]>='a' && senha[i]<='z'))
				lower=1;
			 else if((senha[i]>='0' && senha[i]<='9'))
				num=1;
			 else {
				 valida = 0;
				 break;
			 }
		}
		
		if((valida && UPPER && lower && num) && (strlen(senha)>=6 && strlen(senha)<=32))
			printf("Senha valida.\n");
			else printf("Senha invalida.\n");
	}
	return 0;
}
