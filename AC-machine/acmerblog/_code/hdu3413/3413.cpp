#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    double task[110],time[110],cur;
    int cas,n,rest,flag,vis[110],min;
    scanf("%d",&cas);
    for(int i=1; i<=cas; i++)
    {
        scanf("%d",&n);
        rest=n;
        memset(time,0,sizeof(time));
        min=10000009;
        flag=0;
        for(int j=0; j<n; j++)
        {
            cin>>task[j];
            int a=(int)task[j];
            if(task[j]-a<1e-12)
            a--;
            min=min<a?min:a;
        }
        cur=0;
        while(rest)
        {
            memset(vis,0,sizeof(vis));
            cur+=min*rest;
            int minn=min;
            min=10000009;
            for(int j=0; j<n; j++)
            {
                if(task[j]<1e-12&&task[j]>-1e-12)
                    continue;
                task[j]-=minn;
                if(task[j]-1>1e-12)
                {
                    cur++;
                    task[j]--;
                }
                else
                {
                    cur+=task[j];
                    task[j]=0;
                    rest--;
                    time[j]=cur;
                    continue;
                }
                int a=(int)task[j];
                if(task[j]-a<1e-12)
                    a--;
                min=min<a?min:a;
            }
        }
        cout<<"Case "<<i<<":"<<endl;
        for(int i=0; i<n; i++)
            printf("%.2lf\n",time[i]);
    }
    return 0;
}