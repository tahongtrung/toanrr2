#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>
#define MAX 10000
#define  TRUE 1
#define FALSE   0
int A[50][50], D[50][50], S[50][50];
int n, u, v, k;FILE *fp;
void Init(void){
  int i, j, k;
  fp=fopen("DOTHI_Floyd.IN","r");
  if(fp==NULL){
    printf("\n Khong co file input");
    getch(); return;
  }
  for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
      A[i][j]=0;
  fscanf(fp,"%d%d%d",&n,&u,&v);
  printf("\n So dinh do thi:%d",n);
  printf("\n Di tu dinh:%d den dinh %d:",u,v);
  printf("\n Ma tran trong so:");
  for(i=1; i<=n; i++){
    printf("\n");
    for(j=1; j<=n; j++){
      fscanf(fp,"%d", &A[i][j]);
      printf("%5d",A[i][j]);
      if(i!=j && A[i][j]==0)
        A[i][j]=MAX;
    }
  }
  fclose(fp);getch();
}
void Result(void){
  if(D[u][v]>=MAX) {
    printf("\n Khong co duong di");
    getch(); return;
    }
  else {
    printf("\n Duong di ngan nhat:%d", D[u][v]);
    printf("\n Dinh %3d", u);
    while(u!=v) {
      printf("%3d",S[u][v]);
      u=S[u][v];
    }
  }
}
void Floyd(void){
  int i, j,k, found;
  for(i=1; i<=n; i++){
    for(j=1; j<=n;j++){
      D[i][j]=A[i][j];
      if (D[i][j]==MAX) S[i][j]=0;
      else S[i][j]=j;
    }
  }
  /* Mang D[i,j] la mang chua cac gia tri khoan cach ngan nhat tu i den j
  Mang S la mang chua gia tri phan tu ngay sau cua i tren duong di
  ngan nhat tu i->j  */
  for (k=1; k<=n; k++){
    for (i=1; i<=n; i++){
      for (j=1; j<=n; j++){
        if (D[i][k]!=MAX && D[i][j]>(D[i][k]+D[k][j]) ){
        // Tim D[i,j] nho nhat co the co
          D[i][j]=D[i][k]+D[k][j];
          S[i][j]=S[i][k];
          //ung voi no la gia tri cua phan tu ngay sau i
        }
      }
    }
  }
}
int main(void){
  Init();
  Floyd();Result();
}
