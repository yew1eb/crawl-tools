#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1005
int que[15];

struct node
{
    char name[25];
    int num;
    int sum;
} stu[N];

bool cmp(const node &a,const node &b)
{
    if(a.sum == b.sum)
        return strcmp(a.name,b.name) < 0 ? 1 : 0;
    else
        return a.sum > b.sum;
}

int main()
{
    int stu_num,text_num,line,a,cnt;

    while(scanf("%d",&stu_num)!=EOF && stu_num)
    {
        cnt = 0;
        int i;
        scanf("%d%d",&text_num,&line);
        for(i = 1; i<=text_num; i++)
            scanf("%d",&que[i]);
        for(i = 1; i<=stu_num; i++)
        {
            stu[i].sum = 0;
            scanf("%s%d",stu[i].name,&stu[i].num);
            while(stu[i].num--)
            {
                scanf("%d",&a);
                stu[i].sum+=que[a];
            }
            if(stu[i].sum>=line)
                cnt++;
        }
        sort(stu+1,stu+1+stu_num,cmp);
        cout << cnt << endl;
        for(i = 1; i<=stu_num; i++)
        {
            if(stu[i].sum >=line)
                printf("%s %d\n",stu[i].name,stu[i].sum);
            else
                break;
        }
    }
    return 0;
}
