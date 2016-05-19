#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 100050
long long sum_len_left[MAX];
long long sum_len_right[MAX];
int sum_apple_left[MAX],sum_apple_right[MAX];


long long ans;
int Left,Right;
int n,k,l,T,x_len,a_apple;


void solve()
{
    for(int i=1; i<=Left; i++)
    {
        if(i<=k)
            sum_len_left[i]=sum_apple_left[i];
        else
            sum_len_left[i]=sum_len_left[i-k]+sum_apple_left[i];
    }
    for(int i=1; i<=Right; i++)
    {
        if(i<=k)
            sum_len_right[i]=sum_apple_right[i];
        else
            sum_len_right[i]=sum_len_right[i-k]+sum_apple_right[i];
    }
    ans=(sum_len_left[Left]+sum_len_right[Right])*2;
}


int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(sum_len_left,0,sizeof(sum_len_left));
        memset(sum_len_right,0,sizeof(sum_len_right));


        scanf("%d%d%d",&l,&n,&k);
        Left=0,Right=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&x_len,&a_apple);
            for(int j=0; j<a_apple; j++)
            {
                if(x_len*2<l)
                    sum_apple_left[++Left]=x_len;
                else
                    sum_apple_right[++Right]=l-x_len;
            }
        }


        sort(sum_apple_left+1,sum_apple_left+Left+1);
        sort(sum_apple_right+1,sum_apple_right+Right+1);
        solve();


        for(int i=0; i<=k; i++)
        {
            long long lll = (sum_len_left[Left-i]+sum_len_right[max(0,Right-(k-i))])*2;
            ans=min(ans,l+lll);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
