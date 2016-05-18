#include <iostream>
#include <cstdio>
#include <queue>
#include <string>

#define N 10005
#define ll __int64
#define ss(a) scanf("%d",&a)
#define cl(a) memset(a,0,sizeof(a))

using namespace std;

int a[12],f[N];
queue<pair<string,int> > rec;

string find_ans(int n,int m)
{
    while (!rec.empty()) rec.pop();
    pair<string,int>init;
    init.first="";init.second=0;
    rec.push(init);
    int i;
    while (!rec.empty())
    {
        pair<string,int> curr=rec.front();
        for (i=0;i<10;i++)
        {
            if (curr.first.length()==0&&i==0) continue;
            if (a[i]) continue;
            char ch='0'+i;
            string ss=curr.first+ch;
            int x=(curr.second*10+i)%n;
            if (!f[x])
            {
                if (x==0) return ss;
                pair<string,int>u;
                u.first=ss;u.second=x;
                rec.push(u);
                f[x]=1;
            }
        }
        rec.pop();
    }
    return "-1";
}

int main()
{
    int i,n,m,x,cas=0;
    while (ss(n)!=EOF)
    {
        ss(m);
        cl(a);cl(f);
        for (i=1;i<=m;i++) 
        {
            ss(x);a[x]=1;
        }
        printf("Case %d: ",++cas);
        cout<<find_ans(n,m)<<endl;
    }
    return 0;
}
