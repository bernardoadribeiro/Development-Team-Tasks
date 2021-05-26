#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char linha1[61], linha2[61], cpf[12], valorStr[18], valorStr2[18];
    int tam1, tam2;

    scanf(" %s", linha1);
    scanf(" %s", linha2);

    tam1 = strlen(linha1);
    tam2 = strlen(linha2);
    int controle=0, cont_cpf;
    for(cont_cpf=0; controle < 11; cont_cpf++){
        if((linha1[cont_cpf] >= 48) && (linha1[cont_cpf] <= 57)){
            cpf[controle]=linha1[cont_cpf];
            controle++;
        }
    }
    
    cpf[11]='\0';
    printf("cpf %s\n", cpf);
    
    controle=0;
    int conta_casas=0, dispara_contador=0;
    
    for(int i=cont_cpf; (i<tam1) && (conta_casas<3) ;i++){
        if(((linha1[i] >= 48) && (linha1[i] <= 57)) || (linha1[i]== '.')){
	    
            valorStr[controle]=linha1[i];
            controle++;
	    
            if(linha1[i]== '.'){
                dispara_contador=1;
            }
            if(dispara_contador){
                conta_casas++;
            }

        }

    }
    
    valorStr[controle]='\0';

    controle=0;
    conta_casas=0, dispara_contador=0;
    
    for(int i=0; (i<tam2) && (conta_casas<3)  ;i++){
        if(((linha2[i] >= 48) && (linha2[i] <= 57)) || (linha2[i]== '.')){
	    
            valorStr2[controle]=linha2[i];
            controle++;
	    
             if(linha2[i]== '.'){
                dispara_contador=1;
            }
            if(dispara_contador){
                conta_casas++;
            }

        }
    }
    valorStr2[controle]='\0';

    double valor1 = atof(valorStr), valor2 = atof(valorStr2), soma;
    
    soma = valor1+valor2;
    printf("%.2lf\n", soma);

	return 0;
}
