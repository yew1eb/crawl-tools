/**
[有向环] hdu 4324 Triangle LOVE
判断一个有向图中是否有环，因为任意两点都有一条边,故该图只有一个子图
现在想来dfs,拓扑排序什么的都弱爆了，所有结点的入度都>0就AC
*/
#include <stdio.h>
#include <string.h>
int in[2001];
int main(){
	int t,cas = 0,i,j,n;
	scanf("%d",&t);
	while(t--){
		memset(in,0,sizeof(in));
		scanf("%d\n",&n);
		for(i = 0;i < n; ++i){
			for(j = 0; j < n; ++j)
				if(getchar() == '1')
					in[j]++;
			getchar();
		}
			
		for(i = 0; i < n; ++i)
			in[n] += (in[i] != 0);
		printf(in[n] == n ? "Case #%d: Yes\n" : "Case #%d: No\n",++cas);
	}
	return 0;
}