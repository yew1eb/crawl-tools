#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getsum (int x) // getsum_all_letter的函数,我觉得是一个不错的函数, 
{
	int sum = 0;
	while (x)
	{
		sum += x % 10;
		x /= 10;
	}
	return sum;
}


int main ()
{
	int N;
	while (cin >> N)
	{
		if (N == 0)
		{
			break;
			
		}
		for (int x = N + 1; ; x++)
		{
			int key = x;  // 因为你最后还要把这个数字输出来,所以要提前把初始的数字先存起来. 
			int sum_all_letter = getsum (key); //所求的和; 
			int sum_prime = 0; //分解质因数的和; 
			int flag_prime = 0;//标记是x是不是一个素数; 
			for (int i = 2; i <= sqrt (key * 1.0); i++)
			{
				while (key % i == 0)
				{
					flag_prime++;  //这个就是标记:看初始状态的key是不是个素数,如果是素数就得祛除. 
					sum_prime += getsum (i); //方法很奇特. 
					key /= i;
				}
			}
			if (key != 1)
			{
				sum_prime += getsum (key); // 就是排除除到了最后出现了一个prime number,所以加个语句,判断最后的 
			}								//那个除数是不是素数. 
			if (sum_all_letter == sum_prime && flag_prime != 0) //这个思想是真的很不错的, 
			{
				cout << x << endl;
				break;
			}
		}
	}
	return 0;
}
/*
这道题目真的是个好题目,因为涉及的知识点很多, 有怎么样求一个整数的所有数字的和的算法getsum,
也有最正确的求整数的素因数分解的算法...诶.
这个晚上就是搞这个题目了,真的很恨自己呀,,老是出错,一次一次的敲也不往自己的心里面去.
那这样的学习,你就还不如回宿舍里面好好的休息呢..或者去陪你的女朋友去,我一直都认为,
你一直都这样的告诉你自己,如果自己没有真心的学会,那就别做,,你做也不是白做么??仅仅是浪费自己的时间,
浪费自己的青春.
*/