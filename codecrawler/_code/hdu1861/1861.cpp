/*
	Author: ACb0y
	DateTime: 2011年2月11日10:28:45
	Type: 模拟题
	ProblemID: HDU 1861 游船出租
	Result: 3468844	2011-02-12 10:29:14	Accepted	1861	0MS	312K	2194 B	G++	ACb0y
 */
#include <iostream>
using namespace std;
/*
	字典树节点
 */
struct node 
{
	node * pNext[10];
	//借出时间
	char * pStrTime;
};
char strNum[10];
char charFlag;
char strTime[10];
node * root;
double cnt;
double totalM;
/*
	申请一个节点
 */
node * getNode()
{
	node * pNew = (node *)malloc(sizeof(node));
	memset(pNew->pNext, 0, sizeof(pNew->pNext));
	pNew->pStrTime = NULL;
	return pNew;
}
/*
	插入借出船只信息
 */
void insert(node * root, char * strNum, char * strTime)
{
	node * pCur = root;
	int len = strlen(strNum);
	int index = 0;
	for (int i = 0; i < len; ++i)
	{
		index = strNum[0] - '0';
		if (NULL == pCur->pNext[index])
		{
			pCur->pNext[index] = getNode();
		}
		pCur = pCur->pNext[index];
	}
	//这边要判断pStrTime因为有可能会发生覆盖。
	//以免内存泄露
	if (pCur->pStrTime != NULL) 
	{
		free(pCur->pStrTime);
	}
	pCur->pStrTime = (char *)malloc(strlen(strTime) + 1);
	strcpy(pCur->pStrTime, strTime);
}
/*
	规划船只时查询借出船只字典树，并统计
	cnt和totalM。
 */
void query(node * root, char * strNum, char * strTime) 
{
	node * pCur = root;
	int len = strlen(strNum);
	int index = 0;
	for (int i = 0; i < len; ++i) 
	{
		index = strNum[i] - '0';
		if (NULL == pCur->pNext[index])
		{
			return ;
		}
		pCur = pCur->pNext[index];
	}
	//没有该船的借出记录
	if (NULL == pCur->pStrTime) 
	{
		return ;
	}
	int shour;
	int shour;
	int sminute;
	int ehour;
	int eminute;
	sscanf(pCur->pStrTime, "%d:%d", &shour, &sminute);
	sscanf(strTime, "%d:%d", &ehour, &eminute);
	++cnt;
	totalM += (ehour * 60 + eminute) - (shour * 60 + sminute);
}
/*
	释放空间
 */
void clear(node * root) 
{
	if (NULL != root->pStrTime) 
	{
		free(root->pStrTime);
	}
	for (int i = 0; i < 10; ++i) 
	{
		if (NULL != root->pNext[i]) 
		{
			clear(root->pNext[i]);
		}
	}
	free(root);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	root = getNode();
	cnt = 0;
	totalM = 0;
	while (scanf("%s", strNum) != EOF) 
	{
		if (0 == strcmp(strNum, "-1")) 
		{
			break;
		}
		cin >> charFlag >> strTime;
		if (0 == strcmp(strNum, "0")) 
		{
			//这里打了个补丁，当cnt为零的时候
			//totalM / cnt会RE.
			if (0 == cnt) 
			{
				printf("0 0/n");
				continue;
			}
			printf("%.0lf %.0lf/n", cnt, totalM / cnt);
			cnt = 0;
			totalM = 0;
			clear(root);
			root = getNode();
			continue;
		}
		
		//借出船只
		if (charFlag == 'S')
		{
			insert(root, strNum, strTime);
		}
		//归还船只
		else 
		{
			query(root, strNum, strTime);
		}
	}
	return 0;
}