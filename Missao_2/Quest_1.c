/* Faça um programa que leia três números inteiros: X, Y e Z. O seu programa deve imprimir os três
números em ordem crescente.
 * 1 2 3
 * 1 3 2
 * 2 1 3
 * 2 3 1
 * 3 1 2
 * 3 2 1
 * 
 * se tiver 2 iguais
 * se todos forem iguais
 * 
 * */


#include <stdio.h>

int main(){
	
	int x,y,z,a;
	
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);

	if(x>y){
		a=x; 
		x=y; 
		y=a;
	} 
	
	if(y>z){
		a=y; 
		y=z; 
		z=a;
	}
	
	if(x>y) { 
		a=x; 
		x=y; 
		y=a;
	
	} 	
	
	printf("%d, %d, %d",x,y,z);
	
return 0; 
}
