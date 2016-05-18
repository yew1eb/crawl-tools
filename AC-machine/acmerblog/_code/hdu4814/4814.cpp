#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100

int a[N*2];
int n,u,v;

int main()
{
    int i,k,flag;
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        a[N]=n;
        do
        {
            flag=0;
            for(i=0;i<N*2-2;i++)
            {
                if(a[i]&&a[i+1])
                {
                    k=min(a[i],a[i+1]);
                    a[i]-=k;
                    a[i+1]-=k;
                    a[i+2]+=k;
                    flag=1;
                }
            }
            for(i=2;i<N*2-1;i++)
            {
                if(a[i]>1)
                {
                    k=a[i]/2;
                    a[i]%=2;
                    a[i-2]+=k;
                    a[i+1]+=k;
                    flag=1;
                }
            }
        }while(flag);
        for(u=2*N-1;u>N&&!a[u];u--);
        for(v=0;v<N&&!a[v];v++);
        for(i=u;i>=N;i--) printf("%d",a[i]);
        if(v!=N)
        {
            printf(".");
            for(i=N-1;i>=v;i--) printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
