//每次挑出现频率最小的两个元素，应该用优先级队列！！！！！！！！！！

#include <stdio.h>
#include <limits.h>
#include <string.h>
int unionFre(int fre[26]);

int main()
{
	int frequency[26];    //记录每个字母出现的频率
	int n;
	int m;
	char input[10000];
	int letterNum;     //出现的小写字母的个数
	int len;
	int result;
	int i, j;

	scanf("%d", &n);
	while (n --)
	{
		scanf("%d", &m);
		scanf("%s", &input);
		//初始化
		memset(frequency, 0, sizeof(frequency));

		//统计每个字母出现的次数
		len = strlen(input);
		for (i = 0; i < len; i ++)
		{
			frequency[input[i]-'a'] ++;
		}
		//没出现的字母频率均设为最大值
		letterNum = 26;
		for (i = 0; i < 26; i ++)
		{
			if (frequency[i] == 0)
			{
				letterNum --;
				frequency[i] = INT_MAX;
			}
		}

		//如果字符串只由一个字母组成
		if (letterNum == 1)
		{
			