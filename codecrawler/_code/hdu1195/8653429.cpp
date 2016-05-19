#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cmath>
using namespace std;
int visit[11][11][11][11];
struct node
{
    int num[4];
    int step;
};
void bfs(node s1,node s2)
{
    node st,ed;
    queue<node>q;
    int flag,i;
    st=s1;
    st.step=0;
    q.push(st);
    memset(visit,0,sizeof(visit));
    visit[st.num[0]][st.num[1]][st.num[2]][st.num[3]]=1;
    while(!q.empty())
    {
        st=q.front();
        q.pop();
        flag=1;
        for(i=0;i<4;i++)
        if(st.num[i]!=s2.num[i])
        {
            flag=0;
            break;
        }
        if(flag)
        {
            printf("%d\n",st.step);
            return;
        }
        for(i=0;i<4;i++)    //¼Ó1
        {
            ed=st;
            if(st.num[i]==9)
            ed.num[i]=1;
            else
            ed.num[i]=st.num[i]+1;
            if(!visit[ed.num[0]][ed.num[1]][ed.num[2]][ed.num[3]])
            {
                visit[ed.num[0]][ed.num[1]][ed.num[2]][ed.num[3]]=1;
                ed.step=st.step+1;
                q.push(ed);
            }
        }
        for(i=0;i<4;i++)    //¼õ1
        {
            ed=st;
            if(st.num[i]==1)
            ed.num[i]=9;
            else
            ed.num[i]=st.num[i]-1;
            if(!visit[ed.num[0]][ed.num[1]][ed.num[2]][ed.num[3]])
            {
                visit[ed.num[0]][ed.num[1]][ed.num[2]][ed.num[3]]=1;
                ed.step=st.step+1;
                q.push(ed);
            }
        }
        for(i=0;i<3;i++)
        {
            ed=st;
            ed.num[i]=st.num[i+1];
            ed.num[i+1]=st.num[i];
            if(!visit[ed.num[0]][ed.num[1]][ed.num[2]][ed.num[3]])
            {
                visit[ed.num[0]][ed.num[1]][ed.num[2]][ed.num[3]]=1;
                ed.step=st.step+1;
                q.push(ed);
            }
        }
    }
    return;
}
int main()
{
    int t,i;
    node s1,s2;
    char str[2][4];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str[0]);
        for(i=0;i<4;i++)
        s1.num[i]=str[0][i]-'0';
        scanf("%s",str[1]);
        for(i=0;i<4;i++)
        s2.num[i]=str[1][i]-'0';
        bfs(s1,s2);
    }
    return 0;
}
