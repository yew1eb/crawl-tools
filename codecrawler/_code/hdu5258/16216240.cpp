#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=50;
int N;
struct node
{
    int x1,y1,x2,y2;
} a[maxn];
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i=0; i<N; i++)
        {
            scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
            if(a[i].y1==a[i].y2&&a[i].x1>a[i].x2) swap(a[i].x1,a[i].x2);
            if(a[i].x1==a[i].x2&&a[i].y1>a[i].y2) swap(a[i].y1,a[i].y2);
        }
        int ans=0;
        for(int i=0; i<N; i++) if(a[i].x1==a[i].x2)
            for(int j=i+1; j<N; j++) if(a[j].x1==a[j].x2)
                for(int p=0; p<N; p++) if(a[p].y1==a[p].y2)
                    for(int q=p+1; q<N; q++) if(a[q].y1==a[q].y2)
                            if(a[i].x1!=a[j].x1&&a[p].y1!=a[q].y1)
                                if(a[p].y1>=max(a[i].y1,a[j].y1)&&a[p].y1<=min(a[i].y2,a[j].y2))
                                    if(a[q].y1>=max(a[i].y1,a[j].y1)&&a[q].y1<=min(a[i].y2,a[j].y2))
                                        if(a[i].x1>=max(a[p].x1,a[q].x1)&&a[i].x1<=min(a[p].x2,a[q].x2))
                                            if(a[j].x1>=max(a[p].x1,a[q].x1)&&a[j].x1<=min(a[p].x2,a[q].x2)) ans++;

        printf("Case #%d:\n%d\n",cas++,ans);
    }
    return 0;
}