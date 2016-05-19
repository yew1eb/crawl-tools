#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<map>
#include<cmath>
#include<iostream>
#include <queue>
#include <stack>
#include<algorithm>
#include<set>
using namespace std;
#define INF 1e8
#define inf -0x3f3f3f3f
#define eps 1e-8
#define LL long long
#define M 100001
#define mol 100000007
#define M 100000+1

map<string, bool>mp;
map<string, bool> ::iterator it;

void bre(string a,string b)
{
    it=mp.find(b);
    if(it==mp.end())
        mp[b]=false;
    mp[a]=mp[b];
}
int main()
{
    string s1, s2, s;
    int n,i,j,Case=1;
    while( scanf("%d",&n)&&n)
    {
        mp.clear ();
        mp["a"]=true;
       while(n--)
       {
           cin>>s1>>s>>s2;
           bre(s1,s2);
       }
       cout<<"Program #"<<Case++<<endl;
       int flag=0;
       for(it = mp.begin ();it != mp.end();it++ )
       {
           if(it->second == true)
           {
               cout<< it->first <<" ";
               flag=1;
           }
       }
       if(!flag) cout<<"none";
       cout<<endl<<endl;
    }
    return 0;
}