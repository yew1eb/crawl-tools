#include <iostream>
using namespace std;
#define N 85
char matrix[N][N];

int main(){
#ifndef ONLINE_JUDGE
	freopen("Iin.txt","r",stdin);
#endif
	int n,ce=0,i,j,k,quan;
	char b,a,c;
	while (scanf("%d %c %c",&n,&b,&a)!=EOF){
		ce++;
		quan=0;
		memset(matrix,0,sizeof(matrix));
		for (k=(n+1)/2-1;k>=0;k--){
			if (quan%2==0)
				c=b;
			else c=a;
			quan++;
			for (i=k,j=i;j<n-i;j++){ //画横的。
				matrix[i][j]=c;
				matrix[n-i-1][j]=c;
			}
			for (i=k,j=i;j<n-i;j++){ //画竖的。
				matrix[j][i]=c;
				matrix[j][n-i-1]=c;
			}
		}
		matrix[0][n-1]=matrix[0][0]=' ';
		matrix[n-1][0]=matrix[n-1][n-1]=' ';
		if (ce!=1)
			putchar(10);
		if (n==1){
			printf("%c\n",b);
			continue;
		}
		for (i=0;i<n;i++){
			for (j=0;j<n;j++)
				printf("%c",matrix[i][j]);
			putchar(10);
		}
	}
	return 0;
}