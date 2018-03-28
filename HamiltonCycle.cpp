#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>
#define MAX 50
#define  TRUE 1
#define FALSE   0
int A[MAX][MAX], C[MAX], B[MAX];
int n,i, d;
void Init(void){
  int i, j;FILE *fp;
  fp= fopen("DOTHI_HamiltonCycle.IN", "r");
  if(fp==NULL){
    printf("\n Khong co file input");
    getch(); return;
  }
  fscanf(fp,"%d",&n);
  printf("\n So dinh do thi:%d", n);
  printf("\n Ma tran ke:");
  for(i=1; i<=n; i++){
    printf("\n");
    for(j=1; j<=n; j++){
      fscanf(fp, "%d", &A[i][j]);
      printf("%3d", A[i][j]);
    }
  }
  fclose(fp);
  for (i=1; i<=n;i++)
    C[i]=0;
}
void Result(void){
  int i;
  printf("\n ");
  for(i=n; i>=0; i--)
    printf("%3d", B[i]);
  d++;
}
void Hamilton(int *B, int *C, int i){
  int j, k;
  for(j=1; j<=n; j++){
    if(A[B[i-1]][j]==1 && C[j]==0){
      B[i]=j; C[j]=1;
      if(i<n) Hamilton(B, C, i+1);
      else if(B[i]==B[0]) Result();
      C[j]=0;
    }
  }
}
int main(void){
  B[0]=1; i=1;d=0;    Init();
  Hamilton(B,C,i);
  if(d==0)    printf("\n Khong co chu trinh Hamilton");
  }
