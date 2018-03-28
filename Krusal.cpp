#include <stdio.h>
#include <conio.h>
#include <dos.h>
#define MAX 50
#define  TRUE 1
#define FALSE   0
int   n, m, minl, connect;
int    dau[500],cuoi[500], w[500];
int      daut[50], cuoit[50], father[50];
void Init(void){
  int i; FILE *fp;
  fp=fopen("DOTHI_Kruskal.in","r");
  fscanf(fp, "%d%d", &n,&m);
  printf("\n So dinh do thi:%d", n);
  printf("\n So canh do thi:%d", m);
  printf("\n Danh sach ke do thi:");
  for(i=1; i<=m;i++){
    fscanf(fp, "%d%d%d", &dau[i], &cuoi[i], &w[i]);
    printf("\n Canh %d: %5d%5d%5d", i, dau[i], cuoi[i], w[i]);
  }
  fclose(fp);getch();
}
void Heap(int First, int Last){
  int j, k, t1, t2, t3;
  j=First;
  while(j<=(Last/2)){
    if( (2*j)<Last && w[2*j + 1]<w[2*j])
      k = 2*j +1;
    else
      k=2*j;
    if(w[k]<w[j]){
      t1=dau[j]; t2=cuoi[j]; t3=w[j];
      dau[j]=dau[k]; cuoi[j]=cuoi[k]; w[j]=w[k];
      dau[k]=t1; cuoi[k]=t2; w[k]=t3;  j=k;
    }
    else j=Last;
  }
}


int Find(int i){
  int tro=i;
  while(father[tro]>0) tro=father[tro];
  return(tro);
}
void Union(int i, int j){
  int x = father[i]+father[j];
  if(father[i]>father[j]) {father[i]=j;father[j]=x; }
  else {
    father[j]=i;  father[i]=x;
  }
}
void Kruskal(void){
  int i, last, u, v, r1, r2, ncanh, ndinh;
  for(i=1; i<=n; i++)   father[i]=-1;
  for(i= m/2;i>0; i++)
    Heap(i,m);
  last=m; ncanh=0; ndinh=0;minl=0;connect=TRUE;
  while(ndinh<n-1 && ncanh<m){
    ncanh=ncanh+1;  u=dau[1]; v=cuoi[1];
    r1= Find(u); r2= Find(v);
    if(r1!=r2) {
      ndinh=ndinh+1; Union(r1,r2);
      daut[ndinh]=u; cuoit[ndinh]=v;
      minl=minl+w[1];
    }
    dau[1]=dau[last];  cuoi[1]=cuoi[last]; w[1]=w[last]; last=last-1;
    Heap(1, last);
  }
  if(ndinh!=n-1) connect=FALSE;
}
void Result(void){
  int i;
  printf("\n Do dai cay khung nho nhat:%d", minl);
  printf("\n Cac canh cua cay khung nho nhat:");
  for(i=1; i<n; i++)
    printf("\n %5d%5d",daut[i], cuoit[i]);
 }
int main(void){
  Init(); Kruskal();Result(); getch();
}
