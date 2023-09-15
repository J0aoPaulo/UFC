#include <stdio.h>

typedef struct 
{
    char apelido[50];
    float proprina;
    char partido[20];
}Politico;

float calcular_total_propina(Politico politicos[], int n){
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        total += politicos[i].proprina;
    }
    return total;
}

int main(){
    int n;
    scanf("%d", &n);
    Politico x[n];
    
    for (int i = 0; i < n; i++)
    {
        scanf(" %[^\n]", x[i].apelido);
        scanf("%f", &x[i].proprina);
        scanf(" %[^\n]", x[i].partido);
    }
    printf("%f", calcular_total_propina(x, n));
}