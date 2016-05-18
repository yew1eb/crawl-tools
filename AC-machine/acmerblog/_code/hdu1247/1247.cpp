#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int MAXN=26;
const int MAX=50005;
char word[MAX][27];

struct node
{
   bool is;
   node *next[MAXN];
   node()
   {
      is=false;
      memset(next,0,sizeof(next));
   }
};

void Insert(node *rt,char *s)
{
    int i=0;
    node *p=rt;
    while(s[i])
    {
         int k=s[i++]-'a';
         if(p->next[k]==NULL)
            p->next[k]=new node();
         p=p->next[k];
    }
    p->is=true; //该结点是单词的尾
}

bool Search(node *rt,char s[])
{
	int i=0,top=0,stack[1000];
	node *p=rt;
	while(s[i])
	{
		int k=s[i++]-'a';
		if(p->next[k]==NULL) return 0;
		p=p->next[k];
		if(p->is && s[i]) //找到该单词含有子单词的分隔点
			stack[top++]=i;//入栈
	}
	while(top)//从可能的分割点去找
	{
	    bool ok=1;
		i=stack[--top];
		p=rt;
		while(s[i])
		{
			int k=s[i++]-'a';
			if(p->next[k]==NULL)
			{
				ok=false;
				break;
			}
			p=p->next[k];
		}
		if(ok && p->is)//找到最后,并且是单词的
			return 1;
	}
	return 0;
}

int main()
{
    int i=0;
    node *rt=new node();
    while(gets(word[i]))
    {
        Insert(rt,word[i]);
        i++;
	}
	for(int j=0;j<i;j++)
		if(Search(rt,word[j]))
		   printf("%s\n",word[j]);
    return 0;
}