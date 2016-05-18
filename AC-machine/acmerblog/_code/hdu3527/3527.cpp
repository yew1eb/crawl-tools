#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
map <string, int> mp, mp2, mp3;
map <string, int>::iterator it, it2;

struct PP
{
    string str;
    int p;
    bool operator < (const PP & a) const
    {
        return p > a.p;
    }
};
void solve()
{
    priority_queue <PP> pq;
    for(it = mp2.begin(); it != mp2.end(); it++)
    {
        string tmp = it->first;
        if(mp.find(tmp) != mp.end() && mp3.find(tmp) == mp3.end())
            pq.push((PP){it->first, it->second});
    }

    if(pq.size() == 0)
    {
        cout<<"No enemy spy"<<endl;
        return ;
    }
    bool flag = false;
    while(!pq.empty())
    {
        if(flag)
            cout<<" "<<pq.top().str;
        else
        {
            cout<<pq.top().str;
            flag = true;
        }
        pq.pop();
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    int a, b, c;
    while(cin>>a>>b>>c)
    {
        mp.clear();
        mp2.clear();
        mp3.clear();
        string str;
        for(int i = 0;i < a; i++)
        {
            cin>>str;
            mp[str] = 1;
        }
        for(int i = 0;i < b; i++)
        {
            cin>>str;
            mp2[str] = i;
        }
        for(int i = 0;i < c; i++)
        {
            cin>>str;
            mp3[str] = 1;
        }
        
        solve();
    }
    return 0;
}
    