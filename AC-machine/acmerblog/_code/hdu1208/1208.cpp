/*
	map[ i ][ j ]表示跳几格   f [ i ][ j ] 表示有几种条法
	其实就是一个子状态继承问题，如果map[ i ][ j ]为k，
	那么 f [ i+k ][ j ] 和f[i][j+k] 就可以增加 f [ i ][ j ]种跳跃方法了。
*/
#include<stdio.h>
#include<string.h>
char map[55][55];
__int64 f[55][55];
int main()
{
	int n,i,j;
	while(scanf("%d",&n),n!=-1)
	{
		getchar();
		for(i=0;i<n;i++)
			gets(map[i]);//原先没注意数字是连着输入的，按数字读的
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(map[i][j]-'0')
				{
					if(i+map[i][j]-'0'<=n)
						f[i+map[i][j]-'0'][j]+=f[i][j];
					if(j+map[i][j]-'0'<=n)
						f[i][j+map[i][j]-'0']+=f[i][j];
				}
		printf("%I64d\n",f[n-1][n-1]);//输出时忘了用%I64d
	}
	return 0;
}