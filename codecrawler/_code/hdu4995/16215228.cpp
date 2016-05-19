#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
struct Node{
    double v;
    int x,rank;
    bool operator <(const Node& a ) const{
        return x<a.x;
    }
}node[100010];
void read(int& a)
{
    char c;
    while (c=getchar(),c>'9'||c<'0');
    a=c-'0';
    while (c=getchar(),c>='0'&&c<='9')
        a=a*10+c-'0';
}
int main()
{
    
    int T,n,m,k,i;
    int mark[100010];
    //freopen("data.in","r",stdin);
    read(T);
    while (T--)
    {
        memset(mark,0,sizeof(mark));
        double temp,ans=0;
        int tp;
        read(n),read(m),read(k);
        for(i=1;i<=n;i++)
        {
            read(node[i].x);
            read(tp);
            node[i].v=tp;
            node[i].rank=i;
        }
        sort(node+1,node+n+1);
        for(int i=1;i<=n;i++)
        {
            mark[node[i].rank]=i;
        }
        while(m--)
        {
            temp=0;
            read(tp);
            tp=mark[tp];
            int l=tp-1,r=tp+1;
            int tpk=k;
            while (tpk--)
            {
                if(l>0&&r<=n)
                {
                    if((node[tp].x-node[l].x)==(node[r].x-node[tp].x))
                    {
                        if((node[l].rank)<(node[r].rank))
                        {
                            temp+=node[l].v;
                            l--;
                        }
                        else {
                            temp+=node[r].v;
                            r++;
                        }
                    }
                    else if((node[tp].x-node[l].x)<(node[r].x-node[tp].x))
                    {
                        temp+=node[l].v;
                        l--;
                    }
                    else {
                        temp+=node[r].v;
                        r++;
                    }
                }
                else if(l>0)
                {
                    temp+=node[l].v;
                    l--;
                }
                else {
                    temp+=node[r].v;
                    r++;
                }
            }
            node[tp].v=temp/k;
            ans+=node[tp].v;
        }
        printf("%.6f\n",ans);
    }
    return 0;
}