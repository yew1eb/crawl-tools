#include<stdio.h>
#include<string.h>
#include<algorithm>
struct ac
{
	int x,y,z;
}a[505];
bool map[505][505];
bool visit[505];
int path[505];
int n;
bool cmp(ac b,ac c)
{
	if(b.x<c.x) return true;
	if(b.x==c.x&&b.y<c.y) return true;
	if(b.x==c.x&&b.y==c.y&&b.z<c.z) return true;
	return false;
}
bool dfs(int x)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(map[x][i]&&!visit[i])
		{
			visit[i]=1;
			if(!path[i]||dfs(path[i]))
			{
				path[i]=x;
				return true;
			}
		}
	}
	return false;
}
void match()
{
    memset(path,0,sizeof(path));
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        memset(visit,0,sizeof(visit));
        if(dfs(i)) sum++;
    }
    printf("%d\n",n-sum);
}
int main()
{
	int i,j;
	while(scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++)
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		std::sort(a+1,a+n+1,cmp);
		memset(map,0,sizeof(map));
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
				if(a[i].x<a[j].x&&a[i].y<a[j].y&&a[i].z<a[j].z)
					map[i][j]=1;
        match();
    }
	return 0;
}
