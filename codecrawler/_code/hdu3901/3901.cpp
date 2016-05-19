#include<iostream>
using namespace std;

const int N=100010;
char t[N], s[N], tmp[N];
int next[N], tn, sn, flag;

void getnext(char *s)
{
	int len=strlen(s);
	int i=0, j=-1;
	next[0] = -1;
	while(i<len)
	{
		if(j==-1 || s[i]==s[j] || s[i]=='?' || s[j]=='?')
			next[++i] = ++j;
		else
			j = next[j];
	}
}
int getindex(int ti, char tmp[])
{
	int len = strlen(tmp);
	int j=0;
	while(ti<tn && j<len)
	{
		if(j==-1 || t[ti]==tmp[j] || tmp[j]=='?')
		{
			ti++, j++;
		}
		else
			j = next[j];
	}
	if(j==len)
		return ti;
	return -1;
}

int main()
{
	int i, j, k, l;
	while(scanf("%s %s", t, s)!=EOF)
	{
		tn = strlen(t);
		sn = strlen(s);
		
		for(i=0,j=0; i<tn && j<sn; )
		{
			for( ; j<sn&&s[j]=='*'; j++); 
			for(k=j; k<sn&&s[k]!='*'; k++);

			for(l=j; l<k; l++)
				tmp[l-j] = s[l];
			tmp[l-j] = '\0';

			getnext(tmp);
			flag = getindex(i, tmp);
			if(flag==-1)
				break;
			i = flag;
			j = k;
		}
		while(j<sn && s[j]=='*')
			j++;
		if(j<sn)
			flag = -1;

		if(flag==-1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}