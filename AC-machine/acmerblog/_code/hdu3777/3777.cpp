//============================================================================
// Name : E.cpp
// Author : 
// Version :
// Copyright : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>


using namespace std;


int N;

bool vis[1100];

char str[1100];

int main()
{
//	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);
	int s,t;
	while(scanf("%d",&N)!=EOF && N)
	{
		for(int i=1;i<=N;i++)
			vis[i]=false;
		scanf("%s",str);
		char * p;
		p=strtok(str,",");
		while(p)
		{
//			sscanf(p,"%d-%d",&s,&t);
			bool bingo=false;
			for(char* x=p;*x;x++)
				if('-'==*x)
				{
					bingo=true;
					break;
				}
			if(bingo)
			{
				sscanf(p,"%d-%d",&s,&t);
//				printf("%d %d\n",s,t);
				if(s<=t)
				{
					for(int i=s;i<=t;i++)
					{
						if(i<=0 || i>N)
							break;
						vis[i]=true;
					}
				}
			}
			else
			{
				sscanf(p,"%d",&s);
				if(s>=1 && s<=N)
					vis[s]=true;
			}

//			printf("%d %d\n",s,t);

			p=strtok(NULL,",");
		}
		int res=0;
		for(int i=1;i<=N;i++)
		{
			if(vis[i])
				res++;
		}
		printf("%d\n",res);
	}











	return 0;
}