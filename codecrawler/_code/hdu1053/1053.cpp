#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct tree 
{
	char ch;
	int count;//字母为ch在字符串中出现的次数
	int deep;//BFS时，结点深度
	tree *left,*right;
	tree(){left = right = NULL,deep = count = 0,ch = '?';}
	friend bool operator<(tree a,tree b)
	{
		return a.count>b.count;
	}
};
/*记录字符种类和每个字符出现次数*/
struct kind 
{
	char ch;
	int count;
}letter[201];
int length;
int sum;
priority_queue<tree>PriorQueue;/*结点极小优先队列，比较关键码为tree.count*/

void Huffman()
{
	sum = 0;
	int i;
	tree *a,*b,node,*c,root;
	queue<tree>q;
	/*生成结点*/
	for (i=0;i<length;i++)
	{
		node.count = letter[i].count;
		node.ch = letter[i].ch;
		PriorQueue.push(node);
	}
	while (PriorQueue.size()!=1)
	{
		/*优先队列取出两个最小结点，进行构树*/
		a = new tree;
		*a = PriorQueue.top(),PriorQueue.pop();
		b = new tree;
		*b = PriorQueue.top(),PriorQueue.pop();
		c = new tree;
		c->count = a->count+b->count;
		c->left = a,c->right = b;
		PriorQueue.push(*c);
	}
	root = PriorQueue.top(),PriorQueue.pop(),root.deep = 0;//根节点为0层
	q.push(root);
	while (!q.empty())
	{
		node = q.front(),q.pop();
		if (node.left)
		{
			node.left->deep = node.deep+1;
			q.push(*node.left);
		}
		if (node.right)
		{
			node.right->deep = node.deep+1;
			q.push(*node.right);
		}
		if(!node.left&&!node.right)
			sum+=node.deep*node.count;
	}
}
int main()
{
	char str[1005],i,len,count;
	while (scanf("%s",str)&&strcmp(str,"END")!=0)
	{
		len = strlen(str);
		str[len] = '!';
		sort(str,str+len);
		for (length = 0,count=1,i=1;i<=len;i++)
		{
			if (str[i]!=str[i-1])
			{
				letter[length].ch = str[i-1];
				letter[length++].count = count;
				count = 1;
			}
			else
				count++;
		}
		if(length==1)
			printf("%d %d 8.0/n",8*len,len);
		else
		{
			Huffman();
			printf("%d %d %.1lf/n",len*8,sum,len*8*1.0/sum);
		}
		
	}
	return 0;
}