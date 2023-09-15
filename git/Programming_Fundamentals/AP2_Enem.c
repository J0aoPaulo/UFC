#include <stdio.h>

typedef struct {
    float media;
    float notas[5];
    char nome[100];
}Aluno;
    
int main(){
    int n, m_facul, qtd = 0;
    scanf("%d", &n);
    Aluno x[n];

    for (int i = 0; i < n; i++)
    {
        scanf(" %[^\n]", x[i].nome);
        scanf("%f %f %f %f %f", &x[i].notas[0], &x[i].notas[1], &x[i].notas[2], &x[i].notas[3], &x[i].notas[4]);
        x[i].media = (x[i].notas[0] + x[i].notas[1] + x[i].notas[2] + x[i].notas[3] + x[i].notas[4]) / 5;
    }
    scanf("%d", &m_facul);
    
    for (int i = 0; i < n; i++)
    {
        if(x[i].media > m_facul) qtd++;
    }
    
    printf("%d", qtd);
    
    for (int i = 0; i < n; i++)
    {
        if(x[i].media > m_facul){
            printf("%s\n", x[i].nome);
        } 
    }
}
/* Questão com o objetivo de pegar 5 notas de n alunos
verificar quantos desses alunos estão acima da média e 
imprimir os nomes desses alunos */
