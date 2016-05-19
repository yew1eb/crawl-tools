#include<iostream>
using namespace std;
int p[1011];
int find(int x)
{
    if(x!=p[x])
      p[x]=find(p[x]);
     return p[x];
}
void unions(int x,int y)
{
    p[x]=y;
}
int main()
{
    int T,a,b,x,y,n,m;
    cin>>T;
    while(T--)
    {

        cin>>n>>m;
        for(int i=1;i<=n;i++)
            p[i]=i;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            x=find(a);
            y=find(b);
            if(x!=y)
            unions(x,y);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        if(p[i]==i) ans++;
        cout<<ans<<endl;
    }
}
