#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


vector<int> gra[100005];
int sg(int now,int fa)
{
 int sum=0;
 for(int i=0;i<gra[now].size();i++)
 if(gra[now][i]!=fa) sum^=sg(gra[now][i],now)+1;
 return sum;
}
int main()
{
 // freopen("1.txt","r",stdin);
 int c;
 while(scanf("%d",&c)==1)
 {
 int n,x,y,sum=0;
 bool anti=1;
 for(int k=0;k<c;k++)
 {
 scanf("%d",&n);
 for(int i=n;i>-1;i--)
 gra[i].clear();
 for(int i=1;i<n;i++)
 {
 scanf("%d%d",&x,&y);
 gra[x].push_back(y);
 gra[y].push_back(x);
 }
 int temp=sg(1,0);
 if(temp>1) anti=0;
 sum^=temp;
 }
 if(anti)
 {
 if(sum==0) printf("PP\n");
 else printf("QQ\n");
 }
 else
 {
 if(sum) printf("PP\n");
 else printf("QQ\n");
 }
 }
 return 0;
}