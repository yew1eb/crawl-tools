#include <iostream>
using namespace std;
#define N 1005
double map[N][N],prob[N];
bool visited[N];

int main(){
#ifndef ONLINE_JUDGE
	freopen("1596in.txt","r",stdin);
#endif
	int n,i,j,m,a,b,t,k;
	double max;
	while (scanf("%d",&n)!=EOF){
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				scanf("%lf",&map[i][j]);
		scanf("%d",&m);
		for (i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			a=a-1;
			b=b-1;
			memset(visited,false,sizeof(visited));
			visited[a]=true;
			for (j=0;j<n;j++)
				prob[j]=map[a][j];
			for (j=1;j<n;j++){
				max=0;
				for (k=0;k<n;k++)
					if (prob[k]>=max&&!visited[k]){
						max=prob[k];
						t=k;
					}
				visited[t]=true;
				if (t==b){
					if (prob[b]<=0)
						printf("What a pity!\n");
					else printf("%.3lf\n",prob[b]);
					break;
				}
				for (k=0;k<n;k++)
					if (!visited[k]&&prob[t]*map[t][k]>prob[k])
						prob[k]=prob[t]*map[t][k];
			}
		}
	}
	return 0;
}