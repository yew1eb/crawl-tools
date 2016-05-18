#include <cstdio>
#include <cstdlib>
#include <cstring>
const int N = 30005;
int set[N];
int high[N]; //i元素上面（加上i）的元素个数 
int low[N];  //i元素下面的元素个数 
int findset(int x){
	if(x == set[x])
		return set[x];
	int tm = set[x];
	set[x] = findset(set[x]);
	low[x] += low[tm];
	return set[x];
}
void unionset(int x,int y){
	int fx = findset(x);
	int fy = findset(y);
	if( fx == fy)
		return ;
	set[fx] = fy;
	low[fx] += high[fy];
	high[fy] += high[fx];
}
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		for(int i = 1; i <= N; i++){
			set[i] = i;
		         high[i] = 1;
		}
		memset(low,0,sizeof(low));
		char op;
		int x,y;
		getchar();
		for(int i =1 ; i <= n; i++){
			scanf("%c",&op);
			if(op == 'C'){
				scanf("%d",&x);
				findset(x);
				printf("%d\n",low[x]);
			}
			else{
				scanf("%d%d",&x,&y);
				unionset(x,y);
			}
			getchar();
		}
	}
	return 0;
}