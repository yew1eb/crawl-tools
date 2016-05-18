/*
	说起这题真的会气死人的，物理到现在全忘了，什么叫干涉完全不知道，等于说这题根本没办法解
	看了解题报告才知道，悲剧！！看来做ACM什么都要学好啊，上回也有一个物理的要积分的题目
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#define IP 3.1415926
using namespace std;
int main()
{
	double r, h;
	while( scanf("%lf %lf", &h, &r) != EOF)
	{
		double ans = asin(0.01 * r / (4 * h));
		printf("%0.2lf/n", 180 * ans / IP);
	}
}