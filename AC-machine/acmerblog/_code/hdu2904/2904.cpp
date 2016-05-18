#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
struct Edge
{
 int l,r,w;
 bool operator<(const Edge &b)const
 {
 return w>b.w;
 }
};
Edge p[100005];
int set[105];
int m;
int map[105][105],w[105];
int find(int x)
{
 if(x==set[x])return x;
 return set[x]=find(set[x]);
}
int main()
{
 int T;
 scanf("%d",&T);
 while(T--)
 {
 scanf("%d",&m);
 memset(map,0,sizeof(map));
 for(int i=0;i<m;i++)
 {
 int j,t,k;
 scanf("%d",&j);
 scanf("%d%d",&w[j],&t);
 while(t--)
 {
 scanf("%d",&k);
 map[j][k]=map[k][j]=1;
 }
 }
 Edge tmp;
 int tot=0,sum=0;
 for(int i=0;i<m;i++)
 for(int j=i+1;j<m;j++)
 if(map[i][j])
 {
 tmp.l=i;
 tmp.r=j;
 tmp.w=(w[i]+w[j]);
 p[tot++]=tmp;
 sum+=w[i]+w[j];
 }
 sort(p,p+tot);
 //for(int i=0;i<tot;i++)printf("%d ",p[i].w);puts("");
 for(int i=0;i<m;i++)set[i]=i;
 int cnt=0,ret=0;
 for(int i=0;i<tot;i++)
 {
 int l=find(p[i].l);
 int r=find(p[i].r);
 //printf("%d %d %d %d\n",p[i].l,p[i].r,l,r);
 if(l==r)continue;
 set[l]=r;
 //cnt++;
 ret+=p[i].w;
 //if(cnt==m-1)break;
 }
 printf("%d\n",sum-ret);
 }
}
/*
100
7
0 3 2
1 2
1 1 2
0 3
2 3 2
0 3
3 1 4
1 2 4 5
4 2 2
3 6
5 1 2
3 6
6 2 2
4 5

4
0 2 2
1 2
1 1 3
0 2 3
2 1 3
0 1 3
3 3 2
1 2
*/