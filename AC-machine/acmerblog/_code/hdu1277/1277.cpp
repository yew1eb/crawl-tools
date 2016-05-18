#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<list>
#include<iostream>
#include<map>
using namespace std;
#define inf 0x3f3f3f3f
#define Max 11000
char s[60010],str[66];
int ans[1010],rec;
char st[60010];
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int q[Max*60],cnt;
struct node
{
    int id,fail;
    int next[10];
    void init()
    {
        id=fail=0;
        memset(next,0,sizeof(next));
    }
}tri[Max*60];
void insert(char *s,int num)
{
    int i,p,id;
    p=0;
    for(i=0;s[i];i++)
    {
        id=s[i]-'0';
        if(!tri[p].next[id])
        {
            tri[++cnt].init();
            tri[p].next[id]=cnt;
        }
        p=tri[p].next[id];
    }
    tri[p].id=num;
}
void bfs()
{
    int i,id,suf,p,head,tail;
    p=0;head=tail=0;
    for(i=0;i<10;i++)
    {
        if(tri[0].next[i])
        {
            q[tail++]=tri[0].next[i];
            tri[q[tail-1]].fail=0;
        }
        else
            tri[0].next[i]=0;
    }
    while(head<tail)
    {
        //printf("akkkk");
        p=q[head++];suf=tri[p].fail;
        for(i=0;i<10;i++)
        {
            if(tri[p].next[i])
            {
                q[tail++]=tri[p].next[i];
                tri[q[tail-1]].fail=tri[suf].next[i];
            }
            else
            {
                tri[p].next[i]=tri[suf].next[i];
            }
        }
    }
}
int query(char *s)
{
    int i,id,p,tmp;
    p=0;
    for(i=0;s[i];i++)
    {
        id=s[i]-'0';
        p=tri[p].next[id];
        tmp=p;
        if(tmp&&tri[tmp].id!=-1)
        {
            if(tri[tmp].id)
            ans[rec++]=tri[tmp].id;
            tri[tmp].id=-1;
            tmp=tri[tmp].fail;
        }
    }
    return rec;
}
int main()
{
    int n,m,i;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        s[0]=0;
        tri[0].init();
        cnt=0;
        rec=0;
        while(m--)
        {
            scanf("%s",st);
            strcat(s,st);
        }
      //  printf("%s\n",s);
        for(i=1;i<=n;i++)
        {
            scanf("%s%s%s%s",str,str,str,str);
            insert(str,i);
        }
        bfs();
       if(query(s)==0)
            puts("No key can be found !");
        else
        {
            printf("Found key:");
            for(i=0;i<rec;i++)
            {
                  printf(" [Key No. %d]",ans[i]);
            }
            puts("");
        }

    }
}