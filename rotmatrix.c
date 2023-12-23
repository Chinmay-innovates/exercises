#include<stdio.h>
int i,j,n;
void rotateMatrix(int n,int mat[n][n])
{
 for(int i=0;i<n/2;i++)
 {
    for(int j=i;j<n-i-1;j++)
    {
    int temp=mat[i][j];
    mat[i][j]=mat[n-j-1][i];
    mat[n-j-1][i]=mat[n-i-1][n-j-1];
    mat[n-i-1][n-j-1]=mat[j][n-i-1];
    mat[j][n-i-1]=temp;
  }
 }
}

void setZeros(int mat[3][3])
{
    int zeroRow[3]={0};
    int zeroCol[3]={0};

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if (mat[i][j]==0)
            {
              zeroRow[i]=1;
              zeroCol[j]=1;
            }
        }
    }
//row=0
for(i=0;i<3;i++)
{
    if (zeroRow[i]==1)
    {
        for(j=0;j<3;j++)
        {
            mat[i][j]=0;
        }    
    }
