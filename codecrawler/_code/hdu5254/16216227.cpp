#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
vector<int>vx;
vector<int>vy;
int n,m;
int a[555][555];
bool judge(int x,int y)
{
    int tem1 = 0;
    int tem2 = 0;
    int tem3 = 0;
    int tem4 = 0;
    if(x>1&&a[x-1][y]==1)tem1++;
    if(x<n&&a[x+1][y]==1)tem2++;
    if(y>1&&a[x][y-1])tem3++;
    if(y<m&&a[x][y+1])tem4++;
    return ((tem1&tem3)|(tem1&tem4)|(tem2&tem3)|(tem2&tem4));
}
int main()
{
    int T,i,j,k,q,ca=1,x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&q);
        memset(a,0,sizeof(a));
        for(i=0; i<q; i++)
        {
            scanf("%d%d",&x,&y);
            a[x][y]=1;
        }
        vx.clear();
        vy.clear();
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(a[i][j]==0)
                {
                    vx.push_back(i);
                    vy.push_back(j);
                }
            }
        }
        bool flag = false;
        while(!flag)
        {
            flag = true;
            for(i=0; i<vx.size(); i++)
            {
                x = vx[i];
                y = vy[i];
                if(judge(x,y))
                {
                    flag = false;
                    a[x][y]=1;
                    vx.erase(vx.begin()+i);
                    vy.erase(vy.begin()+i);
                    i--;
                }
            }
        }
        printf("Case #%d:\n",ca++);
        printf("%d\n",(n*m-vx.size()));
    }
    return 0;
}
