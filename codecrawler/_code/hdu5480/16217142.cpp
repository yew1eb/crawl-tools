#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
#include<list>
#include<set>
#include<string>
#include<map>
using namespace std;
int heng[100005];
int shu[100005];
int inx[100005];
int iny[100005];
int sum(int end,int *p)
{
    int sum = 0;
    while(end > 0)
    {
        sum += p[end];
        end -= end&-end;
    }
    return sum;
}
void pluss(int pos,int num,int n,int *p)
{
    while(pos <= n)
    {
        p[pos] += num;
        pos += pos&-pos;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k,q;
        scanf("%d%d%d%d",&n,&m,&k,&q);
        memset(heng,0,sizeof(heng));
        memset(shu,0,sizeof(shu));
        memset(inx,0,sizeof(inx));
        memset(iny,0,sizeof(iny));
        for(int i=1; i<=k; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(!heng[x])
            {
                heng[x]=1;
                pluss(x,1,m,inx);
            }
            if(!shu[y])
            {
                shu[y]=1;
                pluss(y,1,n,iny);
            }
        }
        for(int i=1;i<=q;i++)
        {
            bool mark=false;
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(sum(x2,inx)-sum(x1-1,inx)==x2-x1+1||sum(y2,iny)-sum(y1-1,iny)==y2-y1+1) mark=true;
            if(mark) printf("Yes\n");
            else printf("No\n");
        }
    }
    return  0;
}
