#include <stdio.h>
#include <string.h>
char str[5010];
void Ready()
{
	while(gets(str),strcmp(str,"START"));
}
void Deal(char* c)
{
	while(gets(str),strcmp(str,"END"))
	{
		if(str[0]=='\0')
			strcat(c," ");
		else
			strcat(c,str);
	}
}
int main()
{
	int z,i,j,Li,Lj;
	bool PE,WA;
	char ac[5010],my[5010];
	scanf("%d",&z);
	while(z--)
	{
		PE = WA = false;
		ac[0] = my[0] = '\0';
		Ready();
		Deal(ac);
		Ready();
		Deal(my);
		i = j = 0;
		Li = strlen(ac);
		Lj = strlen(my);
		while(i<Li || j<Lj)
		{
			if(ac[i] == my[j])
			{
				i ++;j ++;
				continue;
			}
			PE = true;
			if(ac[i]==' ' || ac[i]=='\t')
			{
				i ++;
				continue;
			}
			if(my[j]==' ' || my[j]=='\t')
			{
				j ++;
				continue;
			}
			WA = true;
			break;
		}
		puts(WA?"Wrong Answer":(PE?"Presentation Error":"Accepted"));
	}
	return 0;
}