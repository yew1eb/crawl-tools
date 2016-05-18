#include<cstdio>
#define INF 0x3fff

const int M=1002;
int num[M][M/2]={{0},{0},{1},{1}}; //给前面的四个直接赋值。 
int b[M]={1}; 
void calc()    //巧妙！ 
{
	for(int i=4;i<M-1;++i){
		for(int c=0,j=0;j<400;++j){
			b[j]=b[j]*2+c;
			c=b[j]/10;
			b[j]=b[j]%10;	
		}
		for(int c=0,j=0;j<400;++j){
			num[i][j]=b[j]+num[i-2][j]+c;
			c=num[i][j]/10;
			num[i][j]=num[i][j]%10;    //存取余数。（降位） 
		}
	}
}
int main()
{
	int n;
	calc();
	while(~scanf("%d",&n)){
		bool flag=false;
		if(n==1)
			puts("0");
		else{
			for(int i=300;i>=0;--i){
				if(num[n][i]||flag){
					printf("%d",num[n][i]);
					flag=true;
				}
			}
			puts("");
		}
	}
	return 0;
}