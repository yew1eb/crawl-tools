/************************************************************************/
/* 稳定排序

Time Limit: 3000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 2282    Accepted Submission(s): 896


Problem Description
大家都知道，快速排序是不稳定的排序方法。
如果对于数组中出现的任意a[i],a[j](i<j),其中a[i]==a[j]，在进行排序以后a[i]一定出现在a[j]之前，则认为该排序是稳定的。

某高校招生办得到一份成绩列表，上面记录了考生名字和考生成绩。并且对其使用了某排序算法按成绩进行递减排序。现在请你判断一下该排序算法是否正确，如果正确的话，则判断该排序算法是否为稳定的。


Input
本题目包含多组输入，请处理到文件结束。
对于每组数据，第一行有一个正整数N(0<N<300)，代表成绩列表中的考生数目。
接下来有N行，每一行有一个字符串代表考生名字(长度不超过50，仅包含'a'~'z'),和一个整数代表考生分数(小于500)。其中名字和成绩用一个空格隔开。
再接下来又有N行，是上述列表经过某排序算法以后生成的一个序列。格式同上。


Output
对于每组数据，如果算法是正确并且稳定的，就在一行里面输出"Right"。如果算法是正确的但不是稳定的，就在一行里面输出"Not Stable"，并且在下面输出正确稳定排序的列表，格式同输入。如果该算法是错误的，就在一行里面输出"Error",并且在下面输出正确稳定排序的列表，格式同输入。

注意，本题目不考虑该排序算法是错误的，但结果是正确的这样的意外情况。


Sample Input
3
aa 10
bb 10
cc 20
cc 20
bb 10
aa 10
3
aa 10
bb 10
cc 20
cc 20
aa 10
bb 10
3
aa 10
bb 10
cc 20
aa 10
bb 10
cc 20


Sample Output
Not Stable
cc 20
aa 10
bb 10
Right
Error
cc 20
aa 10
bb 10


Author
linle


Source
2008浙大研究生复试热身赛（2）——全真模拟
*/
/************************************************************************/

#include "iostream"
#include "stdio.h"
#include "math.h"
#include "map"
#include "vector"
#include "queue"
#include "memory.h"
#include "algorithm"
#include "string"
using namespace std;

struct SC
{
	int id;
	char name[60];
	int score;
	bool operator <(const SC a)const
	{
		if(a.score!=score)
			return a.score<score;
		return id<a.id;
	}
}stu[305],res[305];

int main()
{
	int n,i;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			scanf("%s%d",&stu[i].name,&stu[i].score),stu[i].id=i;
		sort(stu,stu+n);
		SC tmp;
		bool sorterror=false,error=false;
		for(i=0;i<n;i++)
		{
			scanf("%s%d",&res[i].name,&res[i].score);
			if(strcmp(res[i].name,stu[i].name))
			{
				if(res[i].score==stu[i].score)
					sorterror=true;
				else
					error=true;
			}
		}
		if(error)
			cout<<"Error"<<endl;
		else if(sorterror)
			cout<<"Not Stable"<<endl;
		else{
			cout<<"Right"<<endl;continue;}
		for(i=0;i<n;i++)
			printf("%s %d\n",stu[i].name,stu[i].score);
	}
}