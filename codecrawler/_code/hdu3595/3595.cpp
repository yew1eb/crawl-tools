#include<cstdio>
int cnt=0;
bool dfs(int a,int b)
{
 if(a<b) a^=b,b^=a,a^=b;
 if(b==0) return 0;
 if(!dfs(b,a%b)){cnt++;return 1;}
 if(a/b>1){cnt+=2;return 1;}
 else {cnt++;return 0;}
}
int main()
{
 int n;
 while(scanf("%d",&n)!=EOF)
 {
 int x,y,a=0,b=0;
 for(int i=0;i<n;i++)
 {
 scanf("%d%d",&x,&y);
 cnt=0;
 if(dfs(x,y)) a=a>cnt?a:cnt;
 else b=b>cnt?b:cnt;
 }
 puts(a>b?"MM":"GG");
 }
 return 0;
}