#include"stdio.h"
#include"string.h"
#include"stdlib.h"

int n;
__int64 ans;
struct Dictree
{
	struct Dictree *child[9];
	int num;
};
struct Dictree *root;

void insert(char str[])
{
	struct Dictree *now,*next;
	int i,l;
	now=root;
	for(i=0;str[i];i++)
	{
		if(now->child[str[i]-'0']!=NULL)
			now=now->child[str[i]-'0'];
		else
		{
			next=(struct Dictree *)malloc(sizeof(struct Dictree));
			next->num=0;
			for(l=1;l<=8;l++)	next->child[l]=NULL;
			now->child[str[i]-'0']=next;
			now=next;
		}
	}
	now->num++;
}
void get_ans(struct Dictree *now)
{
	int l;
	__int64 temp=now->num-1;
	ans+=(1+temp)*temp/2;
	for(l=1;l<=8;l++)
		if(now->child[l]!=NULL)
			get_ans(now->child[l]);
}
int main()
{
	int i,l;
	int temp,k;
	char str1[22],str2[22];
	while(scanf("%d",&n)!=-1)
	{
		root=(struct Dictree *)malloc(sizeof(struct Dictree));
		root->num=0;
		for(l=1;l<=8;l++)	root->child[l]=NULL;
		for(i=0;i<n;i++)
		{
			scanf("%s",str1);
			k=0;
			temp=1;
			for(l=1;str1[l];l++)
			{
				if(str1[l]!=str1[l-1])
				{
					str2[k++]=temp+'0';
					temp=1;
				}
				else	temp++;
			}
			str2[k++]=temp+'0';
			str2[k]=0;
			insert(str2);
		}
		ans=0;
		get_ans(root);
		printf("%I64d\n",ans);
	}
	return 0;
}