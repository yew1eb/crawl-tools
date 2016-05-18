#include<stdio.h>
#define SIZE 1000006
int next[SIZE];
char str[SIZE];

void getnext(int n)
{
	int i=0,j=-1;
	next[0]=-1;
	while(i<n){
		if(j==-1 || str[i]==str[j]){
			i++;
			j++;
			next[i] = j;
		}
		else{
			j = next[j];
		}
	}
}
int main()
{
	int nT=1,n,i,mixed,circulate;
	while(scanf("%d",&n),n){
		getchar();
		gets(str);
		getnext(n);
		printf("Test case #%d\n",nT++);
		for(i=1;i<=n;i++){
			mixed = 2*next[i]-i;       //重叠部分
			circulate = next[i]-mixed; //循环节长度
			if(mixed>=0 && i%circulate==0){
				printf("%d %d\n",i,i/circulate);
			}
		}
		printf("\n");
	}
	return 0;
}