#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
map<string,int> m;
int set[100005];
int num[100005];
int find(int x)
{
    int r=x;
    while(r!=set[r])
    r=set[r];
    int i=x;
    while(i!=r)
    {
        int j=set[i];
        set[i]=r;
        i=j;
    }
    return r;
}
void merge(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    {
        set[fx]=fy;
        num[fy]+=num[fx];
        printf("%d\n",num[fy]);
    }
    else
    {
        printf("%d\n",num[fy]);
    }
}
int main()
{
    int t;
    char a[25];
    char b[25];
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            int n;
            scanf("%d",&n);
            for(int i=1;i<100005;i++)
            {
                set[i]=i;
                num[i]=1;
            }
            m.clear();
            int ans=1;
            for(int i=1;i<=n;i++)
            {
                scanf("%s%s",a,b);
                if(!m[a])
                {
                    m[a]=ans++;
                }
                if(!m[b])
                {
                    m[b]=ans++;
                }
                merge(m[a],m[b]);
            }
        }
    }
    return 0;
}
