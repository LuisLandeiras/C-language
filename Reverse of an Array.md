## This project reverses an array which is given by the user:
````c
#include <stdio.h>

void inverte(char a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("-> %c\n", a[n - i - 1]);
    }
}

int main(void)
{
    int n = 0;
    printf("Indique quantos elementos pretende colocar no array -> ");
    scanf("%d", &n);
    char letras[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &letras[i]);
    }
    inverte(letras, n);
    return 0;
}
````
