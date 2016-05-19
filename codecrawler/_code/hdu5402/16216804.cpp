//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<stdio.h>
#include<math.h>
#include <string>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#include<utility>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
#define eps 1e-8
#define inf 0x3f3f3f3f
#define rd(x) scanf("%d",&x)
#define rd2(x,y) scanf("%d%d",&x,&y)
#define ll long long int
#define mod 1000000007
#define maxn 900006
#define maxm 500010
int f[101][101],n,m;
int main()
{
    while(~scanf("%d%d",&n,&m)){
            int kx=-1;
            int ky=-1;
            int sum=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
        {
            rd(f[i][j]);
            sum+=f[i][j];
            if((i+j-2)%2){
                if(kx==-1) kx=i,ky=j;
                else if(f[i][j]<f[kx][ky]) kx=i,ky=j;
            }
        }
        if(n%2||m%2){
            printf("%d\n",sum);
            if(n&1)
            for(int i=1;i<=n;i++)
            {
                if(i!=1) printf("D");
                for(int j=2;j<=m;j++)
                    if(i%2) printf("R");
                else printf("L");
            }
            else if(m&1)
                for(int i=1;i<=m;i++)
            {
                if(i!=1) printf("R");
                for(int j=2;j<=n;j++)
                    if(i%2) printf("D");
                else printf("U");
            }
            printf("\n");
            continue;
        }
        printf("%d\n",sum-f[kx][ky]);
        int k=1;
        while(1){
            if(kx%2&&k==kx) break;
        if(kx%2==0&&(k+1)==kx) break;
            for(int i=2;i<=m;i++)
                if(k%2) printf("R");
            else printf("L");
            printf("D");
            k++;
        }
        if(kx%2){
            int cx=k;
            int cy=1;
            while((cy+1)!=ky){
                printf("DRUR");
                cy+=2;
            }
            printf("DR");cx++;cy++;
            while(cy!=m){
                printf("RURD");cy+=2;
            }
                    //cx--;cy++;
                k+=2;
            }
        else{
            int cx=k;
            int cy=1;
            while(cy!=ky){
                printf("DRUR");
                cy+=2;
            }
            printf("RD");cx++;cy++;
            while(cy!=m) {
                printf("RURD");cy+=2;
            }
            k+=2;
        }
        for(int i=k;i<=n;i++)
        {
            printf("D");
            for(int j=2;j<=m;j++)
                if(i%2) printf("L");
            else printf("R");
        }
        printf("\n");
    }
    return 0;
}
