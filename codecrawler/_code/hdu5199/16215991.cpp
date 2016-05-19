#include<iostream>
#include<map>
using namespace std;
map<int,int>mapp;
int main()
{
    cin.sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m)
    {
        mapp.clear();
        while(n--)
        {
            int x;
            cin>>x;
            if(mapp.find(x)==mapp.end()) mapp[x]=1;
            else mapp[x]++;
        }
        while(m--)
        {
            int x;
            cin>>x;
            if(mapp.find(x)==mapp.end()) cout<<"0"<<endl;
            else cout<<mapp[x]<<endl,mapp[x]=0;
        }
    }
    return 0;
} 