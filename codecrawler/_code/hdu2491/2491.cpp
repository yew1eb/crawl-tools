#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct node
{
	int start,end,last,middle;
}wedding[100005];
int cmp(const void* a,const void* b)
{
	if((*(node*)a).middle == (*(node*)b).middle)
		return (*(node*)a).start-(*(node*)b).start;
	else
		return (*(node*)a).middle-(*(node*)b).middle;
}
int main()
{
	int n,time,i;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){
			scanf("%d%d",&wedding[i].start,&wedding[i].end);
			wedding[i].last=(wedding[i].end-wedding[i].start)/2+1;//仪式持续时间超过婚礼一半
			wedding[i].middle=wedding[i].start+wedding[i].last;
		}
		qsort(wedding,n,sizeof(wedding[0]),cmp);
		time=wedding[0].start;
		for(i=0;i<n;i++){
			if(time>wedding[i].end-wedding[i].last){
				break;
			}
			if(time<=wedding[i].start)
				time=wedding[i].middle;
			else
				time+=wedding[i].last;
		}
		if(i==n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}