#include "stdio.h"
#include "string.h"

int now;
void pri(int l,int r)
{
    int i;
    printf("%d - %d\n",l,l+1);
    now++;
    for (i=l+2;i<=r;i++)
    {
        printf("%d * %d\n",now,i);
        now++;
    }
}

void make(int l, int r)
{
    printf("1 + 2\n");  // now+1
    printf("4 + 5\n");  // now+2
    printf("7 + 8\n");  // now+3
    printf("10 + 11\n"); // now+4
    printf("%d + 12\n",now+4); // now+5
    printf("%d / 3\n",now+1); // now+6
    printf("%d * %d\n",now+6,now+2); // now+7
    printf("%d / 6\n",now+7); // now+8
    printf("%d * %d\n",now+8,now+3); // now+9
    printf("%d / 9\n",now+9); //now+10;
    printf("%d * %d\n",now+10,now+5); // now+11;
    printf("%d / 13\n",now+11); // now+12;
    now+=12;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n<=3) printf("-1\n");
        if (n==4)
        {
            printf("1 * 2\n");
            printf("5 + 3\n");
            printf("6 + 4\n");
        }
        if (n==5)
        {
            printf("1 / 2\n");
            printf("6 / 3\n");
            printf("4 - 7\n");
            printf("5 * 8\n");
        }
        if (n==6)
        {
            printf("1 + 2\n");
            printf("7 + 3\n");
            printf("8 + 4\n");
            printf("9 + 5\n");
            printf("10 - 6\n");
        }
        if (n==7)
        {
            printf("1 / 2\n");
            printf("3 * 4\n");
            printf("9 - 8\n");
            printf("5 + 6\n");
            printf("10 / 11\n");
            printf("12 * 7\n");
        }
        if (n==8)
        {
            printf("1 - 2\n");
            printf("9 * 3\n");
            printf("10 * 4\n");
            printf("11 * 5\n");
            printf("12 + 6\n");
            printf("13 + 7\n");
            printf("14 + 8\n");
        }
        if (n==9)
        {
            printf("4 / 5\n");
            printf("6 / 7\n");
            printf("8 / 9\n");
            printf("1 + 2\n");
            printf("13 + 3\n");
            printf("14 - 10\n");
            printf("15 - 11\n");
            printf("16 - 12\n");
        }
        if (n==10)
        {
            printf("1 / 2\n");
            printf("3 / 4\n");
            printf("5 / 6\n");
            printf("7 / 8\n");
            printf("9 + 10\n");
            printf("11 + 12\n");
            printf("16 + 13\n");
            printf("17 + 14\n");
            printf("18 + 15\n");
        }
        if (n==11)
        {
            printf("1 + 2\n");
            printf("3 / 4\n");
            printf("5 / 6\n");
            printf("12 + 13\n");
            printf("15 + 14\n");
            printf("7 - 8\n");
            printf("17 * 9\n");
            printf("18 * 10\n");
            printf("19 * 11\n");
            printf("20 + 16\n");
        }
        if (n==12)
        {
            printf("1 + 2\n");
            printf("13 / 3\n");
            printf("14 * 4\n");
            now=15;
            pri(5,12);
            printf("15 + %d\n",now);
        }
        if (n==14)
        {
            printf("1 / 2\n");
            printf("3 / 4\n");
            printf("5 - 15\n");
            printf("17 - 16\n");
            printf("6 + 7\n");
            printf("19 / 8\n");
            printf("20 * 18\n");
            now=21;
            pri(9,14);
            printf("21 + %d\n",now);
        }
        if (n==13 || n>=15)
        {
            now=n;
            make(1,13);
            if (n==13) continue;
            else
            if (n==15)
            {
                printf("14 / 15\n");
                printf("%d * %d\n",now,now+1);
            }
            else
            {
                int mark;
                mark=now;
                pri(14,n);
                printf("%d + %d\n",mark,now);
            }
        }
    }
    return 0;
}
