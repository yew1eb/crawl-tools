#include<stdio.h>
#include<string.h>
int hash[128];
struct TrieNode{
	int no;//对应的数字串的编号，这个编号利于后面对出现次数进行统计
	TrieNode *next[10];
}node[30005];
TrieNode *root = &node[0];
int cnt,result[5005];
char word[10],s[10];
void init()
{
	//每个字母对应的数字
	hash['a']=hash['b']=hash['c']=2;
	hash['d']=hash['e']=hash['f']=3;
	hash['g']=hash['h']=hash['i']=4;
	hash['j']=hash['k']=hash['l']=5;
	hash['m']=hash['n']=hash['o']=6;
	hash['p']=hash['q']=hash['r']=hash['s']=7;
	hash['t']=hash['u']=hash['v']=8;
	hash['w']=hash['x']=hash['y']=hash['z']=9;
}
void initRoot()
{
	int i;
	for(i=0;i<10;i++)
	{
		root->next[i]=NULL;
	}
}
//向字典树中插入新的串。
void insert(char str[],int num)
{
	TrieNode *p = root;
	int len=strlen(str),i,j;
	for(i=0;i<len;i++)
	{
		if(p->next[str[i]-'0']==NULL)
		{
			p->next[str[i]-'0']=&node[cnt];
			for(j=0;j<10;j++)node[cnt].next[j]=NULL;
			node[cnt].no=-1;
			cnt++;
		}
		p=p->next[str[i]-'0'];
	}
	//设置数字串对应的编号
	p->no=num;
}
/** 查询一个字母字符串对应的数字串 */
void query(char str[])
{
	int len=strlen(str),i;
	TrieNode *p=root;
	for(i=0;i<len;i++)
	{
		p=p->next[hash[str[i]]];
		if(p==NULL)break;
	}
	if(p==NULL)return;//该串对应的数字串不存在。
	else{
		if(p->no!=-1)result[p->no]++;
	}
}
int main()
{
	int t,m,n,i;
	scanf("%d",&t);
	init();
	while(t--)
	{
		cnt=1;
		initRoot();
		memset(result,0,sizeof(result));
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%s",word);
			insert(word,i);
		}
		for(i=0;i<m;i++)
		{
			scanf("%s",s);
			query(s);
		}
		for(i=0;i<n;i++)
		{
			//顺序打出每个串出现的次数。
			printf("%d\n",result[i]);
		}
	}
	return 0;
}