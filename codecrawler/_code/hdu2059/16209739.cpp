#include<iostream>
using namespace std;
#include<cstdio>
#define INF 100000000.0
int main()
{
    int  L,C,T;
    int VR,VT1,VT2;
    int p[105],N;
    double dp[105];
    int i,j;
    double tmp;
    while(cin>>L)
    {
        cin>>N>>C>>T;
        cin>>VR>>VT1>>VT2;
        p[0]=0;
        for(i=1;i<=N;i++)
            cin>>p[i];
        p[N+1]=L;
        dp[0]=0;
        for(i=1;i<=N+1;i++)
        {
            double min=INF;
            for(j=0;j<i;j++)
            {
                int l=p[i]-p[j];
                if(l<C)
                     tmp=l*1.0/VT1;
                else
                     tmp=C*1.0/VT1+(l-C)*1.0/VT2;
                if(j!=0)
                    tmp+=T;
                if(min>dp[j]+tmp)
                    min=dp[j]+tmp;
            }
            dp[i]=min;
        }
        printf(dp[N+1]>(L*1.0/VR)?"Good job,rabbit!\n":"What a pity rabbit!\n");
    }
    return 0;
}

