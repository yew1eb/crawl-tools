#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cctype>

using namespace std;

int main()
{
    int n,t,ans,res;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        ans=0;
        for(int i=0;i*(i+1)*(i+2)/6<=n;i++)
        {
            res=0;
            t=n-i*(i+1)*(i+2)/6;
            for(int j=(int)pow(n,1.0/3);j>=0;j--)  //æ¾å°äºç­äºtçæå¤§ç«æ¹æ°
            {
                if(j*j*j<=t)
                {
                    res=j*j*j;
                    break;
                }
            }
            if(res+i*(i+1)*(i+2)/6>ans)
                ans=res+i*(i+1)*(i+2)/6;
        }
        printf("%d\n",ans);
    }
    return 0;
}
