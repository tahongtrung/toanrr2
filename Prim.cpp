#include <stdio.h>
#include <conio.h>
#define  TRUE 1
#define FALSE   0
#define MAX 10000
int   a[100][100];
int  n,m, i,sc,w;
int   chuaxet[100];
int   cbt[100][3];
FILE *f;
void Init (void){
  int  p,i,j,k;
  for(i=1; i<=n; i++)
    for(j=1; j<=n;j++)
      a[i][j]=0;
  f=fopen("DOTHI_Prim.in","r");
  fscanf(f,"%d%d",&n,&m);
  printf("\n So dinh: %3d  ",n);
  printf("\n So canh: %3d", m);
  printf("\n Danh sach canh:");
  for(p=1; p<=m; p++){
    fscanf(f,"%d%d%d",&i,&j,&k);
    printf("\n %3d%3d%3d", i, j, k);
    a[i][j]=k; a[j][i]=k;
  }
  for (i=1; i<=n; i++){
    printf("\n");
    for (j=1; j<=n; j++){
      if (i!=j && a[i][j]==0)
        a[i][j]=MAX;
      printf("%7d",a[i][j]);
    }
  }
  fclose(f);getch();
}
void Result(void){
   for(i=1;i<=sc; i++)
    printf("\n %3d%3d", cbt[i][1], cbt[i][2]);
}
void PRIM(void){
  int i,j,k,top,min,l,t,u;
  int s[100];
  sc=0;w=0;u=1;
  for(i=1; i<=n; i++)
    chuaxet[i]=TRUE;
  top=1;s[top]=u;
  chuaxet[u]=FALSE;
  while (sc<n-1) {
    min=MAX;
    for (i=1; i<=top; i++){
      t=s[i];
      for(j=1; j<=n; j++){
        if (chuaxet[j] && min>a[t][j]){
          min=a[t][j];
          k=t;l=j;
        }
      }
    }
    sc++;w=w+min;
    cbt[sc][1]=k;cbt[sc][2]=l;
    chuaxet[l]=FALSE;a[k][l]=MAX;
    a[l][k]=MAX;top++;s[top]=l;
    printf("\n");
  }
}
int main(void){
  Init();PRIM();Result();
}
