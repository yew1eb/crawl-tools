#include <stdio.h>
#include <math.h>

int p[100];
int up;
long long ansa,ansb,ans;
long long a,b;

void DFS(int n,bool tag,long long num)
{
    if (n==up)
    {
        if (tag==1)
        {
            ansa-=a/num;
            ansb-=b/num;
        }
        else
        {
            ansa+=a/num;
            ansb+=b/num;
        }
        return;
    }
    DFS(n+1,tag,num);
    DFS(n+1,!tag,num*p[n]);
}

int main()
{
    int i,j,n,T,k,cnt;
    cnt=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d%d",&a,&b,&n);
        a--;
        ansa=ansb=0;
        up=0;
        k=n;
        for (i=2;i<=sqrt(n*1.0);i++)
        {
            if (k%i==0)
            {
                while(k%i==0) k=k/i;
                p[up++]=i;
            }
        }
        if (k!=1)
        {
            p[up++]=k;
        }
        DFS(0,0,1);
      //  printf("%lld..%lld\n",ansb,ansa);
        printf("Case #%d: %I64d\n",cnt++,ansb-ansa);
    }
    return 0;
}
