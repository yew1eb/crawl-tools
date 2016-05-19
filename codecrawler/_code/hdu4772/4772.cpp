#include<iostream>
#include<cstdio>
using namespace std;
int a[31][31],b[31][31];
int main()
{
    int N;int i,j,m,n;
    while(scanf("%d",&N)!=EOF,N)
    {
        int cnt[5]={0};
        //cout<<1<<endl;
        for( i=1;i<=N;i++)
            for( j=1;j<=N;j++)
             scanf("%d",&a[i][j]);
        for( i=1;i<=N;i++)
            for( j=1;j<=N;j++)
             scanf("%d",&b[i][j]);
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                if(a[i][j]==b[i][j])
                    cnt[1]++;
                if(a[N+1-j][i]==b[i][j])
                    cnt[2]++;
                if(a[N+1-i][N+1-j]==b[i][j])
                    cnt[3]++;
                if(a[j][N+1-i]==b[i][j])
                    cnt[4]++;
            }
            //cout<<-1<<endl;
        }
        int sum=0;
        for(i=1;i<=4;i++)
        {
            sum=max(sum,cnt[i]);
        }
        printf("%d\n",sum);
    }
}