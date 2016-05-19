#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#define INF ((1<<23)-1)
using namespace std;
map<int ,double> mp;
double f[1010][60];
typedef struct
{
    int x; double p;
}Point;
Point pt[1010];
int kk,m;

void initial()
{
    for(int i=0;i<=1000;i++)
        for(int j=0;j<=50;j++)
            f[i][j]=INF;
    for(int i=0;i<=m;i++)
        for(int j=i;j<=m;j++)
            f[i][j]=0.0;
}

int main()
{
    int k,i,j,l,x; double p;
    while( scanf("%d%d",&kk,&m),kk+m )
    {
        mp.clear();
        initial();
        for(i=1;i<=kk;i++)
        {
            scanf("%d",&l);
            for(j=1;j<=l;j++)
            {
                scanf("%d%lf",&x,&p);
                mp[x]+=p;
            }
        }
        map<int,double>::iterator it;
        j=1;
        for( it=mp.begin(); it!=mp.end();it++,j++)
        {
            pt[j].x=(it->first);
            pt[j].p=(it->second);
        }
        int n=j-1;
        for( i=1;i<=n;i++ )
        {
            for(j=1;j<=m && j<=i; j++ )
            {
                f[i][j]=INF;
                double pre=0.000,suf=0.000;
                int cur=i; double add=0.000;
                for(k=i-1;k>=j-1;k--)
                {
                    if( k+1 != i )
                    {
                        pre+=pt[k+1].p;
                        add+=pt[k+1].p*(pt[cur].x-pt[k+1].x);
                    }
                    while( pt[cur].p+suf < pre )
                    {
                        suf+=pt[cur].p;
                        cur--;
                        pre-=pt[cur].p;
                        add-=pt[cur].p*(pt[cur+1].x-pt[cur].x);
                        add+=pt[cur+1].p*(pt[cur+1].x-pt[cur].x);
                        add-=pre*(pt[cur+1].x-pt[cur].x);
                        add+=(suf-pt[cur+1].p)*(pt[cur+1].x-pt[cur].x);
                    }
                    f[i][j]=min(f[i][j],f[k][j-1]+add);
                }
            }
        }
        printf("%.2lf\n",f[n][m]);
    }
    return 0;
}
