#include <stdio.h>

int main(){
	
	float nota1, nota2, nota3, nota4, media, notaFinal, notaExame;
	
	scanf(" %f", &nota1);
	scanf(" %f", &nota2);
	scanf(" %f", &nota3);
	scanf(" %f", &nota4);
	
	media = (nota1*2 + nota2*3 + nota3*4 + nota4*1)/10;
	
	if (media>=7.0){
		printf("Media: %.1f\n", media);
		printf("Aluno aprovado.\n");
	} else if (media<5.0){
		printf("Media: %.1f\n", media);
		printf("Aluno reprovado.\n");
	  } else if (media>=5.0 && media<=6.9){
		  printf("Media: %.1f\n", media);
		  printf("Aluno em exame.\n");
		  scanf(" %f", &notaExame);
			
		  notaFinal = (media + notaExame)/2;
					
		  if (notaFinal>=5.0){
			  printf("Nota do exame: %.1f\n", notaExame);
			  printf("Aluno aprovado.\n");
			  printf("Media final: %.1f\n", notaFinal);
			} else {
				printf("Nota do exame: %.1f\n", notaExame);
				printf("Aluno reprovado.\n");
				printf("Media final: %.1f\n", notaFinal);
			 }
	    }
	
	return 0;
}
