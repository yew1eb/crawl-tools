/**#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int jiec(int n)
{
    int s=1;
    for(int i=1;i<=n;i++)
    {
        s=s*i;
    }
    return s;
}
int main()
{
    int n,f;
    for(int i=1;i<=2147483647;i++)
    {
        int sum=0;
        n=i;
        while(n)
        {
            f=n%10;
            sum+=jiec(f);
            n=n/10;
        }
        if(i==sum)
        printf("%d\n",i);
    }
    return 0;
}*/

#include<stdio.h>
int main()
{
    printf("1\n2\n145\n40585\n");
    return 0;
}