#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1010
int que[15];

struct node
{
    char str[22];
    int num;
    int score;
}stu[N];

bool cmp(const node &a, const node &b)
{
    if(a.score == b.score)
        return strcmp(a.str, b.str) < 0 ? 1 : 0; //æå­å¸åºååº
    else
        return a.score > b.score;
}

int main()
{
    int student, question, judge, x, count;
    while(scanf("%d", &student) && student)
    {
        count = 0;
        for(int i = 1; i <= student; ++i)
        {
            stu[i].score = 0;
            stu[i].num = 0;
        }
        scanf("%d%d", &question, &judge);
        for(int i = 1; i <= question; ++i)
            scanf("%d", &que[i]);
        for(int i = 1; i <= student; ++i)
        {
            scanf("%s%d", stu[i].str, &stu[i].num);
            while(stu[i].num--)
            {
                scanf("%d", &x);
                stu[i].score += que[x];
            }
            if(stu[i].score >= judge)
                    count++;
        }
        sort(stu + 1, stu + 1 + student, cmp);
        printf("%d\n", count);
        for(int i = 1; i <= student; ++i)
        {
            if(stu[i].score >= judge)
                printf("%s %d\n", stu[i].str, stu[i].score);
            else
                break;
        }
    }
    return 0;
}