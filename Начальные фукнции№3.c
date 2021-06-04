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

void Plus(int *matrix1, int n, int m, int *matrix2,int *matrix3)
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            *(matrix3 + j + i*m) = *(matrix1 + j + i*m) +*(matrix2 + j + i*m);}}
    return;
}

void Minus(int *matrix1, int n, int m, int *matrix2,int *matrix3)
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            *(matrix3 + j + i*m) = *(matrix1 + j + i*m) - *(matrix2 + j + i*m);}}
    return;
}
void Composition(int *matrix1, int n1, int m1, int *matrix2,int n2, int m2,int *matrix3)
{
    int i,j,k,sum=0;
    for(i=0;i<n1;i++){
        for(j=0;j<m2;j++){
                for(k=0;k<m1;k++){
                    sum=sum+*(matrix1 + k + i*m1)*(*(matrix2 + j + k*m2));}
                *(matrix3 + j + i*m2)=sum;
                sum=0;}}

    return;
}
void Random_Matrix(int *matrix, int n, int m, int minn, int maxx)
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            *(matrix + j + i*m) =minn+rand()%maxx;}}
    return;
}

void Random_Symetrical_Matrix(int *matrix, int n, int m, int minn, int maxx)
{
    int i,j,num;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            num = minn+rand()%maxx;
            *(matrix + j + i*m) = num;
            *(matrix + i + j*m) = num;}}
    return;
}

int main()
{
    return 0;
}
