#include<string.h>
#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
char mp[160][160],c[161];
int f[4][2]={{-1,0},{0,-1},{0,1},{1,0}},len=1,maxlen=0;
struct khp
{
int x,y;
};
void bfs(int x,int y)
{
int i,j;
khp t;
t.x=x;
t.y=y;
queue<khp> k;
k.push(t);
mp[x][y]='*';
while(!k.empty())
{
khp r=k.front();
k.pop();
for(i=0;i<4;i++)
{
int a=f[i][0]+r.x;
int b=f[i][1]+r.y;

if(a>=0&&a<=55&&b>=0&&b<=55&&mp[a][b]!='*')
{
t.x=a;
t.y=b;
mp[a][b]='*';
k.push(t);
}
}
}
}
void init()
{
int i,j;
maxlen=0,len=1;
memset(mp,0,sizeof(mp));
for(i=0;i<55;i++)
mp[0][i]=' ',mp[i][0]=' ';
}
int main()
{
int i,j;
init();
while(gets(c)!=NULL)
{
int w=strlen(c);
if(w==0)
{
bool jd=0;

for(i=0;i<=len&&!jd;i++)
for(j=0;j<=len;j++)
if(mp[i][j]==' ')
{
bfs(i,j);
jd=1;
break;
}
bool judge=0;

for(i=0;i<=maxlen&&!judge;i++)
for(j=0;j<=maxlen;j++)
if(mp[i][j]==' ')
{
judge=1;
break;
}
if(judge) puts("A");
else puts("C");
init();
}
else
{
int l=strlen(c),e=1;
mp[len][0]=' ';
for(i=0;i<l;i++)
mp[len][e++]=c[i];
mp[len++][e]=c[i];
if(l>maxlen) maxlen=l;
memset(c,0,sizeof(c));
}
}
bool jd=0;

for(i=0;i<=100&&!jd;i++)
for(j=0;j<=100;j++)
if(mp[i][j]==' ')
{
bfs(i,j);
jd=1;
break;
}
bool judge=0;

for(i=0;i<=maxlen&&!judge;i++)
for(j=0;j<=maxlen;j++)
if(mp[i][j]==' ')
{
judge=1;
break;
}
if(judge) puts("A");
else puts("C");
return 0;
}