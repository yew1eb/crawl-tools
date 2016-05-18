#include"stdio.h"
#include"string.h"
struct A
{
	char low;                           //第一个位置
	char up;                            //最后一个位置
}E[1111];
int map[1111];
int k;
int flag;


void DFS(char c)
{
	int i;
	int next_c;


	if(c=='m')	flag=1;
	if(flag==1)	return ;


	for(i=0;i<k;i++)
	{
		if(map[i]==1)	continue;
		if(E[i].low==c)
		{
			next_c=E[i].up;
			map[i]=1;
			DFS(next_c);
			map[i]=0;
		}
	}
//	return ;                                   这个return是不是不写的话，编译器会自动加上啊？
}


int main()
{
	char temp[111];
	int i;
	while(scanf("%s",temp)!=-1)
	{
		///
		if(strcmp(temp,"0")==0)	continue;
		
		E[0].low=temp[0];
		E[0].up=temp[strlen(temp)-1];
		k=1;
		while(scanf("%s",temp),strcmp(temp,"0")!=0)
		{
			E[k].low=temp[0];
			E[k].up=temp[strlen(temp)-1];
			k++;
		}


		///
		flag=0;
		for(i=0;i<k;i++)
		{
			if(E[i].low=='b')
			{
				memset(map,0,sizeof(map));
				map[i]=1;
				DFS(E[i].up);
			}
			if(flag==1)			break;
		}


		if(flag==1)	printf("Yes.\n");
		else		printf("No.\n");
	}
	return 0;
}