#include"stdio.h"
#include"string.h"
#include"stdlib.h"
char num[10000111];
int ans[100000],k;
int base[20];
void getprime()
{
    int i,l;
    memset(num,-1,sizeof(num));
    num[0]=num[1]=0;
    for(i=2;i<=10000000;i++)
    {
        if(num[i])
        {
            for(l=2*i;l<=10000000;l+=i)
            {
                num[l]=0;
            }
        }
    }
}
int flag;
void getans(int len)
{
    int i;
    int temp=0;
    for(i=len-1;i>=0;i--)    {temp*=10;temp+=base[i];}
    if(num[temp])
    {
        if(flag==0 && temp>11)
        {
            ans[k++]=11;
            flag=1;
        }
        ans[k++]=temp;
    }
}
void create(int len,int k)
{
    int j;
    if(k+1==len)    j=1;
    else            j=0;
    for(;j<=9;j++)
    {
        base[k]=base[len-1-k]=j;
        if(k==len/2)    {getans(len);continue;}
        create(len,k-1);
    }
}
int main()
{
    int i;
    int a,b;
    int low,mid,up;


    getprime();
    flag=k=0;
    for(i=1;i<=7;i+=2)    create(i,i-1);


    while(scanf("%d%d",&a,&b)!=-1)
    {
        low=0;up=k-1;mid=(low+up)>>1;
        while(low<=up)
        {
            if(ans[mid]<a)    low=mid+1;
            else            up=mid-1;
            mid=(low+up)>>1;
        }
        for(;low<k;low++)
        {
            if(ans[low]<=b)    printf("%d\n",ans[low]);
            else            break;
        }
        printf("\n");
    }
    return 0;
}