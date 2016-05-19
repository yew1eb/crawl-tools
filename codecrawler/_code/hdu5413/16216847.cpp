#include<stdio.h>
#include<string.h>
#include<iostream>
#include<bitset>
using namespace std;
#define N 20010
#define M 100010
#pragma comment(linker, "/STACK:1024000000,1024000000")

//bool kd[N][N];
bitset<N> bs[N];//å°boolæ¢æbitsetå°±ä¸è¶ç©ºé´äº
int head[N],to[M],nextedge[M];
int order[N];
int fro[N];
int sq[N];
int cou;
int edge[M][2];

void add(int a,int b){
    to[cou]=b;nextedge[cou]=head[a];head[a]=cou++;
}

int main(){
    int t;
    int n,m;
    int a,b;
    int ans;

    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        cou=0;
        memset(head,-1,sizeof(head));
        //memset(kd,false,sizeof(kd));
        for(int i=1;i<=n;i++){
            bs[i].reset();
        }
        memset(fro,0,sizeof(fro));
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            edge[i][0]=a;
            edge[i][1]=b;
            add(a,b);
            fro[b]++;
        }

        int qend=0;
        int oend=0;
        for(int i=1;i<=n;i++){
            if(fro[i]==0){
                sq[qend++]=i;
                order[oend++]=i;
            }
        }

        while(qend!=0){
            int temp=sq[--qend];

            for(int i=head[temp];i!=-1;i=nextedge[i]){
                int v=to[i];
                fro[v]--;
                if(!fro[v]){
                    order[oend++]=v;
                    sq[qend++]=v;
                }
            }
        }

        /*for(int i=0;i<oend;i++){
            printf("%d ",order[i]);
        }
        printf("\n");*/

        for(int i=oend-1;i>=0;i--){//æè§æ¯è¿éæµªè´¹äºå¾å¤æ¶é´ï¼åºè¯¥è¦ç®åä¸ä¸ã
            int u=order[i];
            for(int j=head[u];j!=-1;j=nextedge[j]){
                int v=to[j];

                //kd[u][v]=true;
                bs[u][v]=1;
                /*for(int k=1;k<=n;k++){
                    //kd[u][k]=kd[v][k];
                    if(bs[v][k]){
                        bs[u][k]=1;
                    }
                }*/
                bs[u]|=bs[v];
            }
        }



        ans=0;
        for(int i=0;i<m;i++){
            int u=edge[i][0];
            int v=edge[i][1];

            for(int j=head[u];j!=-1;j=nextedge[j]){
                if(/*kd[to[j]][v]*/bs[to[j]][v]){
                    ans++;
                    break;
                }
            }
        }

        printf("%d\n",ans);
    }
}
