#include <stdio.h>
#include <conio.h>
#include <iostream>
#define MAX 50
#define TRUE 1
#define FALSE 0
int A[MAX][MAX], n,chuaxet[MAX], truoc[MAX], s, t;
void Init(void){//Doc du lieu va khoi dau cac bien
  int i,j;FILE *fp;
  fp=fopen("dothi_duongdi.in","r");
  fscanf(fp,"%d",&n);
  printf("\n So dinh do thi:%d",n);
  for(i=1; i<=n; i++){
  printf("\n");chuaxet[i]=TRUE;truoc[i]=0;
    for(j=1; j<=n; j++){
      fscanf(fp,"%d",&A[i][j]);
      printf("%3d",A[i][j]);
    }
  }
}
void DFS(int u){//Thuat toan DFS
  int v;
  printf("%3d",u);chuaxet[u]=FALSE;
  for(v=1; v<=n; v++){
    if(A[u][v] && chuaxet[v]){
       truoc[v]=u;DFS(v);
    }
  }
}
void BFS(int i){//Thuat toan BFS
  int queue[MAX], low=1, high=1, u, v;
  queue[low]=i;chuaxet[i]=FALSE;
  while(low<=high){
    u = queue[low];low=low+1;
    for(v=1; v<=n; v++){
      if(A[u][v] && chuaxet[v]){
        high = high+1;queue[high]=v;
        truoc[v]=u; chuaxet[v]=FALSE;
      }
    }
  }
}

void Duongdi (void){
  if (truoc[t]==0){
    printf("\n Khong ton tai duong di");
    getch(); return;
  }
  printf("\n Duong di:");
  int j = t;printf("%3d<=",j);
  while(truoc[j]!=s){
    printf("%3d<=",truoc[j]);j=truoc[j];
  }
  printf("%3d",s); getch();
}
int main (void){
  Init();
  printf("\n Dinh dau: ");scanf("%d",&s);
  printf("\n Dinh cuoi: ");scanf("%d",&t);
  //DFS(s);
  BFS(s);
Duongdi();
}
