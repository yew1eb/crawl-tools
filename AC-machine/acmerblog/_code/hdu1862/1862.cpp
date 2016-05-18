#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct _excel
{
    char no[7];
    char name[9];
    int score;
}excel;

excel ex[100001];

int cmpno(const void *a, const void *b)
{
    excel *fa = (excel*)a;
    excel *fb = (excel*)b;
    return strcmp(fa->no, fb->no) > 0 ? 1 : -1;
}

int cmpname(const void *a, const void *b)
{
    excel *fa = (excel *)a;
    excel *fb = (excel *)b;
    if(strcmp(fa->name, fb->name)!=0)return strcmp(fa->name, fb->name) > 0 ? 1 : -1;
    return strcmp(fa->no, fb->no) > 0 ? 1 : -1;
}

int cmpscore(const void *a, const void *b)
{
    excel *fa = (excel *)a;
    excel *fb = (excel *)b;
    if(fa->score != fb->score)return fa->score - fb->score > 0 ? 1 : -1;
    return strcmp(fa->no, fb->no) > 0 ? 1 : -1;
}

int main()
{
//    freopen("input.in", "r", stdin);
    int n, i, hw;
    int cas = 1;
    while(scanf("%d%d", &n, &hw)&&n){
        for(i = 0; i < n; i ++){
            scanf("%s%s%d", ex[i].no, ex[i].name, &ex[i].score);
        }
        if(hw == 1){
            qsort(ex, n, sizeof(ex[0]), cmpno);
        }
        else if(hw == 2){
            qsort(ex, n, sizeof(ex[0]), cmpname);
        }
        else if(hw == 3){
            qsort(ex, n, sizeof(ex[0]), cmpscore);
        }

        printf("Case %d:\n", cas ++);
        for(i = 0; i < n; i ++){
            printf("%s %s %d\n", ex[i].no, ex[i].name, ex[i].score);
        }
    }
    return 0;
}