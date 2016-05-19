#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int maxxx(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
char ch[105][105];
int maxx=0;
int heng[105][105],shu[105][105],xie1[105][105],xie2[105][105];
int main()
{
//    freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        memset(heng,0,sizeof(heng));
        memset(shu,0,sizeof(shu));
        memset(xie1,0,sizeof(xie1));
        memset(xie2,0,sizeof(xie2));
        maxx=0;
        for(int i=0;i<n;i++)
            scanf("%s",ch[i]);
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ch[i][j]=='.')
                {
                    if(heng[i][j]==0)
                    {
                        int pn=1,k=j+1;
                        while(k<n&&ch[i][k]=='.')
                        {
                            k++;
                            pn++;
                        }
                        for(int p=j;p<k;p++)
                            heng[i][p]=maxxx(k-p,p-j+1);
                    }
                    if(shu[i][j]==0)
                    {
                        int pn=1,k=i+1;
                        while(k<n&&ch[k][j]=='.')
                        {
                            k++;
                            pn++;
                        }
                        for(int p=i;p<k;p++)
                            shu[p][j]=maxxx(p-i+1,k-p);
                    }
                    if(xie1[i][j]==0)
                    {
                        int pn=1,k=i+1,p=j-1;
                        while(k<n&&p>=0&&ch[k][p]=='.')
                        {
                            k++;
                            p--;
                            pn++;
                        }
                        for(int x=i,y=j;x<k;x++,y--)
                            xie1[x][y]=maxxx(x-i+1,k-x);
                    }
                    if(xie2[i][j]==0)
                    {
                        int pn=1,k=i+1,p=j+1;
                        while(k<n&&p<n&&ch[k][p]=='.')
                        {
                            k++;
                            p++;
                            pn++;
                        }
                        for(int x=i,y=j;x<k;x++,y++)
                            xie2[x][y]=maxxx(x-i+1,k-x);
                    }
                }
            }
        }
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(heng[i][j]+shu[i][j]>maxx)
                    maxx=heng[i][j]+shu[i][j];
                if(xie1[i][j]+xie2[i][j]>maxx)
                    maxx=xie1[i][j]+xie2[i][j];
            }
        }
        cout<<maxx-1<<endl;
    }
    return 0;
}