#include <iostream>
using namespace std;
#define N 200000
#define max(a,b) a>b?a:b

struct LineTree
{
	int l,r;
	int size;
	LineTree *lchild,*rchild;
};

LineTree mem[4*N];
int pos;
int h,w,n;
int f;

LineTree *NewTree()
{
	LineTree *s=&mem[pos++];
	return s;
}

LineTree *CreateTree(int a,int b)
{
	int mid;
	LineTree *s=NewTree();
	s->l=a;
	s->r=b;
	s->size=w;
	if(b-a>1)
	{
		mid=(a+b)/2;
		s->lchild=CreateTree(a,mid);
		s->rchild=CreateTree(mid+1,b);
	}
	else if(b-a==1)
	{
		s->lchild=CreateTree(a,a);
		s->rchild=CreateTree(b,b);
	}
	return s;
}

void search(LineTree *t,int a)
{
	if(a>t->size) return;
	if(t->l==t->r)
	{
		t->size-=a;
		f=t->l;
		return;
	}
	if(t->lchild->size>=a)
		search(t->lchild,a);
	else if(t->rchild->size>=a)
		search(t->rchild,a);
	t->size=max(t->lchild->size,t->rchild->size);
}

int main()
{
	int x;
	LineTree *s;
	while(scanf("%d%d%d",&h,&w,&n)!=EOF)
	{
		pos=0;
		h=h<n?h:n;
		s=CreateTree(1,h);
		while(n--)
		{
			scanf("%d",&x);
			f=-1;
			search(s,x);
			printf("%d/n",f);
		}
	}
	return 0;
}