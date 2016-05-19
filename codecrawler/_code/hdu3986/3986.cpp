#include"stdio.h"
#include"string.h"


struct A
{
	int dis;
	int pre;
	int pre_len;
	int total;
	int mem[1011];
	int len[1011];
}E[1011];
int n;


int SPFA()
{
	int k,key;
	int queue[2222];
	int i;
	int hash[1011];


	memset(hash,0,sizeof(hash));
	key=1;
	k=0;
	queue[0]=1;
	hash[1]=1;


	while(k<key)
	{
		for(i=0;i<E[queue[k]].total;i++)
		{
			if(E[queue[k]].dis+E[queue[k]].len[i]<E[E[queue[k]].mem[i]].dis)
			{
				E[E[queue[k]].mem[i]].pre=queue[k];
				E[E[queue[k]].mem[i]].pre_len=E[queue[k]].len[i];
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
	return E[n].dis;
}
int main()
{
	int T;
	int m;
	int i,l;
	int a,b,c;
	int ans;
	int des[1011],des2[1011],len,k;
	int temp;
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);


		for(i=1;i<=n;i++)
		{
			E[i].total=0;
			E[i].dis=1111111111;
			E[i].pre=i;
		}
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			E[a].mem[E[a].total]=b;
			E[a].len[E[a].total++]=c;
			E[b].mem[E[b].total]=a;
			E[b].len[E[b].total++]=c;
		}


		E[1].dis=0;
		temp=SPFA();
		
		k=0;
		temp=n;
		while(E[temp].pre!=temp)
		{
			des2[k]=E[temp].pre_len;
			des[k++]=temp;
			temp=E[temp].pre;
		}
		des[k++]=temp;


		ans=-1;
		for(i=0;i<k-1;i++)
		{
			a=des[i];
			b=des[i+1];
			len=des2[i];


			for(l=0;l<E[a].total;l++)	if(E[a].mem[l]==b && E[a].len[l]==len)	break;
			for(;l<E[a].total-1;l++)	{E[a].mem[l]=E[a].mem[l+1];E[a].len[l]=E[a].len[l+1];}
			E[a].total--;
			for(l=0;l<E[b].total;l++)	if(E[b].mem[l]==a && E[b].len[l]==len)	break;
			for(;l<E[b].total-1;l++)	{E[b].mem[l]=E[b].mem[l+1];E[b].len[l]=E[b].len[l+1];}
			E[b].total--;


			for(l=2;l<=n;l++)	E[l].dis=1111111111;
			E[1].dis=0;


			temp=SPFA();
			if(temp>ans)	ans=temp;


			E[a].mem[E[a].total]=b;
			E[a].len[E[a].total++]=len;
			E[b].mem[E[b].total]=a;
			E[b].len[E[b].total++]=len;
		}


		if(ans==1111111111)	printf("-1\n");
		else				printf("%d\n",ans);
	}
	return 0;
}