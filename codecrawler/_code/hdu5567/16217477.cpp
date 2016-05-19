#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=100+10;

int a[maxn],n,b,c;

int main()
{
        while(scanf("%d%d%d",&n,&b,&c)!=EOF)
        {
                for(int i=1;i<=n;i++)
                        scanf("%d",&a[i]);
                        int cnt=0;
                for(int i=1;i<=n;i++)
                        for(int j=i+1;j<=n;j++)
                        {
                           if(abs(a[i]-a[j])%b==c) cnt++;
                        }
                        printf("%d\n",cnt);
        }
        return 0;
}
