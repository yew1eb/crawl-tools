#include<stdio.h>
#include<string.h>
#define N 505
int map[N][N],index[N],used[N],n,m;
//map表示邻接矩阵，index记录入度，used记录是否排序
void toposort()
{
	int i,j,topo=0;
	while(topo<n){
		for(i=1;i<=n;i++){
			if(index[i]==0&&used[i]==0){//i从小到大，号码小的优先
				used[i]=1;break;//删除入度为0的点
			}
		}
		if(i==n+1)return;//如果没有入度为一的点则结束
		if(topo)
			printf(" ");
		printf("%d",i);
		topo++;
		for(j=1;j<=n;j++){//将所有以 i 为起点的边删除
			if(map[i][j]==1){
				map[i][j]=0;
				index[j]--;
			}
		}
	}
}
int main()
{
	int i,a,b;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(map,0,sizeof(map));
		memset(index,0,sizeof(index));
		memset(used,0,sizeof(used));
		for(i=1;i<=m;i++){
			scanf("%d%d",&a,&b);
			if(map[a][b]==0){//考虑重边的情况
				map[a][b]=1;
				index[b]++;
			}
		}
		toposort();
		printf("\n");
	}
	return 0;
}