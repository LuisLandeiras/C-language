#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int n,m,x;

//Function used to read both of the matrices
void read2Dim(int v[n][m]){
    printf("Define the matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%i", &v[i][j]);
        }
    }
}

//Function used to write both of the matrices 
void write2Dim(int v[n][m],int b[n][m]){
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

//Function used to do the sum of the matrices
void sum2Dim(int v[n][m],int b[n][m]){
    printf("Matrix sum:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){ 
            printf(" %i ", b[i][j]+v[i][j]);
        }
        printf("\n");
    }
}

//Function used to do the subtraction of the matrices
void sub2Dim(int v[n][m],int b[n][m]){
    printf("Matrix subtraction:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){ 
            printf(" %i ", v[i][j]-b[i][j]);
        }
        printf("\n");
    }
}

//Function used to do the multiplication of the matrices
//This function only multiplicate matrices with the same length and height
void mult2Dim(int v[n][m],int b[n][m]){
    printf("Matrix multiplication:\n");
    int r[n][m];
    //Inicializate all the positions of the array by zero
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            r[i][j]=0;
        }   
    }
    //Cicle reponsible for the multiplication of both of the matrices
    for (int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            for(int x=0;x<n;x++){ 
                 r[i][j] += (v[i][x] * b[x][j]);
            }
        }
    }
    //Cicle responsible for showing the matrix multiplication
    for (int i=0; i<n; i++){
        for (int j = 0; j<m; j++){
            printf(" %i ", r[i][j]);
        }
        printf("\n");
    }
}

//Function that show the menu
void menu(int v[n][m], int b[n][m]){
    printf("Indicate the option you want:\n");
    printf("1-Sum of matrices\n2-Subtraction of matrices\n3-Multiplication of matrices\n");
    scanf("%i", &x);
    switch(x){
        case 1:
            read2Dim(v);
            read2Dim(b);
            write2Dim(v,b);
            sum2Dim(v,b);
        break;
        case 2:
            read2Dim(v);
            read2Dim(b);
            write2Dim(v,b);
            sub2Dim(v,b);
        break;
        case 3:
            //Only do the multiplication if the length is equal to height
            if(n == m){ 
            read2Dim(v);
            read2Dim(b);
            write2Dim(v,b);
            mult2Dim(v,b);
            }
            //If n != m show again the menu to start again
            else{
                printf("\n");
                //This one is used if multiplication goes wrong(1)
                printf("Both of the matrices need to have the same length and height!\n");
                printf("Indicate the height of the matrix: ");
                scanf("%i", &n);
                printf("Indicate the length of the matrix: ");
                scanf("%i", &m);
                printf("\n");
                menu(v,b);
            }
        break;
        default:printf("Option not available.\n");
    }
}
int main(void){
    printf("\n");
    //This one is used one the first inicialization of the programm(2)
    printf("Indicate the height of the matrix: ");  
    scanf("%i", &n);
    printf("Indicate the length of the matrix: ");
    scanf("%i", &m); 
    printf("\n");
    int v[n][m];
    int b[n][m];
    menu(v,b);
    return 0;
}
