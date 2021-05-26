#include <stdio.h>
#include <math.h>

int main() {
 
    int n, x, contIn=0, contOut=0;
    
    scanf(" %d", &n);
    
    if(n>= pow(-10,7) && n<= pow(10,7)){
		for(int i=1; i<=n; i++){
			scanf(" %d", &x); 
			
			if (x>=10 && x<=20)
				contIn++;
				else if (x<10 || x>20)
					contOut++;
		}
	}
	printf("%d in\n", contIn);
	printf("%d out\n", contOut);
		
 
    return 0;
}
