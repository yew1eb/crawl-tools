/*
 * hdu-1002
 * mike-w
 * 2012-5-21
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include<assert.h>
#endif

#define MAX_NUM_LEN 1234
#define BASE 10000
#define WIDTH 4
#define min(a,b) ((a)>(b)?(b):(a))

int conv(char *buf, int *s)
{
	int len=strlen(buf);
	int weight=1,pos=MAX_NUM_LEN-1;
	int i;
	memset(s,0,sizeof(int)*MAX_NUM_LEN);
	for(i=1;i<=len;i++)
	{
		s[pos]+=(buf[len-i]-'0')*weight;
		weight*=10;
		if(weight==BASE)
			weight=1, pos--;
	}
	s[0]=pos;
	return 0;
}

int add(int *a1, int *a2, int *s)
{
	memset(s,0,sizeof(int)*MAX_NUM_LEN);
	int end=min(a1[0], a2[0]);
	int carry=0,i;
	for(i=MAX_NUM_LEN-1;i>=end;i--)
	{
		s[i]=a1[i]+a2[i]+carry;
		carry=s[i]/BASE;
		s[i]%=BASE;
	}
	if(carry)
		s[i]=carry,s[0]=i;
	else
		s[0]=i+1;
	return 0;
}

int disp(int *s)
{
	int i=s[0];
	while(i<MAX_NUM_LEN && s[i]==0)
		i++;
	if(i==MAX_NUM_LEN)
		putchar('0');
	else
		printf("%d",s[i]);
	for(i++;i<MAX_NUM_LEN;i++)
		printf("%0*d",WIDTH,s[i]);
	return 0;
}

int read_num(int *s)
{
	char buf[MAX_NUM_LEN];
	memset(s,0,sizeof(int)*MAX_NUM_LEN);
	scanf("%s",buf);
	conv(buf,s);
	return 0;
}

int main(void)
{
#ifndef ONLINE_JUDGE
	assert(freopen("in","r",stdin));
#endif
	int ncase,ccase;
	int n1[MAX_NUM_LEN];
	int n2[MAX_NUM_LEN];
	int s[MAX_NUM_LEN];
	scanf("%d",&ncase);
	for(ccase=1;ccase<=ncase;ccase++)
	{
		if(ccase>1)
			putchar('\n');
		printf("Case %d:\n",ccase);
		read_num(n1);
		read_num(n2);
		add(n1, n2, s);
		disp(n1)
		printf(" + ");
		disp(n2);
		printf(" = ");
		disp(s);
		printf("\n");
	}
	return 0;
}
/*
 * extra words:
 * 我的存储大数的方法：
 * char* -> int*
 * 数字在数组中与尾部对齐——不倒序存储！
 * 数组的首位标示了数字可能开始的位置，有可能比实际开始位置
 * 提前。
 * 输出的过程中注意过滤掉数组前面的0
 */