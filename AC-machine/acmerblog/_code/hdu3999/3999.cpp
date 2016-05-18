#include"stdio.h"
#include"string.h"
#include"stdlib.h"

int n;
struct Tree
{
	struct Tree *left,*right;
	int num;
};
struct Tree *root;
int ans[100111],k;

void insert(int aim)
{
	struct Tree *now,*next;
	now=root;
	while(now->num)
	{
		if(aim<now->num)
		{
			if(now->left==NULL)
			{
				next=(struct Tree *)malloc(sizeof(struct Tree));
				next->left=next->right=NULL;
				next->num=0;
				now->left=next;
				now=next;
			}
			else	now=now->left;
		}
		else
		{
			if(now->right==NULL)
			{
				next=(struct Tree *)malloc(sizeof(struct Tree));
				next->left=next->right=NULL;
				next->num=0;
				now->right=next;
				now=next;
			}
			else	now=now->right;
		}
	}
	now->num=aim;
}
void solve(struct Tree *now)
{
	ans[k++]=now->num;
	if(now->left!=NULL)	solve(now->left);
	if(now->right!=NULL)solve(now->right);
}
int main()
{
	int i;
	int temp;
	while(scanf("%d",&n)!=-1)
	{
		if(n<=0)	continue;
		root=(struct Tree *)malloc(sizeof(struct Tree));
		root->left=root->right=NULL;
		root->num=0;
		for(i=0;i<n;i++)	{scanf("%d",&temp);insert(temp);}

		k=0;
		solve(root);
		printf("%d",ans[0]);
		for(i=1;i<k;i++)	printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}