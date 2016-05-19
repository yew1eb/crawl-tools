#include<stdio.h>
#include<string.h>
const int N=1e5+10;
int main()
{
    int n,d1,d2,a[N],vis[N],vis2[N];
    while(scanf("%d%d%d",&n,&d1,&d2)!=EOF)
    {
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        memset(vis,0,sizeof(vis));
        memset(vis2,0,sizeof(vis2));
        for(int i=1; i<n; i++)
        {
            if(a[i]+d1==a[i+1])vis[i]=1;
            if(a[i]+d2==a[i+1])vis2[i]=1;
        }
//        for(int i=1; i<=n; i++)
//            printf("%d ",vis[i]);
//        puts("");
//        for(int i=1; i<=n; i++)
//            printf("%d ",vis2[i]);
//        puts("");
        // puts("ASJD");
        long long sum=n;
        for(int i=1; i<=n; i++)
        {
            int cnt=1;
            if(vis[i]==1)
            {
                int t=-1;
                for(int j=i; j<=n; j++)
                    if(vis[j]==1)
                    {
                        cnt++;
                        vis2[j]=0;
                    }
                    else
                    {
                        t=j;
                        break;
                    }
                i+=cnt-1;
                //printf("!!i %d\n",i,cnt);
                if(t!=-1)
                    for(int j=t; j<=n; j++)
                        if(vis2[j]==1)
                        {
                            cnt++;
                            vis2[j]=0;
                        }
                        else
                        {
                            break;
                        }
                cnt-=1;
                //printf("%d\n",cnt);
                sum+=(long long)(1+cnt)*cnt/2;
            }
        }
        //printf("%d\n",sum);
//        for(int i=1; i<=n; i++)
//        {
//            printf("%d ",vis2[i]);
//        }
        for(int i=1; i<=n; i++)
        {
            int cnt=1;
            if(vis2[i]==1)
            {
                for(int j=i; j<=n; j++)
                    if(vis2[j]==1)
                        cnt++;
                    else
                        break;
                cnt-=1;
                i+=cnt;
                sum+=(long long)(1+cnt)*cnt/2;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
/*
5 0 0
1 1 1 1 1

8 4 2
1 -1 -1 -1 8 8 4 6

8 2 -2
2 3 6 8 6 4 4 0

2 5 8
5 1

5 2 -2
2 4 2 4 2

8 1 -1
1 2 3 2 1 2 4 5

8 1 -1
3 2 1 2 3 2 1 2

5 1 -1
1 2 3 2 1

*/
