#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define max_node 16*16*16*16*16*4+100
#define inf 0xfffffff
int total;
int R[max_node];
int L[max_node];
int U[max_node];
int D[max_node];
int col[max_node];
int row[max_node];
int h[16*16*16+10];
int s[16*16*4+10];
int ans[16*16*16+10];
void initDL(int c)
{
	memset(h,-1,sizeof(h));
	memset(s,0,sizeof(s));
	for(int i=0;i<=c;i++)
	{
		D[i]=U[i]=i;
		L[i+1]=i;
		R[i]=i+1;
	}
	R[c]=0;
	total=c+1;
}
void link(int r,int c)
{
	s[c]++;
	row[total]=r;
	col[total]=c;
	U[total]=U[c];
	D[U[c]]=total;
	D[total]=c;
	U[c]=total;
	if(h[r] == -1)
		h[r]=L[total]=R[total]=total;
	else
	{
		L[total]=L[h[r]];
		R[L[h[r]]]=total;
		R[total]=h[r];
		L[h[r]]=total;
	}
	total++;
}
void remove(int c)
{
	L[R[c]]=L[c];
	R[L[c]]=R[c];
	for(int i=D[c];i!=c;i=D[i])
		for(int j=R[i];j!=i;j=R[j])
		{
			U[D[j]]=U[j];
			D[U[j]]=D[j];
			s[col[j]]--;
		}
}
void resume(int c)
{
	for(int i=U[c];i!=c;i=U[i])
		for(int j=L[i];j!=i;j=L[j])
		{
			U[D[j]]=j;
			D[U[j]]=j;
			s[col[j]]++;
		}
	L[R[c]]=c;
	R[L[c]]=c;
}
bool flag[max_node];
int num;
void dance(int dep)
{
	if(num == 2)
		return;
	if(R[0] == 0)
	{
		num++;
		if(num == 1)
		{
			memset(flag,false,sizeof(flag));
			for(int i=0;i<dep;i++)
				flag[ans[i]]=true;
		}
		return;
	}
	int mm=inf;
	int c;
	for(int i=R[0];i;i=R[i])
		if(s[i] < mm)
		{
			mm=s[i];
			c=i;
		}
	remove(c);
	for(int i=D[c];i!=c;i=D[i])
	{
		ans[dep]=row[i];
		for(int j=R[i];j!=i;j=R[j])
			remove(col[j]);
		dance(dep+1);
		if(num == 2)
			return;
		for(int j=L[i];j!=i;j=L[j])
			resume(col[j]);
	}
	resume(c);
	return;
}
int N,M;
void build(char str[][110])
{
	initDL(M*M*4);
	for(int i=0;i<M;i++)
		for(int j=0;j<M;j++)
		{
			int begin,end;
			if(str[i][j] == '.')
			{
				begin=0;
				end=M-1;
			}
			else
			{
				if('A' <= str[i][j] && str[i][j] <= 'Z')
					begin=end=str[i][j]-'A'+9;
				else
					begin=end=str[i][j]-'1';
			}
			for(int k=begin;k<=end;k++)
			{
				int x=i*M*M+j*M+k;
				int y1=i*M+j;
				int y2=M*M+i*M+k;
				int y3=M*M+M*M+j*M+k;
				int y4=M*M+M*M+M*M+((i/N)*N+(j/N))*M+k;
				link(x+1,y1+1);
				link(x+1,y2+1);
				link(x+1,y3+1);
				link(x+1,y4+1);
			}
		}
}
char g[110][110];
char str[110][110];
void get_num()
{
	build(str);
	num=0;
	dance(0);
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		M=N*N;
		for(int i=0;i<M;i++)
			scanf("%s",g[i]);
		for(int i=0;i<M;i++)
			for(int j=0;j<M;j++)
				str[i][j]=g[i][j];
		get_num();
		if(num == 0)
			printf("No Solution\n");
		else if(num == 2)
			printf("Multiple Solutions\n");
		else
		{
			bool ok=true;
			for(int i=0;i<M && ok;i++)
				for(int j=0;j<M && ok;j++)
				{
					if(g[i][j] != '.')
					{
						str[i][j]='.';
						get_num();
						if(num != 2)
							ok=false;
						str[i][j]=g[i][j];
					}
				}
			if(ok)
			{
				get_num();
				for(int i=0;i<M;i++)
				{
					for(int j=0;j<M;j++)
						for(int k=1;k<=M;k++)
							if(flag[i*M*M+j*M+k])
							{
								if(k >= 10)
									printf("%c",'A'+(k-10));
								else
									printf("%c",'0'+k);
								break;
							}
					printf("\n");
				}
			}
			else
				printf("Not Minimal\n");
		}
	}
	return 0;
}