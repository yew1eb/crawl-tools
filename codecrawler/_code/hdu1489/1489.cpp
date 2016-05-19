/*UVaOJ: 0.065s*/
/*HDU: 62ms,1740KB*/
/*POJ: 375ms,2056KB*/

#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

struct node
{
	int pos, num;
} a[100000];

deque<node> buy, sell;

int main()
{
	int n, temp;
	while (scanf("%d", &n), n)
	{
		buy.clear();
		sell.clear();
		node tempbuy, tempsell;
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			a[i].pos = i;
			a[i].num = temp;
			if (temp > 0)
				buy.push_back(a[i]);
			else if (temp < 0)
				sell.push_back(a[i]);//注意a[i].num是负数

			//while里面的操作就像回合制游戏一样，你懂的~
			while (!(buy.empty() || sell.empty()))
			{
				tempbuy = buy.front();
				buy.pop_front();
				tempsell = sell.front();
				sell.pop_front();
				if (tempbuy.num + tempsell.num > 0)
				{
					sum -= tempsell.num * abs(tempbuy.pos - tempsell.pos);
					tempbuy.num += tempsell.num;
					buy.push_front(tempbuy);
				}
				else
				{
					if (tempbuy.num + tempsell.num < 0)
					{
						tempsell.num += tempbuy.num;
						sell.push_front(tempsell);
					}
					sum += tempbuy.num * abs(tempbuy.pos - tempsell.pos);
				}
			}
		}
		printf("%I64d\n",sum);
	}
	return 0;
}