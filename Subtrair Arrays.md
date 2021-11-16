## Subtrai dois arrays de tamanho variável dado pelo o utilizador
´´´´ c
#include<stdio.h>

int subtrairanterior(int vetor[], int n){
    for (int i = 0; i < n; i++)
    {
        if (i > 0){
            printf("%i\n", vetor[i] - vetor[i - 1]);
        }
        else{
            printf("%i\n", vetor[i]);
        }
    }
}

int main(void){
    int n = 0;
    printf("Por favor indique o número de elementos que pretende -> ");
    scanf("%d", &n);
    int vetor[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }
    subtrairanterior(vetor, n);
    return 0;
}
´´´´
