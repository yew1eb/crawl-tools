#include<iostream>
#include<algorithm>

using namespace std;

//freopen("C://i.txt","r",stdin);

#define N 1000001

int n;
char s[N];
int go[N];
int ans[N];
int main()
{
	freopen("C://i.txt","r",stdin);
	int i,j,k;
	while (cin>>s)
	{
		n=strlen(s);
		k=0;
		for (i=0;i<n;i++) if (s[i]=='.')
			break;
		
		for (i++;i<n;i++)
		{
			go[k++]=s[i]-'0';
		}
		for (i=0;i<k;i++)
		{
			ans[i]=go[i]*125;
		
		}
	

		for (i=k-1;i;i--)
		{
		
			for (j=i;j<k;j++)
			{
				ans[j]*=125;
				ans[j-1]+=ans[j]/1000;
				ans[j]%=1000;
			}
			//cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<endl;
		}
		
	
		while (ans[k-1]==0)
			k--;
		printf("%s [8] = 0.",s);
		
		for (i=0;i<k;i++)
		{
			if (ans[i]<10)
			{
				printf("00");
			}
			else if (ans[i]<100) 
			{
				printf("0");
			}
			printf("%d",ans[i]);
		}
		
		printf(" [10]\n");
	}

}
