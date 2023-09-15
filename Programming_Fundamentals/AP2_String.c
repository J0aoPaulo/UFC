#include <stdio.h>

int main(){
    system("cls");
    int  cont01 = 0, cont02 = 0;
    char str01[101], str02[101], str03[101];

    scanf("%[^\n]", str01);
    scanf(" %[^\n]", str02);
    
    for (int i = 0, j = 0; i < str01[i]; i++, j++){
        str03[j] = str01[i];
        cont01++;
    }

    for (int i = 0, j = cont01; i < str02[i]; i++, j++){
        str03[j] = str02[i];
        cont02++;
    }
    printf("%s\n", str03);
    printf("%d\n", cont01 + cont02);
}
/* Questão com o objetivo de concatenar duas strings
fazer a impressão da string concatenada e seu tamanho */