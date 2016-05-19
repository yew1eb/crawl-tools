#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

int a[30];
bool vis[30];
int n,m,sum,len;
bool dfs(int cur,int time ,int k)
{
    if(time==3)  return true;
    for(int i=k; i>=1; i--)
    {
        if(!vis[i]){
            vis[i]=true;
            if(cur+a[i]==len){
                if(dfs(0,time+1,m)) return true;
            }
            else if(cur+a[i]<len){
                if(dfs(cur+a[i],time,i-1)) return true;     //¹Ø¼üÊÇi-1..²»È»»áÒ»Ö±³¬Ê±µÄ¡£¡£

            }
            vis[i]=false;
        }
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m); sum=0;
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        memset(vis,0,sizeof(vis));
        sort(a,a+m);
        if(sum%4==0&&a[m]<=sum/4)
        {
            len=sum/4;
            if(dfs(0,0,m))  printf("yes\n");
            else            printf("no\n");
        }
        else  printf("no\n");

    }
    return 0;
}
