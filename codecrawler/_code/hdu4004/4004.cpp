#include"iostream"
#include"cstdio"
#include"cstring"
#include"algorithm"
using namespace std;
const int N=500005;

int dir[N],dis[N];
int main()
{
    int n,m,L;
    int i;
    int low,mid,up;
    int temp,max,cnt;
    while(scanf("%d%d%d",&L,&n,&m)!=-1)
    {
        dis[0]=0;
        for(i=1;i<=n;i++)   scanf("%d",&dis[i]);
        dis[n+1]=L;
        sort(dis,dis+n+2);
        max=0;
        for(i=0;i<=n;i++)
        {
            dir[i]=dis[i+1]-dis[i];
            if(max<dir[i])  max=dir[i];
        }

        if(m>n)    {printf("%d\n",max);continue;}
        low=max;up=L;
        while(low<=up)
        {
            mid=(low+up)>>1;
            i=cnt=0;
            while(i<=n && cnt<m)
            {
                cnt++;
                temp=mid;
                while(i<=n && dir[i]<=temp)
                {
                    temp-=dir[i];
                    i++;
                }
            }
            if(cnt<=m && i>n)   up=mid-1;
            else    low=mid+1;
        }
        cout<<low<<endl;
    }
    return 0;
}
