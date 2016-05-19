#include <iostream>
#include <algorithm>
using namespace std;
#define N 200005
int junctions[N];

struct road_node{
	int x,y,len;
};
road_node roads[N];

int findfather(int n){
	if (n!=junctions[n])
		junctions[n]=findfather(junctions[n]);
	return junctions[n];
}

bool cmp(road_node a,road_node b){
	return a.len<b.len;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("2988in.txt","r",stdin);
#endif
	int n,m,i,a,b,len_total,num,light;
	while (scanf("%d%d",&n,&m)!=EOF){
		if (n==0&&m==0)
			break;
		len_total=0;
		num=0;
		for (i=0;i<n;i++)
			junctions[i]=i;
		for (i=0;i<m;i++){
			scanf("%d%d%d",&roads[i].x,&roads[i].y,&roads[i].len);
			len_total+=roads[i].len;
		}
		sort(roads,roads+m,cmp);
		i=0;
		light=0;
		while (num<n-1&&i<m){
			a=findfather(roads[i].x);
			b=findfather(roads[i].y);
			if (a!=b){
				junctions[b]=a;
				num++;
				light+=roads[i].len;
			}
			i++;
		}
		printf("%d\n",len_total-light);
	}
	return 0;
}