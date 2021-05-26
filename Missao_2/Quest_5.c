#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int x = rand()%100;
	int y = rand()%100;
	float m;
	m = (x + y / 2);
if(x>y){printf("O %d é maior\nO %d é menor",x,y);}
	else {printf("O %d é menor\nO %d é maior",x,y);}
	printf("\nA média é:%4.2f",m);
	return 0;
}
