#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<queue>
using namespace std;
int ans[1111][5];
char str[1111111];
#define cc 130
int id,vis[1111],a[1111];
struct node
{
	int count;
	struct node *next[cc];
	struct node *fail;
	void init()
	{
		int i;
		for(i=0;i<cc;i++)
			next[i]=NULL;
		count=0;
		fail=NULL;
	}
}*root;
void insert()
{
	int len,k;
	node *p=root;
	len=strlen(str);
	for(k=0;k<len;k++)
	{
		int pos=str[k]-31;
		if(p->next[pos]==NULL)
		{
			p->next[pos]=new node;
			p->next[pos]->init();
			p=p->next[pos];
		}
		else p=p->next[pos];
	}
	p->count=id;
}

void getfail()
{
	int i;
	node *p,*temp,*son;
	queue<struct node *>que;
	que.push(root);
	p=root;
	while(!que.empty())
	{
		temp=que.front();
		que.pop();
		for(i=0;i<cc;i++)
		{
			son=temp->next[i];
			if(son!=NULL)
			{
				if(temp==root)
				{
					son->fail=root;
				}
				else
				{
					p=temp->fail;
					while(p)
					{
						if(p->next[i]!=NULL)
						{
							son->fail=p->next[i];///
							break;
						}
						//else ע������û��else
							p=p->fail;
					}
					if(p==NULL) son->fail=root;
				}
				que.push(son);
			}	
		}
		 }
}

void query()
{
	int len,i,cnt=0,pos;
	len=strlen(str);
	node *p,*temp;
	p=root;
	for(i=0;i<len;i++)
	{
		pos=str[i]-31;
		while(!p->next[pos]&&p!=root) p=p->fail;
		p=p->next[pos];
		if(!p) p=root;
		temp=p;
		while(temp!=root)//ֻҪ�޸������Ｔ��
		{
			if(temp->count>=1&&!vis[temp->count])
			{
				ans[id][cnt++]=temp->count;
				vis[temp->count]=1;
			}
			temp=temp->fail;
		}
	}
}
int main()
{
	int n,m,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		root= new node;
		root->fail=NULL;
		root->init();
		getchar();
		for(i=1;i<=n;i++)
		{
			gets(str);
			id=i;
			insert();
		}
		getfail();
		scanf("%d",&m);
		getchar();
		memset(ans,0,sizeof(ans));
		for(i=1;i<=m;i++)
		{
			memset(vis,0,sizeof(vis));
			id=i;
			gets(str);
			query();
		}
		int cnt=0;
		for(i=1;i<=m;i++)
		{
			if(ans[i][0]>=1)
			{
				cnt++;
				printf("web %d:",i);
				int a[1111];
				memset(a,0,sizeof(a));
				for(j=0;ans[i][j]>=1;j++)
				{
					a[ans[i][j]]=1;
				}
				int k;
				for(k=1;k<1100;k++)
				{
					if(a[k])
					 printf(" %d",k);
				}
				printf("\n");
			}
		}
		printf("total: %d\n",cnt);
	}
	return 0;
	
}