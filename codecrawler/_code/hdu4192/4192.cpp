#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char stack1[20],stack2[20],str[20];
int top1,top2;
int n,m;
int v[10];
int flag;
int fv[10];
int cur[10];

int cal()
{
    int i,j;
    int lcm[10],len = 0;
    j = 0;
    for(i = 0;i < top2;i ++)
    {
        if(islower(stack2[i]))
            lcm[len ++] = cur[j ++];
        else
        {
            len --;
            switch(stack2[i])
            {
                case '+':lcm[len - 1] += lcm[len];
                break;
                case '-':lcm[len - 1] -= lcm[len];
                break;
                case '*':lcm[len - 1] *= lcm[len];
            }
        }
    }
    return lcm[0];
}

void dfs(int i,int cnt)
{
    if(flag)
        return;
    if(cnt == n - 1)
    {
        if(cal() == m)
        {
            flag = 1;
        }
        return;
    }
    int j;
    for(j = 0;j < n;j ++)
    {
        if(!fv[j])
        {
            fv[j] = 1;
            cur[cnt + 1] = v[j];
            dfs(j,cnt + 1);
            fv[j] = 0;
        }
    }
}

int main()
{
    int i;
    char c;
    while(scanf("%d",&n),n)
    {
        for(i = 0;i < n;i ++)
            scanf("%d",&v[i]);
        scanf("%d",&m);
        top1 = top2 = 0;
        scanf("%s",str);
        for(i = 0;i < strlen(str);i ++)
        {
            switch(str[i])
            {
                case '(':stack1[top1 ++] = str[i];
                break;
                case ')':while(stack1[top1 - 1] != '(')
                               stack2[top2 ++] = stack1[--top1];
                        top1 --;
                        break;
                case '*':if(top1 == 0 || stack1[top1 - 1] == '+'
                    || stack1[top1 - 1] == '-' || stack1[top1 - 1] == '(')
                            stack1[top1 ++] = '*';
                        else
                        {
                            while(stack1[top1 - 1] == '*')
                                stack2[top2 ++] = stack1[--top1];
                        }
                        break;
                case '+':
                case '-':if(stack1[top1 - 1] == '(' || top1 == 0)
                            stack1[top1 ++] = str[i];
                        else
                        {
                            while(stack1[top1 - 1] == '*')//stack1[top1 - 1] == '+' || stack1[top1 - 1] == '-')//之前写的有问题，竟然能过。。。
                                stack2[top2 ++] = stack1[--top1];
                        }
                        break;
                default:stack2[top2 ++] = str[i];
            }
        }
        flag = 0;
        for(i = 0;i < n;i ++)
        {
            memset(fv,0,sizeof(fv));
            fv[i] = 1;
            cur[0] = v[i];
            dfs(i,0);
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
        /*for(i = 0;i < top2;i ++)
            printf("%c",stack2[i]);
        printf("\n");*/
    }
    return 0;
}
//62MS	324K