#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#define LL long long
using namespace std;
int flag1[1000],flag2[1000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int tem1=0;
        for(int i=0;i<s.length();i++)
        {
            flag1[i]=tem1;
            if(s[i]=='(')
                tem1++;

        }
        tem1=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            flag2[i]=tem1;
            if(s[i]==')')
                tem1++;

        }
        int ans=1100;
        for(int i=0;i<s.length();i++)
            ans=min(ans,flag1[i]+flag2[i]);
        printf("%d\n",ans);
    }
    return 0;
}
