//hdu 1231  dp(最大连续子序列)

//题目给出一串数字，要求输出 最大连续子序列的 和 
//与序列第一个数和最后一个数
//若所有数都是负的则 和为0，并输出第一个数和最后一个数

//具体看代码


#include <stdio.h>

#define N 50005

int n_num;
int num[N];


int main()
{
    while(scanf("%d", &n_num), n_num)
    {
        for(int i = 0; i < n_num; ++i)
            scanf("%d", &num[i]);

        int sum, ans, st, ed, ans_st, ans_ed;
        //初始化
        ans_st = ans_ed = st = ed = sum = ans = num[0];

        for(int i = 1; i < n_num; ++i)
        {
            if(sum > 0) //若i 之前序列和大于0，则加上i 肯定
            {           //比之前的序列大
                sum += num[i];
                ed = num[i];
            }       //若 i 之前的序列 小于 等于0 则加上 i 肯定更小
            else    //因此 i 自成一个序列
                st = ed = sum = num[i]; 
                
            //若之前的序列为负 第i个为0，则照样更新
            //若得到的序列中 都为 负 则怎么更新 ans 都是负的
            if(ans < sum)   //若 到 i 的序列大于 记录的最大值，
            {               //则记下 序列第一个和最后一个数
                ans_st = st;
                ans_ed = ed;
                ans = sum;      //更新最大值
            }
        }
        if(ans < 0) //若 ans 为负的，则所有序列中肯定没有 0的
            printf("0 %d %d\n", num[0], num[n_num-1]);
        else
            printf("%d %d %d\n", ans, ans_st, ans_ed);
    }
    return 0;
}