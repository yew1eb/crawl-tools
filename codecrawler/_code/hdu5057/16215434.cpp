//1296ms
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=100000+1000;
int a[11][maxn];
int b[maxn];
int c[maxn];
int ans[maxn];
int n,m;
struct node
{
    int kind;
    int l,r,d,p,pos,value;
}op[maxn];
int low(int k)
{
    return k&(-k);
}
void update(int x,int k,int v)
{
    while(k<maxn)
    {
        a[x][k]+=v;
        k+=low(k);
    }
}
int getsum(int x,int k)
{
    int ans=0;
    while(k>0)
    {
        ans+=a[x][k];
        k-=low(k);
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            c[i]=b[i];
        }
        char s[10];
        for(int i=0;i<m;i++)
        {
            scanf("%s",s);
            if(s[0]=='Q')
            {
                op[i].kind=0;
                scanf("%d%d%d%d",&op[i].l,&op[i].r,&op[i].d,&op[i].p);
            }
            else
            {
                op[i].kind=1;
                scanf("%d%d",&op[i].pos,&op[i].value);
            }
        }
        int po=1;
        for(int i=1;i<=10;i++)//æä½æä¸¾
        {
            memset(a,0,sizeof(a));
            for(int j=1;j<=n;j++)
            {
                b[j]=c[j];//æ¯æ¬¡æ¢å¤ä¸ºåæ¥çå¼
                int temp=(b[j]/po)%10;
                update(temp,j,1);
            }
            for(int j=0;j<m;j++)
            {
                if(op[j].kind==1)//æ´æ¹æä½
                {
                    int temp=(b[op[j].pos]/po)%10;
                    update(temp,op[j].pos,-1);
                    temp=(op[j].value/po)%10;
                    update(temp,op[j].pos,1);
                    b[op[j].pos]=op[j].value;
                }
                else
                {
                    if(op[j].d==i)//å¯¹åºä½çæ¥è¯¢
                    ans[j]=getsum(op[j].p,op[j].r)-getsum(op[j].p,op[j].l-1);
                    else
                    ;
                }
            }
            po=po*10;
        }
        for(int j=0;j<m;j++)
        if(op[j].kind==0)
        {
            printf("%d\n",ans[j]);
        }
    }
    return 0;
}
