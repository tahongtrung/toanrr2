#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define MAX  100
#define  MAXC 10000

int C[MAX][MAX]; //Ma tran trong so bieu dien do thi
int D[MAX];      //Do dai duong di
int Trace[MAX];  //Luu lai vet duong di
int n, m, S, F;  // n:So dinh; S: Dinh bat dau; F: Dinh ket thuc
FILE *fp;
void Read_Data(void){
     int i, u, v;fp = fopen("dothi.in","r");
     fscanf(fp,"%d%d%d%d",&n,&m,&S,&F);
     for(u=1; u<=n; u++)
        for(v=1; v<=n; v++)
         if (u==v) C[u][v]=0;
           else C[u][v]=MAXC;
     for(i=1; i<=m; i++)
         fscanf(fp,"%d%d%d",&u,&v,&C[u][v]);
     fclose(fp);
}
void Init(void){
    int i;
    for( i=1; i<=n; i++){
        D[i] = C[S][i];
        Trace[i]=S;
    }
}
void Result(void){
    if (D[F]==MAXC) printf("\n Khong co duong di");
    else {
         printf("\n Do dai %d den %d: %d", S, F, D[F]);
         while (F!=S ){
               printf("%d <--",F);
               F = Trace[F];
         }
    }
}
void Bellman_Ford(void){
    int k, u, v;D[S]=0;
    for( k=1; k<=n-2; k++){
         for(v=1; v<=n; v++){
            // if (v!=S ){
                for( u=1; u<=n; u++){
                     if (D[v]>D[u]+C[u][v]){
                        D[v] = D[u]+C[u][v];
                        Trace[u]=v;
                     }
                }
            // }
         }
    }
}
int main()
{
      Read_Data();Init();
      Bellman_Ford(); Result();
      system("PAUSE");
      return 0;
}
