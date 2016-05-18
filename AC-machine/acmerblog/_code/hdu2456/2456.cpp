#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>

using namespace std;

const int maxn = 1010;
char s[maxn][maxn];

struct Node
{
    int next[2];
    int count;
    void init()
    {
        next[0] = next[1] = -1;
        count =0;
    }
}node[50*50*110];
int cnt;

int newNode()
{
    node[cnt].init();
    return cnt++;
}

char code(char c)
{
    if(c=='*')  return 0;
    return 1;
}

void insert(char *s)
{
    int p=0;
    while(*s)
    {
        int i = code(*s);
        s++;
        if(node[p].next[i]==-1) node[p].next[i] = newNode();
        p = node[p].next[i];
    }


    node[p].count++;
   // printf("%d -> %d\n",p,node[p].count);
}

char  t[50*55];

int main()
{
   // freopen("in","r",stdin);
    int cases = 1;
    int n,m,T,p,q;
    while(scanf("%d%d%d%d%d",&n,&m,&T,&p,&q),n||m||T||p||q)
    {
        int i,j,k,ii,jj;
        for(i=0;i<n;i++)
            scanf("%s",s[i]);

        node[0].init();
        cnt = 1;
        for(i=0;i<T;i++)
        {
            for(ii=0;ii<p;ii++)
                scanf("%s",t+ii*q);
            insert(t);
           // cout<<t<<endl;
        }

        int ans =0;
        for(i=0;i+p<=n;i++)
        for(j=0;j+q<=m;j++)
        {
            int pp=0;
            for(ii=0;ii<p&&pp!=-1;ii++)
            for(jj=0;jj<q;jj++)
            {
                int c = code(s[i+ii][j+jj]);
                pp=node[pp].next[c];
                if(pp==-1)   break;
            }

            if(pp==-1)   continue;
            ans += node[pp].count;
           // cout<<"pp="<<pp<<"ans="<<ans<<endl;
           // if(ans>=T)  break;
            node[pp].count = 0;
        }

        printf("Case %d: %d\n",cases++,ans);
    }
    return 0;
}