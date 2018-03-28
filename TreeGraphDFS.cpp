#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 50
#define  TRUE 1
#define FALSE  0
int CBT[MAX][2], n, A[MAX][MAX], chuaxet[MAX], sc, QUEUE[MAX];
void Init(void){
  int i, j;FILE *fp;
  fp= fopen("DOTHI_TreeGraphDFS.IN", "r");
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
    chuaxet[i]=TRUE;
}
void TREE_DFS(int i){
  int j; chuaxet[i] = FALSE;
  if(sc==n-1) return;
  for(j=1; j<=n; j++){
    if (chuaxet[j] && A[i][j]){  sc++;
      CBT[sc][1]=i; CBT[sc][2]=j;
      if(sc==n-1) return;
      TREE_DFS(j);
    }
  }
}
void Result(void){
  int i, j;
  for(i=1; i<=sc; i++){
    printf("\n Canh %d:", i);
    for(j=1; j<=2; j++)
      printf("%3d", CBT[i][j]);
  }
}
int main(void){
  int i; Init(); sc=0; i=1; /* xây dựng cây bao trùm tại đỉnh 1*/
  TREE_DFS(i);
  if(sc<n-1) printf("\n Đồ thị không liên thông");
else Result();
}
