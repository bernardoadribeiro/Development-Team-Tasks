#include <stdio.h>

int main(){
	
	int hora, minuto, horaFinal, minutoFinal, duracaoHora, duracaoMin ;
	
	scanf(" %d", &hora);
	scanf(" %d", &minuto);
	scanf(" %d", &horaFinal);
	scanf(" %d", &minutoFinal);
	
	if ((minuto>=1 && minuto<=59 && hora>=0 && hora<=24) && (minutoFinal>=1 && minutoFinal<=59 && horaFinal>=0 && horaFinal<=24)){
		
		duracaoHora = horaFinal - hora;
		duracaoMin = minutoFinal - minuto;
		
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)", duracaoHora, duracaoMin);
		
	}
		
	
	
	return 0;	
}
