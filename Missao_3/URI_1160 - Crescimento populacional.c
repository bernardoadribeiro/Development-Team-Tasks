#include <stdio.h>

int main(){
	int T, PA, PB, contAnos=0;
	double G1, G2; //percentual
	
	scanf(" %d", &T);
	if(T>=1 && T<=3000)
		for(int i=1; i<=T;i++){
			scanf(" %d", &PA);		
			scanf(" %d", &PB);
			
			scanf(" %lf", &G1);
			scanf(" %lf", &G2);
			
			//if((G1>=0.1 && G1<=10.) && (G2>=0.0 && G2<=10.0) && G2<G1){
				
				contAnos=0;
				while(contAnos<101){
					PA = PA + ((PA*G1)/100);
					PB = PB + ((PB*G2)/100);
					contAnos++;
					
					if (contAnos>100){
						printf("Mais de 1 seculo.\n");
						continue;
					}
						else if(PA>PB){
							printf("%d anos.\n", contAnos);
							break;
						}
						
				}
			//}
			//printf("PA=%d | PB=%d || %d\n", PA, PB, contAnos);
		}	
	return 0;
}
