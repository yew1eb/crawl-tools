#include"stdio.h"
#include"string.h"
#include"algorithm"
using namespace std;
int n,ans;
int A[4010];
int cnt;
int ret;
int t[3];
int is_prime(int x)
{
    int i;
    for(i=2;i*i<=x;i++)
        if(x%i==0)return 0;
        return 1;
}
//从第x个开始，已经找到y个，总共需要找z个。。。
void dfs(int x,int y,int z)
{
    int i;    
    if(y==z)
    {
        int tem=n;
        int f=0;
        for(i=0;i<z;i++)
        {
            if(tem%(t[i]-1)!=0)
            {
                f=1;break;
            }
            tem/=(t[i]-1);
        }
        if(f==0)
        {
            for(i=0;i<z;i++)
            {
                while(tem%t[i]==0)
                    tem/=t[i];
            }
            if(tem==1)ret++;
        }
    }
    else
    {
        for(i=x;i<cnt;i++)
        {
            t[y]=A[i];
            dfs(i+1,y+1,z);
        }
    }
}

int main()
{
    while(scanf("%d",&n)!=-1)
    {
        if(n==1)
        {
            printf("2\n");
            continue;
        }
        else
        {
            int i,j;
            cnt=0;
            //将n的素因子存入A中。
            for(i=1;i*i<=n;i++)
            {
                if(n%i==0&&is_prime(i+1)==1)
                    A[cnt++]=i+1;
                if(n%i==0&&is_prime(n/i+1)==1)
                    A[cnt++]=n/i+1;
            }
            sort(A,A+cnt);
            //可能有重复的。。。
            for(i=1;i<cnt;i++)
            {
                if(A[i]==A[i-1])
                {
                    for(j=i;j<cnt-1;j++)
                        A[j]=A[j+1];
                    cnt--;
                }
            }
            ans=0;
            for(i=1;i<=3;i++)
            {
                ret=0;
                dfs(0,0,i);
                ans+=ret;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}