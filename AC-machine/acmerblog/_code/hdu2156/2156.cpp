#include<stdio.h>
#include<math.h>
#include<string.h>
#define max 50001
double x[max]={0,1};
int main(){
    int n,i;
	double sum=1;
	for(i=2;i<max;i++){
		sum+=2*(1.0/i);
		x[i]=x[i-1]+sum;
	}
	while(scanf("%d",&n)&& n){ 
		printf("%.2lf\n",x[n]);
	}
	return 0;
}