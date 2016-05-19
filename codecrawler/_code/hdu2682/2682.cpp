#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define MAX 1000006
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int prime[MAX];
int set[606];
struct node
{
	int a,b,len;
}map[180000];

int cmp(const void* a,const void*b)
{
	return (*(node*)a).len-(*(node*)b).len;
}

//并查集
int find(int x)
{
	if(set[x]!=x){
		set[x]=find(set[x]);
	}
	return set[x];
}
int Union(int a,int b)
{
	int x=find(a);
	int y=find(b);
	if(x==y)
		return 0;
	set[x]=y;
	return 1;
}

int main()
{
	int T,n,i,j,k,temp,cnt,cost;

	//筛选法求素数
	memset(prime,0,sizeof(prime));
	prime[0]=1;
	prime[1]=1;
	for(i=2;i<MAX;i++){
		if(prime[i]==0){
			for(j=2;j<MAX;j++){
				temp=i*j;
				if(temp>MAX)break;
				prime[temp]=1;
			}
		}
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&set[i]);
		}
		
		//建图
		for(i=0,k=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(prime[set[i]]==0 || prime[set[j]]==0 || prime[set[i]+set[j]]==0){
					map[k].a=i;
					map[k].b=j;
					map[k++].len=min(min(set[i],set[j]),abs(set[i]-set[j]));
				}
			}
		}
		qsort(map,k,sizeof(map[0]),cmp);

		for(i=0;i<n;i++){
			set[i]=i;
		}
		for(i=0,cnt=0,cost=0;i<k;i++){
			if(Union(map[i].a,map[i].b)==1){
				cost+=map[i].len;
				cnt++;
			}
		}
		if(cnt==(n-1))
			printf("%d\n",cost);
		else
			printf("-1\n");
	}
	return 0;
}