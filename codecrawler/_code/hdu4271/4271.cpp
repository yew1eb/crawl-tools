#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define to first
#define val second
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,x,y) for(int i=x;i<=(int)y;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long long LL;
const int N = 1e5+100;
const int inf = 0x3f3f3f3f;

int d[12][N]={0};
int dp(char *s1,char *s2,int l1,int l2){
     int  tmp=inf;
     for(int i=1;i<=l1;i++){
         d[i][0]=i;
         for(int j=1;j<=l2;j++){
             d[i][j]=min(d[i-1][j-1]+(s1[i-1]!=s2[j-1]),min(d[i-1][j],d[i][j-1])+1);
             if(i==l1)  tmp=min(tmp,d[i][j]);
         }
     }
     return tmp;
 }
char src[15][15],str[N*2];
int main()
{
   while(scanf("%s",str)==1){
       int Q; scanf("%d",&Q);
       int ans = inf,po = 1;
       int l1 = strlen(str);
       for(int i=l1,j=0;j<15;i++,j++) str[i]=str[j];

       for(int i=1;i<=Q;i++){
           scanf("%s",src[i]);
           int l2 = strlen(src[i]);
           int te = inf;
           if(l1 < l2){
               for(int j=0;j<l1;j++){
                   te = min(te,dp(src[i],str+j,l2,l1));
               }
           }
           else {
                te = min(te, dp(src[i],str,l2,l1+min(20,l1)));
           }
           if(te < ans || (te==ans && strcmp(src[po],src[i])>0)){
                ans = te; po = i;
           }
       }
       printf("%s %d\n",src[po],ans);
   }
   return 0;
}
