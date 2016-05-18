#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std;
int n,gp_boy[505][505],gp_girl[505][505],boy[505],girl[505],rank[505];
map<string,int>mp_boy,mp_girl;
string sboy[505],sgirl[505];
char s[1000];
void deal()
{
    memset(boy,0,sizeof(boy));
    memset(girl,0,sizeof(girl));
    for(int i=1;i<=n;i++)rank[i]=1;
    while(1)
    {
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(!boy[i])
            {
                int g=gp_boy[i][rank[i]++];
                if(!girl[g])
                    boy[i]=g,girl[g]=i;
                else if(gp_girl[g][i]>gp_girl[g][girl[g]])
                        boy[girl[g]]=0,girl[g]=i,boy[i]=g;
                flag=1;
            }
        }
        if(!flag)break;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<sboy[i]<<' '<<sgirl[boy[i]]<<endl;
    }
    puts("");
}
int main()
{
    while(~scanf("%d",&n))
    {
        getchar();
        mp_boy.clear(),mp_girl.clear();
        int pos=1,tem;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);
                sboy[i]=s,mp_boy[s]=i;
                for(int j=1;j<=n;j++)
                {
                    scanf("%s",s);
                    tem=mp_girl[s];
                    if(tem==0)
                    mp_girl[s]=tem=pos++,sgirl[tem]=s;
                    gp_boy[i][j]=tem;
                }
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            int x=mp_girl[s];
            for(int j=0;j<n;j++)
            {
                scanf("%s",s);
                int y=mp_boy[s];
                gp_girl[x][y]=n-j;
            }
        }
        deal();
    }
    return 0;
}