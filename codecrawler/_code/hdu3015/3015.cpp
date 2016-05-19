/************hdu3015*****************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010

int num_small[N],sum_small[N];

int n;

struct tree
{
    int x,h;
    int cx,ch;//存x和h的rank
    int id;
}t[N],t1[N],t2[N];

void add(int i,int num,int *a)
{
    while(i<=n)
    {
        a[i]+=num;
        i+=i&(-i);
    }
}

__int64 sum(int i,int *a)
{
    __int64 ans=0;
    while(i>0)
    {
        ans+=a[i];
        i-=i&(-i);
    }
    return ans;
}

bool cmp1(tree a,tree b)
{
    return a.x<b.x;
}
bool cmp2(tree a,tree b)
{
    return a.h<b.h;
}
bool cmp(tree a,tree b)
{
    return a.ch>b.ch;//!!!!
}

void init()
{
    sort(t1+1,t1+n+1,cmp1);
    sort(t2+1,t2+n+1,cmp2);
    int i,j,k;
    k=t1[1].id;
    t1[1].cx=1;
    t[k].cx=1;
    for(i=2;i<=n;i++)
    {
        if(t1[i].x==t1[i-1].x)
        {
            t1[i].cx=t1[i-1].cx;
            k=t1[i].id;
            t[k].cx=t1[i].cx;
        }
        else
        {
            t1[i].cx=i;
            k=t1[i].id;
            t[k].cx=t1[i].cx;
        }
    }
    t2[1].ch=1;
    k=t2[1].id;
    t[k].ch=1;
    for(i=2;i<=n;i++)
    {
        if(t2[i].h==t2[i-1].h)
        {
            t2[i].ch=t2[i-1].ch;
            k=t2[i].id;
            t[k].ch=t2[i].ch;
        }
        else
        {
            t2[i].ch=i;
            k=t2[i].id;
            t[k].ch=t2[i].ch;
        }
    }
    /*for(i=1;i<=n;i++)
    printf("%d ",t[i].cx);
    printf("/n");
    for(i=1;i<=n;i++)
    printf("%d ",t[i].ch);
    printf("/n");*/
}
int main()
{
    //freopen("a.txt","r",stdin);
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&t[i].x,&t[i].h);
        t[i].id=i;
        t1[i]=t2[i]=t[i];
    }
    init();
    sort(t+1,t+n+1,cmp);
    memset(num_small,0,sizeof(num_small));
    memset(sum_small,0,sizeof(sum_small));
    __int64 ans=0;
    __int64 sum_x=t[1].cx;//t[i]前面所有数总和
    add(t[1].cx,1,num_small);
    add(t[1].cx,t[1].cx,sum_small);
    __int64 num_min,sum_min;
    for(i=2;i<=n;i++)
    {
        num_min=sum(t[i].cx,num_small);//t[i]前面比a[i]小的数的个数
        sum_min=sum(t[i].cx,sum_small);//t[i]前面比a[i]小的数的和
        //printf("!%d/n", num_min*t[i].cx-sum_min+sum_x-sum_min-(i-num_min-1)*t[i].cx);
        ans+=t[i].ch*(num_min*t[i].cx-sum_min + sum_x-sum_min-(i-num_min-1)*t[i].cx);//第i个与其他的差的和
        add(t[i].cx,1,num_small);
        add(t[i].cx,t[i].cx,sum_small);
        sum_x+=t[i].cx;
    }
    printf("%I64d/n",ans);
    }
    return 0;
}