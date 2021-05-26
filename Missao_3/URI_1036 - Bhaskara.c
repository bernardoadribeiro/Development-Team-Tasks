/*Leia 3 valores de ponto flutuante e efetue o cálculo das raízes da equação de Bhaskara. 
Se não for possível calcular as raízes, mostre a mensagem correspondente “Impossivel calcular”, caso haja uma divisão por 0 ou raiz de numero negativo.
*/

#include <stdio.h>
#include <math.h>

int main(){
	
	double a, b, c, delta, R1, R2;
	
	scanf(" %lf", &a);
	scanf(" %lf", &b);
	scanf(" %lf", &c);
	
	delta = pow(b,2) -4*a*c;
	
	if (delta<0 || a==0)
		printf("Impossivel calcular\n");
		else{
			R1 = ((b*(-1))+sqrt(delta))/(2*a);
			R2 = ((b*(-1))-sqrt(delta))/(2*a);
			
			printf("R1 = %.5f\n", R1);
			printf("R2 = %.5f\n", R2);
		}
	return 0;
}
