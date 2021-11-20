#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int n,m,x;
void read2Dim(int v[n][m], int n, int m){
    printf("Define the matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%i", &v[i][j]);
        }
    }
}
void write2Dim(int v[n][m],int b[n][m], int n, int m){
    printf("Matrix 1:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf(" %i ", v[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2:\n");
    for(int k=0;k<n;k++){
        for(int w=0;w<m;w++){
            printf(" %i ", b[k][w]);
        }
        printf("\n");
    }
}
void sum2Dim(int v[n][m],int b[n][m], int n, int m){
    printf("Matrix sum:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){ 
            printf(" %i ", b[i][j]+v[i][j]);
        }
        printf("\n");
    }
}
void sub2Dim(int v[n][m],int b[n][m], int n, int m){
    printf("Matrix subtraction:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){ 
            printf(" %i ", v[i][j]-b[i][j]);
        }
        printf("\n");
    }
}
void mult2Dim(int v[n][m],int b[n][m],int n,int m){
    printf("Matrix multiplication:\n");
    int mult = 0, matrixmult[n][m];
    for (int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            matrixmult[n][m]=0;
            for(int x=0;x<n;x++){ 
                 mult += (v[i][x] * b[x][j]);
            }
            matrixmult[i][j] = mult;               
            mult = 0;
        }
        mult = 0;
    }
    for (int i=0; i<n; i++){
        for (int j = 0; j<m; j++){
            printf(" %i ", matrixmult[i][j]);
        }
        printf("\n");
    }
}
void menu(int x, int v[n][m], int b[n][m], int n, int m){
    printf("Indicate the option you want:\n");
    printf("1-Sum of matrix\n2-Subtraction of matrix\n3-Multiplication of matrix\n");
    scanf("%i", &x);
    switch(x){
        case 1:
            read2Dim(v,n,m);
            read2Dim(b,n,m);
            write2Dim(v,b,n,m);
            sum2Dim(v,b,n,m);
        break;
        case 2:
            read2Dim(v,n,m);
            read2Dim(b,n,m);
            write2Dim(v,b,n,m);
            sub2Dim(v,b,n,m);
        break;
        case 3:
            if(n == m){ 
            read2Dim(v,n,m);
            read2Dim(b,n,m);
            write2Dim(v,b,n,m);
            mult2Dim(v,b,n,m);
            }
            else{
                printf("\n");
                printf("Both of the matrix need to have the same length and height!\n");
                printf("Indicate the height of the matrix: ");
                scanf("%i", &n);
                printf("Indicate the length of the matrix: ");
                scanf("%i", &m);
                printf("\n");
                menu(x,v,b,n,m);
            }
        break;
        default:printf("Option not available.\n");
    }
}
int main(void){
    printf("\n");
    printf("Indicate the height of the matrix: ");
    scanf("%i", &n);
    printf("Indicate the length of the matrix: ");
    scanf("%i", &m); 
    printf("\n");
    int v[n][m];
    int b[n][m];
    menu(x,v,b,n,m);
    return 0;
}
