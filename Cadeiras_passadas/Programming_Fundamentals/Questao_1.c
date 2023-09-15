#include <stdio.h>

int main(){
    system("cls");
    int n, res = 0;
    scanf("%d", &n);
    int vet[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &vet[i]); 
    }
    
    for (int i = 0; i < n; i += 2){
        res += (vet[i] + vet[i + 1]) * (i + 1);
    }
    
    printf("%d", res);
}