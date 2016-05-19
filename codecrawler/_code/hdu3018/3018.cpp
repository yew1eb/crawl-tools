#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
int f[100005],hash[100005];
int du[100005],count[100005]; //du为每个节点的次数,count为每个分图奇数次数的点的个数
vector<int> a;
int n,m;
void init()
{
	int i;
	a.clear();
	memset(hash,0,sizeof(hash));
	memset(du,0,sizeof(du));
	memset(count,0,sizeof(count));
	for(i=1;i<=n;i++)
	f[i]=i;
}
int find(int x)
{
	int r=x;
	while(f[r]!=r)
	r=f[r];
	f[x]=r;
	return r;
}
void Union(int x,int y)
{
	int fx,fy;
	fx=find(x);
	fy=find(y);
	if(fx!=fy)
	f[fx]=fy;
}
int main()
{
	int a1,a2;
	int k,i,sum;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		while(m--)
		{
			scanf("%d %d",&a1,&a2);
			du[a1]++;
			du[a2]++;
			Union(a1,a2);
		}
		for(i=1;i<=n;i++)
		{
			k=find(i);
			if(!hash[k])
			{
				a.push_back(k); //k为一个连通分图的代表元素
				hash[k]=1;
			}
			if(du[i]%2==1)//计算奇数次数的点的个数
            count[k]++;
		}
		sum=0;
		for(i=0;i<a.size();i++)
		{
			k=a[i];
			if(du[k]==0) //孤立结点
			continue;
			if(count[k]==0)//欧拉回路一笔即可画成
			sum++;
			else
			sum+=(count[k]/2);//图中次数为奇数的点一定为偶数个
		}
		printf("%d\n",sum);
	}
	return 0;
}