#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=201;
const int maxm=130;
struct node
{
    int x;
    int y;
    int key;
    int ans;
}q[maxn*maxn*maxm];
char map[maxn][maxn];
int n,m,k,sx,sy,desx,desy,pre,last,keyx[8],keyy[8],cur,movex[4]={1,-1,0,0},movey[4]={0,0,-1,1};
bool vis[maxn][maxn][maxm];
bool isborder(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m)
	return true;
    return false;
}
int Move(int x,int y,int key,int ans,int pos)
{
    while(1)
    {
	x+=movex[pos];
	y+=movey[pos];
	if(isborder(x,y))
	    return 0;
	if(map[x][y]=='E'&&key==k)
	    return ans;
	if(map[x][y]=='K')
	{
	    for(int i=0;i<cur;i++)
		if(keyx[i]==x&&keyy[i]==y)
		{
		    key|=(1<<i);
		    break;
		}
	    continue;
	}
	if(map[x][y]=='L')
	{
	    if(!vis[x][y][key])
	    {
		vis[x][y][key]=1;
		int val=Move(x,y,key,ans,2);
		vis[x][y][key]=0;
		return val;
	    }
	    return 0;
	}
	if(map[x][y]=='R')
	{
	    if(!vis[x][y][key])
	    {
		vis[x][y][key]=1;
		int val=Move(x,y,key,ans,3);
		vis[x][y][key]=0;
		return val;
	    }
	    return 0; 
	}
	if(map[x][y]=='D')
	{
	    if(!vis[x][y][key])
	    {
		vis[x][y][key]=1;
		int val=Move(x,y,key,ans,0);
		vis[x][y][key]=0;
		return val;
	    }
	    return 0;
	}
	if(map[x][y]=='U')
	{
	    if(!vis[x][y][key])
	    {
		vis[x][y][key]=1;
		int val=Move(x,y,key,ans,1);
		vis[x][y][key]=0;
		return val;
	    }
	    return 0;
	}
	if(map[x][y]=='#')
	{
	    x-=movex[pos];
	    y-=movey[pos];
	    break;
	}
    }
    if(!vis[x][y][key])
    {
	vis[x][y][key]=1;
	node ita;
	ita.x=x;
	ita.y=y;
	ita.key=key;
	ita.ans=ans;
	q[last++]=ita;
    }
    return 0;
}
int BFS()
{
    node st;
    st.x=sx;
    st.y=sy;
    st.key=0;
    st.ans=0;
    memset(vis,0,sizeof(vis));
    pre=0,last=1;
    q[pre]=st;
    vis[st.x][st.y][st.key]=1;
    while(pre<last)
    {
	node now=q[pre++];
	for(int i=0;i<4;i++)
	{
	    int ans=Move(now.x,now.y,now.key,now.ans+1,i);
	    if(ans)
		return ans;
	}
    }
    return -1;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
	cur=0;
	for(int i=0;i<n;i++)
	    scanf("%s",map[i]);
	for(int i=0;i<n;i++)
	    for(int j=0;j<m;j++)
	    {
		if(map[i][j]=='S')
		{
		    sx=i;
		    sy=j;
		}
		else if(map[i][j]=='E')
		{
		    desx=i;
		    desy=j;
		}
		else if(map[i][j]=='K')
		{
		    keyx[cur]=i;
		    keyy[cur++]=j;
		}
	    }
	k=(1<<cur)-1;
	printf("%d\n",BFS());
    }
    return 0;
}
