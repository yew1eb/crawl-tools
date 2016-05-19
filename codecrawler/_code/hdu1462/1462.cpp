#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cassert>
using namespace std;
#undef _DEBUG
#ifdef _DEBUG
#define PRINT_VAR() {/
    printf("%3d: p = %x, q = %x/n", __LINE__, p, q);/
}
#endif
char ans[30][50];
char a[100], b[100], c[100], d[100];
int main()
{
    int cs = 1;

    while(scanf("%s%s%s%s", a, b, c, d) == 4)
    {
        memset(ans, 0, sizeof(ans));
        strcpy(ans[10], a);
        int offset = strlen(a) + 3;
        strcpy(ans[10] + offset, c);
        char *p = a;
        while(*p)
        {
            char *q = b - 1;
            while(*++q && *q != *p) {}
            if(*q)
            {
                int i = 1;
                char *t = q;
                while(--t >= b)
                    ans[10 - i++][p - a] = *t;
                t = q;
                i = 1;
                while(*++t)
                    ans[10 + i++][p - a] = *t;
                break;
            }
#ifdef _DEBUG
            PRINT_VAR();
#endif
            ++p;
        }
        bool isSolvable = ((*p) ? true : false);
        p = c;
        while(*p && isSolvable)
        {
            char *q = d - 1;
            while(*++q && *q != *p) {}
            if(*q)
            {
                int i = 1;
                char *t = q;
                while(--t >= d)
                    ans[10 - i++][p - c + offset] = *t;
                t = q;
                i = 1;
                while(*++t)
                    ans[10 + i++][p - c + offset] = *t;
                break;
            }
#ifdef _DEBUG
            PRINT_VAR();
#endif
            ++p;
        }

        isSolvable = isSolvable && (*p);

        if(cs++ != 1)
            printf("/n");

        if(! isSolvable)
        {
            printf("Unable to make two crosses/n");
            continue;
        }

        int r = 0;
        while(r < 30)
        {
            bool lineIsEmpty = true;
            int c = 0;
            while(c < 50)
            {
                int spaces = 0;
                while(c < 50 && !ans[r][c])
                {
                    ++c;
                    ++spaces;
                }
                if(c >= 50)
                {
                    if(! lineIsEmpty)
                        printf("/n");
                    ++c;
                    continue;
                }

                lineIsEmpty = false;

                while(spaces-- > 0)
#ifdef _DEBUG
                    printf(".");
#else
                    printf(" ");
#endif
                printf("%c", ans[r][c]);
                ++c;
            }
            ++r;
        }
    }
    return 0;
}