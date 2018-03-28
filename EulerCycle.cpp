#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50
#define  TRUE 1
#define FALSE   0
int A[MAX][MAX], n, u=1;
void Init(void){
  int i, j;FILE *fp;
  fp = fopen("DOTHI_EulerCycle.IN", "r");
  fscanf(fp,"%d", &n);
  printf("\n So dinh do thi:%d",n);
  printf("\n Ma tran ke:");
  for(i=1; i<=n;i++){
    printf("\n");
    for(j=1; j<=n;j++){
      fscanf(fp,"%d", &A[i][j]);
      printf("%3d", A[i][j]);
    }
  }
  fclose(fp);
}
int Kiemtra(void){
  int i, j, s, d;  d=0;
  for(i=1; i<=n;i++){
    s=0;
    for(j=1; j<=n;j++)
      s+=A[i][j];
    if(s%2) d++;
  }
  if(d>0) return(FALSE);
  return(TRUE);
}
void EulerCycle(int u){
int v, x, top, dCE;
  int stack[MAX], CE[MAX];
  top=1; stack[top]=u;dCE=0;
  do {
    v = stack[top];x=1;
    while (x<=n && A[v][x]==0)
      x++;
    if (x>n) {
      dCE++; CE[dCE]=v; top--;
    }
    else {
      top++; stack[top]=x;
      A[v][x]=0; A[x][v]=0;
    }
  } while(top!=0);
  printf("\n Co chu trinh Euler:");
  for(x=dCE; x>0; x--)
    printf("%3d", CE[x]);
}
int main(void){
  Init();
  if(Kiemtra())
    EulerCycle(u);
  else printf("\n Khong co chu trinh Euler");
}
