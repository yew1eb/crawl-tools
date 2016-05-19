#include<iostream>
using namespace std;
int main()
{
    int n,m,N,i,count,j;
    scanf("%d",&N); 
    while(N--)
    {
        int c=1;
        while(scanf("%d%d",&n,&m),n+m)
        {
            count=0;
            for(i=1;i<=n;i++)
            {
                for(j=i+1;j<n;j++)
                if((i*i+j*j+m)%(i*j)==0)count++;
            }
            printf("Case %d: %d\n",c++,count);
        }
        if(N)printf("\n");
    }
    return 0;    
}