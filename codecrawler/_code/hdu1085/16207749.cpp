#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
typedef __int64 ll;
typedef unsigned __int64 ULL;
#define inf 99999999
#define maxn 100100
ll c1[maxn],c2[maxn];
int main(){
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c)){
        if(a==0&&b==0&&c==0) break;
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        int lmax=a+2*b+5*c;
        for(int i=0;i<=a;i++){
            c1[i]=1; c2[i]=0;
        }
        for(int j=0;j<=a;j++){
            for(int k=0;k<=2*b;k+=2){
                c2[j+k]+=c1[j];
            }
        }
        for(int j=0;j<=a+2*b;j++){
            c1[j]=c2[j];
            c2[j]=0;
        }
        for(int j=0;j<=a+2*b;j++){
            for(int k=0;k<=5*c;k+=5){
                c2[j+k]+=c1[j];
            }
        }
        for(int j=0;j<=a+2*b+5*c;j++){
            c1[j]=c2[j];
            c2[j]=0;
        }
        for(int i=1;i<=lmax+1;i++){
            if(!c1[i]){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}