//动态压缩dp
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

typedef struct _homework
{
	char name[102];
	int deadline;
	int needday;
}homework;

homework hwk[16];
int n;

typedef struct _DP
{
	int ndday;
	int pre;
	int lowcost;
}DP;

DP dp[1<<15];
bool visited[1<<15];

void output(int status)
{
	int curwk = dp[status].pre ^ status;
	int curid = 0;
	curwk >>= 1;
	while(curwk){
		curid ++;
		curwk >>= 1;
	}
	if(dp[status].pre != 0){
		output(dp[status].pre);
	}
	printf("%s\n", hwk[curid].name);
}

int main()
{
	freopen("input.txt", "r", stdin);
	int t, i, j;
	int upper, cur, curtmp, reduce;
	scanf("%d", &t);
	while(t --){
		scanf("%d", &n);
		for(i = 0; i < n; i ++){
			scanf("%s%d%d", hwk[i].name, &hwk[i].deadline, &hwk[i].needday);
		}
		memset(visited, false, sizeof(visited));
		upper = (1 << n) - 1;//最大
		dp[0].ndday = 0, dp[0].lowcost = 0, dp[0].pre = -1;
		visited[0] = true;
		for(i = 0; i < upper; i ++){
			for(j = 0; j < n; j ++){
				cur = 1 << j;
				if((cur & i) == 0){
					curtmp = cur | i;
					dp[curtmp].lowcost = dp[i].lowcost + hwk[j].needday;
					reduce = dp[curtmp].lowcost - hwk[j].deadline;
					if(reduce < 0)reduce = 0;
					reduce += dp[i].ndday;
					if(visited[curtmp]){
						if(reduce < dp[curtmp].ndday){
							dp[curtmp].ndday = reduce;
							dp[curtmp].pre = i;
						}
					}
					else {
						visited[curtmp] = true;
						dp[curtmp].ndday = reduce;
						dp[curtmp].pre = i;
					}//else
				}//if
			}//for
		}//for
		printf("%d\n", dp[upper].ndday);
		output(upper);
	}//while
	return 0;
}