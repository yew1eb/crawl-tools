#include<stdio.h>
#include<string.h>
#define MAX 110010

char str[MAX],str1[2*MAX];
int mana[2*MAX];
int len;
int ans;

int min(int a,int b)
{
	return a<b?a:b;
}

int max(int a,int b)
{
	return a>b?a:b;
}

void manachar()
{
	int i,j,k;
	memset(mana,0,sizeof(mana));
	str1[0]='&';
	for(i=0,j=1;str[i]!=0;i++)
	{
		str1[j++]='#';
		str1[j++]=str[i];
	}
	str1[j++]='#';
	str1[j]='*';
	len=j;
	i=1;
	int mx=0,id;
	ans=0;
	for(i=1;i<len;i++)
	{
		if(mx>i) mana[i]=min(mx-i,mana[2*id-i]);
		else mana[i]=1;
		for(;str1[i-mana[i]]==str1[i+mana[i]];mana[i]++);
		if(mana[i]+i>mx)
		{
			mx=mana[i]+i;
			id=i;
		}
		if(mana[i]>ans)
			ans=mana[i];
	}
}

int main()
{
	while(scanf("%s",str)!=EOF)
	{
		len=strlen(str);
		manachar();
		printf("%d\n",ans-1);
	}
	return 0;
}