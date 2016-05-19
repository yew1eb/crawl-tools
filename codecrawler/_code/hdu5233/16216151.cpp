#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int>mapp[100000+5];
map<int,int>root;
int he[100000+5];
int main()
{
    int n,m;
    cin.sync_with_stdio(false);
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++) mapp[i].clear();
        root.clear();
        for(int i=1;i<=n;i++) cin>>he[i];
        for(int i=n;i>=1;i--)
        {
            if(root.find(he[i])==root.end()) root[he[i]]=i,mapp[i].push_back(i);
            else mapp[root[he[i]]].push_back(i); 
        }
        for(int i=0;i<m;i++)
        {
            int x;
            cin>>x;
            x=root[x];
            if(mapp[x].size()) cout<<mapp[x][mapp[x].size()-1]<<endl,mapp[x].erase(mapp[x].end()-1);
            else cout<<"-1"<<endl;
        }
    }
    return 0;
}