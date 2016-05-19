#include<cstdio>
int main()
{
    int t,n;
    char s;
    scanf("%d",&t);
    getchar();

    for(int i = 0;i < t;++i)
    {
        n = 0;
        while((s = getchar())!= '\n')
        {
            if(s <='9' && s>='0') ++n;
        }
        printf("%d\n",n);
    }
    return 0;
}
