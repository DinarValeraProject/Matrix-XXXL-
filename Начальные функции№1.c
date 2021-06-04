#include <stdio.h>
#include <stdlib.h>

void Print(int *matrix, int n, int m)
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ", *(matrix + j + i*m));}
        printf("\n");}
    return;
}

void Identity_Matrix(int *matrix, int n, int m)
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            *(matrix + j + i*m) = 1;}}
    return;
}

void Identity_Diagonal_Matrix(int *matrix, int n, int m)
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if (i==j)
                *(matrix + j + i*m) = 1;
            else
                *(matrix + j + i*m) = 0;}}
    return;
}
int main()
{
    int matrix1[10][10];
    Identity_Diagonal_Matrix(&matrix1[0][0],10,10);
    Print(&matrix1[0][0],10,10);

    return 0;
}
