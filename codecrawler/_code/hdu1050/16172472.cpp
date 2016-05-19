#include <cstdio>
#include <algorithm>

using namespace std;

#define SIZE 205

struct Data_Type
{
    int from, to;
    bool flag;
}moving[SIZE];

bool Cmp(const Data_Type a, const Data_Type b)
{
    return a.from < b.from;
}

int main(void)
{
    int i, testNum, n;

    scanf("%d", &testNum);
    while (testNum-- != 0)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &moving[i].from, &moving[i].to);
            if (moving[i].from > moving[i].to)
            {
                int temp = moving[i].from;
                moving[i].from = moving[i].to;
                moving[i].to = temp;
            }
            if (moving[i].from % 2 == 0)
            {
                moving[i].from--;
            }
            if (moving[i].to % 2 == 1)
            {
                moving[i].to++;
            }
            moving[i].flag = false;
        }
        sort(moving, moving+n, Cmp);
        bool completion = false;
        int count = -1, priorTo;
        while (!completion)
        {
            completion = true;
            count++;
            priorTo = 0;
            for (i = 0; i < n; i++)
            {
                if (!moving[i].flag && moving[i].from > priorTo)
                {
                    moving[i].flag = true;
                    priorTo = moving[i].to;
                    completion = false;
                }
            }
        }
        printf("%d\n", count*10);
    }
    return 0;
}