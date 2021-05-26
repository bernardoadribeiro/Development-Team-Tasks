#include <stdio.h>
#include <string.h>

char* tostring(int inteiro){
    int algarismo, resto;
    int divisor, i, div;
    for(i=0, divisor = 1; divisor * 10 <= inteiro; divisor *= 10, i++){/*retora o divisor máximo*/}
    char* string=(char*)malloc(i+2*sizeof(char));
    for( i=0; inteiro >=10 ;i++, divisor/=10){
        resto = inteiro%divisor;
        inteiro /= divisor;
        string[i]= inteiro + '0';
        inteiro = resto;
    }
    string[i]= inteiro + '0';
    string[i+1]= 0;
    return string;
}

int main(){
    printf("%s", tostring(1));
    return 0;
}
