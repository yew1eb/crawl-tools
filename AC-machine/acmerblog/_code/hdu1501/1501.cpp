#include<stdio.h>
#include<string.h>

char a[201],b[201],c[402];
int la,lb,lc;
int dp[201][201];

int main()
{
	int ncase;
	scanf("%d",&ncase);
	for(int n=1; n<=ncase; n++) {
		
		a[0]='p';
		b[0]='p';
		c[0]='p';
		
		scanf("%s%s%s",a+1,b+1,c+1);
		
		la=strlen(a);
		lb=strlen(b);
		lc=strlen(c);
		
		la-=1;
		lb-=1;
		
		//处理边界
		for (int i=1; i<=la; i++)
			if (a[i]==c[i]) dp[i][0]=1; 
		
		for (int i=1; i<=lb; i++)
			if (b[i]==c[i]) dp[0][i]=1;
		//DP
		for (int i=1; i<=la; i++)
			for (int j=1; j<=lb; j++)
				dp[i][j]= (dp[i-1][j]&&(a[i]==c[i+j]))||(dp[i][j-1]&&(b[j]==c[i+j]));
		
		printf("Data set %d: ",n);
		if (dp[la][lb]==1) printf("yes\n");
		else printf("no\n");
		
	}
}