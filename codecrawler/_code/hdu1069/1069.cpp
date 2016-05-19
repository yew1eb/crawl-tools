#include<stdio.h>
#include<stdlib.h>
#define N 95
int f[N];  //f[N]记录加上第i个木块后的最大高度
struct X
{
	int x,y,z;
}block[N];
int cmp(const struct X* a,const struct X* b)
{
	if((*a).x!=(*b).x)
		return (*a).x-(*b).x;
	else
		return (*a).y-(*b).y;
}
int main()
{
	int T,n,a,b,c,i,j,temp,tallest;
	T=1;
	while(scanf("%d",&n),n){
		for(i=0,j=0;j<n;j++){       //每种木块可以有三种放法
			scanf("%d%d%d",&a,&b,&c);
			block[i].x=a; block[i].y=b; block[i].z=c;
			block[i+1].x=a; block[i+1].y=c; block[i+1].z=b;
			block[i+2].x=c; block[i+2].y=b; block[i+2].z=a;
			i+=3;
		}
		for(i=0;i<n*3;i++){          //找出每种木块的长和宽
			if(block[i].x<block[i].y){
				temp=block[i].x;
				block[i].x=block[i].y;
				block[i].y=temp;
			}
		}
		qsort(block,n*3,sizeof(block[0]),cmp); //先按木块的"长"升序排列，"长"相等时再按"宽"升序排列
		for(i=0,tallest=0;i<3*n;i++){    //将f[i]初始化为第i个的高度，计算f[i]时，遍历0—>i，找出放上第i个木块时的最大高度。
			f[i]=block[i].z;
			for(j=0;j<=i;j++){
				if(block[i].x>block[j].x&&block[i].y>block[j].y){
					f[i]=max(f[i],f[j]+block[i].z);
				}
				tallest=max(tallest,f[i]);
			}
		}
		printf("Case %d: maximum height = %d\n",T++,tallest);
	}
	return 0;
}