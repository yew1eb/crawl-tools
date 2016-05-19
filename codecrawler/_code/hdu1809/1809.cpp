#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<algorithm>
#include<cmath>

using namespace std;
//#pragma comment(linker,"/STACK:1000000000,1000000000")

#define LL long long

const int N=55;
string s;
map<string,int>str;
int n,m;
int dfs()
{
    map<string,int>::iterator it;
    it=str.find(s);
    if(it!=str.end())
    return (it->second);
    bool visited[12];
    memset(visited,false,sizeof(visited));
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<m-1;++j)
        {
            if(s[i*m+j]=='1'||s[(i-1)*m+j]=='1'||s[i*m+j+1]=='1'||s[(i-1)*m+j+1]=='1')
            continue;
            s[i*m+j]='1';s[(i-1)*m+j]='1';s[i*m+j+1]='1';s[(i-1)*m+j+1]='1';
            visited[dfs()]=true;
            s[i*m+j]='0';s[(i-1)*m+j]='0';s[i*m+j+1]='0';s[(i-1)*m+j+1]='0';
        }
    }
    for(int i=0;i<=11;++i)
    if(!visited[i])
    {str[s]=i;return i;}
}
int main()
{
    //freopen("data.txt","r",stdin);
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        int k=0;
        while(T--)
        {
            scanf("%d %d",&n,&m);
            str.clear();
            s.clear();
            string a;
            for(int i=0;i<n;++i)
            {
                cin>>a;
                s+=a;
            }
            //cout<<s<<endl;
            k=(k^dfs());
        }
        if(k)
        printf("Yes\n");
        else
        printf("No\n");
    }
    return 0;
}