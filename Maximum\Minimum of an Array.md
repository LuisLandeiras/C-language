## This project find in between the array the maximum and the minimum number:
````c
#include<stdio.h>

void ler(int v[], int n, int a){
    if (n > 0){
        scanf("%d", &v[n - 1]);
        ler(v, n - 1, a);
    }
    else{
        printf("O maior valor do vetor é: %d\n", maximo(v, a));
        printf("O menor valor do vetor é: %d\n", minimo(v, a));
    }
}

int maximo(int v[], int n){
    int maximo = -99999999;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > maximo)
        {
            maximo = v[i];
        }
    }
    return maximo;
}

int minimo(int v[], int n){
    int minimo = 999999999;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < minimo)
        {
            minimo = v[i];
        }
    }
    return minimo;
}

int main(void){
    int n;
    printf("Indique o tamanho do vetor -> ");
    scanf("%i", &n);
    int v[n];
    ler(v, n, n);
    return 0;
}
````
