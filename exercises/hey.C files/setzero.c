#include<stdio.h>
int i,j;

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
}
//col=0
for(j=0;j<3;j++){
    if (zeroCol[j]==1)
    {
        for(i=0;i<3;i++)
        {
            mat[i][j]=0;
        }    
    }
 }
}

void printmat(int mat[3][3])
{
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
        printf("%d ",mat[i][j]);
      }
      printf("\n");
    }
}
int main(){
    int matrix[3][3]={ {1 , 2, 3},{4 , 0, 6},{7 , 8, 9}};
    printf("original matrix\n");
    printmat(matrix);
    setZeros(matrix);
    printf("matrix after setting zeros\n");
    printmat(matrix);
    return 0; 
}
    
