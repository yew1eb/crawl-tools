#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,j,num,n,ans[21];
    bool exist[21];
    long long m,f[21]={0,1};
    
    for(i=2;i<=20;i++)    f[i]=i*f[i-1]+i;
    
    while(scanf("%d%I64d",&n,&m)!=EOF)
    {
        num=0;
        memset(exist,0,sizeof(exist));
        while(num<n)
        {    
            if(m==0)    break;
            for(i=1;i<=n;i++)
            {
                if(exist[i])    continue;
                
                if(m>f[n-num-1]+1)    m-=f[n-num-1]+1;
                else
                {
                    ans[++num]=i;
                    exist[i]=1;
                    m--;
                    break;
                }
            }
        }
        
        for(i=1;i<num;i++)    printf("%d ",ans[i]);
        printf("%d\n",ans[num]);
        
    }
    return 0;
}



