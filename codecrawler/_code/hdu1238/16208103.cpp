#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
string str[105];
string temp;
string retemp;
int ans,n;
void  dfs(string temp,string retemp,int cur)
{
    if(temp.size()>ans&&cur==n+1)
    {
        ans=temp.size();
        return ;
    }
    if(temp.size()<=ans)
    return ;
    if(str[cur].size()<temp.size())
    return ;
    string now="";
    for(int i=0;i<=str[cur].size()-temp.size();i++)
    {
        now=str[cur].substr(i,temp.size());
        if(now==temp||now==retemp)
        {
            dfs(temp,retemp,cur+1);
            break;
        }

    }
    return ;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            cin>>str[i];
        }
        ans=0;
        for(int i=0;i<str[1].size();i++)
        {
            temp="";
            retemp="";
            for(int j=i;j<str[1].size();j++)
            {
                temp+=str[1][j];
                retemp="";
                //retemp=strrev(temp);
                for(int k=temp.size()-1;k>=0;k--)
                {
                    retemp+=temp[k];
                }
                dfs(temp,retemp,2);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
2
3
ABCD
BCDFF
BRCD
2
rose
orchid
*/
