#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

struct node
{
    char name[110];
    int birth;
}stu[105];

struct cmp
{
    bool operator()(const node & a, const node & b)
    {
        return a.birth>b.birth;
    }
};

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        getchar();
        for(int i=0; i<n; i++)
        {
            gets(stu[i].name);
            int len = strlen(stu[i].name);
            stu[i].birth = stu[i].name[len-4]*1000+stu[i].name[len-3]*100+stu[i].name[len-2]*10+stu[i].name[len-1];
            stu[i].name[len-5] = '\0';
        }

        sort(stu, stu+n, cmp());
        for(int i=0; i<n; i++)
            printf("%s\n", stu[i].name);
    }
    return 0;
}
