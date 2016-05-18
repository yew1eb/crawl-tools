/*
 * 1584_2.cpp
 *
 *  Created on: 2013年8月22日
 *      Author: Administrator
 */

#include <iostream>

using namespace std;

/**
 * vis[] :某一张牌的访问情况
 * a[s] = i ;牌面s在第i个位置
 * ans : 所需要的最小移动步数
 *
 */
const int maxn = 10000000;
int a[11];
bool visited[11];
int  ans;

/**
 * cur :当前移动牌数
 * temp :当前移动步数
 */
void dfs(int cur , int temp){
	//如果当前移动步数>=全局移动步数
	if(temp >= ans){
		return ;
	}
	//如果当前移动排数  == 9(为什么不==10呢??以为10是不需要移动的)
	if(cur == 9){
		ans = temp;
		return ;
	}

	int i,j;
	for( i = 1 ; i < 10 ; ++i){
		if(!visited[i]){
			for(j = i+1 ; j <= 10 ; ++j){ //这个用来确定i牌要移到什么位置
				if(!visited[j]){//比如要移1了，如果2,3,4,5都已经被移动过了 那么这几张牌必定叠放在6的下面，所以要移到6的位置
					visited[i] = true;
					dfs(cur + 1, temp + abs(a[i] - a[j]));
					break;//注意不要再这个地方回溯 如果回溯了 就像是又一个全排列 而且牌得移动不合理，比如2移到6了，结果回溯就直接跳过3~6到了7的下面
				}
			}
			visited[i] = false;
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){

		memset(visited,false,sizeof(visited));
		ans = maxn;
		int i;
		for( i = 1 ; i <= 10 ; ++i){
			int s;
			scanf("%d",&s);
			a[s] = i;
		}

		dfs(0,0);
		printf("%d\n",ans);
	}
}