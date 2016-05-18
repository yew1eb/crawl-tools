#include"stdio.h"
#include"string.h"


struct A
{
	int total;
	int dis;
	int mem[6];
	int len[6];
}E[444];


int MIN(int a,int b)
{
	return a>b?b:a;
}


void SPFA(int s)
{
	int k,key;
	int hash[555];
	int i;
	int queue[888];


	queue[0]=s;
	key=1;
	k=0;
	memset(hash,0,sizeof(hash));
	hash[s]=1;
	while(k<key)
	{
		for(i=0;i<E[queue[k]].total;i++)
		{
			if(E[queue[k]].dis+E[queue[k]].len[i]<E[E[queue[k]].mem[i]].dis)
			{
				E[E[queue[k]].mem[i]].dis=E[queue[k]].dis+E[queue[k]].len[i];
				if(!hash[E[queue[k]].mem[i]])
				{
					hash[E[queue[k]].mem[i]]=1;
					queue[key++]=E[queue[k]].mem[i];
				}
			}
		}
		hash[queue[k++]]=0;
	}
}
int main()
{
	int n,m;
	int n_temp;
	int i,l;
	int limit;
	int temp;
	int t1,t2;
	char str[10];


	while(scanf("%d%d",&n,&m),n||m)
	{
		temp=(n+1)*(m+1);
		for(i=1;i<=temp;i++)	{E[i].total=0;E[i].dis=11111111;}


		n_temp=2*n+1;
		for(i=0;i<n_temp;i++)
		{
			if(i%2)	limit=m+1;
			else	limit=m;
			for(l=0;l<limit;l++)
			{
				scanf("%d%s",&temp,str);
				if(temp==0)	continue;
				temp=2520/temp;
				if(i%2==0)	{t1=(i/2)*(m+1)+l+1;t2=t1+1;}
				else		{t1=((i-1)/2)*(m+1)+l+1;t2=t1+m+1;}
				if(str[0]=='*')
				{
					E[t1].mem[E[t1].total]=t2;
					E[t1].len[E[t1].total++]=temp;
					E[t2].mem[E[t2].total]=t1;
					E[t2].len[E[t2].total++]=temp;
				}
				else if(str[0]=='v')
				{
					E[t1].mem[E[t1].total]=t2;
					E[t1].len[E[t1].total++]=temp;
				}
				else if(str[0]=='^')
				{
					E[t2].mem[E[t2].total]=t1;
					E[t2].len[E[t2].total++]=temp;
				}
				else if(str[0]=='>')
				{
					E[t1].mem[E[t1].total]=t2;
					E[t1].len[E[t1].total++]=temp;
				}
				else if(str[0]=='<')
				{
					E[t2].mem[E[t2].total]=t1;
					E[t2].len[E[t2].total++]=temp;
				}
			}
		}


		E[1].dis=0;
		SPFA(1);


		if(E[(n+1)*(m+1)].dis==11111111)	printf("Holiday\n");
		else								printf("%d blips\n",E[(n+1)*(m+1)].dis);
	}
	return 0;
}