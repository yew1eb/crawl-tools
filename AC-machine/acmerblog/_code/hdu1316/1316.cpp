#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h> 
#define M 105

char a[M+2],b[M+2];

char book[1000][M+2];

int cmp(char *s1,char *s2)
{
	for(int i=0;i<=M;++i)
	{
		if(i==M)
		{ 
			return s1[i]-s2[i];//如果到最后一位相等,要保证返回0; 
		}
		if(s1[i]==s2[i])
			continue;
		else
		{ 
			return s1[i]-s2[i];
		}
	}
} 

//一下两个函数是二分查找上下界的位置. 
//查找原则是下界数组坐标减一,上界数组坐标加一 

int find1(int i,char *x)    
{ 
	int low=0,high=i,mid; //定义左右指针,中间指针 
	while(low<=high)
	{
		mid=(low+high)/2;
		int t=cmp(book[mid],x); 
		if(t>0)
			high=mid-1;//改变左右界,并偏移(为了使左右指针交错) 
		else if(t==0) 
			return mid-1;  
		else
			low=mid+1;
	}  
	return high;   //跳出时, high 变量在左边
}

int find2(int i,char *x)
{
	int low=0,high=i,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		int t=cmp(book[mid],x); 
		if(t>0) 
			high=mid-1;  
		else if(t==0) 
			return mid+1; 
		else 
			low=mid+1;  
	} 
	return low; 
}

int main()
{
	int p=M,i=2;  //p用于标记最高位的位置 
	book[0][M]=1,book[1][M]=2;
	while(book[i-1][M-100]<=1)
	{
		for(int j=M;j>=p;--j)
			book[i][j]=book[i-1][j]+book[i-2][j];
		for(int j=M;j>=p;--j)
		{
			int c=book[i][j]/10;
			book[i][j]%=10;
			book[i][j-1]+=c;
		}     //即时进位操作 
		if(book[i][p-1]>0) //判断是否最高位发生变化 
			--p;//如果当前的最高位的下一位不为零,则指针减一 
		++i; 
	}    
	while(scanf("%s%s",a,b),a[0]-'0'||b[0]-'0')
	{
		int cnt=0,p;
		int last1=strlen(a)-1;
		int last2=strlen(b)-1;
		for(int j=last1,k=M;j>=0;--j,--k)
		{
			a[k]=a[j]-'0';
			a[j]=0;          //消除干扰比较的因素,置零操作 
		} 
		for(int j=last2,k=M;j>=0;--j,--k)
		{	
			b[k]=b[j]-'0';
			b[j]=0; 
		} 
		int l=find1(i-1,a); 
		int r=find2(i-1,b); 
		printf("%d\n",r-l-1);
		memset(a,0,sizeof(a));  //清除上一次操作的数据遗留 
		memset(b,0,sizeof(b)); 
	} 
    return 0;
}