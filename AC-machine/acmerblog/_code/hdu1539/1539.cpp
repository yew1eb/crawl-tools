#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<iostream>
using namespace std;
vector<int> v;
vector<int> tmp;
char b[100];
int a,ans,l;
int tot;
int MIN;
int flag;
void dfs(int pos,int sum)
{
    if(sum>a) return;
    if(pos>l) return;
    if(pos==l)
    {
        if(sum<=a&&(a-sum)<MIN)
        {
            flag=0;
            v.clear();
            MIN=a-sum;
            ans=sum;
            for(int i=0;i<tmp.size();i++)
            v.push_back(tmp[i]);
        }
        else if(sum==ans) flag=1;
        return;
    }
    for(int i=pos;b[i];i++)
    {
        int s=0;
        for(int j=pos;j<=i;j++)
        s=s*10+b[j]-'0';
        tmp.push_back(s);
        dfs(i+1,sum+s);
        tmp.pop_back();
    }
}
int main()
{
    while(scanf("%d %s",&a,b))
    {
        flag=0;
        v.clear();
        tmp.clear();
        tot=0;
        MIN=0x3f3f3f3f;
        ans=0x3f3f3f3f;
        int s=0;
        l=strlen(b);
        if(!a&&strcmp(b,"0")==0) break;
        s=0;
        for(int i=0;b[i];i++)
        {
            s+=b[i]-'0';
        }
        if(s>a) {printf("error\n");continue;}
        dfs(0,0);
        if(flag) {printf("rejected\n");continue;}
        if(atoi(b)==a){printf("%d %d\n",a,a);continue;}
        printf("%d",ans);
        for(int i=0;i<v.size();i++)
        printf(" %d",v[i]);
        printf("\n");
    }
    return 0;
}