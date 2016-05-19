#include"stdio.h"
#include"string.h"
int hash[1000111];
int main()
{
    __int64 a,b,c;
    __int64 temp0,temp;
    __int64 flag;
    int i;
    int T;
    int head,tail,len;
    scanf("%d",&T);
    while(T--)
    {
        memset(hash,0,sizeof(hash));
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        a%=c;

        hash[a]=1;
        for(i=2,temp=a;i<=b;i++)
        {
            temp*=a;
            temp%=c;
            if(hash[temp]==1)    break;
            hash[temp]=1;
        }
        tail=i;

        if(i>=b)
        {
            printf("%I64d\n",temp);
            continue;
        }
        flag=temp;
        for(i=1,temp=a;i<=b;i++)
        {
            if(temp==flag)    break;
            temp*=a;
            temp%=c;
        }
        head=i;
        len=tail-head;

        temp0=b;
        temp0-=head;
        temp0%=len;
        temp0+=head;
        for(i=2,temp=a;i<=temp0;i++)
        {
            temp*=a;
            temp%=c;
        }
        printf("%I64d\n",temp);
    }
    return 0;
}