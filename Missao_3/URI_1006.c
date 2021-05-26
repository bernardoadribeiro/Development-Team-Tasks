#include <stdio.h>

int main(){
	
	double notaA, notaB, notaC, media;
	
	scanf(" %lf", &notaA);
	scanf(" %lf", &notaB);
	scanf(" %lf", &notaC);
	
	media = ((notaA*2)+(notaB*3)+(notaC*5))/10;
	
	printf("MEDIA = %.1f\n", media);
	
	return 0;
}
