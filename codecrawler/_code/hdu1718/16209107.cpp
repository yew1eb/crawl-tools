#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int cmp(const int x,const int y)
{
    return x > y;
}
int main()
{
    char flag[100],a[100];
    int k,b,tem,num[1005];
    while(~scanf("%s",flag))
    {
        k = 0;
        while(~scanf("%s%d",&a,&b))
        {
            if(!strcmp(a,"0") && b==0) break;
            if(!strcmp(a,flag))
                tem = b;
            num[k++] = b;
        }
        sort(num,num+k,cmp);
        int cnt = 1;
        for(int i = 0; i<k; i++)
        {
            if(num[i] > tem)
                cnt++;
            else
                break;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
