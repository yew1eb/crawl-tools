#include <stdio.h>
int k;
__int64 a,b;
__int64 pow(int x,int y)
{
    int i;
    __int64 s=1;
    for(i=0;i<y;i++)
        s*=x;
    return s;
}
#define MAX pow(2,63) 
int test()
{
    __int64 max,min;
    if(k==64)min=-MAX,max=MAX-1;
    else    
        min=-MAX>>k,max=(MAX>>k)-1;
    if(a==0&&b==0)return 0;
    if(a>0&&b<0)return 0;
    if(a<0&&b>0)return 0;
    if(a>0)
        return (max-a)<b;
    return (min-a)>b;
}
int main()
{
    while(~scanf("%d",&k))
    {
        scanf("%I64d%I64d",&a,&b);
        printf(test()?"Yes\n":"WaHaHa\n");
    }
    return 0;
}