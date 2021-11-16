## This project calculate the avarage of the array which is given by the user:
````c
#include<stdio.h>
int add = 0;

int AddArray(int vetor[], int n){
    if (n > 0){
        add = vetor[n] + add;
        AddArray(vetor, n - 1);
    }
    return add;
}

float MedArray(float add, float length){
    return (add/length);
}

void ler(int vetor[], int n, int length){
    if (n > 0){
        scanf("%i", &vetor[n]);
        ler(vetor, n - 1, length);
    }
    else{
        printf("A soma de todos os elementos do vetor é:\n-> %i\n", AddArray(vetor, length));
        printf("A media dos valores do vetor é:\n-> %.2f\n", MedArray(add, length));
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
