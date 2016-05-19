#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10005
typedef int Elemtype;
typedef struct Stack
{
    Elemtype data[M];
    int top;
}Stack;
struct Stack *Init()
{
    struct Stack *s;
    s= (struct Stack *)malloc(sizeof(struct Stack ));
    if(s!= NULL)
    {
        s->top = -1;
        return s;
    }
    else exit(0);
}

int main()
{
    struct Stack *s;
    int n,temp;
    s = Init();
    while(scanf("%d",&n)!= EOF)
    {
        while(n)
        {
            s->top++;
            s->data[s->top] = n%2;
            n = n/2;
        }
        while(s->top != -1)
        {
            temp = s->data[s->top];
            s->top--;
            printf("%d",temp);
        }
        printf("\n");
    }
    return 0;
}