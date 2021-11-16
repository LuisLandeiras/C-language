## This project sum the array with a random length:
```` c
#include<stdio.h>
int add = 0;

int AddArray(int vetor[], int n){
    if (n > 0){
        add = vetor[n] + add;
        AddArray(vetor, n - 1);
    }
    return add;
}

void ler(int vetor[], int n, int length){
    if (n > 0){
        scanf("%i", &vetor[n]);
        ler(vetor, n - 1, length);
    }
    else{
        printf("A soma de todos os elementos do vetor é:\n-> %i\n", AddArray(vetor, length));
    }
}

int main(void){
    int n;
    printf("Indique o tamanho do vetor: ");
    scanf("%i", &n);
    int vetor[n];
    ler(vetor, n, n);
    return 0;
}
````
