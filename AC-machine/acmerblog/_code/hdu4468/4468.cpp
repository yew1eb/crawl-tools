#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 100005
int next[MAXN];
char s[MAXN],p[MAXN];
void getnext(int n,int st)
{
    for(int i=st+1;i<n;i++)
    {
        int j=next[i];
        while(j&&p[i]!=p[j])
        {
            j=next[j];
        }
        if(p[i]==p[j])
        {
            next[i+1]=j+1;
        }
        else
        {
            next[i+1]=0;
        }
    }
}
int ans;
int updata(int last,int now,int st)
{
   // int len=strlen(p)   //因为加了这句,TLE调了我好久。
    int len=st+1;
    for(int i=last+1;i<=now;i++)
    {
        p[len++]=s[i];
    }
    p[len]='\0';
    getnext(len,st);
    return len;
}
int kmp(int m)
{
    getnext(m,0);
    int j=0;
    int last;
    for(int i=0;s[i];i++)
    {
        while(j&&s[i]!=p[j])
            j=next[j];
        if(j==0&&s[i]!=p[j])
        {
            m=updata(last,i,m-1);
            last=i;
        }
        if(s[i]==p[j])
          j++;
        if(j==m)
        {
            last=i;
        }
    }
    for(int i=last+1;s[i];i++)
        m++;
    ans=m;
    return -1;
}
int main()
{
    int cas=1;
    while(scanf("%s",&s)!=EOF)
    {
        memset(next,0,sizeof(next));
        p[0]=s[0];
        p[1]='\0';
        ans=1;
        kmp(1);
        printf("Case %d: %d\n",cas++,ans);
    }
}
