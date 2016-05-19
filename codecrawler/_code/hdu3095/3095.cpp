#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<map>
#include<sstream>
using namespace std;

struct node
{
    int a[15];
    string s;
    int t;
    int z1,z2;//两个0的位置
};
queue<node>sq,eq;
map<string,int>sm,em;
int tCase,a[15],ans;
const string se="012345678910110";
int d[13][5]={{2,-1},{2,5,-1},{0,1,3,6,-1},{2,7,-1},{5,-1},{1,4,6,9,-1},{2,5,7,10,-1},{3,6,8,11,-1},{7,-1},{5,10,-1},{6,9,11,12,-1},{7,10,-1},{10,-1}};//方向
inline string change(int a[])
{
    string s;
    for(int i=0;i<=12;i++)
    {
        stringstream ss;
        string str;
        ss<<a[i];
        ss>>str;
        s+=str;
    }
    return s;
}


inline void bfs_ex(queue<node>&q,map<string,int>&s,map<string,int>&e,node v)
{
    int a1=v.z1,a2=v.z2;
    for(int i=0;d[a1][i]!=-1&&ans==-1;i++)
    {
        node w=v;
        swap(w.a[a1],w.a[d[a1][i]]);
        w.z1=d[a1][i];
        w.z2=a2;
        w.t=v.t+1;
        if(w.t>20)
        {
            ans=-2;break;
        }
        w.s=change(w.a);
        if(e[w.s]!=0)
        {
            ans=w.t+e[w.s]-2;
            if(ans>20) ans=-2;
            break;
        }
        else if(s[w.s]==0)
        {
            s[w.s]=w.t;
            q.push(w);
        }
    }
    for(int i=0;d[a2][i]!=-1&&ans==-1;i++)
    {
        node w=v;
        swap(w.a[a2],w.a[d[a2][i]]);
        w.z2=d[a2][i];
        w.z1=a1;
        w.t=v.t+1;
        if(w.t>20)
        {
            ans=-2;break;
        }
        w.s=change(w.a);
        if(e[w.s]!=0)
        {
            ans=w.t+e[w.s]-2;
            if(ans>20) ans=-2;
            break;
        }
        else if(s[w.s]==0)
        {
            s[w.s]=w.t;
            q.push(w);
        }
    }
}
inline void bfs()
{
    while(!sq.empty()&&!eq.empty()&&ans==-1)
    {
        node vn,ve;
        vn=sq.front();
        ve=eq.front();
        int t=vn.t+ve.t-2;
        if(t>20)
        {
            ans=-2;
            break;
        }
        else if(sq.size()<=eq.size())
        {
            sq.pop();
            if(em[vn.s]!=0)
            {
                ans=em[vn.s]+vn.t-2;
                if(ans>20) ans=-2;
                break;
            }
            else if(t==20)
            {
                ans=-2;break;
            }
            else if(t<20)
            {
                bfs_ex(sq,sm,em,vn);
            }
        }
        else if(sq.size()>eq.size())
        {
            eq.pop();
            if(sm[ve.s]!=0)
            {
                ans=sm[ve.s]+ve.t-2;
                if(ans>20) ans=-2;
                break;
            }
            else if(t==20)
            {
                ans=-2;break;
            }
            else if(t<20)
            {
                bfs_ex(eq,em,sm,ve);
            }
        }
    }
}


int main()
{
    scanf("%d",&tCase);
    for(int j=1;j<=tCase;j++)
    {
        sm.clear();
        em.clear();
        while(!sq.empty()) sq.pop();
        while(!eq.empty()) eq.pop();
        node v;
        bool f=0;
        for(int i=0;i<=12;i++)
        {
            scanf("%d",&v.a[i]);
            if(v.a[i]==0&&f==0)
            {
                v.z1=i;f=1;
            }
            else if(v.a[i]==0&&f==1)
            {
                v.z2=i;
            }
        }
        string s=change(v.a);
        v.s=s;
        v.t=1;
        sm[v.s]=1;
        sq.push(v);

        node e;
        e.t=1;
        e.s=se;
        em[se]=1;
        for(int i=0;i<=12;i++) e.a[i]=i;
        e.a[12]=0;
        e.z1=0;
        e.z2=12;
        eq.push(e);

        ans=-1;
        bfs();
        if(ans>=0)
        printf("%d\n",ans);
        else
        printf("No solution!\n");
    }
    return 0;
}