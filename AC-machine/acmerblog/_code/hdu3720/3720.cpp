#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#define maxn 1005
#define MAXN 100005
#define mod 1000000007
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;
char name[100];
char type[100];
int power[30];
int maps[30][30];
map<string,int> mt;
map<string,int> na;
int mp[30];
vector<int> player[4];
vector<int> ans;
int ANS;
void dfs2(int pos,int sum);
void dfs3(int pos,int sum);
void dfs4(int pos,int sum);

void dfs1(int pos,int sum)
{
    if(sum==1) {dfs2(-1,0);return;}
    for(int i=pos+1;i<player[0].size();i++)
    {
        ans.push_back(player[0][i]);
        dfs1(i,sum+1);
        ans.pop_back();
    }
}
void dfs2(int pos,int sum)
{
    if(sum==4) {dfs3(-1,0);return;}
    for(int i=pos+1;i<player[1].size();i++)
    {
        ans.push_back(player[1][i]);
        dfs2(i,sum+1);
        ans.pop_back();
    }
}
void dfs3(int pos,int sum)
{
    if(sum==4) {dfs4(-1,0);return;}
    for(int i=pos+1;i<player[2].size();i++)
    {
        ans.push_back(player[2][i]);
        dfs3(i,sum+1);
        ans.pop_back();
    }
}
void dfs4(int pos,int sum)
{
    if(sum==2)
    {
        int s=0;
        for(int i=0;i<ans.size();i++)
        {
            for(int j=i+1;j<ans.size();j++)
            {
                s+=maps[ans[i]][ans[j]];
            }
            s+=power[ans[i]];
        }
        ANS=max(s,ANS);
        return;
    }
    for(int i=pos+1;i<player[3].size();i++)
    {
        ans.push_back(player[3][i]);
        dfs4(i,sum+1);
        ans.pop_back();
    }
}
int main()
{
    mt["goalkeeper"]=0;
    mt["defender"]=1;
    mt["midfielder"]=2;
    mt["striker"]=3;
    int p;
    while(cin>>name)
    {
        ANS=-0x3f3f3f3f;
        ans.clear();
        na.clear();
        for(int i=0;i<4;i++) player[i].clear();

        cin>>p>>type;
        player[mt[type]].push_back(1);
        power[1]=p;

        na[name]=1;
        for(int i=2;i<=23;i++)
        {
            cin>>name>>p>>type;
            na[name]=i;
            player[mt[type]].push_back(i);
            power[i]=p;
        }
        int n;
        memset(maps,0,sizeof(maps));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>name>>type>>p;
            maps[na[name]][na[type]]=p;
            maps[na[type]][na[name]]=p;
        }

        if(player[0].size()<1||player[1].size()<4||player[2].size()<4||player[3].size()<2)
        {
            cout<<"impossible"<<endl;
            continue;
        }
        dfs1(-1,0);
        cout<<ANS<<endl;
    }
    return 0;
}