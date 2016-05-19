//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<stack>
#include<queue>
using namespace std;
#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define clr(x,a) memset(x,a,sizeof(x))
#define read(x) scanf("%d",&x)
//#define read(x,y) scanf("%d%d",&x,&y)
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int N = 55555;
const int MOD=1e9+7;
const int MAX=0x3f3f3f3f;
int n,m,num,n1,n2;
int b[N];
int mi[N];
int ma[N];
int main(){
   while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        num=unique(b,b+n)-b;
        n1=0;n2=0;
        if(num>1){
            if(b[0]>b[1]) ma[n2++]=b[0];
            for(int i=1;i<n-1;i++){
                if(b[i]>b[i-1] && b[i]>b[i+1]) ma[n2++]=b[i];
                if(b[i]<b[i-1] && b[i]<b[i+1]) mi[n1++]=b[i];
            }
            if(b[n-1]>b[n-2]) ma[n2++]=b[n-1];
            sort(mi,mi+n1);
            sort(ma,ma+n2);
        }
        int x;
        for(int i=0;i<m;i++){
            scanf("%d",&x);
                int ans1=upper_bound(mi,mi+n1,x)-mi; 
                int ans2=upper_bound(ma,ma+n2,x)-ma;
                printf("%d\n",n2-ans2-(n1-ans1));
        }

   }

  return 0;
}
