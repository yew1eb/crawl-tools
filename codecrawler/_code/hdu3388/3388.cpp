#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef  long long ll;

int flag[40000],prime[40000],pri_num;
int factor[25],fac_num;
ll t,ans,sum,mid;

void get_prime()
{
    int i,j;

    memset(flag,0,sizeof(flag));
    for(i = 2;i*i<40000;i++)
     if(flag[i]==0)
      for(j = i*i;j<40000;j+=i)
       flag[j] = 1;
    pri_num = 0;
    for(i = 2;i<40000;i++)
     if(flag[i]==0)
      prime[pri_num++] = i;
}

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

void dfs(int set,int num,int kk)
{
    int i;

    for(i = set;i<=fac_num-num+kk;i++)
    {
        sum*=factor[i];
        if(kk==num-1)
         ans+=(mid/sum)*t;
        else
         dfs(i+1,num,kk+1);
        sum/=factor[i];
    }
}

int main()
{
    int m,n,k,i,j,T,cc;
    ll low,high,keep,INF;

    cc = 0;
    get_prime();
    scanf("%d",&T);
    INF = 1;
    for(i = 1;i<=62;i++)
     INF*=2;
    while(T--)
    {
        cc++;
        scanf("%d%d%d",&m,&n,&k);
        if(m==1&&n==1)
        {
            printf("Case %d: %d\n",cc,k);
            continue;
        }
        fac_num = 0;
        for(i = 0;i<pri_num&&m>=prime[i];i++)
         if(m%prime[i]==0)
         {
             factor[fac_num++] = prime[i];
             while(m%prime[i]==0)
              m/=prime[i];
         }
         if(m>1)
          factor[fac_num++] = m;
        for(i = 0;i<pri_num&&n>=prime[i];i++)
         if(n%prime[i]==0)
         {
             factor[fac_num++] = prime[i];
             while(n%prime[i]==0)
              n/=prime[i];
         }
         if(n>1)
          factor[fac_num++] = n;
         qsort(factor,fac_num,sizeof(factor[0]),cmp);
         n = fac_num;
         fac_num = 0;
         for(i = 1;i<n;i++)
          if(factor[i]!=factor[i-1])
           factor[fac_num++] = factor[i-1];
         factor[fac_num++] = factor[n-1];
         low = 1;high = INF;
         while(low<=high)
         {
             mid = high-(high-low)/2;
             ans = 0;
             t = 1;
             for(i = 1;i<=fac_num;i++)
             {
                 sum = 1;
                 dfs(0,i,0);
                 t*=-1;
             }
             ans = mid-ans;
             if(ans>=(ll)k)
             {
                 keep = mid;
                 high = mid-1;
             }
             else
              low = mid+1;
         }
         printf("Case %d: %I64d\n",cc,keep);
    }
    return 0;
}