#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int f[55];
int Max;
int n,V,m;
bool hash[55];

void dfs(int x,int cnt,int s){ // 表示 到第x个物品，取了cnt个，总价值s
  if(cnt>n||x>m) return;
  if(s>Max) Max=s;
  int i;
 // int num=0;
 // long long ss=s;
 // for(i=m;i>=1;i--){
 //  if(hash[i]==0){
 //   ss+=f[i];
 //   num++;
 //  }
 //  if(num+cnt==n) break;
 // }
 // if(ss<V) {Max=ss;return;}

  for(i=x+1;i<=m;i++) {
   if(hash[i]==0) {

    if(s+f[i]>V) continue;
    hash[i]=1;
    dfs(x+1,cnt+1,s+f[i]);
    hash[i]=0;
   }
  }
}

int main()
{
 while(scanf("%d%d",&n,&V)!=EOF) {

  scanf("%d",&m);

  for(int i=1;i<=m;i++)
   scanf("%d",f+i);

   sort(f+1,f+1+m);   //排序

   // 38~42行,是剪枝, 不加就TLE,加了就 15MS，有时 0MS
   // 14-23行类似
   long long ss=0;   //注意要用64位，不然n个大的物品加起来可能就超 int 了
   for(int i=m;i>m-n;i--) ss+=f[i];    //求最大的n个物品总价值
   if(f[1]>V) ss=0;

   if(ss<V) {printf("%I64d/n",ss);continue;} //如果最大的n个物品总和比V小，就不用搜了

   Max=0;

   memset(hash,0,sizeof(hash));

   dfs(0,0,0);     // 表示 到第0个物品，取了0个，总价值0

   printf("%d/n",Max);
 }
}