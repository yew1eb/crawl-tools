#include<stdio.h>
#include<string.h>

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//四个方向搜索
char map[110][110];
int flag[110][110];//flag[x][y]>0表示(x,y)处的羊已划分到某个区域中。
int H,W;

int check(int x,int y){
	if(x>=0 && y>=0 && x<H && y<W)return 1;
	return 0;
}

void dfs(int x,int y,int cnt){
	int i,dx,dy;
	for(i=0;i<4;i++){
		dx=x+dir[i][0];
		dy=y+dir[i][1];
		//从(x,y)点搜索到(dx,dy)，并且(dx,dy)处的羊还未划分到某个区域中。
		if(check(dx,dy) && flag[dx][dy]==0 && map[dx][dy]=='#'){
			flag[dx][dy]=cnt;//标记已划分
			//从(dx,dy)开始搜索查看(dx,dy)的"四周"是否有未标记的点
			dfs(dx,dy,cnt);
		}
	}
}

int main(){
	int T,i,j,cnt;
	scanf("%d",&T);
	while(T--){
		memset(flag,0,sizeof(flag));
		scanf("%d%d",&H,&W);
		for(i=0;i<H;i++)scanf("%s",map[i]);
		cnt=0;
		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
				//(i,j)处有羊，并且尚未标记。一个新的区域。
				if(map[i][j]=='#' && flag[i][j]==0){
					cnt++;//区域数加1
					flag[i][j]=cnt;
					dfs(i,j,cnt);
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}