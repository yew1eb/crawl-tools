//ashione 2011-6-1 ,欧拉回路检测
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define SetMax 1001
int in[SetMax],out[SetMax],map[SetMax][SetMax];
bool mark[SetMax];
void init(int n){
	memset(mark,false,(n+1)*sizeof(bool));
	memset(map,0,sizeof(map));
	memset(in,0,(n+1)*sizeof(int));
	memset(out,0,(n+1)*sizeof(int));
}
void dfs(int k,int n){//DFS寻找最大连通分量
	mark[k]=true;
	for(int i=1;i<=n;i++)
		if(map[k][i] && !mark[i]){
			dfs(i,n);
			break;
		}	
}
int main(){
	int n,m,a,b,i,j;
	while(cin>>n && n){
		cin>>m;
		init(n);
		while(m--){
			scanf("%d %d",&a,&b);
			map[a][b]=map[b][a]=1;
			out[a]++,in[b]++;//无向图入度与出度
			in[a]++,out[b]++;
		}
		dfs(1,n);		
		for(i=1;i<=n;i++)
			if(out[i]!=in[i] || !mark[i] || in[i]%2==1 )//当节点入度不等于出度或者连通分量大于1或者为奇数入度则不为欧拉回路
				break;
		puts((i==n+1)?"1":"0");
	}			
	return 0;
}