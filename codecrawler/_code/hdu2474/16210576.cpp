#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct que
{
    int id;
    long long value;
    bool operator<(const que& y)const
    {
        return value<y.value;
    }
};
long long a[51000][4],r[51000][4],s[4];
int head[4];
que q[4][51000];
int n,m;
bool v[51000];
bool can(int x)
{
    for(int j=1;j<=m;j++)
    if(s[j]<r[x][j])return false;
    return true;
}
bool all_end()
{
    for(int i=1;i<=m;i++)
    if(head[i]<=n)return false;
    return true;
}
int main()
{
    while(cin>>n>>m)
    {
        for(int j=1;j<=m;j++)
         for(int i=1;i<=n;i++)
            cin>>a[i][j];
        for(int j=1;j<=m;j++)
         for(int i=1;i<=n;i++)
            cin>>r[i][j];
        for(int i=1;i<=m;i++)
            cin>>s[i];

        for(int i=1;i<=n;i++)
         for(int j=1;j<=m;j++)
         {
            q[j][i].id=i;
            q[j][i].value=r[i][j];
         }
        for(int j=1;j<=m;j++)
            sort(q[j]+1,q[j]+1+n);
        memset(v,false,sizeof(v));
        for(int j=1;j<=m;j++)
        head[j]=1;
        int num=0;
        while(num<=n)
        {
            if(all_end())break;
            for(int i=1;i<=m;i++)
            while(head[i]<=n && v[q[i][head[i]].id])head[i]++;
            for(int i=1;i<=m;i++)
            {
                if(head[i]<=n && can(q[i][head[i]].id))
                {
                    v[q[i][head[i]].id]=true;
                    for(int j=1;j<=m;j++)
                    s[j]+=a[q[i][head[i]].id][j];
                    num++;
                    head[i]++;
                    break;
                }
                else
                head[i]++;
            }
        }
        if(num==n)cout<<"Yes"<<endl;else cout<<"No"<<endl;
    }
    return 0;
}