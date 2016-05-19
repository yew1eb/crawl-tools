#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<sstream>
#include<string>
#include<climits>
#include<set>
#include<bitset>
#include<cmath>
#include<deque>
#include<map>
#include<queue>
#include<stack>
#define LL long long
using namespace std;

int main()
{
    LL num[11];
    LL n,m,nn;
    LL a,b,id;
    int flag;
    int tt;
    int i,j;
    int cas=1;
    while(~scanf("%I64d%I64d",&n,&m)&&(n||m))
    {
        printf("Case #%d: ",cas++);
        int i;int ans;
        a=0;b=0;tt=0;flag=0;
        for(i=1;i<=m;i++)
        {
            if(n%i!=0)
            {
                n=(n/i+1)*i;
                if(tt<11) num[tt++]=n;
                else{
                    int bj=0;
                    for(j=1;j<=9;j++)
                        if(num[j+1]-num[j]==num[j]-num[j-1])
                        bj++;
                    if(bj==9)
                    {ans=num[5]-num[4];
                    flag=1;}
                    for(j=0;j<10;j++)
                        num[j]=num[j+1];
                    num[10]=n;
                }
            }
            if(flag)
            {
                id=i;
                n+=(m-i)*ans;
                break;
            }
        }
        cout<<n<<endl;
    }
    return 0;
}
