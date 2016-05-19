#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define M 100010
using namespace std;
long long a[M],b[M];
long long sum;

void GB(ll* A,int x,int y ,ll* T)
{
    int i;
    if(y-x>1)
    {
        int m=x+(y-x)/2;
        int l=x,r=m,t=x;
        GB(A,x,m,T);
        GB(A,m,y,T);
        while(l<m||r<y)
        {
            if(r>=y||(l<m&&A[l]<=A[r]))
                T[t++]=A[l++];
            else
            {
                T[t++]=A[r++];
                sum+=m-l;
            }
        }
        for(i=x;i<y;i++)
            A[i]=T[i];
    }
}

int main()
{
    int n,m;
    int i,j;
    while(~scanf("%d%d",&n,&m))
    {
        memset(b,0,sizeof b);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        sum=0;
        GB(a,0,n,b);
        sum-=m;
        if(sum<0)sum=0;
        printf("%I64d\n",sum);
    }
    return 0;
}