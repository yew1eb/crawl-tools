#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define N 100011

int n;
struct A
{
    int x,y;
}E[N];
int x[N],y[N];

int lowbit[N];
__int64 C[2][N];								//0x、1y

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
void get_lowbit()
{
    int i;
    for(i=1;i<=100000;i++)    lowbit[i]=i&(-i);
}

__int64 sum(int K,int k)
{
    __int64 p=0;
    while(k>0 && k<=n)
    {
        p+=C[K][k];
        k-=lowbit[k];
    }
    return p;
}
void update(int K,int k,int dir)
{
    while(k>0 && k<=n)
    {
        C[K][k]+=dir;
        k+=lowbit[k];
    }
}
void init()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&E[i].x,&E[i].y);
        x[i]=E[i].x;
        y[i]=E[i].y;
    }
    x[0]=y[0]=-1111111111;
    qsort(x,n+1,sizeof(int),cmp);
    qsort(y,n+1,sizeof(int),cmp);
    memset(C,0,sizeof(C));
    for(i=1;i<=n;i++)
    {
        update(0,i,x[i]);
        update(1,i,y[i]);
    }
}
__int64 solve()
{
    int i;
    int low,mid,up;
    __int64 a,b;
    __int64 sum_x,sum_y;
    __int64 temp,ans;
    ans=100011;
    ans*=1000000000;
    sum_x=sum(0,n);
    sum_y=sum(1,n);
    for(i=1;i<=n;i++)
    {
        low=1;up=n;mid=(low+up)>>1;
        while(low<=up)
        {
            if(x[mid]<E[i].x)    low=mid+1;
            else                up=mid-1;
            mid=(low+up)>>1;
        }
        a=sum(0,low);
        temp=(__int64)low*E[i].x-a+sum_x-a-(n-(__int64)low)*E[i].x;
        low=1;up=n;mid=(low+up)>>1;
        while(low<=up)
        {
            if(y[mid]<E[i].y)    low=mid+1;
            else                up=mid-1;
            mid=(low+up)>>1;
        }
        b=sum(1,low);
        temp+=(__int64)low*E[i].y-b+sum_y-b-(n-(__int64)low)*E[i].y;
        if(temp<ans)    ans=temp;
    }
    return ans;
}

int main()
{
    int T;
    get_lowbit();
    scanf("%d",&T);
    while(T--)
    {
        init();
        printf("%I64d\n",solve());
    }
    return 0;
}