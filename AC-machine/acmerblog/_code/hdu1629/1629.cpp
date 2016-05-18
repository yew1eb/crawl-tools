/*0.019s*/

#include<cstdio>
#include<cstring>
const int N = 20;
const char answer[][20] =
{
	"highest-card", "one-pair", "two-pairs", "three-of-a-kind", "straight",
	"flush", "full-house", "four-of-a-kind", "straight-flush"
};
const int bas_two[] = {16, 8, 4, 2, 1};

struct Card
{
	char name[5];
	int number,suit;
} hand[N];

char str[N];
int A[N], B[N], C[N];

int is_number(char c)
{
	if (c == 'A') return 1;
	if (c == 'T') return 10;
	if (c == 'J') return 11;
	if (c == 'Q') return 12;
	if (c == 'K') return 13;
	return c & 15;
}

int is_suit(char c)
{
	if (c == 'C') return 0;
	if (c == 'D') return 1;
	if (c == 'H') return 2;
	return 3; ///'S'
}

void handle(int cur, char str[])
{
	strcpy(hand[cur].name, str);
	hand[cur].number = is_number(str[0]);
	hand[cur].suit = is_suit(str[1]);
}

bool maxLink_num(int num[])///顺子检测
{
	bool flag;
	for (int i = 1; i < 10; i++)
	{
		if (num[i] > 1) return false;
		if (num[i] == 1)
		{
			flag = true;
			for (int j = 1; j < 5; j++)
			{
				if (num[i + j] != 1)
				{
					flag = false;
					break;
				}
			}
			if (flag) return true;
		}
	}
	if (num[10] == 1 && num[11] == 1 && num[12] == 1 && num[13] == 1 && num[1] == 1)
		return true;
	return false;
}

int judge(int cur)
{
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	memset(C, 0, sizeof(C));
	for (int i = 0; i < 5; i++)
	{
		if (cur / bas_two[i])
			B[i] = 0;
		else
			B[i] = 1;
		cur %= bas_two[i];
	}
	int cnt = 0;
	for (int i = 0; cnt < 5; i++)
	{
		if (!B[i])
		{
			A[hand[i].number]++;
			C[hand[i].suit]++;
			cnt++;
		}
	}
	/// Judge color and num;
	int max = 0,flag_color = 0, flag_num = 0;///最大同点数，不同花数，不同点数
	for (int i = 1; i < 14; i++){
		if (A[i] > max) max = A[i];
		if (A[i]) flag_num++;
	}
	for (int i = 0; i < 4; i++)
		if (C[i]) flag_color++;
	bool link = maxLink_num(A);
	///
	if (flag_color == 1 && link)   return 8;///5同花且是顺子
	if (max == 4)                  return 7;///4同点
	if (max == 3 && flag_num == 2) return 6;///3同点加上一对（有2个不同点的牌）
	if (flag_color == 1)           return 5;///5同花
	if (link)                      return 4;///顺子
	if (max == 3)                  return 3;///3同点
	if (max == 2 && flag_num == 3) return 2;///两对对子（有3个不同点的牌）
	if (max == 2)                  return 1;///一对对子
	return 0;
}

int main()
{
	int max = 0, flag = 0;
	while (true)
	{
		memset(hand, 0, sizeof(hand));
		max = flag = 0;
		for (int i = 0; i < 10; i++)
		{
			if (scanf("%s", str) != 1)
			{
				flag = 1;
				break;
			}
			handle(i, str);
		}
		if (flag) break;
		for (int i = 0; i < 32; i++)///枚举
		{
			flag = judge(i);
			if (flag > max) max = flag;
		}
		// Print
		printf("Hand: ");
		for (int i = 0; i < 5; i++)
			printf("%s ", hand[i].name);
		printf("Deck: ");
		for (int i = 5; i < 10; i++)
			printf("%s ", hand[i].name);
		printf("Best hand: %s\n", answer[max]);
	}
	return 0;
}