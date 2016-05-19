#include<stdio.h>
#include<string.h>
int n,m,ma[1050][1050],mark[1050],link[1050];
int find(int a)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(ma[a][i]==1&&mark[i]==0)
        {
            mark[i]=1;
            if(link[i]==-1||find(link[i])==1)
            {
                link[i]=a;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int i,x,j,y,z,sum,temp=0;
    char ch1,ch2,ch3,ch4;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        memset(ma,0,sizeof(ma));
        memset(link,-1,sizeof(link));
        for(i=1;i<=n;i++)
        {
            scanf("%d%c%c%c%d%c",&x,&ch1,&ch2,&ch3,&z,&ch4);
            for(j=1;j<=z;j++)
            {
                scanf("%d",&y);
                 ma[x][y]=1;
            }
        }
        for(i=0;i<n;i++)
            {
                    memset(mark,0,sizeof(mark));
                      sum=sum+find(i);
            }
        printf("%d\n",n-sum/2);
    }
    return 0;
}