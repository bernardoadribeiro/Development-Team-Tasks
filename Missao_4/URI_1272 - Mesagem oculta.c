#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, j, tam;
    char frase[52], oculta[52];

    scanf("%d", &N);
    getchar();

    for (; N > 0; --N) {
        fgets(frase, 52, stdin);
        tam = strlen(frase) - 1;

        for (i = 0, j = 0; i < tam; ++i) {
            if (frase[i] != ' ' && (!i || frase[i-1] == ' '))
                oculta[j++] = frase[i];
        }
        oculta[j] = '\0';

        puts(oculta);
    }

    return 0;
}
