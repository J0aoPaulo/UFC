#include <stdio.h>

int main(){
    char frase[101];
    scanf("%[^\n]", frase);
    char letra;
    scanf("%c", &letra);
    
    for(int i = 0; frase[i] != '\0'; i++){
        if(letra == 'm' && frase[i] >= 'A' && frase[i] <= 'Z'){
            frase[i] = frase[i] + 32;
        }else if(letra == 'M' && frase[i] >= 'a' && frase[i] <= 'z'){
            frase[i] = frase[i] - 32;
        }
    }
    printf("%s", frase);
}